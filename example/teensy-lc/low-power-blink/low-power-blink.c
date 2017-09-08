//+------------------------------------------------------------------------------------------------+
//| Source code for the low power LED blink example.                                               |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "gpio.h"

PROCESS(low_power_blink, "Low power blink process");

AUTOSTART_PROCESSES(&low_power_blink);

PROCESS_THREAD(low_power_blink, ev, data) {
  static struct etimer et;

  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  GPIO_PIN_MODE_OUTPUT(13);   //Use pin as output

  for (;;) {
    //Turn on the LED.
    GPIO_PIN_SET(13);

    //Set the event timer to 1/10th of a second, then wait for the timer to expire.
    etimer_set(&et, CLOCK_SECOND / 10);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

    //Turn off the LED.
    GPIO_PIN_CLEAR(13);

    //Set the event timer to 4 seconds, then wait for the timer to expire.
    etimer_set(&et, CLOCK_SECOND * 4);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
  }

  PROCESS_END();
}
