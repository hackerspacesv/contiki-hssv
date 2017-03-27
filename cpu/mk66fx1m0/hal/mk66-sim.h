//+------------------------------------------------------------------------------------------------+
//| Kinetis MK66 SIM peripheral registers header.                                                  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_SIM_H_
#define MK66_SIM_H_

#include <stdint.h>

struct SIM_type {
  uint32_t SOPT1;             //System options register 1
  uint32_t SOPT1CFG;          //SOPT1 configuration register
  uint32_t USBPHYCTL;         //USB PHY control register
  uint32_t reserved0[1022];
  uint32_t SOPT2;             //System options register 2
  uint32_t reserved1;
  uint32_t SOPT4;             //System options register 4
  uint32_t SOPT5;             //System options register 5
  uint32_t reserved2;
  uint32_t SOPT7;             //System options register 7
  uint32_t SOPT8;             //System options register 8
  uint32_t SOPT9;             //System options register 9
  uint32_t SDID;              //System device identification register
  uint32_t SCGC1;             //System clock gating control register 1
  uint32_t SCGC2;             //System clock gating control register 2
  uint32_t SCGC3;             //System clock gating control register 3
  uint32_t SCGC4;             //System clock gating control register 4
  uint32_t SCGC5;             //System clock gating control register 5
  uint32_t SCGC6;             //System clock gating control register 6
  uint32_t SCGC7;             //System clock gating control register 7
  uint32_t CLKDIV1;           //System clock divider register 1
  uint32_t CLKDIV2;           //System clock divider register 2
  uint32_t FCFG1;             //Flash configuration register 1
  uint32_t FCFG2;             //Flash configuration register 2
  uint32_t UIDH;              //Unique identification register high
  uint32_t UIDMH;             //Unique identification register mid-high
  uint32_t UIDML;             //Unique identification register mid-low
  uint32_t UIDL;              //Unique identification register low
  uint32_t CLKDIV3;           //System clock divider register 3
  uint32_t CLKDIV4;           //System clock divider register 4
};

#define SIM ((volatile struct SIM_type *) 0x40047000)

//System options register 1 bitfields
#define SIM_SOPT1_RAMSIZE_8K            (1 << 12)   //RAM size
#define SIM_SOPT1_RAMSIZE_16K           (3 << 12)
#define SIM_SOPT1_RAMSIZE_24K           (4 << 12)
#define SIM_SOPT1_RAMSIZE_32K           (5 << 12)
#define SIM_SOPT1_RAMSIZE_48K           (6 << 12)
#define SIM_SOPT1_RAMSIZE_64K           (7 << 12)
#define SIM_SOPT1_RAMSIZE_96K           (8 << 12)
#define SIM_SOPT1_RAMSIZE_128K          (9 << 12)
#define SIM_SOPT1_RAMSIZE_256K          (11 << 12)
#define SIM_SOPT1_OSC32KSEL_OSC32KCLK   (0 << 18)   //32K oscillator clock select
#define SIM_SOPT1_OSC32KSEL_RTC         (2 << 18)
#define SIM_SOPT1_OSC32KSEL_LPO         (3 << 18)
#define SIM_SOPT1_USBVSTBY_No_Standby   (0 << 29)   //USB regulator standby (VLPR, VLPW)
#define SIM_SOPT1_USBVSTBY_Standby      (1 << 29)
#define SIM_SOPT1_USBSSTBY_No_Standby   (0 << 30)   //USB regulator standby (Stop, VLPS, LLS, VLLS)
#define SIM_SOPT1_USBSSTBY_Standby      (1 << 30)
#define SIM_SOPT1_USBREGEN_Disabled     (0 << 31)   //USB voltage regulator enable
#define SIM_SOPT1_USBREGEN_Enabled      (1 << 31)

//SOPT1 configuration register bitfields
#define SIM_SOPT1CFG_URWE_W_Disable   (0 << 24)   //USB voltage regulator enable write enable
#define SIM_SOPT1CFG_URWE_W_Enable    (1 << 24)
#define SIM_SOPT1CFG_UVSWE_W_Disable  (0 << 25)   //USB voltage regulator VLP standby write enable
#define SIM_SOPT1CFG_UVSWE_W_Enable   (1 << 25)
#define SIM_SOPT1CFG_USSWE_W_Disable  (0 << 26)   //USB voltage regulator stop standby write enable
#define SIM_SOPT1CFG_USSWE_W_Enable   (1 << 26)

//USB PHY control register bitfields
#define SIM_USBPHYCTL_USBVREGSEL_VREG_IN0   (0 << 8)    //Selects default input voltage source
#define SIM_USBPHYCTL_USBVREGSEL_VREG_IN1   (1 << 8)
#define SIM_USBPHYCTL_USBVREGPD_Disabled    (0 << 9)    //Enables the pulldown of the USB regulator
#define SIM_USBPHYCTL_USBVREGPD_Enabled     (1 << 9)
#define SIM_USBPHYCTL_USB3VOUTTRG_2_733     (0 << 20)   //USB 3.3V output target
#define SIM_USBPHYCTL_USB3VOUTTRG_3_020     (1 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_074     (2 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_130     (3 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_188     (4 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_248     (5 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_310     (6 << 20)
#define SIM_USBPHYCTL_USB3VOUTTRG_3_662     (7 << 20)
#define SIM_USBPHYCTL_USBDISILIM_Enabled    (0 << 23)   //USB disable inrush current limit
#define SIM_USBPHYCTL_USBDISILIM_Disabled   (1 << 23)

//System options register 2 bitfields
#define SIM_SOPT2_USBSLSRC_MCGIRCLK           (0 << 0)    //USB slow clock source
#define SIM_SOPT2_USBSLSRC_RTC                (1 << 0)
#define SIM_SOPT2_USBREGEN_Disabled           (0 << 1)    //USB PHY PLL regulator enable
#define SIM_SOPT2_USBREGEN_Enabled            (1 << 1)
#define SIM_SOPT2_RTCCLKOUTSEL_1Hz            (0 << 4)    //RTC clock out select
#define SIM_SOPT2_RTCCLKOUTSEL_32KHz          (1 << 4)
#define SIM_SOPT2_CLKOUTSEL_Flex_Bus          (0 << 5)    //CLKOUT select
#define SIM_SOPT2_CLKOUTSEL_Flash             (2 << 5)
#define SIM_SOPT2_CLKOUTSEL_LPO               (3 << 5)
#define SIM_SOPT2_CLKOUTSEL_MCGIRCLK          (4 << 5)
#define SIM_SOPT2_CLKOUTSEL_RTC               (5 << 5)
#define SIM_SOPT2_CLKOUTSEL_OSCERCLK0         (6 << 5)
#define SIM_SOPT2_CLKOUTSEL_IRC               (7 << 5)
#define SIM_SOPT2_FBSL_Disallow_All           (0 << 8)    //FlexBus security level
#define SIM_SOPT2_FBSL_Allow_Data             (2 << 8)
#define SIM_SOPT2_FBSL_Allow_All              (3 << 8)
#define SIM_SOPT2_TRACECLKSEL_MCGOUTCLK_Div   (0 << 12)   //Debug trace clock select
#define SIM_SOPT2_TRACECLKSEL_Core_System     (1 << 12)
#define SIM_SOPT2_PLLFLLSEL_MCGFLLCLK         (0 << 16)   //PLL/FLL clock select
#define SIM_SOPT2_PLLFLLSEL_MCGPLLCLK         (1 << 16)
#define SIM_SOPT2_PLLFLLSEL_USB1_PFD          (2 << 16)
#define SIM_SOPT2_PLLFLLSEL_IRC48             (3 << 16)
#define SIM_SOPT2_USBSRC_External             (0 << 18)   //USB clock source select
#define SIM_SOPT2_USBSRC_Internal             (1 << 18)
#define SIM_SOPT2_RMIISRC_EXTAL               (0 << 19)   //RMII clock source select
#define SIM_SOPT2_RMIISRC_External            (1 << 19)
#define SIM_SOPT2_TIMESRC_Core_System         (0 << 20)   //IEEE 1588 timestamp clock source select
#define SIM_SOPT2_TIMESRC_PLLFLLSEL           (1 << 20)
#define SIM_SOPT2_TIMESRC_OSCERCLK            (2 << 20)
#define SIM_SOPT2_TIMESRC_External            (3 << 20)
#define SIM_SOPT2_TPMSRC_Disabled             (0 << 24)   //TPM clock source select
#define SIM_SOPT2_TPMSRC_PLLFLLSEL_Div        (1 << 24)
#define SIM_SOPT2_TPMSRC_OSCERCLK             (2 << 24)
#define SIM_SOPT2_TPMSRC_MCGIRCLK             (3 << 24)
#define SIM_SOPT2_LPUARTSRC_Disabled          (0 << 26)   //LPUART clock source select
#define SIM_SOPT2_LPUARTSRC_PLLFLLSEL_Div     (1 << 26)
#define SIM_SOPT2_LPUARTSRC_OSCERCLK          (2 << 26)
#define SIM_SOPT2_LPUARTSRC_MCGIRCLK          (3 << 26)
#define SIM_SOPT2_SDHCSRC_Core_System         (0 << 28)   //SDHC clock source select
#define SIM_SOPT2_SDHCSRC_PLLFLLSEL           (1 << 28)
#define SIM_SOPT2_SDHCSRC_OSCERCLK            (2 << 28)
#define SIM_SOPT2_SDHCSRC_External            (3 << 28)

//System options register 4 bitfields
#define SIM_SOPT4_FTM0FLT0_FTM0_FLT0    (0 << 0)    //FTM0 fault 0 select
#define SIM_SOPT4_FTM0FLT0_CMP0         (1 << 0)
#define SIM_SOPT4_FTM0FLT1_FTM0_FLT1    (0 << 1)    //FTM0 fault 1 select
#define SIM_SOPT4_FTM0FLT1_CMP1         (1 << 1)
#define SIM_SOPT4_FTM0FLT2_FTM0_FLT2    (0 << 2)    //FTM0 fault 2 select
#define SIM_SOPT4_FTM0FLT2_CMP2         (1 << 2)
#define SIM_SOPT4_FTM0FLT3_FTM0_FLT3    (0 << 3)    //FTM0 fault 3 select
#define SIM_SOPT4_FTM0FLT3_CMP3         (1 << 3)
#define SIM_SOPT4_FTM1FLT0_FTM1_FLT0    (0 << 4)    //FTM1 fault 0 select
#define SIM_SOPT4_FTM1FLT0_CMP0         (1 << 4)
#define SIM_SOPT4_FTM2FLT0_FTM2_FLT0    (0 << 8)    //FTM2 fault 0 select
#define SIM_SOPT4_FTM2FLT0_CMP0         (1 << 8)
#define SIM_SOPT4_FTM3FLT0_FTM3_FLT0    (0 << 12)   //FTM3 fault 0 select
#define SIM_SOPT4_FTM3FLT0_CMP0         (1 << 12)
#define SIM_SOPT4_FTM1CH0SRC_FTM1_CH0   (0 << 18)   //FTM1 channel 0 input capture source select
#define SIM_SOPT4_FTM1CH0SRC_CMP0       (1 << 18)
#define SIM_SOPT4_FTM1CH0SRC_CMP1       (2 << 18)
#define SIM_SOPT4_FTM1CH0SRC_USB        (3 << 18)
#define SIM_SOPT4_FTM2CH0SRC_FTM2_CH0   (0 << 20)   //FTM2 channel 0 input capture source select
#define SIM_SOPT4_FTM2CH0SRC_CMP0       (1 << 20)
#define SIM_SOPT4_FTM2CH0SRC_CMP1       (2 << 20)
#define SIM_SOPT4_FTM2CH1SRC_FTM2_CH1   (0 << 22)   //FTM2 channel 1 input capture source select
#define SIM_SOPT4_FTM2CH1SRC_EOR_Mix    (1 << 22)
#define SIM_SOPT4_FTM0CLKSEL_FTM_CLK0   (0 << 24)   //FTM0 external clock pin select
#define SIM_SOPT4_FTM0CLKSEL_FTM_CLK1   (1 << 24)
#define SIM_SOPT4_FTM1CLKSEL_FTM_CLK0   (0 << 25)   //FTM1 external clock pin select
#define SIM_SOPT4_FTM1CLKSEL_FTM_CLK1   (1 << 25)
#define SIM_SOPT4_FTM2CLKSEL_FTM_CLK0   (0 << 26)   //FTM2 external clock pin select
#define SIM_SOPT4_FTM2CLKSEL_FTM_CLK1   (1 << 26)
#define SIM_SOPT4_FTM3CLKSEL_FTM_CLK0   (0 << 27)   //FTM3 external clock pin select
#define SIM_SOPT4_FTM3CLKSEL_FTM_CLK1   (1 << 27)
#define SIM_SOPT4_FTM0TRG0SRC_HSCMP0    (0 << 28)   //FTM0 hardware trigger 0 source select
#define SIM_SOPT4_FTM0TRG0SRC_FTM1      (1 << 28)
#define SIM_SOPT4_FTM0TRG1SRC_PDB       (0 << 29)   //FTM0 hardware trigger 1 source select
#define SIM_SOPT4_FTM0TRG1SRC_FTM2      (1 << 29)
#define SIM_SOPT4_FTM3TRG0SRC_FTM1      (1 << 30)   //FTM3 hardware trigger 0 source select
#define SIM_SOPT4_FTM3TRG1SRC_FTM2      (1 << 31)   //FTM3 hardware trigger 1 source select

//System options register 5 bitfields
#define SIM_SOPT5_UART0TXSRC_TX_Pin     (0 << 0)    //UART 0 transmit data source select
#define SIM_SOPT5_UART0TXSRC_TX_FTM1    (1 << 0)
#define SIM_SOPT5_UART0TXSRC_TX_FTM2    (2 << 0)
#define SIM_SOPT5_UART0RXSRC_RX_Pin     (0 << 2)    //UART 0 receive data source select
#define SIM_SOPT5_UART0RXSRC_CMP0       (1 << 2)
#define SIM_SOPT5_UART0RXSRC_CMP1       (2 << 2)
#define SIM_SOPT5_UART1TXSRC_TX_Pin     (0 << 4)    //UART 1 transmit data source select
#define SIM_SOPT5_UART1TXSRC_TX_FTM1    (1 << 4)
#define SIM_SOPT5_UART1TXSRC_TX_FTM2    (2 << 4)
#define SIM_SOPT5_UART1RXSRC_RX_Pin     (0 << 6)    //UART 1 receive data source select
#define SIM_SOPT5_UART1RXSRC_CMP0       (1 << 6)
#define SIM_SOPT5_UART1RXSRC_CMP1       (2 << 6)
#define SIM_SOPT5_LPUART0TXSRC_TX_Pin   (0 << 16)   //LPUART0 transmit data source select
#define SIM_SOPT5_LPUART0TXSRC_TPM1     (1 << 16)
#define SIM_SOPT5_LPUART0TXSRC_TPM2     (2 << 16)
#define SIM_SOPT5_LPUART0RXSRC_RX_Pin   (0 << 18)   //LPUART0 receive data source select
#define SIM_SOPT5_LPUART0RXSRC_CMP0     (1 << 18)
#define SIM_SOPT5_LPUART0RXSRC_CMP1     (2 << 18)

//System options register 7 bitfields
#define SIM_SOPT7_ADC0TRGSEL_PDB          (0 << 0)    //ADC0 trigger select
#define SIM_SOPT7_ADC0TRGSEL_CMP0         (1 << 0)
#define SIM_SOPT7_ADC0TRGSEL_CMP1         (2 << 0)
#define SIM_SOPT7_ADC0TRGSEL_CMP2         (3 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT0         (4 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT1         (5 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT2         (6 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT3         (7 << 0)
#define SIM_SOPT7_ADC0TRGSEL_FTM0         (8 << 0)
#define SIM_SOPT7_ADC0TRGSEL_FTM1         (9 << 0)
#define SIM_SOPT7_ADC0TRGSEL_FTM2         (10 << 0)
#define SIM_SOPT7_ADC0TRGSEL_FTM3         (11 << 0)
#define SIM_SOPT7_ADC0TRGSEL_RTC_Alarm    (12 << 0)
#define SIM_SOPT7_ADC0TRGSEL_RTC_Seconds  (13 << 0)
#define SIM_SOPT7_ADC0TRGSEL_LPTMR        (14 << 0)
#define SIM_SOPT7_ADC0TRGSEL_TPM1         (15 << 0)
#define SIM_SOPT7_ADC0PRETRGSEL_A         (0 << 4)    //ADC0 pretrigger select
#define SIM_SOPT7_ADC0PRETRGSEL_B         (1 << 4)
#define SIM_SOPT7_ADC0ALTTRGEN_PDB        (0 << 7)    //ADC0 alternate trigger enable
#define SIM_SOPT7_ADC0ALTTRGEN_Alt        (1 << 7)
#define SIM_SOPT7_ADC1TRGSEL_PDB          (0 << 8)    //ADC1 trigger select
#define SIM_SOPT7_ADC1TRGSEL_CMP0         (1 << 8)
#define SIM_SOPT7_ADC1TRGSEL_CMP1         (2 << 8)
#define SIM_SOPT7_ADC1TRGSEL_CMP2         (3 << 8)
#define SIM_SOPT7_ADC1TRGSEL_PIT0         (4 << 8)
#define SIM_SOPT7_ADC1TRGSEL_PIT1         (5 << 8)
#define SIM_SOPT7_ADC1TRGSEL_PIT2         (6 << 8)
#define SIM_SOPT7_ADC1TRGSEL_PIT3         (7 << 8)
#define SIM_SOPT7_ADC1TRGSEL_FTM0         (8 << 8)
#define SIM_SOPT7_ADC1TRGSEL_FTM1         (9 << 8)
#define SIM_SOPT7_ADC1TRGSEL_FTM2         (10 << 8)
#define SIM_SOPT7_ADC1TRGSEL_FTM3         (11 << 8)
#define SIM_SOPT7_ADC1TRGSEL_RTC_Alarm    (12 << 8)
#define SIM_SOPT7_ADC1TRGSEL_RTC_Seconds  (13 << 8)
#define SIM_SOPT7_ADC1TRGSEL_LPTMR        (14 << 8)
#define SIM_SOPT7_ADC1TRGSEL_TPM2         (15 << 8)
#define SIM_SOPT7_ADC1PRETRGSEL_A         (0 << 12)   //ADC1 pretrigger select
#define SIM_SOPT7_ADC1PRETRGSEL_B         (1 << 12)
#define SIM_SOPT7_ADC1ALTTRGEN_PDB        (0 << 15)   //ADC1 alternate trigger enable
#define SIM_SOPT7_ADC1ALTTRGEN_Alt        (1 << 15)

//System options register 8 bitfields
#define SIM_SOPT8_FTM0SYNCBIT_Clear     (0 << 0)    //FTM0 hardware trigger 0 software sync
#define SIM_SOPT8_FTM0SYNCBIT_Set       (1 << 0)
#define SIM_SOPT8_FTM1SYNCBIT_Clear     (0 << 1)    //FTM1 hardware trigger 0 software sync
#define SIM_SOPT8_FTM1SYNCBIT_Set       (1 << 1)
#define SIM_SOPT8_FTM2SYNCBIT_Clear     (0 << 2)    //FTM2 hardware trigger 0 software sync
#define SIM_SOPT8_FTM2SYNCBIT_Set       (1 << 2)
#define SIM_SOPT8_FTM3SYNCBIT_Clear     (0 << 3)    //FTM3 hardware trigger 0 software sync
#define SIM_SOPT8_FTM3SYNCBIT_Set       (1 << 3)
#define SIM_SOPT8_FTM0OCH0SRC_Normal    (0 << 16)   //FTM0 channel 0 output source
#define SIM_SOPT8_FTM0OCH0SRC_Mod_FTM1  (1 << 16)
#define SIM_SOPT8_FTM0OCH1SRC_Normal    (0 << 17)   //FTM0 channel 1 output source
#define SIM_SOPT8_FTM0OCH1SRC_Mod_FTM1  (1 << 17)
#define SIM_SOPT8_FTM0OCH2SRC_Normal    (0 << 18)   //FTM0 channel 2 output source
#define SIM_SOPT8_FTM0OCH2SRC_Mod_FTM1  (1 << 18)
#define SIM_SOPT8_FTM0OCH3SRC_Normal    (0 << 19)   //FTM0 channel 3 output source
#define SIM_SOPT8_FTM0OCH3SRC_Mod_FTM1  (1 << 19)
#define SIM_SOPT8_FTM0OCH4SRC_Normal    (0 << 20)   //FTM0 channel 4 output source
#define SIM_SOPT8_FTM0OCH4SRC_Mod_FTM1  (1 << 20)
#define SIM_SOPT8_FTM0OCH5SRC_Normal    (0 << 21)   //FTM0 channel 5 output source
#define SIM_SOPT8_FTM0OCH5SRC_Mod_FTM1  (1 << 21)
#define SIM_SOPT8_FTM0OCH6SRC_Normal    (0 << 22)   //FTM0 channel 6 output source
#define SIM_SOPT8_FTM0OCH6SRC_Mod_FTM1  (1 << 22)
#define SIM_SOPT8_FTM0OCH7SRC_Normal    (0 << 23)   //FTM0 channel 7 output source
#define SIM_SOPT8_FTM0OCH7SRC_Mod_FTM1  (1 << 23)
#define SIM_SOPT8_FTM3OCH0SRC_Normal    (0 << 24)   //FTM3 channel 0 output source
#define SIM_SOPT8_FTM3OCH0SRC_Mod_FTM2  (1 << 24)
#define SIM_SOPT8_FTM3OCH1SRC_Normal    (0 << 25)   //FTM3 channel 1 output source
#define SIM_SOPT8_FTM3OCH1SRC_Mod_FTM2  (1 << 25)
#define SIM_SOPT8_FTM3OCH2SRC_Normal    (0 << 26)   //FTM3 channel 2 output source
#define SIM_SOPT8_FTM3OCH2SRC_Mod_FTM2  (1 << 26)
#define SIM_SOPT8_FTM3OCH3SRC_Normal    (0 << 27)   //FTM3 channel 3 output source
#define SIM_SOPT8_FTM3OCH3SRC_Mod_FTM2  (1 << 27)
#define SIM_SOPT8_FTM3OCH4SRC_Normal    (0 << 28)   //FTM3 channel 4 output source
#define SIM_SOPT8_FTM3OCH4SRC_Mod_FTM2  (1 << 28)
#define SIM_SOPT8_FTM3OCH5SRC_Normal    (0 << 29)   //FTM3 channel 5 output source
#define SIM_SOPT8_FTM3OCH5SRC_Mod_FTM2  (1 << 29)
#define SIM_SOPT8_FTM3OCH6SRC_Normal    (0 << 30)   //FTM3 channel 6 output source
#define SIM_SOPT8_FTM3OCH6SRC_Mod_FTM2  (1 << 30)
#define SIM_SOPT8_FTM3OCH7SRC_Normal    (0 << 31)   //FTM3 channel 7 output source
#define SIM_SOPT8_FTM3OCH7SRC_Mod_FTM2  (1 << 31)

//System options register 9 bitfields
#define SIM_SOPT9_TPM1CH0SRC_TPM1     (0 << 18)   //TPM1 channel 0 input capture source select
#define SIM_SOPT9_TPM1CH0SRC_CMP0     (1 << 18)
#define SIM_SOPT9_TPM1CH0SRC_CMP1     (2 << 18)
#define SIM_SOPT9_TPM2CH0SRC_TPM2     (0 << 20)   //TPM2 channel 0 input capture source select
#define SIM_SOPT9_TPM2CH0SRC_CMP0     (1 << 20)
#define SIM_SOPT9_TPM2CH0SRC_CMP1     (2 << 20)
#define SIM_SOPT9_TPM1CLKSEL_CLKIN0   (0 << 25)   //TPM1 external clock pin select
#define SIM_SOPT9_TPM1CLKSEL_CLKIN1   (1 << 25)
#define SIM_SOPT9_TPM2CLKSEL_CLKIN0   (0 << 26)   //TPM2 external clock pin select
#define SIM_SOPT9_TPM2CLKSEL_CLKIN1   (1 << 26)

//System device identification register bitfields
#define SIM_SDID_PINID_Msk      0x0000000F  //Pincount identification
#define SIM_SDID_PINID_Pos      0
#define SIM_SDID_FAMID_Msk      0x00000070  //Kinetis family identification (obsolete)
#define SIM_SDID_FAMID_Pos      4
#define SIM_SDID_DIEID_Msk      0x00000F80  //Device die ID
#define SIM_SDID_DIEID_Pos      7
#define SIM_SDID_REVID_Msk      0x0000F000  //Device revision number
#define SIM_SDID_REVID_Pos      12
#define SIM_SDID_SERIESID_Msk   0x00F00000  //Kinetis series ID
#define SIM_SDID_SERIESID_Pos   20
#define SIM_SDID_SUBFAMID_Msk   0x0F000000  //Kinetis sub-family ID
#define SIM_SDID_SUBFAMID_Pos   24
#define SIM_SDID_FAMILYID_Msk   0xF0000000  //Kinetis family ID
#define SIM_SDID_FAMILYID_Pos   28

//System clock gating control register 1 bitfields
#define SIM_SCGC1_I2C2_Disabled   (0 << 6)    //I2C2 clock gate control
#define SIM_SCGC1_I2C2_Enabled    (1 << 6)
#define SIM_SCGC1_I2C3_Disabled   (0 << 7)    //I2C3 clock gate control
#define SIM_SCGC1_I2C3_Enabled    (1 << 7)
#define SIM_SCGC1_UART4_Disabled  (0 << 10)   //UART4 clock gate control
#define SIM_SCGC1_UART4_Enabled   (1 << 10)

//System clock gating control register 2 bitfields
#define SIM_SCGC2_ENET_Disabled     (0 << 0)    //ENET clock gate control
#define SIM_SCGC2_ENET_Enabled      (1 << 0)
#define SIM_SCGC2_LPUART0_Disabled  (0 << 4)    //LPUART0 clock gate control
#define SIM_SCGC2_LPUART0_Enabled   (1 << 4)
#define SIM_SCGC2_TPM1_Disabled     (0 << 9)    //TPM1 clock gate control
#define SIM_SCGC2_TPM1_Enabled      (1 << 9)
#define SIM_SCGC2_TPM2_Disabled     (0 << 10)   //TPM2 clock gate control
#define SIM_SCGC2_TPM2_Enabled      (1 << 10)
#define SIM_SCGC2_DAC0_Disabled     (0 << 12)   //DAC0 clock gate control
#define SIM_SCGC2_DAC0_Enabled      (1 << 12)
#define SIM_SCGC2_DAC1_Disabled     (0 << 13)   //DAC1 clock gate control
#define SIM_SCGC2_DAC1_Enabled      (1 << 13)

//System clock gating control register 3 bitfields
#define SIM_SCGC3_RNGA_Disabled       (0 << 0)    //RNGA clock gate control
#define SIM_SCGC3_RNGA_Enabled        (1 << 0)
#define SIM_SCGC3_USBHS_Disabled      (0 << 1)    //USBHS clock gate control
#define SIM_SCGC3_USBHS_Enabled       (1 << 1)
#define SIM_SCGC3_USBHSPHY_Disabled   (0 << 2)    //USBHS PHY clock gate control
#define SIM_SCGC3_USBHSPHY_Enabled    (1 << 2)
#define SIM_SCGC3_USBHSDCD_Disabled   (0 << 3)    //USBHS DCD clock gate control
#define SIM_SCGC3_USBHSDCD_Enabled    (1 << 3)
#define SIM_SCGC3_FLEXCAN1_Disabled   (0 << 4)    //FLEXCAN1 clock gate control
#define SIM_SCGC3_FLEXCAN1_Enabled    (1 << 4)
#define SIM_SCGC3_SPI2_Disabled       (0 << 12)   //SPI2 clock gate control
#define SIM_SCGC3_SPI2_Enabled        (1 << 12)
#define SIM_SCGC3_SDHC_Disabled       (0 << 17)   //SDHC clock gate control
#define SIM_SCGC3_SDHC_Enabled        (1 << 17)
#define SIM_SCGC3_FTM2_Disabled       (0 << 24)   //FTM2 clock gate control
#define SIM_SCGC3_FTM2_Enabled        (1 << 24)
#define SIM_SCGC3_FTM3_Disabled       (0 << 25)   //FTM3 clock gate control
#define SIM_SCGC3_FTM3_Enabled        (1 << 25)
#define SIM_SCGC3_ADC1_Disabled       (0 << 27)   //ADC1 clock gate control
#define SIM_SCGC3_ADC1_Enabled        (1 << 27)

//System clock gating control register 4 bitfields
#define SIM_SCGC4_EWM_Disabled      (0 << 1)    //EWM clock gate control
#define SIM_SCGC4_EWM_Enabled       (1 << 1)
#define SIM_SCGC4_CMT_Disabled      (0 << 2)    //CMT clock gate control
#define SIM_SCGC4_CMT_Enabled       (1 << 2)
#define SIM_SCGC4_I2C0_Disabled     (0 << 6)    //I2C0 clock gate control
#define SIM_SCGC4_I2C0_Enabled      (1 << 6)
#define SIM_SCGC4_I2C1_Disabled     (0 << 7)    //I2C1 clock gate control
#define SIM_SCGC4_I2C1_Enabled      (1 << 7)
#define SIM_SCGC4_UART0_Disabled    (0 << 10)   //UART0 clock gate control
#define SIM_SCGC4_UART0_Enabled     (1 << 10)
#define SIM_SCGC4_UART1_Disabled    (0 << 11)   //UART1 clock gate control
#define SIM_SCGC4_UART1_Enabled     (1 << 11)
#define SIM_SCGC4_UART2_Disabled    (0 << 12)   //UART2 clock gate control
#define SIM_SCGC4_UART2_Enabled     (1 << 12)
#define SIM_SCGC4_UART3_Disabled    (0 << 13)   //UART3 clock gate control
#define SIM_SCGC4_UART3_Enabled     (1 << 13)
#define SIM_SCGC4_USBOTG_Disabled   (0 << 18)   //USBOTG clock gate control
#define SIM_SCGC4_USBOTG_Enabled    (1 << 18)
#define SIM_SCGC4_CMP_Disabled      (0 << 19)   //CMP clock gate control
#define SIM_SCGC4_CMP_Enabled       (1 << 19)
#define SIM_SCGC4_VREF_Disabled     (0 << 20)   //VREF clock gate control
#define SIM_SCGC4_VREF_Enabled      (1 << 20)

//System clock gating control register 5 bitfields
#define SIM_SCGC5_LPTMR_Disabled  (0 << 0)    //Low power timer access control
#define SIM_SCGC5_LPTMR_Enabled   (1 << 0)
#define SIM_SCGC5_TSI_Disabled    (0 << 5)    //TSI clock gate control
#define SIM_SCGC5_TSI_Enabled     (1 << 5)
#define SIM_SCGC5_PORTA_Disabled  (0 << 9)    //Port A clock gate control
#define SIM_SCGC5_PORTA_Enabled   (1 << 9)
#define SIM_SCGC5_PORTB_Disabled  (0 << 10)   //Port B clock gate control
#define SIM_SCGC5_PORTB_Enabled   (1 << 10)
#define SIM_SCGC5_PORTC_Disabled  (0 << 11)   //Port C clock gate control
#define SIM_SCGC5_PORTC_Enabled   (1 << 11)
#define SIM_SCGC5_PORTD_Disabled  (0 << 12)   //Port D clock gate control
#define SIM_SCGC5_PORTD_Enabled   (1 << 12)
#define SIM_SCGC5_PORTE_Disabled  (0 << 13)   //Port E clock gate control
#define SIM_SCGC5_PORTE_Enabled   (1 << 13)

//System clock gating control register 6 bitfields
#define SIM_SCGC6_FTF_Disabled        (0 << 0)    //Flash memory clock gate control
#define SIM_SCGC6_FTF_Enabled         (1 << 0)
#define SIM_SCGC6_DMAMUX_Disabled     (0 << 1)    //DMA mux clock gate control
#define SIM_SCGC6_DMAMUX_Enabled      (1 << 1)
#define SIM_SCGC6_FLEXCAN0_Disabled   (0 << 4)    //FlexCAN0 clock gate control
#define SIM_SCGC6_FLEXCAN0_Enabled    (1 << 4)
#define SIM_SCGC6_RNGA_Disabled       (0 << 9)    //RNGA clock gate control
#define SIM_SCGC6_RNGA_Enabled        (1 << 9)
#define SIM_SCGC6_SPI0_Disabled       (0 << 12)   //SPI0 clock gate control
#define SIM_SCGC6_SPI0_Enabled        (1 << 12)
#define SIM_SCGC6_SPI1_Disabled       (0 << 13)   //SPI1 clock gate control
#define SIM_SCGC6_SPI1_Enabled        (1 << 13)
#define SIM_SCGC6_I2S_Disabled        (0 << 15)   //I2S clock gate control
#define SIM_SCGC6_I2S_Enabled         (1 << 15)
#define SIM_SCGC6_CRC_Disabled        (0 << 18)   //CRC clock gate control
#define SIM_SCGC6_CRC_Enabled         (1 << 18)
#define SIM_SCGC6_USBDCD_Disabled     (0 << 21)   //USB DCD clock gate control
#define SIM_SCGC6_USBDCD_Enabled      (1 << 21)
#define SIM_SCGC6_PDB_Disabled        (0 << 22)   //PDB clock gate control
#define SIM_SCGC6_PDB_Enabled         (1 << 22)
#define SIM_SCGC6_PIT_Disabled        (0 << 23)   //PIT clock gate control
#define SIM_SCGC6_PIT_Enabled         (1 << 23)
#define SIM_SCGC6_FTM0_Disabled       (0 << 24)   //FTM0 clock gate control
#define SIM_SCGC6_FTM0_Enabled        (1 << 24)
#define SIM_SCGC6_FTM1_Disabled       (0 << 25)   //FTM1 clock gate control
#define SIM_SCGC6_FTM1_Enabled        (1 << 25)
#define SIM_SCGC6_FTM2_Disabled       (0 << 26)   //FTM2 clock gate control
#define SIM_SCGC6_FTM2_Enabled        (1 << 26)
#define SIM_SCGC6_ADC0_Disabled       (0 << 27)   //ADC0 clock gate control
#define SIM_SCGC6_ADC0_Enabled        (1 << 27)
#define SIM_SCGC6_RTC_Disabled        (0 << 29)   //RTC access control
#define SIM_SCGC6_RTC_Enabled         (1 << 29)
#define SIM_SCGC6_DAC0_Disabled       (0 << 30)   //DAC0 clock gate control
#define SIM_SCGC6_DAC0_Enabled        (1 << 31)

//System clock gating control register 7 bitfields
#define SIM_SCGC7_FLEXBUS_Disabled  (0 << 0)  //FlexBus clock gate control
#define SIM_SCGC7_FLEXBUS_Enabled   (1 << 0)
#define SIM_SCGC7_DMA_Disabled      (0 << 1)  //DMA clock gate control
#define SIM_SCGC7_DMA_Enabled       (1 << 1)
#define SIM_SCGC7_MPU_Disabled      (0 << 2)  //MPU clock gate control
#define SIM_SCGC7_MPU_Enabled       (1 << 2)
#define SIM_SCGC7_SDRAMC_Disabled   (0 << 3)  //SDRAMC clock gate control
#define SIM_SCGC7_SDRAMC_Enabled    (1 << 3)

//System clock divider register 1 bitfields
#define SIM_CLKDIV1_OUTDIV4_Msk   0x000F0000  //Clock 4 output divider value
#define SIM_CLKDIV1_OUTDIV4_Pos   16
#define SIM_CLKDIV1_OUTDIV3_Msk   0x00F00000  //Clock 3 output divider value
#define SIM_CLKDIV1_OUTDIV3_Pos   20
#define SIM_CLKDIV1_OUTDIV2_Msk   0x0F000000  //Clock 2 output divider value
#define SIM_CLKDIV1_OUTDIV2_Pos   24
#define SIM_CLKDIV1_OUTDIV1_Msk   0xF0000000  //Clock 1 output divider value
#define SIM_CLKDIV1_OUTDIV1_Pos   28

//System clock divider register 2 bitfields
#define SIM_CLKDIV2_USBFRAC_Msk   0x00000001  //USB clock divider fraction
#define SIM_CLKDIV2_USBFRAC_Pos   0
#define SIM_CLKDIV2_USBDIV_Msk    0x0000000E  //USB clock divider divisor
#define SIM_CLKDIV2_USBDIV_Pos    1

//Flash configuration register 1 bitfields
#define SIM_FCFG1_FLASHDIS_Enabled    (0 << 0)    //Flash disable
#define SIM_FCFG1_FLASHDIS_Disabled   (1 << 0)
#define SIM_FCFG1_FLASHDOZE_EnWait    (0 << 1)    //Flash doze
#define SIM_FCFG1_FLASHDOZE_DisWait   (1 << 1)
#define SIM_FCFG1_DEPART_Msk          0x00000F00  //FlexNVM partition
#define SIM_FCFG1_DEPART_Pos          8
#define SIM_FCFG1_EESIZE_16K          (0 << 16)   //EEPROM size
#define SIM_FCFG1_EESIZE_8K           (1 << 16)
#define SIM_FCFG1_EESIZE_4K           (2 << 16)
#define SIM_FCFG1_EESIZE_2K           (3 << 16)
#define SIM_FCFG1_EESIZE_1K           (4 << 16)
#define SIM_FCFG1_EESIZE_512          (5 << 16)
#define SIM_FCFG1_EESIZE_256          (6 << 16)
#define SIM_FCFG1_EESIZE_128          (7 << 16)
#define SIM_FCFG1_EESIZE_64           (8 << 16)
#define SIM_FCFG1_EESIZE_32           (9 << 16)
#define SIM_FCFG1_EESIZE_0            (15 << 16)
#define SIM_FCFG1_PFSIZE_32K          (3 << 24)   //Program flash size
#define SIM_FCFG1_PFSIZE_64K          (5 << 24)
#define SIM_FCFG1_PFSIZE_128K         (7 << 24)
#define SIM_FCFG1_PFSIZE_256K         (9 << 24)
#define SIM_FCFG1_PFSIZE_512K         (11 << 24)
#define SIM_FCFG1_PFSIZE_1M           (13 << 24)
#define SIM_FCFG1_PFSIZE_2M           (15 << 24)
#define SIM_FCFG1_NVMSIZE_0           (0 << 28)   //FlexNVM size
#define SIM_FCFG1_NVMSIZE_32K         (3 << 28)
#define SIM_FCFG1_NVMSIZE_64K         (5 << 28)
#define SIM_FCFG1_NVMSIZE_128K        (7 << 28)
#define SIM_FCFG1_NVMSIZE_256K        (9 << 28)
#define SIM_FCFG1_NVMSIZE_512K        (11 << 28)
//Note:There seems to be a typo in the device datasheet. 256K capacity for NVMSIZE is listed twice.

//Flash configuration register 2 bitfields
#define SIM_FCFG2_MAXADDR1_Msk        0x007F0000  //Max address block 1
#define SIM_FCFG2_MAXADDR1_Pos        16
#define SIM_FCFG2_PFLSH_FlexNVM       (0 << 23)   //Program flash only
#define SIM_FCFG2_PFLSH_FlashOnly     (1 << 23)
#define SIM_FCFG2_MAXADDR0_Msk        0x7F000000  //Max address block 0
#define SIM_FCFG2_MAXADDR0_Pos        24
#define SIM_FCFG2_SWAPPFLSH_Inactive  (0 << 31)   //Swap program flash
#define SIM_FCFG2_SWAPPFLSH_Active    (1 << 31)

//System clock divider register 3 bitfields
#define SIM_CLKDIV3_PLLFLLFRAC_Msk  0x00000001  //PLLFLL clock divider fraction
#define SIM_CLKDIV3_PLLFLLFRAC_Pos  0
#define SIM_CLKDIV3_PLLFLLDIV_Msk   0x0000000E  //PLLFLL clock divider divisor
#define SIM_CLKDIV3_PLLFLLDIV_Pos   1

//System clock divider register 4 bitfields
#define SIM_CLKDIV4_TRACEFRAC_Msk  0x00000001   //Trace clock divider fraction
#define SIM_CLKDIV4_TRACEFRAC_Pos  0
#define SIM_CLKDIV4_TRACEDIV_Msk   0x0000000E   //Trace clock divider divisor
#define SIM_CLKDIV4_TRACEDIV_Pos   1

#endif //MK66_SIM_H_
