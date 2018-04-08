//+------------------------------------------------------------------------------------------------+
//| LPTMR peripheral driver for Kinetis MKL26 MCU.                                                 |
//|                                                                                                |
//| This driver provides hardware interrupt services for Contiki's clock and rtimer libraries.     |
//|                                                                                                |
//| The LPTMR (low power timer) can wake the CPU from low power modes while operating from a low   |
//| frequency (and hence, low power) clock reference. It has a very flexible clock selection       |
//| scheme, which makes it ideal for the requirements of clock and rtimer libraries from Contiki.  |
//|                                                                                                |
//| The timer has a 16 bit counter that is continuously compared against a 16 bit compare          |
//| register, generating an interrupt (and waking the system) one cycle after the match occurs.    |
//| This allows scheduling interrupts at arbritrary times, which is very convenient.               |
//|                                                                                                |
//| One (minor) drawback is that 16 bits is a rather low resolution. Meaning that for example,     |
//| when working at 32.768kHz, the timer overflows every 2 seconds, which is a rather short time.  |
//| This means that delays longer than half of that (1 second, because of signed compares) cannot  |
//| be requested through rtimer. If the frequency were to go higher than that, the maximum allowed |
//| time would get even shorter.                                                                   |
//|                                                                                                |
//| This limitation is easily overcome by checking for overflows at every interrupt and updating   |
//| additional 16 bits through software, creating a 32 bit timer effectively. Luckily for us, the  |
//| maximum interrupt interval isn't given by rtimer but rather by the clock library, which        |
//| requires interrupts at a rate much higher than the overflow rate, meaning that we always get a |
//| chance to detect every overflow without skipping.                                              |
//|                                                                                                |
//| It should also be mentioned that on Teensy LC, a 16MHz oscillator comes installed on board     |
//| and the bootloader requires this in order to work properly, meaning that if a low power, low   |
//| frequency, low ppm oscillator (32.768kHz) is needed, it has to be added externally. This can   |
//| be chosen as a power profile option. Check the project documentation for details.              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdint.h>
#include <stdbool.h>

#include "contiki-conf.h"

#include "clock.h"
#include "rtimer.h"

#include "mkl26.h"
#include "mkl26-sim.h"
#include "mkl26-lptmr.h"

//Type used to keep track of time throughout this module. It's basically a 32-bit integer that can
//be interpreted as unsigned (for time tracking and compatibility with rtimer) or signed (for time
//comparisons) or can be decomposed into its two 16 bit unsigned halves.
typedef union {
  uint32_t u32;
  int32_t i32;
  struct {
    uint16_t u16_l;
    uint16_t u16_h;
  };
} lptmr_clock_t;

//Local variables used to track times and status. Shared with LPTMR IRQ handler.
static volatile lptmr_clock_t lptmr_count;    //Last known LPTMR count (extended to 32 bits)
static volatile lptmr_clock_t clock_next;     //Next clock library interrupt time
static volatile lptmr_clock_t rtimer_next;    //Next rtimer library interrupt time
static volatile bool rtimer_req = false;      //Indicates wether an rtimer interrupt is requested

//This macro compares two lptmr_clock_t values called 'a' and 'b', returning true if 'a' is less
//than 'b' (that is, time 'a' comes before time 'b').
#define LPTMR_LT(a, b) (a.i32 - b.i32 < 0)

//This macro calculates the amount of LPTMR timer ticks per clock library tick.
#define CLOCK_SECOND_COUNT (F_LPT / CLOCK_SECOND)

//External callback functions called by this module.
extern void clock_callback();
extern void rtimer_arch_callback();

//This function initializes the LPTMR module.
void lptmr_init() {
  //Clear the LPTMR 32-bit count and set the first periodic interrupt time for clock library.
  lptmr_count.u32 = 0;
  clock_next.u32 = CLOCK_SECOND_COUNT;

  //Initialize the LPTMR timer.
  //---------------------------

  //Enable access to the module.
  SIM->SCGC5 |= SIM_SCGC5_LPTMR_Enabled;

  //Set the clock source depending on the power profile
#if MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_PERFORMANCE_48MHZ_PLL
  //Use the external reference clock (16MHz oscillator) divided by 512 (31.25kHz).
  LPTMR0->PSR = LPTMR_PSR_PCS_OSCERCLK | LPTMR_PSR_PBYP_Enabled | LPTMR_PSR_PRESCALE_Div512;
#elif MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF
  //Use the internal reference clock (fast 4MHz reference) divided by 128 (31.25kHz).
  LPTMR0->PSR = LPTMR_PSR_PCS_MCGIRCLK | LPTMR_PSR_PBYP_Enabled | LPTMR_PSR_PRESCALE_Div128;
#elif MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_LOWPOWER_4MHZ_EXTREF
  //Use the external reference clock (32.768kHz external osc.) without divider.
  LPTMR0->PSR = LPTMR_PSR_PCS_ERCLK32K | LPTMR_PSR_PBYP_Bypassed;
#else
  #error "Unsupported power profile"
#endif

  //Set the compare register to schedule the next periodic interrupt.
  LPTMR0->CMR = clock_next.u16_l - 1;

  //Enable the timer in time counter mode, reset until overflow, enable compare interrupt.
  LPTMR0->CSR = LPTMR_CSR_TEN_Enabled | LPTMR_CSR_TMS_Time_Counter | LPTMR_CSR_TFC_Reset_Overflow |
                LPTMR_CSR_TIE_Enabled;

  //Configure the interrupt in the NVIC.
  //------------------------------------
  NVIC_SetPriority(LPTMR_0_IRQn, 2);  //Set a middle priority level
  NVIC_EnableIRQ(LPTMR_0_IRQn);       //Enable the interrupt
}

//This function returns the current LPTMR counter value extended to 32 bits.
rtimer_clock_t lptmr_get_count() {
  uint16_t cnr;
  lptmr_clock_t value;

  //Disable the IRQ before copying counter values.
  NVIC_DisableIRQ(LPTMR_0_IRQn);

  //Get a copy of last known LPTMR count.
  value.u32 = lptmr_count.u32;

  //Read the current counter value.
  LPTMR0->CNR = 0;    //Latch the value before read
  cnr = LPTMR0->CNR;

  //Couter values copied. Enable the IRQ again.
  NVIC_EnableIRQ(LPTMR_0_IRQn);

  //Check wether the timer overflowed by checking if the current count is less than the last count.
  //If an overflow is detected increase the high word of the copied count.
  if (cnr < value.u16_l)
    value.u16_h++;

  //Update the lower word after the upper word is updated.
  value.u16_l = cnr;

  //Return the updated 32 bit value.
  return value.u32;
}

//This function schedules an interrupt at the specified LPTMR counter value extended to 32 bits.
//When the interrupt occurs the rtimer callback function is called.
void lptmr_rtimer_schedule(rtimer_clock_t time) {
  //Store the requested time and set the interrupt request flag.
  rtimer_next.u32 = time;
  rtimer_req = true;

  //If the requested time comes before the next periodic interrupt, schedule it instead.
  if (LPTMR_LT(rtimer_next, clock_next))
    LPTMR0->CMR = rtimer_next.u16_l - 1;
}

//Interrupt handler for LPTMR peripheral.
void lptmr_0_handler() {
  uint16_t cnr;
  bool rtimer_match;
  bool clock_match;

  //Read the current counter value and clear the interrupt flag.
  LPTMR0->CNR = 0;    //Latch the value before read
  cnr = LPTMR0->CNR;
  LPTMR0->CSR |= LPTMR_CSR_TCF_Set;

  //Check wether the timer overflowed by checking if the current count is less than the last count.
  //If an overflow is detected increase the high word.
  if (cnr < lptmr_count.u16_l)
    lptmr_count.u16_h++;

  //Update the lower word after the upper word is updated.
  lptmr_count.u16_l = cnr;

  //Set the rtimer and clock count match flags when their next values match the current LPTMR value.
  rtimer_match = lptmr_count.u32 == rtimer_next.u32;
  clock_match = lptmr_count.u32 == clock_next.u32;

  //TODO: Testing only. Remove.
  if (!rtimer_match && !clock_match)
    for (;;);

  //If a clock count match occurs, advance its value for the next interrupt.
  if (clock_match)
    clock_next.u32 += CLOCK_SECOND_COUNT;

  //Schedule the next interrupt before calling any callback functions. This allows to compensate for
  //potential code latency, specially if the next interrupt comes right after this one.
  if (!rtimer_match && rtimer_req && LPTMR_LT(rtimer_next, clock_next))
    //Schedule the next rtimer interrupt only if there isn't a count match (if there's a match then
    //there's no need to schedule it as it'll be attended on this ISR run) and the interrupt is
    //requested and it comes before the next periodic interrupt.
      LPTMR0->CMR = rtimer_next.u16_l - 1;
  else
    //If there's no need to schedule the rtimer interrupt, schedule the periodic interrupt instead.
    LPTMR0->CMR = clock_next.u16_l - 1;

  //Check wether an rtimer interrupt was requested and there is an rtimer count match.
  if (rtimer_req && rtimer_match) {
    //Clear the interrupt request flag and call the rtimer architecture callback function.
    rtimer_req = false;
    rtimer_arch_callback();

    //Schedule the next rtimer interrupt if it was requested during the callback and comes before
    //the next periodic interrupt.
    if (rtimer_req && LPTMR_LT(rtimer_next, clock_next))
      LPTMR0->CMR = rtimer_next.u16_l - 1;
  }

  //Call the clock callback function if there is a clock count match.
  if (clock_match)
    clock_callback();
}
