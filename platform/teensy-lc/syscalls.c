//+------------------------------------------------------------------------------------------------+
//| System calls implementation for Newlib C library.                                              |
//|                                                                                                |
//| This file implements some of the system calls required for minimal C library operation.        |
//|                                                                                                |
//| By using '-specs=nosys.specs' in the linker arguments, we get several stub implementations for |
//| all the unimplemented syscalls, which reduces our source code.                                 |
//|                                                                                                |
//| More information on those implementations can be found here:                                   |
//| https://sourceware.org/newlib/libc.html#Syscalls                                               |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>

#include "contiki-conf.h"
#include "sys/cc.h"

#include "gpio.h"
#include "uart.h"

#include "syscalls.h"

//Module configurations.
//----------------------
#ifdef TEENSY_LC_CONF_STDOUT_UART_ENABLED
#define STDOUT_UART_ENABLED TEENSY_LC_CONF_STDOUT_UART_ENABLED
#else
#define STDOUT_UART_ENABLED 0
#endif //TEENSY_LC_CONF_STDOUT_UART_ENABLED

#ifdef TEENSY_LC_CONF_STDOUT_UART_INSTANCE
#define STDOUT_UART_INSTANCE CC_CONCAT_EXT_2(UART, TEENSY_LC_CONF_STDOUT_UART_INSTANCE)
#define STDOUT_UART_RX_ALT   CC_CONCAT_EXT_3(UART, TEENSY_LC_CONF_STDOUT_UART_INSTANCE, _RX)
#define STDOUT_UART_TX_ALT   CC_CONCAT_EXT_3(UART, TEENSY_LC_CONF_STDOUT_UART_INSTANCE, _TX)
#else
#define STDOUT_UART_INSTANCE UART0
#define STDOUT_UART_RX_ALT   UART0_RX
#define STDOUT_UART_TX_ALT   UART0_TX
#endif //TEENSY_LC_CONF_STDOUT_UART_INSTANCE

#ifdef TEENSY_LC_CONF_STDOUT_UART_RX_PIN
#define STDOUT_UART_RX_PIN TEENSY_LC_CONF_STDOUT_UART_RX_PIN
#else
#define STDOUT_UART_RX_PIN BOARD_PIN_0
#endif //TEENSY_LC_CONF_STDOUT_UART_RX_PIN

#ifdef TEENSY_LC_CONF_STDOUT_UART_TX_PIN
#define STDOUT_UART_TX_PIN TEENSY_LC_CONF_STDOUT_UART_TX_PIN
#else
#define STDOUT_UART_TX_PIN BOARD_PIN_1
#endif //TEENSY_LC_CONF_STDOUT_UART_TX_PIN

//Heap start and end locations exposed by the linker script.
extern char __heap_start__;
extern char __heap_end__;

//Initialization function for this module.
void syscalls_init() {
  //Configure the port multiplexing and UART peripheral instance for use by STDOUT if enabled.
#if STDOUT_UART_ENABLED
  GPIO_PIN_MODE_ALT(STDOUT_UART_RX_PIN, STDOUT_UART_RX_ALT);
  GPIO_PIN_MODE_ALT(STDOUT_UART_TX_PIN, STDOUT_UART_TX_ALT);
  uart_init(STDOUT_UART_INSTANCE);
#endif //STDOUT_UART_ENABLED
}

//Implementation of the sbrk system call function. This function moves the program break (which
//marks the end of the program data space) by the increment value. Malloc depends on this function
//to see wether there is free memory and where it is located. This implementation simply advances
//a data pointer inside the heap section while checking that this space is not depleted.
caddr_t _sbrk(int incr) {
  static char *curr_heap_end = &__heap_start__;
  char *prev_heap_end;

  prev_heap_end = curr_heap_end;

  if (curr_heap_end + incr > &__heap_end__) {
    //If the increment would exceed the available heap space, return -1 as a pointer and set errno
    //to ENOMEM (not enough memory).
    return (caddr_t) -1;
    errno = ENOMEM;
  }

  //If there's space available increase the data pointer and return its previous value.
  curr_heap_end += incr;
  return (caddr_t) prev_heap_end;
}

//Implementation of the write system call. This is used by printf to send data to the standard
//output, whose content is then sent out through UART.
int _write(int file, char *ptr, int len) {
  uint32_t i;

  //Only send output for the standard output and standard error file descriptors.
  if (file == STDOUT_FILENO || file == STDERR_FILENO) {
#if STDOUT_UART_ENABLED
    for (i = 0; i < len; i++)
      uart_tx(STDOUT_UART_INSTANCE, *ptr++);
#endif //STDOUT_UART_ENABLED
    return len;
  }
  else {
    //If writing to any other file (which is unimplemented), return -1 and set errno to EBADF (bad
    //file descriptor).
    errno = EBADF;
    return -1;
  }
}
