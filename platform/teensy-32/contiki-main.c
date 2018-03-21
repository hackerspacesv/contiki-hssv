//+------------------------------------------------------------------------------------------------+
//| Teensy 3.2 platform initialization code.                                                       |
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

#include "syscalls.h"

void main() {
  //Initialize the clock library, including timers.
  clock_init();

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

    //TODO: Call sleep function here. Keep power consumption low.
  }
}
