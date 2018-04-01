//+------------------------------------------------------------------------------------------------+
//| RTC peripheral driver for ATSAMD21G18A MCU.                                                    |
//|                                                                                                |
//| This driver provides hardware interrupt services for Contiki's clock and rtimer libraries.     |
//|                                                                                                |
//| The RTC (real time clock) can wake the CPU from standby mode. It's 32KHz clock is provided by  |
//| the very flexible generic clock controller which in turn uses the 32KHz external oscillator    |
//| (XOSC32K) output. Since XOSC32K operates with a low frequency crystal, it has a very low power |
//| requirement, making it ideal for low power profiles while fulfilling the requirements of clock |
//| and rtimer libraries from Contiki.                                                             |
//|                                                                                                |
//| The RTC provides a 32 bit counter mode whose value can be continuously compared against a      |
//| compare value, which can generate an interrupt (and wake the system) on match. This allows     |
//| scheduling interrupts at arbritrary times, which is implemented for the rtimer library.        |
//|                                                                                                |
//| This 32 bit counter width provides great flexibility for rtimer interrupts, allowing for a     |
//| maximum period equal to half of its count capacity (because of signed compares) which is equal |
//| to 65,536 seconds (over 18 hours).                                                             |
//|                                                                                                |
//| The periodic event feature of the RTC is employed to generate event interrupts by dividing the |
//| 32,768Hz input clock by 256, providing a 128Hz time base for Contiki's clock library. Since    |
//| the event system is required for this to work, the EVSYS peripheral driver needs to be         |
//| initialized before this driver. The rtc_event_callback function is called by the EVSYS driver  |
//| to pass the events to this driver, which in turns passes them to the clock_callback function.  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki-conf.h"

#include "samd21.h"

#include "rtc.h"

//External callback functions called by this module.
extern void clock_callback();
extern void rtimer_arch_callback();

//This function initializes the RTC module.
void rtc_init() {
  //Initialize the RTC peripheral.
  //------------------------------

  //Set the RTC generic clock to use the generic clock generator 1.
  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_ID_RTC | GCLK_CLKCTRL_GEN_GCLK1;

  //Restart the RTC to make sure it's in a known state.
  RTC->MODE0.CTRL.bit.SWRST = 1;
  while (RTC->MODE0.CTRL.bit.SWRST);

  //Enable event generation for the periodic event 5, which causes an event every 256 cycles.
  RTC->MODE0.EVCTRL.reg = RTC_MODE0_EVCTRL_PEREO5;

  //Enable the RTC in 32 bit counter mode, don't clear on mach, set a prescale factor of 2.
  RTC->MODE0.CTRL.reg = RTC_MODE0_CTRL_PRESCALER_DIV2 | RTC_MODE0_CTRL_MODE_COUNT32 |
                        RTC_MODE0_CTRL_ENABLE;

  //Note: A prescale factor of 2 is used so that the RTC prescaler is enabled and generates
  //periodic events (any prescaler value other than 1 enables it).

  //Configure the interrupt in the NVIC.
  //------------------------------------
  NVIC_SetPriority(RTC_IRQn, 2);                      //Set a middle priority level
  NVIC_EnableIRQ(RTC_IRQn);                           //Enable the interrupt
}

//This function returns the current RTC counter value.
rtimer_clock_t rtc_get_count() {
  //Perform a read request on the COUNT register.
  RTC->MODE0.READREQ.reg = RTC_READREQ_RREQ | RTC_READREQ_ADDR(RTC_MODE0_COUNT_OFFSET);
  while (RTC->MODE0.STATUS.bit.SYNCBUSY);

  //Read and return the value.
  return RTC->MODE0.COUNT.reg;
}

//This function schedules an interrupt at the specified RTC count value. When the interrupt occurs
//the rtimer callback function is called.
void rtc_rtimer_schedule(rtimer_clock_t time) {
  while (RTC->MODE0.STATUS.bit.SYNCBUSY);             //Wait for potential synchronization
  RTC->MODE0.COMP[0].reg = time;                      //Set the compare value to the requested time
  RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_CMP0;    //Clear the compare 0 interrupt flag
  RTC->MODE0.INTENSET.reg = RTC_MODE0_INTENSET_CMP0;  //Enable the compare 0 interrupt
}

//This RTC event callback function calls the clock library callback function to process ticks.
void rtc_event_callback() {
  clock_callback();
}

//Interrupt handler for RTC peripheral.
void rtc_handler() {
  //clear the interrupt flag and disable the interrupt.
  RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_CMP0;
  RTC->MODE0.INTENCLR.reg = RTC_MODE0_INTENSET_CMP0;

  //Call the rtimer architecture callback function.
  rtimer_arch_callback();
}
