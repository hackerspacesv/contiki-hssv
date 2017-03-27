//+------------------------------------------------------------------------------------------------+
//| WDOG peripheral registers for Kinetis MK66 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_WDOG_H_
#define MK66_WDOG_H_

#include <stdint.h>

struct WDOG_type {
  uint16_t STCTRLH;   //Status and control register high
  uint16_t STCTRLL;   //Status and control register low
  uint16_t TOVALH;    //Time-out value register high
  uint16_t TOVALL;    //Time-out value register low
  uint16_t WINH;      //Window register high
  uint16_t WINL;      //Window register low
  uint16_t REFRESH;   //Refresh register
  uint16_t UNLOCK;    //Unlock register
  uint16_t TMROUTH;   //Timer output register high
  uint16_t TMROUTL;   //Timer output register low
  uint16_t RSTCNT;    //Reset count register
  uint16_t PRESC;     //Prescaler register
};

#define WDOG ((volatile struct WDOG_type *) 0x40052000)

//Status and control register high bitfields
#define WDOG_STCTRLH_WDOGEN_Disabled    (0 << 0)    //Enables or disables the WDOG's operation
#define WDOG_STCTRLH_WDOGEN_Enabled     (1 << 0)
#define WDOG_STCTRLH_CLKSRC_LPO         (0 << 1)    //Selects the clock source for the WDOG timer
#define WDOG_STCTRLH_CLKSRC_Alternate   (1 << 1)
#define WDOG_STCTRLH_IRQRSTEN_Reset     (0 << 2)    //Used to enable the debug breadcrumbs feature
#define WDOG_STCTRLH_IRQRSTEN_Int_Res   (1 << 2)
#define WDOG_STCTRLH_WINEN_Disabled     (0 << 3)    //Enables windowing mode
#define WDOG_STCTRLH_WINEN_Enabled      (1 << 3)
#define WDOG_STCTRLH_ALLOWUPDATE_No     (0 << 4)    //Enables updates to watchdog write-once registers
#define WDOG_STCTRLH_ALLOWUPDATE_Yes    (1 << 4)
#define WDOG_STCTRLH_DBGEN_Disabled     (0 << 5)    //Enables or disables WDOG in debug mode
#define WDOG_STCTRLH_DBGEN_Enabled      (1 << 5)
#define WDOG_STCTRLH_STOPEN_Disabled    (0 << 6)    //Enables or disables WDOG in stop mode
#define WDOG_STCTRLH_STOPEN_Enabled     (1 << 6)
#define WDOG_STCTRLH_WAITEN_Disabled    (0 << 7)    //Enables or disables WDOG in CPU wait mode
#define WDOG_STCTRLH_WAITEN_Enabled     (1 << 7)
#define WDOG_STCTRLH_TESTWDOG_Disabled  (0 << 10)   //Puts the watchdog in functional test mode
#define WDOG_STCTRLH_TESTWDOG_Enabled   (1 << 10)
#define WDOG_STCTRLH_TESTSEL_Quick      (0 << 11)   //Selects the test to be run on the WDOG timer
#define WDOG_STCTRLH_TESTSEL_Byte       (1 << 11)
#define WDOG_STCTRLH_BYTESEL_0          (0 << 12)   //Select the byte to be tested in byte test mode
#define WDOG_STCTRLH_BYTESEL_1          (1 << 12)
#define WDOG_STCTRLH_BYTESEL_2          (2 << 12)
#define WDOG_STCTRLH_BYTESEL_3          (3 << 13)
#define WDOG_STCTRLH_DISTESTWDOG_Clear  (0 << 14)   //Allows to disable the functional test
#define WDOG_STCTRLH_DISTESTWDOG_Set    (1 << 14)

//Status and control register low bitfields
#define WDOG_STCTRLL_INTFLG_Clear   (0 << 15)   //Interrupt flag. Set in order to clear
#define WDOG_STCTRLL_INTFLG_Set     (1 << 15)

//Refresh register constants
#define WDOG_REFRESH_Seq_A 0xA602
#define WDOG_REFRESH_Seq_B 0xB480

//Unlock register constants
#define WDOG_UNLOCK_Seq_A 0xC520
#define WDOG_UNLOCK_Seq_B 0xD928

//Prescaler register bitfields
#define WDOG_PRESC_Div_1  (0 << 8)  //Prescaler for the watchdog clock source
#define WDOG_PRESC_Div_2  (1 << 8)
#define WDOG_PRESC_Div_3  (2 << 8)
#define WDOG_PRESC_Div_4  (3 << 8)

#endif //MK66_WDOG_H_
