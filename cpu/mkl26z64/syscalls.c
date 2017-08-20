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

#include "uart.h"

//Heap start and end locations exposed by the linker script.
extern char __heap_start__;
extern char __heap_end__;

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

//Implementation of th write system call. This is used by printf to send data to the standard
//output, whose content is then sent out through UART.
int _write(int file, char *ptr, int len) {
  uint32_t i;

  //Only send output for the standard output and standard error file descriptors.
  if (file == STDOUT_FILENO || file == STDERR_FILENO) {
    for (i = 0; i < len; i++)
      uart_tx(UART0, *ptr++);
    return len;
  }
  else {
    //If writing to any other file (which is unimplemented), return -1 and set errno to EBADF (bad
    //file descriptor).
    errno = EBADF;
    return -1;
  }
}
