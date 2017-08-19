//+------------------------------------------------------------------------------------------------+
//| Platform implementation for contiki's clock library.                                           |
//|                                                                                                |
//| This module depends on the LPTMR peripheral driver, which calls the clock_callback function.   |
//| See the header in contiki/core/sys/clock.h for details on the exposed interface.               |
//| Note: Deprecated functions aren't implemented.                                                 |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "clock.h"
#include "etimer.h"

#include "mkl26.h"

//Variables used for tracking system time.
static volatile clock_time_t tick_count = 0;      //Amount of clock ticks elapsed since boot
static volatile unsigned long seconds_count = 0;  //Amount of seconds elapsed since boot
static volatile uint16_t subseconds_count = 0;    //Amount of clock ticks elapsed since last second

void clock_init(void) {
  //This function does nothing. This module depends on the LPTMR driver to be initialized.
}

CCIF clock_time_t clock_time(void) {
  //Simply return the current tick count.
  return tick_count;
}

CCIF unsigned long clock_seconds(void) {
  //Return the current seconds count.
  return seconds_count;
}

void clock_set_seconds(unsigned long sec) {
  //Store the new seconds count
  subseconds_count = 0;
  seconds_count = sec;
}

void clock_wait(clock_time_t t) {
  clock_time_t start;

  start = tick_count;
  while (tick_count - start < t) {
    //watchdog_periodic();  //TODO: Implement watchdog timer library.
    //TODO: Cause the CPU to sleep when performing this delay.
  }
}

//This is a minimalistic implementation of the clock_delay_usec function. It is by no means precise,
//(doesn't take into account code execution delays) but at least guarantees that the delayed time
//isn't shorter than requested.
void clock_delay_usec(uint16_t dt) {
#if F_CPU % 1000000 != 0
  #warning "CPU clock period isn't an exact submultiple of 1us, clock_delay_usec() is not accurate"
#endif
  const uint32_t cycles_per_us = F_CPU / 1000000;

  //Prepare the systick timer for a single run for the requested time. Note that the time is 16 bits
  //long, while the counter is 24 bits long. This means that cycles_per_us can be 256 at most.
  SysTick->LOAD = ((uint32_t) dt) * cycles_per_us;                        //Set total cycles
  SysTick->VAL = 0;                                                       //Clear initial count
  SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;   //Enable timer, use F_CPU

  //Wait for the timer to expire.
  while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);

  //Disable the timer.
  SysTick->CTRL = 0;
}

//This callback function is automatically called by the LPTMR driver.
void clock_callback() {
  //Increase the time count.
  tick_count++;
  subseconds_count++;
  if (subseconds_count == CLOCK_SECOND) {
    seconds_count++;
    subseconds_count = 0;
  }

  //Poll the etimer process if there are pending event timers.
  if (etimer_pending()) {
    etimer_request_poll();
  }
}
