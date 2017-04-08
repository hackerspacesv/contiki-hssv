//+------------------------------------------------------------------------------------------------+
//| SIM peripheral registers for Kinetis MK20 MCU.                                                 |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK20_SIM_H_
#define MK20_SIM_H_

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
};

#define SIM ((volatile struct SIM_type *) 0x40047000)

//System options register 1 bitfields
#define SIM_SOPT1_RAMSIZE_8K            (1 << 12)   //RAM size
#define SIM_SOPT1_RAMSIZE_16K           (3 << 12)
#define SIM_SOPT1_RAMSIZE_32K           (5 << 12)
#define SIM_SOPT1_RAMSIZE_64K           (7 << 12)
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

//System options register 2 bitfields
#define SIM_SOPT2_RTCCLKOUTSEL_1Hz            (0 << 4)    //RTC clock out select
#define SIM_SOPT2_RTCCLKOUTSEL_32KHz          (1 << 4)
#define SIM_SOPT2_CLKOUTSEL_Flash             (2 << 5)    //CLKOUT select
#define SIM_SOPT2_CLKOUTSEL_LPO               (3 << 5)
#define SIM_SOPT2_CLKOUTSEL_MCGIRCLK          (4 << 5)
#define SIM_SOPT2_CLKOUTSEL_RTC               (5 << 5)
#define SIM_SOPT2_CLKOUTSEL_OSCERCLK0         (6 << 5)
#define SIM_SOPT2_PTD7PAD_Single              (0 << 11)   //PTD7 pad drive strength
#define SIM_SOPT2_PTD7PAD_Double              (1 << 11)
#define SIM_SOPT2_TRACECLKSEL_MCGOUTCLK       (0 << 12)   //Debug trace clock select
#define SIM_SOPT2_TRACECLKSEL_Core_System     (1 << 12)
#define SIM_SOPT2_PLLFLLSEL_MCGFLLCLK         (0 << 16)   //PLL/FLL clock select
#define SIM_SOPT2_PLLFLLSEL_MCGPLLCLK         (1 << 16)
#define SIM_SOPT2_USBSRC_External             (0 << 18)   //USB clock source select
#define SIM_SOPT2_USBSRC_Internal             (1 << 18)

//System options register 4 bitfields
#define SIM_SOPT4_FTM0FLT0_FTM0_FLT0    (0 << 0)    //FTM0 fault 0 select
#define SIM_SOPT4_FTM0FLT0_CMP0         (1 << 0)
#define SIM_SOPT4_FTM0FLT1_FTM0_FLT1    (0 << 1)    //FTM0 fault 1 select
#define SIM_SOPT4_FTM0FLT1_CMP1         (1 << 1)
#define SIM_SOPT4_FTM0FLT2_FTM0_FLT2    (0 << 2)    //FTM0 fault 2 select
#define SIM_SOPT4_FTM0FLT2_CMP2         (1 << 2)
#define SIM_SOPT4_FTM1FLT0_FTM1_FLT0    (0 << 4)    //FTM1 fault 0 select
#define SIM_SOPT4_FTM1FLT0_CMP0         (1 << 4)
#define SIM_SOPT4_FTM2FLT0_FTM2_FLT0    (0 << 8)    //FTM2 fault 0 select
#define SIM_SOPT4_FTM2FLT0_CMP0         (1 << 8)
#define SIM_SOPT4_FTM1CH0SRC_FTM1_CH0   (0 << 18)   //FTM1 channel 0 input capture source select
#define SIM_SOPT4_FTM1CH0SRC_CMP0       (1 << 18)
#define SIM_SOPT4_FTM1CH0SRC_CMP1       (2 << 18)
#define SIM_SOPT4_FTM1CH0SRC_USB        (3 << 18)
#define SIM_SOPT4_FTM2CH0SRC_FTM2_CH0   (0 << 20)   //FTM2 channel 0 input capture source select
#define SIM_SOPT4_FTM2CH0SRC_CMP0       (1 << 20)
#define SIM_SOPT4_FTM2CH0SRC_CMP1       (2 << 20)
#define SIM_SOPT4_FTM0CLKSEL_FTM_CLK0   (0 << 24)   //FTM0 external clock pin select
#define SIM_SOPT4_FTM0CLKSEL_FTM_CLK1   (1 << 24)
#define SIM_SOPT4_FTM1CLKSEL_FTM_CLK0   (0 << 25)   //FTM1 external clock pin select
#define SIM_SOPT4_FTM1CLKSEL_FTM_CLK1   (1 << 25)
#define SIM_SOPT4_FTM2CLKSEL_FTM_CLK0   (0 << 26)   //FTM2 external clock pin select
#define SIM_SOPT4_FTM2CLKSEL_FTM_CLK1   (1 << 26)
#define SIM_SOPT4_FTM0TRG0SRC_HSCMP0    (0 << 28)   //FTM0 hardware trigger 0 source select
#define SIM_SOPT4_FTM0TRG0SRC_FTM1      (1 << 28)
#define SIM_SOPT4_FTM0TRG1SRC_PDB       (0 << 29)   //FTM0 hardware trigger 1 source select
#define SIM_SOPT4_FTM0TRG1SRC_FTM2      (1 << 29)

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
#define SIM_SOPT7_ADC0TRGSEL_RTC_Alarm    (12 << 0)
#define SIM_SOPT7_ADC0TRGSEL_RTC_Seconds  (13 << 0)
#define SIM_SOPT7_ADC0TRGSEL_LPTMR        (14 << 0)
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
#define SIM_SOPT7_ADC1TRGSEL_RTC_Alarm    (12 << 8)
#define SIM_SOPT7_ADC1TRGSEL_RTC_Seconds  (13 << 8)
#define SIM_SOPT7_ADC1TRGSEL_LPTMR        (14 << 8)
#define SIM_SOPT7_ADC1PRETRGSEL_A         (0 << 12)   //ADC1 pretrigger select
#define SIM_SOPT7_ADC1PRETRGSEL_B         (1 << 12)
#define SIM_SOPT7_ADC1ALTTRGEN_PDB        (0 << 15)   //ADC1 alternate trigger enable
#define SIM_SOPT7_ADC1ALTTRGEN_Alt        (1 << 15)

//System device identification register bitfields
#define SIM_SDID_PINID_Msk      0x0000000F  //Pincount identification
#define SIM_SDID_PINID_Pos      0
#define SIM_SDID_FAMID_Msk      0x00000070  //Kinetis family identification
#define SIM_SDID_FAMID_Pos      4
#define SIM_SDID_REVID_Msk      0x0000F000  //Device revision number
#define SIM_SDID_REVID_Pos      12

//System clock gating control register 1 bitfields
//(All fields reserved)

//System clock gating control register 2 bitfields
#define SIM_SCGC2_DAC0_Disabled     (0 << 12)   //DAC0 clock gate control
#define SIM_SCGC2_DAC0_Enabled      (1 << 12)

//System clock gating control register 3 bitfields
#define SIM_SCGC3_FTM2_Disabled       (0 << 24)   //FTM2 clock gate control
#define SIM_SCGC3_FTM2_Enabled        (1 << 24)
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
#define SIM_SCGC6_FTFL_Disabled       (0 << 0)    //Flash memory clock gate control
#define SIM_SCGC6_FTFL_Enabled        (1 << 0)
#define SIM_SCGC6_DMAMUX_Disabled     (0 << 1)    //DMA mux clock gate control
#define SIM_SCGC6_DMAMUX_Enabled      (1 << 1)
#define SIM_SCGC6_FLEXCAN0_Disabled   (0 << 4)    //FlexCAN0 clock gate control
#define SIM_SCGC6_FLEXCAN0_Enabled    (1 << 4)
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
#define SIM_SCGC6_ADC0_Disabled       (0 << 27)   //ADC0 clock gate control
#define SIM_SCGC6_ADC0_Enabled        (1 << 27)
#define SIM_SCGC6_RTC_Disabled        (0 << 29)   //RTC access control
#define SIM_SCGC6_RTC_Enabled         (1 << 29)
//There's no FTM2 clock gate in this register according to the datasheet. Confirm if this is a typo,
//as this part number definitely has an FTM2 instance.

//System clock gating control register 7 bitfields
#define SIM_SCGC7_DMA_Disabled      (0 << 1)  //DMA clock gate control
#define SIM_SCGC7_DMA_Enabled       (1 << 1)

//System clock divider register 1 bitfields
#define SIM_CLKDIV1_OUTDIV4_Msk   0x000F0000  //Clock 4 output divider value
#define SIM_CLKDIV1_OUTDIV4_Pos   16
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
#define SIM_FCFG1_EESIZE_2K           (3 << 16)   //EEPROM size
#define SIM_FCFG1_EESIZE_1K           (4 << 16)
#define SIM_FCFG1_EESIZE_512          (5 << 16)
#define SIM_FCFG1_EESIZE_256          (6 << 16)
#define SIM_FCFG1_EESIZE_128          (7 << 16)
#define SIM_FCFG1_EESIZE_64           (8 << 16)
#define SIM_FCFG1_EESIZE_32           (9 << 16)
#define SIM_FCFG1_EESIZE_0            (15 << 16)
#define SIM_FCFG1_PFSIZE_64K          (5 << 24)   //Program flash size
#define SIM_FCFG1_PFSIZE_128K         (7 << 24)
#define SIM_FCFG1_PFSIZE_256K         (9 << 24)
#define SIM_FCFG1_NVMSIZE_0           (0 << 28)   //FlexNVM size
#define SIM_FCFG1_NVMSIZE_32K         (3 << 28)

//Flash configuration register 2 bitfields
#define SIM_FCFG2_MAXADDR1_Msk        0x007F0000  //Max address block 1
#define SIM_FCFG2_MAXADDR1_Pos        16
#define SIM_FCFG2_PFLSH_FlexNVM       (0 << 23)   //Program flash
#define SIM_FCFG2_PFLSH_Flash         (1 << 23)
#define SIM_FCFG2_MAXADDR0_Msk        0x7F000000  //Max address block 0
#define SIM_FCFG2_MAXADDR0_Pos        24

#endif //MK20_SIM_H_
