//+------------------------------------------------------------------------------------------------+
//| Teensy LC platform initialization code.                                                        |
//|                                                                                                |
//| This file implements the main function. It first initializes all contiki services and then     |
//| proceeds to run them.                                                                          |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#define DEBUG 1
#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "contiki.h"

#include "mkl26.h"
#include "gpio.h"
#include "lptmr.h"

#include "syscalls.h"

void main() {
  //Set pin 17/A3 as a low level output, so the 74LV1T125 doesn't consume too much power with a
  //floating input.
  GPIO_PIN_MODE_OUTPUT(BOARD_PIN_17);
  GPIO_PIN_CLEAR(BOARD_PIN_17);

  //Initialize the LPTMR peripheral driver, which provides support for clock and rtimer libraries.
  lptmr_init();

  //Initialize clock and rtimer libraries.
  clock_init();
  rtimer_init();

  //Initialize the syscalls submodule, which implements the standard output.
  syscalls_init();

  //Print the operating system version.
  PRINTF("Starting %s\n", CONTIKI_VERSION_STRING);

  //Initialize system processes.
  process_init();
  process_start(&etimer_process, NULL);
  ctimer_init();

  //Automatically start user processes.
  autostart_start(autostart_processes);

  //Run the system.
  for (;;) {
    int n;
    do {
      //watchdog_periodic();  //TODO: Implement watchdog timer library.
      n = process_run();
    } while (n > 0);

    //Enter low power state when there are no more processes to run.
    //Note: Power down state depends on device configuration.
    __WFI();
  }
}
