//+------------------------------------------------------------------------------------------------+
//| Platform configuration file for Teensy LC.                                                     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef PLATFORM_CONF_H_
#define PLATFORM_CONF_H_

//Include the cpu configuration header.
#include "cpu-conf.h"

//Configurations for standard output through UART.
//------------------------------------------------
#ifndef TEENSY_LC_CONF_STDOUT_UART_ENABLED
#define TEENSY_LC_CONF_STDOUT_UART_ENABLED 0
#endif //TEENSY_LC_CONF_STDOUT_UART_ENABLED

#ifndef TEENSY_LC_CONF_STDOUT_UART_INSTANCE
#define TEENSY_LC_CONF_STDOUT_UART_INSTANCE 0
#endif //TEENSY_LC_CONF_STDOUT_UART_INSTANCE

#ifndef TEENSY_LC_CONF_STDOUT_UART_RX_PIN
#define TEENSY_LC_CONF_STDOUT_UART_RX_PIN BOARD_PIN_0
#endif //TEENSY_LC_CONF_STDOUT_UART_RX_PIN

#ifndef TEENSY_LC_CONF_STDOUT_UART_TX_PIN
#define TEENSY_LC_CONF_STDOUT_UART_TX_PIN BOARD_PIN_1
#endif //TEENSY_LC_CONF_STDOUT_UART_TX_PIN

#endif //PLATFORM_CONF_H_
