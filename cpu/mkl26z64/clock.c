//+------------------------------------------------------------------------------------------------+
//| Platform implementation for contiki's clock library.                                           |
//|                                                                                                |
//| See the header in contiki/core/sys/clock.h for details on the exposed interface.               |
//| Note: Deprecated functions aren't implemented.                                                 |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "clock.h"
#include "etimer.h"

#include "mkl26.h"
#include "mkl26-sim.h"
#include "mkl26-pit.h"

//Variables used for tracking system time.
static volatile clock_time_t tick_count = 0;      //Amount of PIT overflow ticks elapsed since boot
static volatile unsigned long seconds_count = 0;  //Amount of seconds elapsed since boot
static volatile uint16_t subseconds_count = 0;    //PIT overflow ticks elapsed since last second

#define BUS_CLK 24000000

void clock_init(void) {
  //Initialize the PIT0 timer.
  SIM->SCGC6 |= SIM_SCGC6_PIT_Enabled;                          //Enable the module clock
  PIT->LDVAL0 = (BUS_CLK / CLOCK_SECOND) - 1;                   //Set the period
  PIT->TCTRL0 = PIT_TCTRL_TEN_Enabled | PIT_TCTRL_TIE_Enabled;  //Enable PIT0 and its interrupt
  PIT->MCR = PIT_MCR_MDIS_Enabled | PIT_MCR_FRZ_DbgStop;        //Enable the PIT

  //Configure the interrupt in the NVIC.
  NVIC_SetPriority(PIT_IRQn, 2);  //Set a middle priority level
  NVIC_EnableIRQ(PIT_IRQn);       //Enable the interrupt
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
  const uint32_t cycles_per_us = BUS_CLK / 1000000;
  uint32_t total_cycles;
  uint32_t elapsed_cycles = 0;
  uint32_t curr_cycle_count, last_cycle_count;

  //Capture the starting value of the PIT counter.
  curr_cycle_count = PIT->CVAL0;

  //Calculate how many PIT cycles to track.
  total_cycles = ((uint32_t) dt) * cycles_per_us;

  //Repeat until all expected cycles have elapsed.
  while (elapsed_cycles < total_cycles) {
    //Refresh the cycle counts.
    last_cycle_count = curr_cycle_count;
    curr_cycle_count = PIT->CVAL0;

    //The PIT timer counts downwards. Calculate the elapsed time since last read.
    elapsed_cycles += last_cycle_count - curr_cycle_count;

    //Adjust in the case of PIT overflow.
    if (curr_cycle_count > last_cycle_count)
      elapsed_cycles += PIT->LDVAL0 + 1;
  }
}

void pit_handler() {
  //Clear the interrupt flag.
  PIT->TFLG0 |= PIT_TFLG_TIF_Set;

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
