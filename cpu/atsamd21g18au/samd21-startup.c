//+------------------------------------------------------------------------------------------------+
//| ATSAMD21G18AU microcontroller initialization code.                                             |
//|                                                                                                |
//| This file implements very basic microcontroller code infrastructure such as the vector table,  |
//| processor and peripheral initialization and memory initialization.                             |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdint.h>

#include "samd21.h"

//Interrupt vector handler function type.
typedef void (* handler_t)();

//Symbols exported by the linker script.
extern uint32_t __stack_end__;
extern const uint32_t __relocate_flash_start__;
extern uint32_t __relocate_sram_start__;
extern uint32_t __relocate_sram_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

//External functions invoked by startup code.
extern void main();

//--------------------------------------------------------------------------------------------------

//Startup routine, located at reset vector.
void startup() {
  const uint32_t *flash;
  uint32_t *sram;

  //Memory initialization.
  //------------------------------------------------------------------------------------------------

  //Copy the initial data for the data section from FLASH to RAM.
  flash = &__relocate_flash_start__;
  sram = &__relocate_sram_start__;
  while (sram < &__relocate_sram_end__)
    *sram++ = *flash++;

  //Initialize the .bss section to zeroes.
  sram = &__bss_start__;
  while (sram < &__bss_end__)
    *sram++ = 0;

  //System is up. Call the main function.
  main();
}

//Default interrupt handler.
static void unused_handler() {
  //The default unused handler does nothing, just stalls the CPU.
  for (;;);
}

//--------------------------------------------------------------------------------------------------

//Weak references for core system handler vectors.
void __attribute__((weak, alias("unused_handler"))) nmi_handler();
void __attribute__((weak, alias("unused_handler"))) hard_fault_handler();
void __attribute__((weak, alias("unused_handler"))) svcall_handler();
void __attribute__((weak, alias("unused_handler"))) pendablesrvreq_handler();
void __attribute__((weak, alias("unused_handler"))) systick_handler();

//Weak references for non-core (peripheral) vectors.
void __attribute__((weak, alias("unused_handler"))) pm_handler();
void __attribute__((weak, alias("unused_handler"))) sysctrl_handler();
void __attribute__((weak, alias("unused_handler"))) wdt_handler();
void __attribute__((weak, alias("unused_handler"))) rtc_handler();
void __attribute__((weak, alias("unused_handler"))) eic_handler();
void __attribute__((weak, alias("unused_handler"))) nvmctrl_handler();
void __attribute__((weak, alias("unused_handler"))) dmac_handler();
void __attribute__((weak, alias("unused_handler"))) usb_handler();
void __attribute__((weak, alias("unused_handler"))) evsys_handler();
void __attribute__((weak, alias("unused_handler"))) sercom0_handler();
void __attribute__((weak, alias("unused_handler"))) sercom1_handler();
void __attribute__((weak, alias("unused_handler"))) sercom2_handler();
void __attribute__((weak, alias("unused_handler"))) sercom3_handler();
void __attribute__((weak, alias("unused_handler"))) sercom4_handler();
void __attribute__((weak, alias("unused_handler"))) sercom5_handler();
void __attribute__((weak, alias("unused_handler"))) tcc0_handler();
void __attribute__((weak, alias("unused_handler"))) tcc1_handler();
void __attribute__((weak, alias("unused_handler"))) tcc2_handler();
void __attribute__((weak, alias("unused_handler"))) tc3_handler();
void __attribute__((weak, alias("unused_handler"))) tc4_handler();
void __attribute__((weak, alias("unused_handler"))) tc5_handler();
void __attribute__((weak, alias("unused_handler"))) tc6_handler();
void __attribute__((weak, alias("unused_handler"))) tc7_handler();
void __attribute__((weak, alias("unused_handler"))) adc_handler();
void __attribute__((weak, alias("unused_handler"))) ac_handler();
void __attribute__((weak, alias("unused_handler"))) dac_handler();
void __attribute__((weak, alias("unused_handler"))) ptc_handler();
void __attribute__((weak, alias("unused_handler"))) i2s_handler();

//--------------------------------------------------------------------------------------------------

//Processor vector table.
static __attribute__ ((section(".vectors"), used))
handler_t const vectors[44] = {
  //Core system handler vectors.
  (handler_t) &__stack_end__,   //0 - Initial stack pointer
  startup,                      //1 - Initial program counter
  nmi_handler,                  //2 - Non maskable interrupt
  hard_fault_handler,           //3 - Hard fault
  unused_handler,               //4
  unused_handler,               //5
  unused_handler,               //6
  unused_handler,               //7
  unused_handler,               //8
  unused_handler,               //9
  unused_handler,               //10
  svcall_handler,               //11 - Supervisor call
  unused_handler,               //12
  unused_handler,               //13
  pendablesrvreq_handler,       //14 - Pendable request for system service
  systick_handler,              //15 - System tick timer

  //Non-core vectors.
  pm_handler,                   //16 - Power manager
  sysctrl_handler,              //17 - System control
  wdt_handler,                  //18 - Watchdog timer
  rtc_handler,                  //19 - Real time counter
  eic_handler,                  //20 - External interrupt controller
  nvmctrl_handler,              //21 - Non-volatile memory controller
  dmac_handler,                 //22 - Direct memory access controller
  usb_handler,                  //23 - Universal serial bus
  evsys_handler,                //24 - Event system
  sercom0_handler,              //25 - Serial communication interface 0
  sercom1_handler,              //26 - Serial communication interface 1
  sercom2_handler,              //27 - Serial communication interface 2
  sercom3_handler,              //28 - Serial communication interface 3
  sercom4_handler,              //29 - Serial communication interface 4
  sercom5_handler,              //30 - Serial communication interface 5
  tcc0_handler,                 //31 - Timer counter for control 0
  tcc1_handler,                 //32 - Timer counter for control 1
  tcc2_handler,                 //33 - Timer counter for control 2
  tc3_handler,                  //34 - Timer counter 3
  tc4_handler,                  //35 - Timer counter 4
  tc5_handler,                  //36 - Timer counter 5
  tc6_handler,                  //37 - Timer counter 6
  tc7_handler,                  //38 - Timer counter 7
  adc_handler,                  //39 - Analog to digital converter
  ac_handler,                   //40 - Analog comparator
  dac_handler,                  //41 - Digital to analog converter
  ptc_handler,                  //42 - Peripheral touch controller
  i2s_handler,                  //43 - Inter IC sound
};
