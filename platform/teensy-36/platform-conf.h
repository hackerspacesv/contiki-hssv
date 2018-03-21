//+------------------------------------------------------------------------------------------------+
//| Platform configuration file for Teensy 3.6.                                                    |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef PLATFORM_CONF_H_
#define PLATFORM_CONF_H_

//Configurations for standard output through UART.
//------------------------------------------------
#ifndef TEENSY_36_CONF_STDOUT_UART_ENABLED
#define TEENSY_36_CONF_STDOUT_UART_ENABLED 0
#endif //TEENSY_36_CONF_STDOUT_UART_ENABLED

#ifndef TEENSY_36_CONF_STDOUT_UART_INSTANCE
#define TEENSY_36_CONF_STDOUT_UART_INSTANCE 0
#endif //TEENSY_36_CONF_STDOUT_UART_INSTANCE

#ifndef TEENSY_36_CONF_STDOUT_UART_RX_PIN
#define TEENSY_36_CONF_STDOUT_UART_RX_PIN BOARD_PIN_0
#endif //TEENSY_36_CONF_STDOUT_UART_RX_PIN

#ifndef TEENSY_36_CONF_STDOUT_UART_TX_PIN
#define TEENSY_36_CONF_STDOUT_UART_TX_PIN BOARD_PIN_1
#endif //TEENSY_36_CONF_STDOUT_UART_TX_PIN

#endif //PLATFORM_CONF_H_
