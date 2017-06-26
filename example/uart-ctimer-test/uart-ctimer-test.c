//+------------------------------------------------------------------------------------------------+
//| Source code for the UART and ctimer test example.                                              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdio.h>

#include "contiki.h"

static struct ctimer timer;

PROCESS(uart_ctimer_test, "UART and ctimer test");

AUTOSTART_PROCESSES(&uart_ctimer_test);

static void callback_function(void *ptr) {
  //The callback function prints the current time and resets the ctimer every second.
  printf("Seconds: %lu\n", clock_seconds());
  ctimer_reset(&timer);
}

PROCESS_THREAD(uart_ctimer_test, ev, data) {
  PROCESS_BEGIN();

  //This process just starts the callback timer and lets it go on its own.
  ctimer_set(&timer, CLOCK_SECOND, callback_function, NULL);

  PROCESS_END();
}
