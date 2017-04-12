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
#include "mk20-gpio.h"
#include "uart.h"

void main() {
  volatile uint32_t i;

  //Configure the port multiplexing to use the UART0 alternate function on pins PTB16 and PTB17,
  //then initialize the UART0 peripheral (used for standard output).
  PORTB->PCR[16] = PORT_PCR_DSE_High | PORT_PCR_MUX_Alt3;   //Use PTB16 as RX
  PORTB->PCR[17] = PORT_PCR_DSE_High | PORT_PCR_MUX_Alt3;   //Use PTB17 as TX
  uart_init(UART0);

  //Print the operating system version.
  PRINTF("Starting %s\n", CONTIKI_VERSION_STRING);

  //This is just an simple test to check that the toolchain is correctly generating code and the
  //microcontroller operates correctly.
  PORTC->PCR[5] = PORT_PCR_MUX_Gpio;
  GPIOC->PDDR |= 1 << 5;
  GPIOC->PSOR = 1 << 5;

  //Blink the LED to confirm that the system is running properly.
  for (;;) {
    GPIOC->PSOR = 1 << 5;
    for (i = 0; i < 1000000; i++);
    GPIOC->PCOR = 1 << 5;
    for (i = 0; i < 1000000; i++);
  }  
}
