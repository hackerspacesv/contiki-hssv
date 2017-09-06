//+------------------------------------------------------------------------------------------------+
//| Source code for the rtimer blink example.                                                      |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "mkl26-port.h"
#include "mkl26-gpio.h"

PROCESS(rtimer_blink, "Rtimer blink");

AUTOSTART_PROCESSES(&rtimer_blink);

static struct rtimer timer;

static void callback(struct rtimer *t, void *ptr) {
  //Toggle the LED pin.
  GPIOC->PTOR = 1 << 5;

  //Reset the timer to the next second ahead.
  rtimer_set(&timer, RTIMER_TIME(&timer) + RTIMER_SECOND, 1, callback, NULL);
}

PROCESS_THREAD(rtimer_blink, ev, data) {
  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  PORTC->PCR[5] = PORT_PCR_MUX_Gpio;  //Use pin as GPIO
  GPIOC->PDDR |= 1 << 5;              //Set pin to output
  GPIOC->PSOR = 1 << 5;               //Set pin state to logic high

  //Set the rtimer to 1 second ahead.
  rtimer_set(&timer, RTIMER_NOW() + RTIMER_SECOND, 1, callback, NULL);

  //Once the timer is activated the callback will restart it automatically. Yield the process.
  for (;;) {
    PROCESS_YIELD();
  }

  PROCESS_END();
}
