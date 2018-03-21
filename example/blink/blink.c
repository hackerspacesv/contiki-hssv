//+------------------------------------------------------------------------------------------------+
//| Source code for the LED blink example.                                                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "gpio.h"

PROCESS(blink, "Blink process");

AUTOSTART_PROCESSES(&blink);

PROCESS_THREAD(blink, ev, data) {
  static struct etimer et;

  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  GPIO_PIN_MODE_OUTPUT(BOARD_PIN_LED);  //Use pin as output
  GPIO_PIN_SET(BOARD_PIN_LED);          //Set pin state to logic high

  //Set the event timer to 1 second.
  etimer_set(&et, CLOCK_SECOND);

  for (;;) {
    //Wait for the timer to expire and then restart it.
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    etimer_reset(&et);
    //Toggle the LED pin.
    GPIO_PIN_TOGGLE(BOARD_PIN_LED);
  }

  PROCESS_END();
}
