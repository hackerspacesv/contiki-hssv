//+------------------------------------------------------------------------------------------------+
//| Source code for the rtimer blink example.                                                      |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "gpio.h"

PROCESS(rtimer_blink, "Rtimer blink");

AUTOSTART_PROCESSES(&rtimer_blink);

static struct rtimer timer;

static void callback(struct rtimer *t, void *ptr) {
  //Toggle the LED pin.
  GPIO_PIN_TOGGLE(BOARD_PIN_LED);

  //Reset the timer to the next second ahead.
  rtimer_set(&timer, RTIMER_TIME(&timer) + RTIMER_SECOND, 1, callback, NULL);
}

PROCESS_THREAD(rtimer_blink, ev, data) {
  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  GPIO_PIN_MODE_OUTPUT(BOARD_PIN_LED);  //Use pin as output
  GPIO_PIN_SET(BOARD_PIN_LED);          //Set pin state to logic high

  //Set the rtimer to 1 second ahead.
  rtimer_set(&timer, RTIMER_NOW() + RTIMER_SECOND, 1, callback, NULL);

  //Once the timer is activated the callback will restart it automatically. Yield the process.
  for (;;) {
    PROCESS_YIELD();
  }

  PROCESS_END();
}
