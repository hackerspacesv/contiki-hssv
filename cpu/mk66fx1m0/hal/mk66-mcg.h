//+------------------------------------------------------------------------------------------------+
//| MCG peripheral registers for Kinetis MK66 MCU.                                                 |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_MCG_H_
#define MK66_MCG_H_

#include <stdint.h>

struct MCG_type {
  uint8_t C1;         //Control 1 register
  uint8_t C2;         //Control 2 register
  uint8_t C3;         //Control 3 register
  uint8_t C4;         //Control 4 register
  uint8_t C5;         //Control 5 register
  uint8_t C6;         //Control 6 register
  uint8_t S;          //Status register
  uint8_t reserved0;
  uint8_t SC;         //Status and control register
  uint8_t reserved1;
  uint8_t ATCVH;      //Auto trim compare value high register
  uint8_t ATCVL;      //Auto trim compare value low register
  uint8_t C7;         //Control 7 register
  uint8_t C8;         //Control 8 register
  uint8_t C9;         //Control 9 register
  uint8_t reserved2;
  uint8_t C11;        //Control 11 register
  uint8_t C12;        //Control 12 register
  uint8_t S2;         //Status 2 register
  uint8_t T3;         //Test 3 register
};

#define MCG ((volatile struct MCG_type *) 0x40064000)

//Control 1 register bitfields
#define MCG_C1_IREFSTEN_Disabled    (0 << 0)  //Internal reference stop enable
#define MCG_C1_IREFSTEN_Enabled     (1 << 0)
#define MCG_C1_IRCLKEN_Disabled     (0 << 1)  //Internal reference clock enable
#define MCG_C1_IRCLKEN_Enabled      (1 << 1)
#define MCG_C1_IREFS_External       (0 << 2)  //Internal reference select
#define MCG_C1_IREFS_Internal       (1 << 2)
#define MCG_C1_FRDIV_Div_1_32       (0 << 3)  //FLL external reference divider
#define MCG_C1_FRDIV_Div_2_64       (1 << 3)
#define MCG_C1_FRDIV_Div_4_128      (2 << 3)
#define MCG_C1_FRDIV_Div_8_256      (3 << 3)
#define MCG_C1_FRDIV_Div_16_512     (4 << 3)
#define MCG_C1_FRDIV_Div_32_1024    (5 << 3)
#define MCG_C1_FRDIV_Div_64_1280    (6 << 3)
#define MCG_C1_FRDIV_Div_128_1536   (7 << 3)
#define MCG_C1_CLKS_FLL_PLLCS       (0 << 6)  //Clock source select
#define MCG_C1_CLKS_Internal        (1 << 6)
#define MCG_C1_CLKS_External        (2 << 6)

//Control 2 register bitfields
#define MCG_C2_IRCS_Slow          (0 << 0)  //Internal reference clock select
#define MCG_C2_IRCS_Fast          (1 << 0)
#define MCG_C2_LP_Clear           (0 << 1)  //Low power select
#define MCG_C2_LP_Set             (1 << 1)
#define MCG_C2_EREFS_External     (0 << 2)  //Extetrnal reference select
#define MCG_C2_EREFS_Oscillator   (1 << 2)
#define MCG_C2_HGO_Low_Power      (0 << 3)  //High gain oscillator select
#define MCG_C2_HGO_High_Gain      (1 << 3)
#define MCG_C2_RANGE_Low          (0 << 4)  //Frequency range select
#define MCG_C2_RANGE_High         (1 << 4)
#define MCG_C2_RANGE_Very_High    (2 << 4)
#define MCG_C2_FCFTRIM_Clear      (0 << 6)  //Fast internal reference clock fine trim
#define MCG_C2_FCFTRIM_Set        (1 << 6)
#define MCG_C2_LOCRE0_Interrupt   (0 << 7)  //Loss of clock reset enable
#define MCG_C2_LOCRE0_Reset       (1 << 7)

//Control 4 register bitfields
#define MCG_C4_SCFTRIM_Msk        0x01      //Slow internal reference clock fine trim
#define MCG_C4_SCFTRIM_Pos        0
#define MCG_C4_FCTRIM_Msk         0x1E      //Fast internal reference clock trim setting
#define MCG_C4_FCTRIM_Pos         1
#define MCG_C4_DRST_DRS_Low       (0 << 5)  //DCO range select
#define MCG_C4_DRST_DRS_Mid       (1 << 5)
#define MCG_C4_DRST_DRS_Mid_High  (2 << 5)
#define MCG_C4_DRST_DRS_High      (3 << 5)
#define MCG_C4_DMX32_Clear        (0 << 7)  //DCO maximum frequency with 32.768 KHz reference
#define MCG_C4_DMX32_Set          (1 << 7)

//Control 5 register bitfields
#define MCG_C5_PRDIV_Div_1        (0 << 0)  //PLL external reference divider
#define MCG_C5_PRDIV_Div_2        (1 << 0)
#define MCG_C5_PRDIV_Div_3        (2 << 0)
#define MCG_C5_PRDIV_Div_4        (3 << 0)
#define MCG_C5_PRDIV_Div_5        (4 << 0)
#define MCG_C5_PRDIV_Div_6        (5 << 0)
#define MCG_C5_PRDIV_Div_7        (6 << 0)
#define MCG_C5_PRDIV_Div_8        (7 << 0)
#define MCG_C5_PLLSTEN_Disabled   (0 << 5)  //PLL stop enable
#define MCG_C5_PLLSTEN_Enabled    (1 << 5)
#define MCG_C5_PLLCLKEN_Disabled  (0 << 6)  //PLL clock enable
#define MCG_C5_PLLCLKEN_Enabled   (1 << 6)

//Control 6 register bitfields
#define MCG_C6_VDIV_Div_16      (0 << 0)    //VCO divider
#define MCG_C6_VDIV_Div_17      (1 << 0)
#define MCG_C6_VDIV_Div_18      (2 << 0)
#define MCG_C6_VDIV_Div_19      (3 << 0)
#define MCG_C6_VDIV_Div_20      (4 << 0)
#define MCG_C6_VDIV_Div_21      (5 << 0)
#define MCG_C6_VDIV_Div_22      (6 << 0)
#define MCG_C6_VDIV_Div_23      (7 << 0)
#define MCG_C6_VDIV_Div_24      (8 << 0)
#define MCG_C6_VDIV_Div_25      (9 << 0)
#define MCG_C6_VDIV_Div_26      (10 << 0)
#define MCG_C6_VDIV_Div_27      (11 << 0)
#define MCG_C6_VDIV_Div_28      (12 << 0)
#define MCG_C6_VDIV_Div_29      (13 << 0)
#define MCG_C6_VDIV_Div_30      (14 << 0)
#define MCG_C6_VDIV_Div_31      (15 << 0)
#define MCG_C6_VDIV_Div_32      (16 << 0)
#define MCG_C6_VDIV_Div_33      (17 << 0)
#define MCG_C6_VDIV_Div_34      (18 << 0)
#define MCG_C6_VDIV_Div_35      (19 << 0)
#define MCG_C6_VDIV_Div_36      (20 << 0)
#define MCG_C6_VDIV_Div_37      (21 << 0)
#define MCG_C6_VDIV_Div_38      (22 << 0)
#define MCG_C6_VDIV_Div_39      (23 << 0)
#define MCG_C6_VDIV_Div_40      (24 << 0)
#define MCG_C6_VDIV_Div_41      (25 << 0)
#define MCG_C6_VDIV_Div_42      (26 << 0)
#define MCG_C6_VDIV_Div_43      (27 << 0)
#define MCG_C6_VDIV_Div_44      (28 << 0)
#define MCG_C6_VDIV_Div_45      (29 << 0)
#define MCG_C6_VDIV_Div_46      (30 << 0)
#define MCG_C6_VDIV_Div_47      (31 << 0)
#define MCG_C6_CME0_Disabled    (0 << 5)    //Clock monitor enable
#define MCG_C6_CME0_Enabled     (1 << 5)
#define MCG_C6_PLLS_FLL         (0 << 6)    //PLL select
#define MCG_C6_PLLS_PLLCS       (1 << 6)
#define MCG_C6_LOLIE0_Disabled  (0 << 7)    //Loss of lock interrupt enable
#define MCG_C6_LOLIE0_Enabled   (1 << 7)

//Status register bitfields
#define MCG_S_IRCST_Msk           0x01      //Internal reference clock status
#define MCG_S_IRCST_Slow          (0 << 0)
#define MCG_S_IRCST_Fast          (1 << 0)
#define MCG_S_OSCINIT0_Msk        0x02      //OSC initialization
#define MCG_S_OSCINIT0_Not_Ready  (0 << 1)
#define MCG_S_OSCINIT0_Ready      (1 << 1)
#define MCG_S_CLKST_Msk           0x0C      //Clock mode status
#define MCG_S_CLKST_FLL           (0 << 2)
#define MCG_S_CLKST_Internal      (1 << 2)
#define MCG_S_CLKST_External      (2 << 2)
#define MCG_S_CLKST_PLL           (3 << 2)
#define MCG_S_IREFST_Msk          0x10      //Internal reference status
#define MCG_S_IREFST_External     (0 << 4)
#define MCG_S_IREFST_Internal     (1 << 4)
#define MCG_S_PLLST_Msk           0x20      //PLL select status
#define MCG_S_PLLST_FLL           (0 << 5)
#define MCG_S_PLLST_PLLCS         (1 << 5)
#define MCG_S_LOCK0_Msk           0x40      //Lock status
#define MCG_S_LOCK0_Unlocked      (0 << 6)
#define MCG_S_LOCK0_Locked        (1 << 6)
#define MCG_S_LOLS0_Msk           0x80      //Loss of lock status
#define MCG_S_LOLS0_Clear         (0 << 7)
#define MCG_S_LOLS0_Set           (1 << 7)

//Status and control register bitfields
#define MCG_SC_LOCS0_Msk          0x01      //OSC0 loss of clock status
#define MCG_SC_LOCS0_Clear        (0 << 0)
#define MCG_SC_LOCS0_Set          (1 << 0)
#define MCG_SC_FCRDIV_Div_1       (0 << 1)  //Fast clock internal reference divider
#define MCG_SC_FCRDIV_Div_2       (1 << 1)
#define MCG_SC_FCRDIV_Div_4       (2 << 1)
#define MCG_SC_FCRDIV_Div_8       (3 << 1)
#define MCG_SC_FCRDIV_Div_16      (4 << 1)
#define MCG_SC_FCRDIV_Div_32      (5 << 1)
#define MCG_SC_FCRDIV_Div_64      (6 << 1)
#define MCG_SC_FCRDIV_Div_128     (7 << 1)
#define MCG_SC_FLTPRSRV_Disabled  (0 << 4)  //FLL filter preserve enable
#define MCG_SC_FLTPRSRV_Enabled   (1 << 4)
#define MCG_SC_ATMF_Msk           0x20      //Automatic trim machine fail flag
#define MCG_SC_ATMF_Clear         (0 << 5)
#define MCG_SC_ATMF_Set           (1 << 5)
#define MCG_SC_ATMS_32KHz         (0 << 6)  //Automatic trim machine select
#define MCG_SC_ATMS_4MHz          (1 << 6)
#define MCG_SC_ATME_Disabled      (0 << 7)  //Automatic trim machine enable
#define MCG_SC_ATME_Enabled       (1 << 7)

//Control 7 register bitfields
#define MCG_C7_OSCSEL_OSCCLK0   (0 << 0)  //MCG OSC clock select
#define MCG_C7_OSCSEL_RTC       (1 << 0)
#define MCG_C7_OSCSEL_OSCCLK1   (2 << 0)

//Control 8 register bitfields
#define MCG_C8_LOCS1_Msk          0x01      //RTC loss of clock status
#define MCG_C8_LOCS1_Clear        (0 << 0)
#define MCG_C8_LOCS1_Set          (1 << 0)
#define MCG_C8_CME1_Disabled      (0 << 5)  //Clock monitor enable 1
#define MCG_C8_CME1_Enabled       (1 << 5)
#define MCG_C8_LOLRE_Interrupt    (0 << 6)  //PLL loss of lock reset enable
#define MCG_C8_LOLRE_Reset        (1 << 6)
#define MCG_C8_LOCRE1_Interrupt   (0 << 7)  //Loss of clock reset enable
#define MCG_C8_LOCRE1_Reset       (1 << 7)

//Control 9 register bitfields
#define MCG_C9_EXT_PLL_LOCS_Msk     0x00000001  //External PLL loss of clock status
#define MCG_C9_EXT_PLL_LOCS_Pos     0
#define MCG_C9_PLL_LOCRE_Interrupt  (0 << 4)    //MCG external PLL loss of clock reset enable
#define MCG_C9_PLL_LOCRE_Reset      (1 << 4)
#define MCG_C9_PLL_CME_Disabled     (0 << 5)    //MCG external PLL clock monitor enable
#define MCG_C9_PLL_CME_Enabled      (1 << 5)

//Control 11 register bitfields
#define MCG_C11_PLLCS_PLL0      (0 << 4)  //PLL clock select
#define MCG_C11_PLLCS_EXT_PLL   (1 << 4)

//Status 2 register bitfields
#define MCG_S2_PLLCST_PLL       (0 << 4)  //PLL clock select status
#define MCG_S2_PLLCST_EXT_Pll   (1 << 4)

#endif //MK66_MCG_H_
