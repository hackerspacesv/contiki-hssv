//+------------------------------------------------------------------------------------------------+
//| Kinetis MK20 microcontroller initialization code.                                              |
//|                                                                                                |
//| This file implements very basic microcontroller code infrastructure such as the vector table,  |
//| processor and peripheral initialization, memory initialization and non-volatile configuration  |
//| bits.                                                                                          |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include <stdint.h>

#include "mk20-wdog.h"
#include "mk20-sim.h"

//Interrupt vector handler function type.
typedef void (* handler_t)();

//Flash configuration field structure.
struct flash_configuration_field_type {
  uint8_t backdoor_comparison_key[8];
  uint8_t FPROT[4];
  uint8_t FSEC;
  uint8_t FOPT;
  uint8_t FEPROT;
  uint8_t FDPROT;
};

//Symbols exported by the linker script.
extern uint32_t __stack_end__;
extern const uint32_t __relocate_flash_start__;
extern uint32_t __relocate_sram_start__;
extern uint32_t __relocate_sram_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

//External functions invoked by startup code.
extern void __libc_init_array();
extern void main();

//--------------------------------------------------------------------------------------------------

//Startup routine, located at reset vector.
void startup() {
  const uint32_t *flash;
  uint32_t *sram;

  //Disable the watcdog.
  WDOG->UNLOCK = WDOG_UNLOCK_Seq_A;
  WDOG->UNLOCK = WDOG_UNLOCK_Seq_B;
  WDOG->STCTRLH = WDOG_STCTRLH_WDOGEN_Disabled | WDOG_STCTRLH_ALLOWUPDATE_Yes;

  //Enable the clocks of all ports.
  SIM->SCGC5 = SIM_SCGC5_PORTA_Enabled | SIM_SCGC5_PORTB_Enabled | SIM_SCGC5_PORTC_Enabled |
               SIM_SCGC5_PORTD_Enabled | SIM_SCGC5_PORTE_Enabled;

  //Copy the initial data for the data section from FLASH to RAM.
  flash = &__relocate_flash_start__;
  sram = &__relocate_sram_start__;
  while (sram < &__relocate_sram_end__)
    *sram++ = *flash++;

  //Initialize the .bss section to zeroes.
  sram = &__bss_start__;
  while (sram < &__bss_end__)
    *sram++ = 0;

  //Initialize libc.
  __libc_init_array();

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
void __attribute__((weak, alias("unused_handler"))) memmanage_fault_handler();
void __attribute__((weak, alias("unused_handler"))) bus_fault_handler();
void __attribute__((weak, alias("unused_handler"))) usage_fault_handler();
void __attribute__((weak, alias("unused_handler"))) svcall_handler();
void __attribute__((weak, alias("unused_handler"))) debug_monitor_handler();
void __attribute__((weak, alias("unused_handler"))) pendablesrvreq_handler();
void __attribute__((weak, alias("unused_handler"))) systick_handler();

//Weak references for non-core (peripheral) vectors.
void __attribute__((weak, alias("unused_handler"))) dma_channel_0_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_1_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_2_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_3_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_4_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_5_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_6_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_7_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_8_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_9_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_10_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_11_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_12_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_13_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_14_handler();
void __attribute__((weak, alias("unused_handler"))) dma_channel_15_handler();
void __attribute__((weak, alias("unused_handler"))) dma_error_handler();
void __attribute__((weak, alias("unused_handler"))) flash_command_complete_handler();
void __attribute__((weak, alias("unused_handler"))) flash_read_collision_handler();
void __attribute__((weak, alias("unused_handler"))) low_voltage_handler();
void __attribute__((weak, alias("unused_handler"))) low_leakage_wakeup_handler();
void __attribute__((weak, alias("unused_handler"))) wdog_ewm_handler();
void __attribute__((weak, alias("unused_handler"))) i2c_0_handler();
void __attribute__((weak, alias("unused_handler"))) i2c_1_handler();
void __attribute__((weak, alias("unused_handler"))) spi_0_handler();
void __attribute__((weak, alias("unused_handler"))) spi_1_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_message_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_bus_off_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_error_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_transmit_warning_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_receive_warning_handler();
void __attribute__((weak, alias("unused_handler"))) can_0_wake_up_handler();
void __attribute__((weak, alias("unused_handler"))) i2s_0_transmit_handler();
void __attribute__((weak, alias("unused_handler"))) i2s_0_receive_handler();
void __attribute__((weak, alias("unused_handler"))) uart_0_lon_handler();
void __attribute__((weak, alias("unused_handler"))) uart_0_status_handler();
void __attribute__((weak, alias("unused_handler"))) uart_0_error_handler();
void __attribute__((weak, alias("unused_handler"))) uart_1_status_handler();
void __attribute__((weak, alias("unused_handler"))) uart_1_error_handler();
void __attribute__((weak, alias("unused_handler"))) uart_2_status_handler();
void __attribute__((weak, alias("unused_handler"))) uart_2_error_handler();
void __attribute__((weak, alias("unused_handler"))) adc_0_handler();
void __attribute__((weak, alias("unused_handler"))) adc_1_handler();
void __attribute__((weak, alias("unused_handler"))) cmp_0_handler();
void __attribute__((weak, alias("unused_handler"))) cmp_1_handler();
void __attribute__((weak, alias("unused_handler"))) cmp_2_handler();
void __attribute__((weak, alias("unused_handler"))) ftm_0_handler();
void __attribute__((weak, alias("unused_handler"))) ftm_1_handler();
void __attribute__((weak, alias("unused_handler"))) ftm_2_handler();
void __attribute__((weak, alias("unused_handler"))) cmt_handler();
void __attribute__((weak, alias("unused_handler"))) rtc_alarm_handler();
void __attribute__((weak, alias("unused_handler"))) rtc_seconds_handler();
void __attribute__((weak, alias("unused_handler"))) pit_0_handler();
void __attribute__((weak, alias("unused_handler"))) pit_1_handler();
void __attribute__((weak, alias("unused_handler"))) pit_2_handler();
void __attribute__((weak, alias("unused_handler"))) pit_3_handler();
void __attribute__((weak, alias("unused_handler"))) pdb_handler();
void __attribute__((weak, alias("unused_handler"))) usb_otg_handler();
void __attribute__((weak, alias("unused_handler"))) usb_charger_detect_handler();
void __attribute__((weak, alias("unused_handler"))) dac_0_handler();
void __attribute__((weak, alias("unused_handler"))) tsi_handler();
void __attribute__((weak, alias("unused_handler"))) mcg_handler();
void __attribute__((weak, alias("unused_handler"))) low_power_timer_handler();
void __attribute__((weak, alias("unused_handler"))) port_a_handler();
void __attribute__((weak, alias("unused_handler"))) port_b_handler();
void __attribute__((weak, alias("unused_handler"))) port_c_handler();
void __attribute__((weak, alias("unused_handler"))) port_d_handler();
void __attribute__((weak, alias("unused_handler"))) port_e_handler();
void __attribute__((weak, alias("unused_handler"))) software_interrupt_handler();

//--------------------------------------------------------------------------------------------------

//Processor vector table, located at 0x00000000.
static __attribute__ ((section(".vectors"), used))
handler_t vectors[111] = {
  //Core system handler vectors.
  (handler_t) &__stack_end__,   //0 - Initial stack pointer
  startup,                      //1 - Initial program counter
  nmi_handler,                  //2 - Non maskable interrupt
  hard_fault_handler,           //3 - Hard fault
  memmanage_fault_handler,      //4 - MemManage fault
  bus_fault_handler,            //5 - Bus fault
  usage_fault_handler,          //6 - Usage fault
  unused_handler,               //7
  unused_handler,               //8
  unused_handler,               //9
  unused_handler,               //10
  svcall_handler,               //11 - Supervisor call
  debug_monitor_handler,        //12 - Debug monitor
  unused_handler,               //13
  pendablesrvreq_handler,       //14 - Pendable request for system service
  systick_handler,              //15 - System tick timer

  //Non-core vectors.
  dma_channel_0_handler,            //16 - DMA channel 0 transfer complete
  dma_channel_1_handler,            //17 - DMA channel 1 transfer complete
  dma_channel_2_handler,            //18 - DMA channel 2 transfer complete
  dma_channel_3_handler,            //19 - DMA channel 3 transfer complete
  dma_channel_4_handler,            //20 - DMA channel 4 transfer complete
  dma_channel_5_handler,            //21 - DMA channel 5 transfer complete
  dma_channel_6_handler,            //22 - DMA channel 6 transfer complete
  dma_channel_7_handler,            //23 - DMA channel 7 transfer complete
  dma_channel_8_handler,            //24 - DMA channel 8 transfer complete
  dma_channel_9_handler,            //25 - DMA channel 9 transfer complete
  dma_channel_10_handler,           //26 - DMA channel 10 transfer complete
  dma_channel_11_handler,           //27 - DMA channel 11 transfer complete
  dma_channel_12_handler,           //28 - DMA channel 12 transfer complete
  dma_channel_13_handler ,          //29 - DMA channel 13 transfer complete
  dma_channel_14_handler ,          //30 - DMA channel 14 transfer complete
  dma_channel_15_handler ,          //31 - DMA channel 15 transfer complete
  dma_error_handler,                //32 - DMA error interrupt channels 0-15
  unused_handler,                   //33
  flash_command_complete_handler,   //34 - Flash memory command complete
  flash_read_collision_handler,     //35 - Flash memory read collision
  low_voltage_handler,              //36 - Low voltage detect and low voltage warning interrupt
  low_leakage_wakeup_handler,       //37 - Low leakage wake up
  wdog_ewm_handler,                 //38 - Watchdog (internal and external)
  unused_handler,                   //39
  i2c_0_handler,                    //40 - I2C 0
  i2c_1_handler,                    //41 - I2C 1
  spi_0_handler,                    //42 - SPI 0
  spi_1_handler,                    //43 - SPI 1
  unused_handler,                   //44
  can_0_message_handler,            //45 - CAN 0 OR'ed message buffer (0 - 15)
  can_0_bus_off_handler,            //46 - CAN 0 bus off
  can_0_error_handler,              //47 - CAN 0 error
  can_0_transmit_warning_handler,   //48 - CAN 0 transmit warning
  can_0_receive_warning_handler,    //49 - CAN 0 receive warning
  can_0_wake_up_handler,            //50 - CAN 0 wake up
  i2s_0_transmit_handler,           //51 - I2S transmit
  i2s_0_receive_handler,            //52 - I2S receive
  unused_handler,                   //53
  unused_handler,                   //54
  unused_handler,                   //55
  unused_handler,                   //56
  unused_handler,                   //57
  unused_handler,                   //58
  unused_handler,                   //59
  uart_0_lon_handler,               //60 - UART 0, all LON interrupts
  uart_0_status_handler,            //61 - UART 0, all status interrupts
  uart_0_error_handler,             //62 - UART 0, all error interrupts
  uart_1_status_handler,            //63 - UART 1, all status interrupts
  uart_1_error_handler,             //64 - UART 1, all error interrupts
  uart_2_status_handler,            //65 - UART 2, all status interrupts
  uart_2_error_handler,             //66 - UART 2, all error interrupts
  unused_handler,                   //67
  unused_handler,                   //68
  unused_handler,                   //69
  unused_handler,                   //70
  unused_handler,                   //71
  unused_handler,                   //72
  adc_0_handler,                    //73 - ADC 0
  adc_1_handler,                    //74 - ADC 1
  cmp_0_handler,                    //75 - CMP 0
  cmp_1_handler,                    //76 - CMP 1
  cmp_2_handler,                    //77 - CMP 2
  ftm_0_handler,                    //78 - FTM 0
  ftm_1_handler,                    //79 - FTM 1
  ftm_2_handler,                    //80 - FTM 2
  cmt_handler,                      //81 - CMT
  rtc_alarm_handler,                //82 - RTC alarm interrupt
  rtc_seconds_handler,              //83 - RTC seconds interrupt
  pit_0_handler,                    //84 - PIT channel 0
  pit_1_handler,                    //85 - PIT channel 1
  pit_2_handler,                    //86 - PIT channel 2
  pit_3_handler,                    //87 - PIT channel 3
  pdb_handler,                      //88 - PDB
  usb_otg_handler,                  //89 - USB OTG
  usb_charger_detect_handler,       //90 - USB charger detect
  unused_handler,                   //91
  unused_handler,                   //92
  unused_handler,                   //93
  unused_handler,                   //94
  unused_handler,                   //95
  unused_handler,                   //96
  dac_0_handler,                    //97 - DAC 0
  unused_handler,                   //98
  tsi_handler,                      //99 - TSI
  mcg_handler,                      //100 - MCG
  low_power_timer_handler,          //101 - Low power timer
  unused_handler,                   //102
  port_a_handler,                   //103 - Port A pin detect
  port_b_handler,                   //104 - Port B pin detect
  port_c_handler,                   //105 - Port C pin detect
  port_d_handler,                   //106 - Port D pin detect
  port_e_handler,                   //107 - Port E pin detect
  unused_handler,                   //108
  unused_handler,                   //109
  software_interrupt_handler,       //110 - Software interrupt
};

//--------------------------------------------------------------------------------------------------

//Flash configuration field instance, located at 0x00000400.
static __attribute__ ((section(".flash_configuration_field"), used))
struct flash_configuration_field_type flash_config = {
  .backdoor_comparison_key = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, },
  .FPROT = { 0xFF, 0xFF, 0xFF, 0xFF, },
  .FSEC = 0xFE,     //Disable backdoor access and security, enable mass erase and factory access.
  .FOPT = 0xF9,     //Disable NMI interrupts and EzPort. Enable normal boot (faster speed).
  .FEPROT = 0xFF,
  .FDPROT = 0xFF,
};
