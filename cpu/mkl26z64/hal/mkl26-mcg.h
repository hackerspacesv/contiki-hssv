//+------------------------------------------------------------------------------------------------+
//| MCG peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_MCG_H_
#define MKL26_MCG_H_

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
  uint8_t C10;        //Control 10 register
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
#define MCG_C1_CLKS_FLL_PLL         (0 << 6)  //Clock source select
#define MCG_C1_CLKS_Internal        (1 << 6)
#define MCG_C1_CLKS_External        (2 << 6)

//Control 2 register bitfields
#define MCG_C2_IRCS_Slow          (0 << 0)  //Internal reference clock select
#define MCG_C2_IRCS_Fast          (1 << 0)
#define MCG_C2_LP_Clear           (0 << 1)  //Low power select
#define MCG_C2_LP_Set             (1 << 1)
#define MCG_C2_EREFS_External     (0 << 2)  //Extetrnal reference select
#define MCG_C2_EREFS_Oscillator   (1 << 2)
#define MCG_C2_HGO0_Low_Power     (0 << 3)  //High gain oscillator select
#define MCG_C2_HGO0_High_Gain     (1 << 3)
#define MCG_C2_RANGE0_Low         (0 << 4)  //Frequency range select
#define MCG_C2_RANGE0_High        (1 << 4)
#define MCG_C2_RANGE0_Very_High   (2 << 4)
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
#define MCG_C5_PRDIV0_Div_1         (0 << 0)    //PLL external reference divider
#define MCG_C5_PRDIV0_Div_2         (1 << 0)
#define MCG_C5_PRDIV0_Div_3         (2 << 0)
#define MCG_C5_PRDIV0_Div_4         (3 << 0)
#define MCG_C5_PRDIV0_Div_5         (4 << 0)
#define MCG_C5_PRDIV0_Div_6         (5 << 0)
#define MCG_C5_PRDIV0_Div_7         (6 << 0)
#define MCG_C5_PRDIV0_Div_8         (7 << 0)
#define MCG_C5_PRDIV0_Div_9         (8 << 0)
#define MCG_C5_PRDIV0_Div_10        (9 << 0)
#define MCG_C5_PRDIV0_Div_11        (10 << 0)
#define MCG_C5_PRDIV0_Div_12        (11 << 0)
#define MCG_C5_PRDIV0_Div_13        (12 << 0)
#define MCG_C5_PRDIV0_Div_14        (13 << 0)
#define MCG_C5_PRDIV0_Div_15        (14 << 0)
#define MCG_C5_PRDIV0_Div_16        (15 << 0)
#define MCG_C5_PRDIV0_Div_17        (16 << 0)
#define MCG_C5_PRDIV0_Div_18        (17 << 0)
#define MCG_C5_PRDIV0_Div_19        (18 << 0)
#define MCG_C5_PRDIV0_Div_20        (19 << 0)
#define MCG_C5_PRDIV0_Div_21        (20 << 0)
#define MCG_C5_PRDIV0_Div_22        (21 << 0)
#define MCG_C5_PRDIV0_Div_23        (22 << 0)
#define MCG_C5_PRDIV0_Div_24        (23 << 0)
#define MCG_C5_PRDIV0_Div_25        (24 << 0)
#define MCG_C5_PLLSTEN0_Disabled    (0 << 5)    //PLL stop enable
#define MCG_C5_PLLSTEN0_Enabled     (1 << 5)
#define MCG_C5_PLLCLKEN0_Disabled   (0 << 6)    //PLL clock enable
#define MCG_C5_PLLCLKEN0_Enabled    (1 << 6)

//Control 6 register bitfields
#define MCG_C6_VDIV0_Div_24     (0 << 0)    //VCO 0 divider
#define MCG_C6_VDIV0_Div_25     (1 << 0)
#define MCG_C6_VDIV0_Div_26     (2 << 0)
#define MCG_C6_VDIV0_Div_27     (3 << 0)
#define MCG_C6_VDIV0_Div_28     (4 << 0)
#define MCG_C6_VDIV0_Div_29     (5 << 0)
#define MCG_C6_VDIV0_Div_30     (6 << 0)
#define MCG_C6_VDIV0_Div_31     (7 << 0)
#define MCG_C6_VDIV0_Div_32     (8 << 0)
#define MCG_C6_VDIV0_Div_33     (9 << 0)
#define MCG_C6_VDIV0_Div_34     (10 << 0)
#define MCG_C6_VDIV0_Div_35     (11 << 0)
#define MCG_C6_VDIV0_Div_36     (12 << 0)
#define MCG_C6_VDIV0_Div_37     (13 << 0)
#define MCG_C6_VDIV0_Div_38     (14 << 0)
#define MCG_C6_VDIV0_Div_39     (15 << 0)
#define MCG_C6_VDIV0_Div_40     (16 << 0)
#define MCG_C6_VDIV0_Div_41     (17 << 0)
#define MCG_C6_VDIV0_Div_42     (18 << 0)
#define MCG_C6_VDIV0_Div_43     (19 << 0)
#define MCG_C6_VDIV0_Div_44     (20 << 0)
#define MCG_C6_VDIV0_Div_45     (21 << 0)
#define MCG_C6_VDIV0_Div_46     (22 << 0)
#define MCG_C6_VDIV0_Div_47     (23 << 0)
#define MCG_C6_VDIV0_Div_48     (24 << 0)
#define MCG_C6_VDIV0_Div_49     (25 << 0)
#define MCG_C6_VDIV0_Div_50     (26 << 0)
#define MCG_C6_VDIV0_Div_51     (27 << 0)
#define MCG_C6_VDIV0_Div_52     (28 << 0)
#define MCG_C6_VDIV0_Div_53     (29 << 0)
#define MCG_C6_VDIV0_Div_54     (30 << 0)
#define MCG_C6_VDIV0_Div_55     (31 << 0)
#define MCG_C6_CME0_Disabled    (0 << 5)    //Clock monitor enable
#define MCG_C6_CME0_Enabled     (1 << 5)
#define MCG_C6_PLLS_FLL         (0 << 6)    //PLL select
#define MCG_C6_PLLS_PLL         (1 << 6)
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
#define MCG_S_PLLST_PLL           (1 << 5)
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
#define MCG_C7_OSCSEL_OSCCLK  (0 << 0)  //MCG OSC clock select
#define MCG_C7_OSCSEL_RTC     (1 << 0)

//Control 8 register bitfields
#define MCG_C8_LOLRE_Interrupt    (0 << 6)  //PLL loss of lock reset enable
#define MCG_C8_LOLRE_Reset        (1 << 6)

//Control 9 register bitfields
//(All fields reserved)

//Control 10 register bitfields
//(All fields reserved)

#endif //MKL26_MCG_H_
