//+------------------------------------------------------------------------------------------------+
//| SIM peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_SIM_H_
#define MKL26_SIM_H_

#include <stdint.h>

struct SIM_type {
  uint32_t SOPT1;             //System options register 1
  uint32_t SOPT1CFG;          //SOPT1 configuration register
  uint32_t reserved0[1023];
  uint32_t SOPT2;             //System options register 2
  uint32_t reserved1;
  uint32_t SOPT4;             //System options register 4
  uint32_t SOPT5;             //System options register 5
  uint32_t reserved2;
  uint32_t SOPT7;             //System options register 7
  uint32_t reserved3[2];
  uint32_t SDID;              //System device identification register
  uint32_t reserved4[3];
  uint32_t SCGC4;             //System clock gating control register 4
  uint32_t SCGC5;             //System clock gating control register 5
  uint32_t SCGC6;             //System clock gating control register 6
  uint32_t SCGC7;             //System clock gating control register 7
  uint32_t CLKDIV1;           //System clock divider register 1
  uint32_t reserved5;
  uint32_t FCFG1;             //Flash configuration register 1
  uint32_t FCFG2;             //Flash configuration register 2
  uint32_t reserved6;
  uint32_t UIDMH;             //Unique identification register mid-high
  uint32_t UIDML;             //Unique identification register mid-low
  uint32_t UIDL;              //Unique identification register low
  uint32_t reserved7[39];
  uint32_t COPC;              //COP control register
  uint32_t SRVCOP;            //Service COP
};

#define SIM ((volatile struct SIM_type *) 0x40047000)

//System options register 1 bitfields
#define SIM_SOPT1_OSC32KSEL_OSC32KCLK   (0 << 18)   //32K oscillator clock select
#define SIM_SOPT1_OSC32KSEL_RTC_CLKIN   (2 << 18)
#define SIM_SOPT1_OSC32KSEL_LPO_1kHz    (3 << 18)
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

//System options register 2 bitfields
#define SIM_SOPT2_RTCCLKOUTSEL_1Hz            (0 << 4)    //RTC clock out select
#define SIM_SOPT2_RTCCLKOUTSEL_OSCERCLK       (1 << 4)
#define SIM_SOPT2_CLKOUTSEL_Bus               (2 << 5)    //CLKOUT select
#define SIM_SOPT2_CLKOUTSEL_LPO               (3 << 5)
#define SIM_SOPT2_CLKOUTSEL_MCGIRCLK          (4 << 5)
#define SIM_SOPT2_CLKOUTSEL_OSCERCLK          (6 << 5)
#define SIM_SOPT2_PLLFLLSEL_MCGFLLCLK         (0 << 16)   //PLL/FLL clock select
#define SIM_SOPT2_PLLFLLSEL_MCGPLLCLK_Div2    (1 << 16)
#define SIM_SOPT2_USBSRC_External             (0 << 18)   //USB clock source select
#define SIM_SOPT2_USBSRC_FLL_PLL_Div2         (1 << 18)
#define SIM_SOPT2_TPMSRC_Disabled             (0 << 24)   //TPM clock source select
#define SIM_SOPT2_TPMSRC_FLL_PLL_Div2         (1 << 24)
#define SIM_SOPT2_TPMSRC_OSCERCLK             (2 << 24)
#define SIM_SOPT2_TPMSRC_MCGIRCLK             (3 << 24)
#define SIM_SOPT2_UART0SRC_Disabled           (0 << 26)   //UART 0 clock source select
#define SIM_SOPT2_UART0SRC_FLL_PLL_Div2       (1 << 26)
#define SIM_SOPT2_UART0SRC_OSCERCLK           (2 << 26)
#define SIM_SOPT2_UART0SRC_MCGIRCLK           (3 << 26)

//System options register 4 bitfields
#define SIM_SOPT4_TPM1CH0SRC_TPM1_CH0     (0 << 18)   //TPM1 channel 0 input capture source select
#define SIM_SOPT4_TPM1CH0SRC_CMP0         (1 << 18)
#define SIM_SOPT4_TPM1CH0SRC_USB          (3 << 18)
#define SIM_SOPT4_TPM2CH0SRC_TPM2_CH0     (0 << 20)   //TPM2 channel 0 input capture source select
#define SIM_SOPT4_TPM2CH0SRC_CMP0         (1 << 20)
#define SIM_SOPT4_TPM0CLKSEL_TPM_CLKIN0   (0 << 24)   //TPM0 external clock pin select
#define SIM_SOPT4_TPM0CLKSEL_TPM_CLKIN1   (1 << 24)
#define SIM_SOPT4_TPM1CLKSEL_TPM_CLKIN0   (0 << 25)   //TPM1 external clock pin select
#define SIM_SOPT4_TPM1CLKSEL_TPM_CLKIN1   (1 << 25)
#define SIM_SOPT4_TPM2CLKSEL_TPM_CLKIN0   (0 << 26)   //TPM2 external clock pin select
#define SIM_SOPT4_TPM2CLKSEL_TPM_CLKIN1   (1 << 26)

//System options register 5 bitfields
#define SIM_SOPT5_UART0TXSRC_TX_Pin     (0 << 0)    //UART 0 transmit data source select
#define SIM_SOPT5_UART0TXSRC_TX_TPM1    (1 << 0)
#define SIM_SOPT5_UART0TXSRC_TX_TPM2    (2 << 0)
#define SIM_SOPT5_UART0RXSRC_RX_Pin     (0 << 2)    //UART 0 receive data source select
#define SIM_SOPT5_UART0RXSRC_CMP0       (1 << 2)
#define SIM_SOPT5_UART1TXSRC_TX_Pin     (0 << 4)    //UART 1 transmit data source select
#define SIM_SOPT5_UART1TXSRC_TX_TPM1    (1 << 4)
#define SIM_SOPT5_UART1TXSRC_TX_TPM2    (2 << 4)
#define SIM_SOPT5_UART1RXSRC_RX_Pin     (0 << 6)    //UART 1 receive data source select
#define SIM_SOPT5_UART1RXSRC_CMP0       (1 << 6)
#define SIM_SOPT5_UART0ODE_Disabled     (0 << 16)   //UART0 open drain enable
#define SIM_SOPT5_UART0ODE_Enabled      (1 << 16)
#define SIM_SOPT5_UART1ODE_Disabled     (0 << 17)   //UART1 open drain enable
#define SIM_SOPT5_UART1ODE_Enabled      (1 << 17)
#define SIM_SOPT5_UART2ODE_Disabled     (0 << 18)   //UART2 open drain enable
#define SIM_SOPT5_UART2ODE_Enabled      (1 << 18)

//System options register 7 bitfields
#define SIM_SOPT7_ADC0TRGSEL_EXTRG_IN     (0 << 0)    //ADC0 trigger select
#define SIM_SOPT7_ADC0TRGSEL_CMP0         (1 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT0         (4 << 0)
#define SIM_SOPT7_ADC0TRGSEL_PIT1         (5 << 0)
#define SIM_SOPT7_ADC0TRGSEL_TPM0         (8 << 0)
#define SIM_SOPT7_ADC0TRGSEL_TPM1         (9 << 0)
#define SIM_SOPT7_ADC0TRGSEL_TPM2         (10 << 0)
#define SIM_SOPT7_ADC0TRGSEL_RTC_Alarm    (12 << 0)
#define SIM_SOPT7_ADC0TRGSEL_RTC_Seconds  (13 << 0)
#define SIM_SOPT7_ADC0TRGSEL_LPTMR0       (14 << 0)
#define SIM_SOPT7_ADC0PRETRGSEL_A         (0 << 4)    //ADC0 pretrigger select
#define SIM_SOPT7_ADC0PRETRGSEL_B         (1 << 4)
#define SIM_SOPT7_ADC0ALTTRGEN_TPM        (0 << 7)    //ADC0 alternate trigger enable
#define SIM_SOPT7_ADC0ALTTRGEN_Alt        (1 << 7)

//System device identification register bitfields
#define SIM_SDID_PINID_Msk      0x0000000F  //Pincount identification
#define SIM_SDID_PINID_Pos      0
#define SIM_SDID_DIEID_Msk      0x00000F80  //Device die number
#define SIM_SDID_DIEID_Pos      7
#define SIM_SDID_REVID_Msk      0x0000F000  //Device revision number
#define SIM_SDID_REVID_Pos      12
#define SIM_SDID_SRAMSIZE_Msk   0x000F0000  //System SRAM size
#define SIM_SDID_SRAMSIZE_Pos   16
#define SIM_SDID_SERIESID_Msk   0x00F00000  //Kinetis series ID
#define SIM_SDID_SERIESID_Pos   20
#define SIM_SDID_SUBFAMID_Msk   0x0F000000  //Kinetis sub family ID
#define SIM_SDID_SUBFAMID_Pos   24
#define SIM_SDID_FAMID_Msk      0xF0000000  //Kinetis family ID
#define SIM_SDID_FAMID_Pos      28

//System clock gating control register 4 bitfields
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
#define SIM_SCGC4_USBOTG_Disabled   (0 << 18)   //USBOTG clock gate control
#define SIM_SCGC4_USBOTG_Enabled    (1 << 18)
#define SIM_SCGC4_CMP_Disabled      (0 << 19)   //CMP clock gate control
#define SIM_SCGC4_CMP_Enabled       (1 << 19)
#define SIM_SCGC4_SPI0_Disabled     (0 << 22)   //SPI0 clock gate control
#define SIM_SCGC4_SPI0_Enabled      (1 << 22)
#define SIM_SCGC4_SPI1_Disabled     (0 << 23)   //SPI1 clock gate control
#define SIM_SCGC4_SPI1_Enabled      (1 << 23)

//System clock gating control register 5 bitfields
#define SIM_SCGC5_LPTMR_Disabled  (0 << 0)    //Low power timer access control
#define SIM_SCGC5_LPTMR_Enabled   (1 << 0)
#define SIM_SCGC5_TSI_Disabled    (0 << 5)    //TSI access control
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
#define SIM_SCGC6_I2S_Disabled        (0 << 15)   //I2S clock gate control
#define SIM_SCGC6_I2S_Enabled         (1 << 15)
#define SIM_SCGC6_PIT_Disabled        (0 << 23)   //PIT clock gate control
#define SIM_SCGC6_PIT_Enabled         (1 << 23)
#define SIM_SCGC6_TPM0_Disabled       (0 << 24)   //TPM0 clock gate control
#define SIM_SCGC6_TPM0_Enabled        (1 << 24)
#define SIM_SCGC6_TPM1_Disabled       (0 << 25)   //TPM1 clock gate control
#define SIM_SCGC6_TPM1_Enabled        (1 << 25)
#define SIM_SCGC6_TPM2_Disabled       (0 << 26)   //TPM2 clock gate control
#define SIM_SCGC6_TPM2_Enabled        (1 << 26)
#define SIM_SCGC6_ADC0_Disabled       (0 << 27)   //ADC0 clock gate control
#define SIM_SCGC6_ADC0_Enabled        (1 << 27)
#define SIM_SCGC6_RTC_Disabled        (0 << 29)   //RTC access control
#define SIM_SCGC6_RTC_Enabled         (1 << 29)
#define SIM_SCGC6_DAC0_Disabled       (0 << 31)   //DAC0 clock gate control
#define SIM_SCGC6_DAC0_Enabled        (1 << 31)

//System clock gating control register 7 bitfields
#define SIM_SCGC7_DMA_Disabled      (0 << 8)  //DMA clock gate control
#define SIM_SCGC7_DMA_Enabled       (1 << 8)

//System clock divider register 1 bitfields
#define SIM_CLKDIV1_OUTDIV4_Msk   0x00070000  //Clock 4 output divider value
#define SIM_CLKDIV1_OUTDIV4_Pos   16
#define SIM_CLKDIV1_OUTDIV1_Msk   0xF0000000  //Clock 1 output divider value
#define SIM_CLKDIV1_OUTDIV1_Pos   28

//Flash configuration register 1 bitfields
#define SIM_FCFG1_FLASHDIS_Enabled    (0 << 0)    //Flash disable
#define SIM_FCFG1_FLASHDIS_Disabled   (1 << 0)
#define SIM_FCFG1_FLASHDOZE_EnDoze    (0 << 1)    //Flash doze
#define SIM_FCFG1_FLASHDOZE_DisDoze   (1 << 1)
#define SIM_FCFG1_PFSIZE_8K           (0 << 24)   //Program flash size
#define SIM_FCFG1_PFSIZE_16K          (1 << 24)
#define SIM_FCFG1_PFSIZE_32K          (3 << 24)
#define SIM_FCFG1_PFSIZE_64K          (5 << 24)
#define SIM_FCFG1_PFSIZE_128K         (7 << 24)
#define SIM_FCFG1_PFSIZE_256K         (9 << 24)

//Flash configuration register 2 bitfields
#define SIM_FCFG2_MAXADDR1_Msk        0x007F0000  //Max address block 1
#define SIM_FCFG2_MAXADDR1_Pos        16
#define SIM_FCFG2_MAXADDR0_Msk        0x7F000000  //Max address block 0
#define SIM_FCFG2_MAXADDR0_Pos        24

//COP control register bitfields
#define SIM_COPC_COPW_Normal          (0 << 0)  //COP windowed mode
#define SIM_COPC_COPW_Windowed        (1 << 0)
#define SIM_COPC_COPCLKS_Int_1kHz     (0 << 1)  //COP Clock Select
#define SIM_COPC_COPCLKS_Bus_Clock    (1 << 1)
#define SIM_COPC_COPT_Disabled        (0 << 2)  //COP watchdog timeout
#define SIM_COPC_COPT_5_LPO_13_Bus    (1 << 2)
#define SIM_COPC_COPT_8_LPO_16_Bus    (2 << 2)
#define SIM_COPC_COPT_10_LPO_18_Bus   (3 << 2)

//Service COP bitfields
#define SIM_SRVCOP_SRVCOP_Msk     0x000000FF  //Service cop register
#define SIM_SRVCOP_SRVCOP_Pos     0
#define SIM_SRVCOP_SRVCOP_Seq_A   0x00000055
#define SIM_SRVCOP_SRVCOP_Seq_B   0x000000AA

#endif //MKL26_SIM_H_
