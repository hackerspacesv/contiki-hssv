//+------------------------------------------------------------------------------------------------+
//| Source code for the LED blink example.                                                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "mk20-port.h"
#include "mk20-gpio.h"

PROCESS(blink, "Blink process");

AUTOSTART_PROCESSES(&blink);

PROCESS_THREAD(blink, ev, data) {
  static struct etimer et;

  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  PORTC->PCR[5] = PORT_PCR_MUX_Gpio;  //Use pin as GPIO
  GPIOC->PDDR |= 1 << 5;              //Set pin to output
  GPIOC->PSOR = 1 << 5;               //Set pin state to logic high

  //Set the event timer to 1 second.
  etimer_set(&et, CLOCK_SECOND);

  for (;;) {
    //Wait for the timer to expire and then restart it.
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    etimer_reset(&et);
    //Toggle the LED pin.
    GPIOC->PTOR = 1 << 5;
  }

  PROCESS_END();
}
