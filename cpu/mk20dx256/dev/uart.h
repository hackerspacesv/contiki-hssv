//+------------------------------------------------------------------------------------------------+
//| UART peripheral driver for Kinetis MK20 MCU.                                                   |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef UART_H_
#define UART_H_

#include "mk20-uart.h"

void uart_init(volatile struct UART_type *UART);
void uart_tx(volatile struct UART_type *UART, uint8_t c);

#endif //UART_H_
