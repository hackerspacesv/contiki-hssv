//+------------------------------------------------------------------------------------------------+
//| Project configuration header for the UART and ctimer test example.                             |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

//Enable STDOUT through UART for any of the supported targets (use default configuration).

#if CONTIKI_TARGET_TEENSY_LC
#define TEENSY_LC_CONF_STDOUT_UART_ENABLED 1
#endif

#if CONTIKI_TARGET_TEENSY_32
#define TEENSY_32_CONF_STDOUT_UART_ENABLED 1
#endif

#if CONTIKI_TARGET_TEENSY_36
#define TEENSY_36_CONF_STDOUT_UART_ENABLED 1
#endif

#endif //PROJECT_CONF_H_
