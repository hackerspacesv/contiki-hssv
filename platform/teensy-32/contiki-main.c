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

#include "mk20-port.h"
#include "uart.h"

void main() {
  //Initialize the clock library, including timers.
  clock_init();

  //Configure the port multiplexing to use the UART0 alternate function on pins PTB16 and PTB17,
  //then initialize the UART0 peripheral (used for standard output).
  PORTB->PCR[16] = PORT_PCR_DSE_High | PORT_PCR_MUX_Alt3;   //Use PTB16 as RX
  PORTB->PCR[17] = PORT_PCR_DSE_High | PORT_PCR_MUX_Alt3;   //Use PTB17 as TX
  uart_init(UART0);

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
