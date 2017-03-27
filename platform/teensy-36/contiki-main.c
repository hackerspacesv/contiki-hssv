//+------------------------------------------------------------------------------------------------+
//| Teensy 3.6 platform initialization code.                                                       |
//|                                                                                                |
//| This file implements the main function. It first initializes all contiki services and then     |
//| proceeds to run them.                                                                          |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "contiki.h"

#include "mk66-port.h"
#include "mk66-gpio.h"

void main() {
  volatile uint32_t i;

  //This is just an simple test to check that the toolchain is correctly generating code and the
  //microcontroller operates correctly.
  PORTC->PCR[5] = PORT_PCR_MUX_Gpio;
  GPIOC->PDDR |= 1 << 5;
  GPIOC->PSOR = 1 << 5;

  //Blink the LED to confirm that the system is running properly.
  for (;;) {
    GPIOC->PSOR = 1 << 5;
    for (i = 0; i < 2000000; i++);
    GPIOC->PCOR = 1 << 5;
    for (i = 0; i < 2000000; i++);
  }

/*
  process_init();

  for (;;) {
    process_run();
  }
*/
}
