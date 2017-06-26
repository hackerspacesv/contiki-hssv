//+------------------------------------------------------------------------------------------------+
//| Source code for the LED blink example.                                                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdint.h>

#include "contiki.h"

#include "mkl26-port.h"
#include "mkl26-gpio.h"

PROCESS(blink, "Blink process");

AUTOSTART_PROCESSES(&blink);

PROCESS_THREAD(blink, ev, data) {
  static volatile uint32_t i;
  PROCESS_BEGIN();

  //Configure the GPIO pin connected to the on-board LED.
  PORTC->PCR[5] = PORT_PCR_MUX_Gpio;  //Use pin as GPIO
  GPIOC->PDDR |= 1 << 5;              //Set pin to output
  GPIOC->PSOR = 1 << 5;               //Set pin state to logic high

  //For the moment this process takes all CPU time. Later we'll switch to etimer once it's ready.
  for (;;) {
    //Wait for about a quarter second
    for (i = 0; i < 2000000; i++);
    //Toggle the LED pin.
    GPIOC->PTOR = 1 << 5;
  }

  PROCESS_END();
}
