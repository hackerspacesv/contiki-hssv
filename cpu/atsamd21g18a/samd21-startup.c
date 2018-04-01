//+------------------------------------------------------------------------------------------------+
//| ATSAMD21G18A microcontroller initialization code.                                              |
//|                                                                                                |
//| This file implements very basic microcontroller code infrastructure such as the vector table,  |
//| processor and peripheral initialization and memory initialization.                             |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdint.h>

#include "contiki-conf.h"

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

  //Common initialization.
  //------------------------------------------------------------------------------------------------

  //Configure the XOSC32K oscillator. Set an startup time of 2048 OSCULP32K cycles, keep the
  //oscillator enabled in standby, enable amplitude control, enable crystal oscillator pins.
  SYSCTRL->XOSC32K.reg = SYSCTRL_XOSC32K_STARTUP(2) | SYSCTRL_XOSC32K_RUNSTDBY |
                         SYSCTRL_XOSC32K_AAMPEN | SYSCTRL_XOSC32K_EN32K | SYSCTRL_XOSC32K_XTALEN;

  //Once configured, enable the oscillator without affecting the other bits.
  SYSCTRL->XOSC32K.reg |= SYSCTRL_XOSC32K_ENABLE;

  //Wait for the XOSC32K oscillator to be ready.
  while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_XOSC32KRDY) == 0);

  //Set the generic clock generator 1 to divide by 1.
  GCLK->GENDIV.reg = GCLK_GENDIV_DIV(1) | GCLK_GENDIV_ID(1);

  //Configure the generic clock generator 1 to use XOSC32K as its source. Keep defaults.
  GCLK->GENCTRL.reg = GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC_XOSC32K | GCLK_GENCTRL_ID(1);

  //Power profile based initialization.
  //------------------------------------------------------------------------------------------------

#if SAMD21_POWER_PROFILE  == SAMD21_POWER_PROFILE_PERFORMANCE_48MHZ
  //Set the DFLL48M generic clock to use the generic clock generator 1.
  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_ID_DFLL48 | GCLK_CLKCTRL_GEN_GCLK1;

  //Enable the DFLL48M before accessing other registers.
  SYSCTRL->DFLLCTRL.reg = SYSCTRL_DFLLCTRL_ENABLE;

  //Configure the DFLL48M to lock as fast as possible (using the maximum allowed values at 50%)
  //using a multiplication factor of 1465 so that output frequency is 32.768kHz * 1465 = 48.005MHz.
  SYSCTRL->DFLLMUL.reg = SYSCTRL_DFLLMUL_CSTEP(31) | SYSCTRL_DFLLMUL_FSTEP(511) |
                         SYSCTRL_DFLLMUL_MUL(1465);

  //Configure the DFLL48M to operate in closed loop (use external reference), wait for lock and
  //disable quick locking. By setting the mode bit the closed loop operation is started.
  SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_WAITLOCK | SYSCTRL_DFLLCTRL_QLDIS |
                           SYSCTRL_DFLLCTRL_MODE;

  //Wait for the DFLL48M to perform the coarse lock and then the fine lock.
  while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLLCKC) == 0);
  while ((SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLLCKF) == 0);

  //Set the generic clock generator 0 to divide by 1.
  GCLK->GENDIV.reg = GCLK_GENDIV_ID(0) | GCLK_GENDIV_DIV(1);

  //Set internal flash timing before switching clocks to 1 wait state. Keep defaults and don't
  //disable manual write.
  NVMCTRL->CTRLB.reg = NVMCTRL_CTRLB_MANW | NVMCTRL_CTRLB_RWS(1);

  //Configure the generic clock generator 0 to use DFLL48M as its source. Keep defaults.
  GCLK->GENCTRL.reg = GCLK_GENCTRL_GENEN | GCLK_GENCTRL_SRC_DFLL48M | GCLK_GENCTRL_ID(0);

#elif SAMD21_POWER_PROFILE == SAMD21_POWER_PROFILE_LOWPOWER_4MHZ
  //Simply reconfigure the OSC8M oscillator to run the system at 4MHz.
  SYSCTRL->OSC8M.bit.PRESC = 1;     //Divide by 2 so Freq = 8MHz / 2 = 4MHz
  SYSCTRL->OSC8M.bit.ONDEMAND = 1;  //Turn on demand mode (disable when not required)
  SYSCTRL->OSC8M.bit.RUNSTDBY = 0;  //Do not run in standby (saves power)

  //Set the SLEEPDEEP bit in the System Control Register to enable STANDBY mode.
  SCB->SCR = SCB_SCR_SLEEPDEEP_Msk;
#endif

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
  unused_handler,               //37
  unused_handler,               //38
  adc_handler,                  //39 - Analog to digital converter
  ac_handler,                   //40 - Analog comparator
  dac_handler,                  //41 - Digital to analog converter
  ptc_handler,                  //42 - Peripheral touch controller
  i2s_handler,                  //43 - Inter IC sound
};
