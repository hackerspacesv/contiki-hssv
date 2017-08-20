//+------------------------------------------------------------------------------------------------+
//| UART peripheral driver for Kinetis MKL26 MCU.                                                  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef UART_H_
#define UART_H_

#include "mkl26-uart0.h"

void uart_init(volatile struct UART0_type *UART);
void uart_tx(volatile struct UART0_type *UART, uint8_t c);

#endif //UART_H_
