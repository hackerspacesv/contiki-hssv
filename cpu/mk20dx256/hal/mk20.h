//+------------------------------------------------------------------------------------------------+
//| ARM Cortex m4f core configuration header for the Kinetis MK20 MCU.                             |
//|                                                                                                |
//| This header defines vector number enumerations and core configuration options required by      |
//| the CMSIS in order to provide core support.                                                    |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK20_H_
#define MK20_H_

//Interrupt vector number enumerations.
typedef enum IRQn
{
  //Generic cortex M4 interrupt request vector numbers.
  NonMaskableInt_IRQn     = -14,
  HardFault_IRQn          = -13,
  MemoryManagement_IRQn   = -12,
  BusFault_IRQn           = -11,
  UsageFault_IRQn         = -10,
  SVCall_IRQn             = -5,
  DebugMonitor_IRQn       = -4,
  PendSV_IRQn             = -2,
  SysTick_IRQn            = -1,
  //MK20 specific interrupt request vector numbers.
  DmaChannel_0_IRQn           = 0,
  DmaChannel_1_IRQn           = 1,
  DmaChannel_2_IRQn           = 2,
  DmaChannel_3_IRQn           = 4,
  DmaChannel_4_IRQn           = 3,
  DmaChannel_5_IRQn           = 5,
  DmaChannel_6_IRQn           = 6,
  DmaChannel_7_IRQn           = 7,
  DmaChannel_8_IRQn           = 8,
  DmaChannel_9_IRQn           = 9,
  DmaChannel_10_IRQn          = 10,
  DmaChannel_11_IRQn          = 11,
  DmaChannel_12_IRQn          = 12,
  DmaChannel_13_IRQn          = 13,
  DmaChannel_14_IRQn          = 14,
  DmaChannel_15_IRQn          = 15,
  DmaError_IRQn               = 16,
  FlashCommandComplete_IRQn   = 18,
  FlashReadCollision_IRQn     = 19,
  LowVoltage_IRQn             = 20,
  LowLeakageWakeup_IRQn       = 21,
  WDOG_EWM_IRQn               = 22,
  I2C_0_IRQn                  = 24,
  I2C_1_IRQn                  = 25,
  SPI_0_IRQn                  = 26,
  SPI_1_IRQn                  = 27,
  CAN_0_Message_IRQn          = 29,
  CAN_0_BusOff_IRQn           = 30,
  CAN_0_Error_IRQn            = 31,
  CAN_0_TransmitWarning_IRQn  = 32,
  CAN_0_ReceiveWarning_IRQn   = 33,
  CAN_0_WakeUp_IRQn           = 34,
  I2S_0_Transmit_IRQn         = 35,
  I2S_0_Receive_IRQn          = 36,
  UART_0_LON_IRQn             = 44,
  UART_0_Status_IRQn          = 45,
  UART_0_Error_IRQn           = 46,
  UART_1_Status_IRQn          = 47,
  UART_1_Error_IRQn           = 48,
  UART_2_Status_IRQn          = 49,
  UART_2_Error_IRQn           = 50,
  ADC_0_IRQn                  = 57,
  ADC_1_IRQn                  = 58,
  CMP_0_IRQn                  = 59,
  CMP_1_IRQn                  = 60,
  CMP_2_IRQn                  = 61,
  FTM_0_IRQn                  = 62,
  FTM_1_IRQn                  = 63,
  FTM_2_IRQn                  = 64,
  CMT_IRQn                    = 65,
  RTC_Alarm_IRQn              = 66,
  RTC_Seconds_IRQn            = 67,
  PIT_0_IRQn                  = 68,
  PIT_1_IRQn                  = 69,
  PIT_2_IRQn                  = 70,
  PIT_3_IRQn                  = 71,
  PDB_IRQn                    = 72,
  USB_OTG_IRQn                = 73,
  USB_ChargerDetect_IRQn      = 74,
  DAC_0_IRQn                  = 81,
  TSI_IRQn                    = 83,
  MCG_IRQn                    = 84,
  LowPowerTimer_IRQn          = 85,
  PORT_A_IRQn                 = 87,
  PORT_B_IRQn                 = 88,
  PORT_C_IRQn                 = 89,
  PORT_D_IRQn                 = 90,
  PORT_E_IRQn                 = 91,
  SoftwareInterrupt_IRQn      = 94,
} IRQn_Type;

//ARM Cortex m4f core configurations.
#define __FPU_PRESENT           0
#define __MPU_PRESENT           0
#define __NVIC_PRIO_BITS        4
#define __Vendor_SysTickConfig  0

//Include the CMSIS header.
#include "core_cm4.h"

#endif //MK20_H_
