//+------------------------------------------------------------------------------------------------+
//| Sparkfun SAMD21G Mini Breakout platform initialization code.                                   |
//|                                                                                                |
//| This file implements the main function. It first initializes all contiki services and then     |
//| proceeds to run them.                                                                          |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "samd21.h"
#include "evsys.h"
#include "rtc.h"

int main() {
  //Initialize the EVSYS peripheral driver, which provides support for the RTC peripheral driver.
  evsys_init();

  //Initialize the RTC peripheral driver, which provides support for clock and rtimer libraries.
  rtc_init();

  //Initialize clock and rtimer libraries.
  clock_init();
  rtimer_init();

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
