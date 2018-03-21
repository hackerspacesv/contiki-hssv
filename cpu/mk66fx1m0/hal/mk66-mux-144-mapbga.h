//+------------------------------------------------------------------------------------------------+
//| Port mux definitions for Kinetis MK66 MCU.                                                     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_MUX_144_MAPBGA_H_
#define MK66_MUX_144_MAPBGA_H_

#define PTA0_PER_INS                    A
#define PTA0_BIT_POS                    0
#define PTA0_ALT_UART0_CTS_b            PORT_PCR_MUX_Alt2
#define PTA0_ALT_UART0_COL_b            PORT_PCR_MUX_Alt2
#define PTA0_ALT_FTM0_CH5               PORT_PCR_MUX_Alt3
#define PTA0_ALT_LPUART0_CTS_b          PORT_PCR_MUX_Alt5
#define PTA0_ALT_JTAG_TCLK              PORT_PCR_MUX_Alt7
#define PTA0_ALT_SWD_CLK                PORT_PCR_MUX_Alt7

#define PTA1_PER_INS                    A
#define PTA1_BIT_POS                    1
#define PTA1_ALT_UART0_RX               PORT_PCR_MUX_Alt2
#define PTA1_ALT_FTM0_CH6               PORT_PCR_MUX_Alt3
#define PTA1_ALT_I2C3_SDA               PORT_PCR_MUX_Alt4
#define PTA1_ALT_LPUART0_RX             PORT_PCR_MUX_Alt5
#define PTA1_ALT_JTAG_TDI               PORT_PCR_MUX_Alt7

#define PTA2_PER_INS                    A
#define PTA2_BIT_POS                    2
#define PTA2_ALT_UART0_TX               PORT_PCR_MUX_Alt2
#define PTA2_ALT_FTM0_CH7               PORT_PCR_MUX_Alt3
#define PTA2_ALT_I2C3_SCL               PORT_PCR_MUX_Alt4
#define PTA2_ALT_LPUART0_TX             PORT_PCR_MUX_Alt5
#define PTA2_ALT_JTAG_TDO               PORT_PCR_MUX_Alt7
#define PTA2_ALT_TRACE_SWO              PORT_PCR_MUX_Alt7

#define PTA3_PER_INS                    A
#define PTA3_BIT_POS                    3
#define PTA3_ALT_UART0_RTS_b            PORT_PCR_MUX_Alt2
#define PTA3_ALT_FTM0_CH0               PORT_PCR_MUX_Alt3
#define PTA3_ALT_LPUART0_RTS_b          PORT_PCR_MUX_Alt5
#define PTA3_ALT_JTAG_TMS               PORT_PCR_MUX_Alt7
#define PTA3_ALT_SWD_DIO                PORT_PCR_MUX_Alt7

#define PTA4_PER_INS                    A
#define PTA4_BIT_POS                    4
#define PTA4_ALT_FTM0_CH1               PORT_PCR_MUX_Alt3
#define PTA4_ALT_NMI_b                  PORT_PCR_MUX_Alt7

#define PTA5_PER_INS                    A
#define PTA5_BIT_POS                    5
#define PTA5_ALT_USB0_CLKIN             PORT_PCR_MUX_Alt2
#define PTA5_ALT_FTM0_CH2               PORT_PCR_MUX_Alt3
#define PTA5_ALT_RMII0_RXER             PORT_PCR_MUX_Alt4
#define PTA5_ALT_MII0_RXER              PORT_PCR_MUX_Alt4
#define PTA5_ALT_CMP2_OUT               PORT_PCR_MUX_Alt5
#define PTA5_ALT_I2S0_TX_BCLK           PORT_PCR_MUX_Alt6
#define PTA5_ALT_JTAG_TRST_b            PORT_PCR_MUX_Alt7

#define PTA6_PER_INS                    A
#define PTA6_BIT_POS                    6
#define PTA6_ALT_FTM0_CH3               PORT_PCR_MUX_Alt3
#define PTA6_ALT_CLKOUT                 PORT_PCR_MUX_Alt5
#define PTA6_ALT_TRACE_CLKOUT           PORT_PCR_MUX_Alt7

#define PTA7_PER_INS                    A
#define PTA7_BIT_POS                    7
#define PTA7_ALT_FTM0_CH4               PORT_PCR_MUX_Alt3
#define PTA7_ALT_RMII0_MDIO             PORT_PCR_MUX_Alt5
#define PTA7_ALT_MII0_MDIO              PORT_PCR_MUX_Alt5
#define PTA7_ALT_TRACE_D3               PORT_PCR_MUX_Alt7

#define PTA8_PER_INS                    A
#define PTA8_BIT_POS                    8
#define PTA8_ALT_FTM1_CH0               PORT_PCR_MUX_Alt3
#define PTA8_ALT_RMII0_MDC              PORT_PCR_MUX_Alt5
#define PTA8_ALT_MII0_MDC               PORT_PCR_MUX_Alt5
#define PTA8_ALT_FTM1_QD_PHA            PORT_PCR_MUX_Alt6
#define PTA8_ALT_TPM1_CH0               PORT_PCR_MUX_Alt6
#define PTA8_ALT_TRACE_D2               PORT_PCR_MUX_Alt7

#define PTA9_PER_INS                    A
#define PTA9_BIT_POS                    9
#define PTA9_ALT_FTM1_CH1               PORT_PCR_MUX_Alt3
#define PTA9_ALT_MII0_RXD3              PORT_PCR_MUX_Alt4
#define PTA9_ALT_FTM1_QD_PHB            PORT_PCR_MUX_Alt6
#define PTA9_ALT_TPM1_CH1               PORT_PCR_MUX_Alt6
#define PTA9_ALT_TRACE_D1               PORT_PCR_MUX_Alt7

#define PTA10_PER_INS                   A
#define PTA10_BIT_POS                   10
#define PTA10_ALT_FTM2_CH0              PORT_PCR_MUX_Alt3
#define PTA10_ALT_MII0_RXD2             PORT_PCR_MUX_Alt4
#define PTA10_ALT_FTM2_QD_PHA           PORT_PCR_MUX_Alt6
#define PTA10_ALT_TPM2_CH0              PORT_PCR_MUX_Alt6
#define PTA10_ALT_TRACE_D0              PORT_PCR_MUX_Alt7

#define PTA11_PER_INS                   A
#define PTA11_BIT_POS                   11
#define PTA11_ALT_FTM2_CH1              PORT_PCR_MUX_Alt3
#define PTA11_ALT_MII0_RXCLK            PORT_PCR_MUX_Alt4
#define PTA11_ALT_I2C2_SDA              PORT_PCR_MUX_Alt5
#define PTA11_ALT_FTM2_QD_PHB           PORT_PCR_MUX_Alt6
#define PTA11_ALT_TPM2_CH1              PORT_PCR_MUX_Alt6

#define PTA12_PER_INS                   A
#define PTA12_BIT_POS                   12
#define PTA12_ALT_CAN0_TX               PORT_PCR_MUX_Alt2
#define PTA12_ALT_FTM1_CH0              PORT_PCR_MUX_Alt3
#define PTA12_ALT_RMII0_RXD1            PORT_PCR_MUX_Alt4
#define PTA12_ALT_MII0_RXD1             PORT_PCR_MUX_Alt4
#define PTA12_ALT_I2C2_SCL              PORT_PCR_MUX_Alt5
#define PTA12_ALT_I2S0_TXD0             PORT_PCR_MUX_Alt6
#define PTA12_ALT_FTM1_QD_PHA           PORT_PCR_MUX_Alt7
#define PTA12_ALT_TPM1_CH0              PORT_PCR_MUX_Alt7

#define PTA13_PER_INS                   A
#define PTA13_BIT_POS                   13
#define PTA13_ALT_CAN0_RX               PORT_PCR_MUX_Alt2
#define PTA13_ALT_FTM1_CH1              PORT_PCR_MUX_Alt3
#define PTA13_ALT_RMII0_RXD0            PORT_PCR_MUX_Alt4
#define PTA13_ALT_MII0_RXD0             PORT_PCR_MUX_Alt4
#define PTA13_ALT_I2C2_SDA              PORT_PCR_MUX_Alt5
#define PTA13_ALT_I2S0_TX_FS            PORT_PCR_MUX_Alt6
#define PTA13_ALT_FTM1_QD_PHB           PORT_PCR_MUX_Alt7
#define PTA13_ALT_TPM1_CH1              PORT_PCR_MUX_Alt7

#define PTA14_PER_INS                   A
#define PTA14_BIT_POS                   14
#define PTA14_ALT_SPI0_PCS0             PORT_PCR_MUX_Alt2
#define PTA14_ALT_UART0_TX              PORT_PCR_MUX_Alt3
#define PTA14_ALT_RMII0_CRS_DV          PORT_PCR_MUX_Alt4
#define PTA14_ALT_MII0_RXDV             PORT_PCR_MUX_Alt4
#define PTA14_ALT_I2C2_SCL              PORT_PCR_MUX_Alt5
#define PTA14_ALT_I2S0_RX_BCLK          PORT_PCR_MUX_Alt6
#define PTA14_ALT_I2S0_TXD1             PORT_PCR_MUX_Alt7

#define PTA15_PER_INS                   A
#define PTA15_BIT_POS                   15
#define PTA15_ALT_SPI0_SCK              PORT_PCR_MUX_Alt2
#define PTA15_ALT_UART0_RX              PORT_PCR_MUX_Alt3
#define PTA15_ALT_RMII0_TXEN            PORT_PCR_MUX_Alt4
#define PTA15_ALT_MII0_TXEN             PORT_PCR_MUX_Alt4
#define PTA15_ALT_I2S0_RXD0             PORT_PCR_MUX_Alt6

#define PTA16_PER_INS                   A
#define PTA16_BIT_POS                   16
#define PTA16_ALT_SPI0_SOUT             PORT_PCR_MUX_Alt2
#define PTA16_ALT_UART0_CTS_b           PORT_PCR_MUX_Alt3
#define PTA16_ALT_UART0_COL_b           PORT_PCR_MUX_Alt3
#define PTA16_ALT_RMII0_TXD0            PORT_PCR_MUX_Alt4
#define PTA16_ALT_MII0_TXD0             PORT_PCR_MUX_Alt4
#define PTA16_ALT_I2S0_RX_FS            PORT_PCR_MUX_Alt6
#define PTA16_ALT_I2S0_RXD1             PORT_PCR_MUX_Alt7

#define PTA17_PER_INS                   A
#define PTA17_BIT_POS                   17
#define PTA17_ALT_SPI0_SIN              PORT_PCR_MUX_Alt2
#define PTA17_ALT_UART0_RTS_b           PORT_PCR_MUX_Alt3
#define PTA17_ALT_RMII0_TXD1            PORT_PCR_MUX_Alt4
#define PTA17_ALT_MII0_TXD1             PORT_PCR_MUX_Alt4
#define PTA17_ALT_I2S0_MCLK             PORT_PCR_MUX_Alt6

#define PTA18_PER_INS                   A
#define PTA18_BIT_POS                   18
#define PTA18_ALT_FTM0_FLT2             PORT_PCR_MUX_Alt3
#define PTA18_ALT_FTM_CLKIN0            PORT_PCR_MUX_Alt4
#define PTA18_ALT_TPM_CLKIN0            PORT_PCR_MUX_Alt7

#define PTA19_PER_INS                   A
#define PTA19_BIT_POS                   19
#define PTA19_ALT_FTM1_FLT0             PORT_PCR_MUX_Alt3
#define PTA19_ALT_FTM_CLKIN1            PORT_PCR_MUX_Alt4
#define PTA19_ALT_LPTMR0_ALT1           PORT_PCR_MUX_Alt6
#define PTA19_ALT_TPM_CLKIN1            PORT_PCR_MUX_Alt7

#define PTA24_PER_INS                   A
#define PTA24_BIT_POS                   24
#define PTA24_ALT_MII0_TXD2             PORT_PCR_MUX_Alt4
#define PTA24_ALT_FB_A29                PORT_PCR_MUX_Alt6

#define PTA25_PER_INS                   A
#define PTA25_BIT_POS                   25
#define PTA25_ALT_MII0_TXCLK            PORT_PCR_MUX_Alt4
#define PTA25_ALT_FB_A28                PORT_PCR_MUX_Alt6

#define PTA26_PER_INS                   A
#define PTA26_BIT_POS                   26
#define PTA26_ALT_MII0_TXD3             PORT_PCR_MUX_Alt4
#define PTA26_ALT_FB_A27                PORT_PCR_MUX_Alt6

#define PTA27_PER_INS                   A
#define PTA27_BIT_POS                   27
#define PTA27_ALT_MII0_CRS              PORT_PCR_MUX_Alt4
#define PTA27_ALT_FB_A26                PORT_PCR_MUX_Alt6

#define PTA28_PER_INS                   A
#define PTA28_BIT_POS                   28
#define PTA28_ALT_MII0_TXER             PORT_PCR_MUX_Alt4
#define PTA28_ALT_FB_A25                PORT_PCR_MUX_Alt6

#define PTA29_PER_INS                   A
#define PTA29_BIT_POS                   29
#define PTA29_ALT_MII0_COL              PORT_PCR_MUX_Alt4
#define PTA29_ALT_FB_A24                PORT_PCR_MUX_Alt6

#define PTB0_PER_INS                    B
#define PTB0_BIT_POS                    0
#define PTB0_ALT_I2C0_SCL               PORT_PCR_MUX_Alt2
#define PTB0_ALT_FTM1_CH0               PORT_PCR_MUX_Alt3
#define PTB0_ALT_RMII0_MDIO             PORT_PCR_MUX_Alt4
#define PTB0_ALT_MII0_MDIO              PORT_PCR_MUX_Alt4
#define PTB0_ALT_SDRAM_CAS_b            PORT_PCR_MUX_Alt5
#define PTB0_ALT_FTM1_QD_PHA            PORT_PCR_MUX_Alt6
#define PTB0_ALT_TPM1_CH0               PORT_PCR_MUX_Alt6

#define PTB1_PER_INS                    B
#define PTB1_BIT_POS                    1
#define PTB1_ALT_I2C0_SDA               PORT_PCR_MUX_Alt2
#define PTB1_ALT_FTM1_CH1               PORT_PCR_MUX_Alt3
#define PTB1_ALT_RMII0_MDC              PORT_PCR_MUX_Alt4
#define PTB1_ALT_MII0_MDC               PORT_PCR_MUX_Alt4
#define PTB1_ALT_SDRAM_RAS_b            PORT_PCR_MUX_Alt5
#define PTB1_ALT_FTM1_QD_PHB            PORT_PCR_MUX_Alt6
#define PTB1_ALT_TPM1_CH1               PORT_PCR_MUX_Alt6

#define PTB2_PER_INS                    B
#define PTB2_BIT_POS                    2
#define PTB2_ALT_I2C0_SCL               PORT_PCR_MUX_Alt2
#define PTB2_ALT_UART0_RTS_b            PORT_PCR_MUX_Alt3
#define PTB2_ALT_ENET0_1588_TMR0        PORT_PCR_MUX_Alt4
#define PTB2_ALT_SDRAM_WE               PORT_PCR_MUX_Alt5
#define PTB2_ALT_FTM0_FLT3              PORT_PCR_MUX_Alt6

#define PTB3_PER_INS                    B
#define PTB3_BIT_POS                    3
#define PTB3_ALT_I2C0_SDA               PORT_PCR_MUX_Alt2
#define PTB3_ALT_UART0_CTS_b            PORT_PCR_MUX_Alt3
#define PTB3_ALT_UART0_COL_b            PORT_PCR_MUX_Alt3
#define PTB3_ALT_ENET0_1588_TMR1        PORT_PCR_MUX_Alt4
#define PTB3_ALT_SDRAM_CS0_b            PORT_PCR_MUX_Alt5
#define PTB3_ALT_FTM0_FLT0              PORT_PCR_MUX_Alt6

#define PTB4_PER_INS                    B
#define PTB4_BIT_POS                    4
#define PTB4_ALT_ENET0_1588_TMR2        PORT_PCR_MUX_Alt4
#define PTB4_ALT_SDRAM_CS1_b            PORT_PCR_MUX_Alt5
#define PTB4_ALT_FTM1_FLT0              PORT_PCR_MUX_Alt6

#define PTB5_PER_INS                    B
#define PTB5_BIT_POS                    5
#define PTB5_ALT_ENET0_1588_TMR3        PORT_PCR_MUX_Alt4
#define PTB5_ALT_FTM2_FLT0              PORT_PCR_MUX_Alt6

#define PTB6_PER_INS                    B
#define PTB6_BIT_POS                    6
#define PTB6_ALT_FB_AD23                PORT_PCR_MUX_Alt5
#define PTB6_ALT_SDRAM_D23              PORT_PCR_MUX_Alt5

#define PTB7_PER_INS                    B
#define PTB7_BIT_POS                    7
#define PTB7_ALT_FB_AD22                PORT_PCR_MUX_Alt5
#define PTB7_ALT_SDRAM_D22              PORT_PCR_MUX_Alt5

#define PTB8_PER_INS                    B
#define PTB8_BIT_POS                    8
#define PTB8_ALT_UART3_RTS_b            PORT_PCR_MUX_Alt3
#define PTB8_ALT_FB_AD21                PORT_PCR_MUX_Alt5
#define PTB8_ALT_SDRAM_D21              PORT_PCR_MUX_Alt5

#define PTB9_PER_INS                    B
#define PTB9_BIT_POS                    9
#define PTB9_ALT_SPI1_PCS1              PORT_PCR_MUX_Alt2
#define PTB9_ALT_UART3_CTS_b            PORT_PCR_MUX_Alt3
#define PTB9_ALT_FB_AD20                PORT_PCR_MUX_Alt5
#define PTB9_ALT_SDRAM_D20              PORT_PCR_MUX_Alt5

#define PTB10_PER_INS                   B
#define PTB10_BIT_POS                   10
#define PTB10_ALT_SPI1_PCS0             PORT_PCR_MUX_Alt2
#define PTB10_ALT_UART3_RX              PORT_PCR_MUX_Alt3
#define PTB10_ALT_FB_AD19               PORT_PCR_MUX_Alt5
#define PTB10_ALT_SDRAM_D19             PORT_PCR_MUX_Alt5
#define PTB10_ALT_FTM0_FLT1             PORT_PCR_MUX_Alt6

#define PTB11_PER_INS                   B
#define PTB11_BIT_POS                   11
#define PTB11_ALT_SPI1_SCK              PORT_PCR_MUX_Alt2
#define PTB11_ALT_UART3_TX              PORT_PCR_MUX_Alt3
#define PTB11_ALT_FB_AD18               PORT_PCR_MUX_Alt5
#define PTB11_ALT_SDRAM_D18             PORT_PCR_MUX_Alt5
#define PTB11_ALT_FTM0_FLT2             PORT_PCR_MUX_Alt6

#define PTB16_PER_INS                   B
#define PTB16_BIT_POS                   16
#define PTB16_ALT_SPI1_SOUT             PORT_PCR_MUX_Alt2
#define PTB16_ALT_UART0_RX              PORT_PCR_MUX_Alt3
#define PTB16_ALT_FTM_CLKIN0            PORT_PCR_MUX_Alt4
#define PTB16_ALT_FB_AD17               PORT_PCR_MUX_Alt5
#define PTB16_ALT_SDRAM_D17             PORT_PCR_MUX_Alt5
#define PTB16_ALT_EWM_IN                PORT_PCR_MUX_Alt6
#define PTB16_ALT_TPM_CLKIN0            PORT_PCR_MUX_Alt7

#define PTB17_PER_INS                   B
#define PTB17_BIT_POS                   17
#define PTB17_ALT_SPI1_SIN              PORT_PCR_MUX_Alt2
#define PTB17_ALT_UART0_TX              PORT_PCR_MUX_Alt3
#define PTB17_ALT_FTM_CLKIN1            PORT_PCR_MUX_Alt4
#define PTB17_ALT_FB_AD16               PORT_PCR_MUX_Alt5
#define PTB17_ALT_SDRAM_D16             PORT_PCR_MUX_Alt5
#define PTB17_ALT_EWM_OUT_b             PORT_PCR_MUX_Alt6
#define PTB17_ALT_TPM_CLKIN1            PORT_PCR_MUX_Alt7

#define PTB18_PER_INS                   B
#define PTB18_BIT_POS                   18
#define PTB18_ALT_CAN0_TX               PORT_PCR_MUX_Alt2
#define PTB18_ALT_FTM2_CH0              PORT_PCR_MUX_Alt3
#define PTB18_ALT_I2S0_TX_BCLK          PORT_PCR_MUX_Alt4
#define PTB18_ALT_FB_AD15               PORT_PCR_MUX_Alt5
#define PTB18_ALT_SDRAM_A23             PORT_PCR_MUX_Alt5
#define PTB18_ALT_FTM2_QD_PHA           PORT_PCR_MUX_Alt6
#define PTB18_ALT_TPM2_CH0              PORT_PCR_MUX_Alt6

#define PTB19_PER_INS                   B
#define PTB19_BIT_POS                   19
#define PTB19_ALT_CAN0_RX               PORT_PCR_MUX_Alt2
#define PTB19_ALT_FTM2_CH1              PORT_PCR_MUX_Alt3
#define PTB19_ALT_I2S0_TX_FS            PORT_PCR_MUX_Alt4
#define PTB19_ALT_FB_OE_b               PORT_PCR_MUX_Alt5
#define PTB19_ALT_FTM2_QD_PHB           PORT_PCR_MUX_Alt6
#define PTB19_ALT_TPM2_CH1              PORT_PCR_MUX_Alt6

#define PTB20_PER_INS                   B
#define PTB20_BIT_POS                   20
#define PTB20_ALT_SPI2_PCS0             PORT_PCR_MUX_Alt2
#define PTB20_ALT_FB_AD31               PORT_PCR_MUX_Alt5
#define PTB20_ALT_SDRAM_D31             PORT_PCR_MUX_Alt5
#define PTB20_ALT_CMP0_OUT              PORT_PCR_MUX_Alt6

#define PTB21_PER_INS                   B
#define PTB21_BIT_POS                   21
#define PTB21_ALT_SPI2_SCK              PORT_PCR_MUX_Alt2
#define PTB21_ALT_FB_AD30               PORT_PCR_MUX_Alt5
#define PTB21_ALT_SDRAM_D30             PORT_PCR_MUX_Alt5
#define PTB21_ALT_CMP1_OUT              PORT_PCR_MUX_Alt6

#define PTB22_PER_INS                   B
#define PTB22_BIT_POS                   22
#define PTB22_ALT_SPI2_SOUT             PORT_PCR_MUX_Alt2
#define PTB22_ALT_FB_AD29               PORT_PCR_MUX_Alt5
#define PTB22_ALT_SDRAM_D29             PORT_PCR_MUX_Alt5
#define PTB22_ALT_CMP2_OUT              PORT_PCR_MUX_Alt6

#define PTB23_PER_INS                   B
#define PTB23_BIT_POS                   23
#define PTB23_ALT_SPI2_SIN              PORT_PCR_MUX_Alt2
#define PTB23_ALT_SPI0_PCS5             PORT_PCR_MUX_Alt3
#define PTB23_ALT_FB_AD28               PORT_PCR_MUX_Alt5
#define PTB23_ALT_SDRAM_D28             PORT_PCR_MUX_Alt5
#define PTB23_ALT_CMP3_OUT              PORT_PCR_MUX_Alt6

#define PTC0_PER_INS                    C
#define PTC0_BIT_POS                    0
#define PTC0_ALT_SPI0_PCS4              PORT_PCR_MUX_Alt2
#define PTC0_ALT_PDB0_EXTRG             PORT_PCR_MUX_Alt3
#define PTC0_ALT_USB0_SOF_OUT           PORT_PCR_MUX_Alt4
#define PTC0_ALT_FB_AD14                PORT_PCR_MUX_Alt5
#define PTC0_ALT_SDRAM_A22              PORT_PCR_MUX_Alt5
#define PTC0_ALT_I2S0_TXD1              PORT_PCR_MUX_Alt6

#define PTC1_PER_INS                    C
#define PTC1_BIT_POS                    1
#define PTC1_ALT_SPI0_PCS3              PORT_PCR_MUX_Alt2
#define PTC1_ALT_UART1_RTS_b            PORT_PCR_MUX_Alt3
#define PTC1_ALT_FTM0_CH0               PORT_PCR_MUX_Alt4
#define PTC1_ALT_FB_AD13                PORT_PCR_MUX_Alt5
#define PTC1_ALT_SDRAM_A21              PORT_PCR_MUX_Alt5
#define PTC1_ALT_I2S0_TXD0              PORT_PCR_MUX_Alt6

#define PTC2_PER_INS                    C
#define PTC2_BIT_POS                    2
#define PTC2_ALT_SPI0_PCS2              PORT_PCR_MUX_Alt2
#define PTC2_ALT_UART1_CTS_b            PORT_PCR_MUX_Alt3
#define PTC2_ALT_FTM0_CH1               PORT_PCR_MUX_Alt4
#define PTC2_ALT_FB_AD12                PORT_PCR_MUX_Alt5
#define PTC2_ALT_SDRAM_A20              PORT_PCR_MUX_Alt5
#define PTC2_ALT_I2S0_TX_FS             PORT_PCR_MUX_Alt6

#define PTC3_PER_INS                    C
#define PTC3_BIT_POS                    3
#define PTC3_ALT_SPI0_PCS1              PORT_PCR_MUX_Alt2
#define PTC3_ALT_UART1_RX               PORT_PCR_MUX_Alt3
#define PTC3_ALT_FTM0_CH2               PORT_PCR_MUX_Alt4
#define PTC3_ALT_CLKOUT                 PORT_PCR_MUX_Alt5
#define PTC3_ALT_I2S0_TX_BCLK           PORT_PCR_MUX_Alt6

#define PTC4_PER_INS                    C
#define PTC4_BIT_POS                    4
#define PTC4_ALT_SPI0_PCS0              PORT_PCR_MUX_Alt2
#define PTC4_ALT_UART1_TX               PORT_PCR_MUX_Alt3
#define PTC4_ALT_FTM0_CH3               PORT_PCR_MUX_Alt4
#define PTC4_ALT_FB_AD11                PORT_PCR_MUX_Alt5
#define PTC4_ALT_SDRAM_A19              PORT_PCR_MUX_Alt5
#define PTC4_ALT_CMP1_OUT               PORT_PCR_MUX_Alt6

#define PTC5_PER_INS                    C
#define PTC5_BIT_POS                    5
#define PTC5_ALT_SPI0_SCK               PORT_PCR_MUX_Alt2
#define PTC5_ALT_LPTMR0_ALT2            PORT_PCR_MUX_Alt3
#define PTC5_ALT_I2S0_RXD0              PORT_PCR_MUX_Alt4
#define PTC5_ALT_FB_AD10                PORT_PCR_MUX_Alt5
#define PTC5_ALT_SDRAM_A18              PORT_PCR_MUX_Alt5
#define PTC5_ALT_CMP0_OUT               PORT_PCR_MUX_Alt6
#define PTC5_ALT_FTM0_CH2               PORT_PCR_MUX_Alt7

#define PTC6_PER_INS                    C
#define PTC6_BIT_POS                    6
#define PTC6_ALT_SPI0_SOUT              PORT_PCR_MUX_Alt2
#define PTC6_ALT_PDB0_EXTRG             PORT_PCR_MUX_Alt3
#define PTC6_ALT_I2S0_RX_BCLK           PORT_PCR_MUX_Alt4
#define PTC6_ALT_FB_AD9                 PORT_PCR_MUX_Alt5
#define PTC6_ALT_SDRAM_A17              PORT_PCR_MUX_Alt5
#define PTC6_ALT_I2S0_MCLK              PORT_PCR_MUX_Alt6

#define PTC7_PER_INS                    C
#define PTC7_BIT_POS                    7
#define PTC7_ALT_SPI0_SIN               PORT_PCR_MUX_Alt2
#define PTC7_ALT_USB0_SOF_OUT           PORT_PCR_MUX_Alt3
#define PTC7_ALT_I2S0_RX_FS             PORT_PCR_MUX_Alt4
#define PTC7_ALT_FB_AD8                 PORT_PCR_MUX_Alt5
#define PTC7_ALT_SDRAM_A16              PORT_PCR_MUX_Alt5

#define PTC8_PER_INS                    C
#define PTC8_BIT_POS                    8
#define PTC8_ALT_FTM3_CH4               PORT_PCR_MUX_Alt3
#define PTC8_ALT_I2S0_MCLK              PORT_PCR_MUX_Alt4
#define PTC8_ALT_FB_AD7                 PORT_PCR_MUX_Alt5
#define PTC8_ALT_SDRAM_A15              PORT_PCR_MUX_Alt5

#define PTC9_PER_INS                    C
#define PTC9_BIT_POS                    9
#define PTC9_ALT_FTM3_CH5               PORT_PCR_MUX_Alt3
#define PTC9_ALT_I2S0_RX_BCLK           PORT_PCR_MUX_Alt4
#define PTC9_ALT_FB_AD6                 PORT_PCR_MUX_Alt5
#define PTC9_ALT_SDRAM_A14              PORT_PCR_MUX_Alt5
#define PTC9_ALT_FTM2_FLT0              PORT_PCR_MUX_Alt6

#define PTC10_PER_INS                   C
#define PTC10_BIT_POS                   10
#define PTC10_ALT_I2C1_SCL              PORT_PCR_MUX_Alt2
#define PTC10_ALT_FTM3_CH6              PORT_PCR_MUX_Alt3
#define PTC10_ALT_I2S0_RX_FS            PORT_PCR_MUX_Alt4
#define PTC10_ALT_FB_AD5                PORT_PCR_MUX_Alt5
#define PTC10_ALT_SDRAM_A13             PORT_PCR_MUX_Alt5

#define PTC11_PER_INS                   C
#define PTC11_BIT_POS                   11
#define PTC11_ALT_I2C1_SDA              PORT_PCR_MUX_Alt2
#define PTC11_ALT_FTM3_CH7              PORT_PCR_MUX_Alt3
#define PTC11_ALT_I2S0_RXD1             PORT_PCR_MUX_Alt4
#define PTC11_ALT_FB_RW_b               PORT_PCR_MUX_Alt5

#define PTC12_PER_INS                   C
#define PTC12_BIT_POS                   12
#define PTC12_ALT_UART4_RTS_b           PORT_PCR_MUX_Alt3
#define PTC12_ALT_FTM_CLKIN0            PORT_PCR_MUX_Alt4
#define PTC12_ALT_FB_AD27               PORT_PCR_MUX_Alt5
#define PTC12_ALT_SDRAM_D27             PORT_PCR_MUX_Alt5
#define PTC12_ALT_FTM3_FLT0             PORT_PCR_MUX_Alt6
#define PTC12_ALT_TPM_CLKIN0            PORT_PCR_MUX_Alt7

#define PTC13_ALT_PER_INS               C
#define PTC13_ALT_BIT_POS               13
#define PTC13_ALT_UART4_CTS_b           PORT_PCR_MUX_Alt3
#define PTC13_ALT_FTM_CLKIN1            PORT_PCR_MUX_Alt4
#define PTC13_ALT_FB_AD26               PORT_PCR_MUX_Alt5
#define PTC13_ALT_SDRAM_D26             PORT_PCR_MUX_Alt5
#define PTC13_ALT_TPM_CLKIN1            PORT_PCR_MUX_Alt7

#define PTC14_PER_INS                   C
#define PTC14_BIT_POS                   14
#define PTC14_ALT_UART4_RX              PORT_PCR_MUX_Alt3
#define PTC14_ALT_FB_AD25               PORT_PCR_MUX_Alt5
#define PTC14_ALT_SDRAM_D25             PORT_PCR_MUX_Alt5

#define PTC15_PER_INS                   C
#define PTC15_BIT_POS                   15
#define PTC15_ALT_UART4_TX              PORT_PCR_MUX_Alt3
#define PTC15_ALT_FB_AD24               PORT_PCR_MUX_Alt5
#define PTC15_ALT_SDRAM_D24             PORT_PCR_MUX_Alt5

#define PTC16_PER_INS                   C
#define PTC16_BIT_POS                   16
#define PTC16_ALT_CAN1_RX               PORT_PCR_MUX_Alt2
#define PTC16_ALT_UART3_RX              PORT_PCR_MUX_Alt3
#define PTC16_ALT_ENET0_1588_TMR0       PORT_PCR_MUX_Alt4
#define PTC16_ALT_FB_CS5_b              PORT_PCR_MUX_Alt5
#define PTC16_ALT_FB_TSIZ1              PORT_PCR_MUX_Alt5
#define PTC16_ALT_FB_BE23_16_BLS15_8_b  PORT_PCR_MUX_Alt5
#define PTC16_ALT_SDRAM_DQM2            PORT_PCR_MUX_Alt5

#define PTC17_PER_INS                   C
#define PTC17_BIT_POS                   17
#define PTC17_ALT_CAN1_TX               PORT_PCR_MUX_Alt2
#define PTC17_ALT_UART3_TX              PORT_PCR_MUX_Alt3
#define PTC17_ALT_ENET0_1588_TMR1       PORT_PCR_MUX_Alt4
#define PTC17_ALT_FB_CS4_b              PORT_PCR_MUX_Alt5
#define PTC17_ALT_FB_TSIZ0              PORT_PCR_MUX_Alt5
#define PTC17_ALT_FB_BE31_24_BLS7_0_b   PORT_PCR_MUX_Alt5
#define PTC17_ALT_SDRAM_DQM3            PORT_PCR_MUX_Alt5

#define PTC18_PER_INS                   C
#define PTC18_BIT_POS                   18
#define PTC18_ALT_UART3_RTS_b           PORT_PCR_MUX_Alt3
#define PTC18_ALT_ENET0_1588_TMR2       PORT_PCR_MUX_Alt4
#define PTC18_ALT_FB_TBST_b             PORT_PCR_MUX_Alt5
#define PTC18_ALT_FB_CS2_b              PORT_PCR_MUX_Alt5
#define PTC18_ALT_FB_BE15_8_BLS23_16_b  PORT_PCR_MUX_Alt5
#define PTC18_ALT_SDRAM_DQM1            PORT_PCR_MUX_Alt5

#define PTC19_PER_INS                   C
#define PTC19_BIT_POS                   19
#define PTC19_ALT_UART3_CTS_b           PORT_PCR_MUX_Alt3
#define PTC19_ALT_ENET0_1588_TMR3       PORT_PCR_MUX_Alt4
#define PTC19_ALT_FB_CS3_b              PORT_PCR_MUX_Alt5
#define PTC19_ALT_FB_BE7_0_BLS31_24_b   PORT_PCR_MUX_Alt5
#define PTC19_ALT_SDRAM_DQM0            PORT_PCR_MUX_Alt5
#define PTC19_ALT_FB_TA_b               PORT_PCR_MUX_Alt6

#define PTD0_PER_INS                    D
#define PTD0_BIT_POS                    0
#define PTD0_ALT_SPI0_PCS0              PORT_PCR_MUX_Alt2
#define PTD0_ALT_UART2_RTS_b            PORT_PCR_MUX_Alt3
#define PTD0_ALT_FTM3_CH0               PORT_PCR_MUX_Alt4
#define PTD0_ALT_FB_ALE                 PORT_PCR_MUX_Alt5
#define PTD0_ALT_FB_CS1_b               PORT_PCR_MUX_Alt5
#define PTD0_ALT_FB_TS_b                PORT_PCR_MUX_Alt5

#define PTD1_PER_INS                    D
#define PTD1_BIT_POS                    1
#define PTD1_ALT_SPI0_SCK               PORT_PCR_MUX_Alt2
#define PTD1_ALT_UART2_CTS_b            PORT_PCR_MUX_Alt3
#define PTD1_ALT_FTM3_CH1               PORT_PCR_MUX_Alt4
#define PTD1_ALT_FB_CS0_b               PORT_PCR_MUX_Alt5

#define PTD2_PER_INS                    D
#define PTD2_BIT_POS                    2
#define PTD2_ALT_SPI0_SOUT              PORT_PCR_MUX_Alt2
#define PTD2_ALT_UART2_RX               PORT_PCR_MUX_Alt3
#define PTD2_ALT_FTM3_CH2               PORT_PCR_MUX_Alt4
#define PTD2_ALT_FB_AD4                 PORT_PCR_MUX_Alt5
#define PTD2_ALT_SDRAM_A12              PORT_PCR_MUX_Alt5
#define PTD2_ALT_I2C0_SCL               PORT_PCR_MUX_Alt7

#define PTD3_PER_INS                    D
#define PTD3_BIT_POS                    3
#define PTD3_ALT_SPI0_SIN               PORT_PCR_MUX_Alt2
#define PTD3_ALT_UART2_TX               PORT_PCR_MUX_Alt3
#define PTD3_ALT_FTM3_CH3               PORT_PCR_MUX_Alt4
#define PTD3_ALT_FB_AD3                 PORT_PCR_MUX_Alt5
#define PTD3_ALT_SDRAM_A11              PORT_PCR_MUX_Alt5
#define PTD3_ALT_I2C0_SDA               PORT_PCR_MUX_Alt7

#define PTD4_PER_INS                    D
#define PTD4_BIT_POS                    4
#define PTD4_ALT_SPI0_PCS1              PORT_PCR_MUX_Alt2
#define PTD4_ALT_UART0_RTS_b            PORT_PCR_MUX_Alt3
#define PTD4_ALT_FTM0_CH4               PORT_PCR_MUX_Alt4
#define PTD4_ALT_FB_AD2                 PORT_PCR_MUX_Alt5
#define PTD4_ALT_SDRAM_A10              PORT_PCR_MUX_Alt5
#define PTD4_ALT_EWM_IN                 PORT_PCR_MUX_Alt6
#define PTD4_ALT_SPI1_PCS0              PORT_PCR_MUX_Alt7

#define PTD5_PER_INS                    D
#define PTD5_BIT_POS                    5
#define PTD5_ALT_SPI0_PCS2              PORT_PCR_MUX_Alt2
#define PTD5_ALT_UART0_CTS_b            PORT_PCR_MUX_Alt3
#define PTD5_ALT_UART0_COL_b            PORT_PCR_MUX_Alt3
#define PTD5_ALT_FTM0_CH5               PORT_PCR_MUX_Alt4
#define PTD5_ALT_FB_AD1                 PORT_PCR_MUX_Alt5
#define PTD5_ALT_SDRAM_A9               PORT_PCR_MUX_Alt5
#define PTD5_ALT_EWM_OUT_b              PORT_PCR_MUX_Alt6
#define PTD5_ALT_SPI1_SCK               PORT_PCR_MUX_Alt7

#define PTD6_PER_INS                    D
#define PTD6_BIT_POS                    6
#define PTD6_ALT_SPI0_PCS3              PORT_PCR_MUX_Alt2
#define PTD6_ALT_UART0_RX               PORT_PCR_MUX_Alt3
#define PTD6_ALT_FTM0_CH6               PORT_PCR_MUX_Alt4
#define PTD6_ALT_FB_AD0                 PORT_PCR_MUX_Alt5
#define PTD6_ALT_FTM0_FLT0              PORT_PCR_MUX_Alt6
#define PTD6_ALT_SPI1_SOUT              PORT_PCR_MUX_Alt7

#define PTD7_PER_INS                    D
#define PTD7_BIT_POS                    7
#define PTD7_ALT_CMT_IRO                PORT_PCR_MUX_Alt2
#define PTD7_ALT_UART0_TX               PORT_PCR_MUX_Alt3
#define PTD7_ALT_FTM0_CH7               PORT_PCR_MUX_Alt4
#define PTD7_ALT_SDRAM_CKE              PORT_PCR_MUX_Alt5
#define PTD7_ALT_FTM0_FLT1              PORT_PCR_MUX_Alt6
#define PTD7_ALT_SPI1_SIN               PORT_PCR_MUX_Alt7

#define PTD8_PER_INS                    D
#define PTD8_BIT_POS                    8
#define PTD8_ALT_I2C0_SCL               PORT_PCR_MUX_Alt2
#define PTD8_ALT_LPUART0_RX             PORT_PCR_MUX_Alt5
#define PTD8_ALT_FB_A16                 PORT_PCR_MUX_Alt6

#define PTD9_PER_INS                    D
#define PTD9_BIT_POS                    9
#define PTD9_ALT_I2C0_SDA               PORT_PCR_MUX_Alt2
#define PTD9_ALT_LPUART0_TX             PORT_PCR_MUX_Alt5
#define PTD9_ALT_FB_A17                 PORT_PCR_MUX_Alt6

#define PTD10_PER_INS                   D
#define PTD10_BIT_POS                   10
#define PTD10_ALT_LPUART0_RTS_b         PORT_PCR_MUX_Alt5
#define PTD10_ALT_FB_A18                PORT_PCR_MUX_Alt6

#define PTD11_PER_INS                   D
#define PTD11_BIT_POS                   11
#define PTD11_ALT_SPI2_PCS0             PORT_PCR_MUX_Alt2
#define PTD11_ALT_SDHC0_CLKIN           PORT_PCR_MUX_Alt4
#define PTD11_ALT_LPUART0_CTS_b         PORT_PCR_MUX_Alt5
#define PTD11_ALT_FB_A19                PORT_PCR_MUX_Alt6

#define PTD12_PER_INS                   D
#define PTD12_BIT_POS                   12
#define PTD12_ALT_SPI2_SCK              PORT_PCR_MUX_Alt2
#define PTD12_ALT_FTM3_FLT0             PORT_PCR_MUX_Alt3
#define PTD12_ALT_SDHC0_D4              PORT_PCR_MUX_Alt4
#define PTD12_ALT_FB_A20                PORT_PCR_MUX_Alt6

#define PTD13_PER_INS                   D
#define PTD13_BIT_POS                   13
#define PTD13_ALT_SPI2_SOUT             PORT_PCR_MUX_Alt2
#define PTD13_ALT_SDHC0_D5              PORT_PCR_MUX_Alt4 
#define PTD13_ALT_FB_A21                PORT_PCR_MUX_Alt6

#define PTD14_PER_INS                   D
#define PTD14_BIT_POS                   14
#define PTD14_ALT_SPI2_SIN              PORT_PCR_MUX_Alt2
#define PTD14_ALT_SDHC0_D6              PORT_PCR_MUX_Alt4
#define PTD14_ALT_FB_A22                PORT_PCR_MUX_Alt6

#define PTD15_PER_INS                   D
#define PTD15_BIT_POS                   15
#define PTD15_ALT_SPI2_PCS1             PORT_PCR_MUX_Alt2
#define PTD15_ALT_SDHC0_D7              PORT_PCR_MUX_Alt4
#define PTD15_ALT_FB_A23                PORT_PCR_MUX_Alt6

#define PTE0_PER_INS                    E
#define PTE0_BIT_POS                    0
#define PTE0_ALT_SPI1_PCS1              PORT_PCR_MUX_Alt2
#define PTE0_ALT_UART1_TX               PORT_PCR_MUX_Alt3
#define PTE0_ALT_SDHC0_D1               PORT_PCR_MUX_Alt4
#define PTE0_ALT_TRACE_CLKOUT           PORT_PCR_MUX_Alt5
#define PTE0_ALT_I2C1_SDA               PORT_PCR_MUX_Alt6
#define PTE0_ALT_RTC_CLKOUT             PORT_PCR_MUX_Alt7

#define PTE1_PER_INS                    E
#define PTE1_BIT_POS                    1
#define PTE1_ALT_SPI1_SOUT              PORT_PCR_MUX_Alt2
#define PTE1_ALT_UART1_RX               PORT_PCR_MUX_Alt3
#define PTE1_ALT_SDHC0_D0               PORT_PCR_MUX_Alt4
#define PTE1_ALT_TRACE_D3               PORT_PCR_MUX_Alt5
#define PTE1_ALT_I2C1_SCL               PORT_PCR_MUX_Alt6
#define PTE1_ALT_SPI1_SIN               PORT_PCR_MUX_Alt7

#define PTE2_PER_INS                    E
#define PTE2_BIT_POS                    2
#define PTE2_ALT_SPI1_SCK               PORT_PCR_MUX_Alt2
#define PTE2_ALT_UART1_CTS_b            PORT_PCR_MUX_Alt3
#define PTE2_ALT_SDHC0_DCLK             PORT_PCR_MUX_Alt4
#define PTE2_ALT_TRACE_D2               PORT_PCR_MUX_Alt5

#define PTE3_PER_INS                    E
#define PTE3_BIT_POS                    3
#define PTE3_ALT_SPI1_SIN               PORT_PCR_MUX_Alt2
#define PTE3_ALT_UART1_RTS_b            PORT_PCR_MUX_Alt3
#define PTE3_ALT_SDHC0_CMD              PORT_PCR_MUX_Alt4
#define PTE3_ALT_TRACE_D1               PORT_PCR_MUX_Alt5
#define PTE3_ALT_SPI1_SOUT              PORT_PCR_MUX_Alt7

#define PTE4_PER_INS                    E
#define PTE4_BIT_POS                    4
#define PTE4_ALT_SPI1_PCS0              PORT_PCR_MUX_Alt2
#define PTE4_ALT_UART3_TX               PORT_PCR_MUX_Alt3
#define PTE4_ALT_SDHC0_D3               PORT_PCR_MUX_Alt4
#define PTE4_ALT_TRACE_D0               PORT_PCR_MUX_Alt5

#define PTE5_PER_INS                    E
#define PTE5_BIT_POS                    5
#define PTE5_ALT_SPI1_PCS2              PORT_PCR_MUX_Alt2
#define PTE5_ALT_UART3_RX               PORT_PCR_MUX_Alt3
#define PTE5_ALT_SDHC0_D2               PORT_PCR_MUX_Alt4
#define PTE5_ALT_FTM3_CH0               PORT_PCR_MUX_Alt6

#define PTE6_PER_INS                    E
#define PTE6_BIT_POS                    6
#define PTE6_ALT_SPI1_PCS3              PORT_PCR_MUX_Alt2
#define PTE6_ALT_UART3_CTS_b            PORT_PCR_MUX_Alt3
#define PTE6_ALT_I2S0_MCLK              PORT_PCR_MUX_Alt4
#define PTE6_ALT_FTM3_CH1               PORT_PCR_MUX_Alt6
#define PTE6_ALT_USB0_SOF_OUT           PORT_PCR_MUX_Alt7

#define PTE7_PER_INS                    E
#define PTE7_BIT_POS                    7
#define PTE7_ALT_UART3_RTS_b            PORT_PCR_MUX_Alt3
#define PTE7_ALT_I2S0_RXD0              PORT_PCR_MUX_Alt4
#define PTE7_ALT_FTM3_CH2               PORT_PCR_MUX_Alt6

#define PTE8_PER_INS                    E
#define PTE8_BIT_POS                    8
#define PTE8_ALT_I2S0_RXD1              PORT_PCR_MUX_Alt2
#define PTE8_ALT_I2S0_RX_FS             PORT_PCR_MUX_Alt4
#define PTE8_ALT_LPUART0_TX             PORT_PCR_MUX_Alt5
#define PTE8_ALT_FTM3_CH3               PORT_PCR_MUX_Alt6

#define PTE9_PER_INS                    E
#define PTE9_BIT_POS                    9
#define PTE9_ALT_I2S0_TXD1              PORT_PCR_MUX_Alt2
#define PTE9_ALT_I2S0_RX_BCLK           PORT_PCR_MUX_Alt4
#define PTE9_ALT_LPUART0_RX             PORT_PCR_MUX_Alt5
#define PTE9_ALT_FTM3_CH4               PORT_PCR_MUX_Alt6

#define PTE10_PER_INS                   E
#define PTE10_BIT_POS                   10
#define PTE10_ALT_I2C3_SDA              PORT_PCR_MUX_Alt2
#define PTE10_ALT_I2S0_TXD0             PORT_PCR_MUX_Alt4
#define PTE10_ALT_LPUART0_CTS_b         PORT_PCR_MUX_Alt5
#define PTE10_ALT_FTM3_CH5              PORT_PCR_MUX_Alt6
#define PTE10_ALT_USB1_ID               PORT_PCR_MUX_Alt7

#define PTE11_PER_INS                   E
#define PTE11_BIT_POS                   11
#define PTE11_ALT_I2C3_SCL              PORT_PCR_MUX_Alt2
#define PTE11_ALT_I2S0_TX_FS            PORT_PCR_MUX_Alt4
#define PTE11_ALT_LPUART0_RTS_b         PORT_PCR_MUX_Alt5
#define PTE11_ALT_FTM3_CH6              PORT_PCR_MUX_Alt6

#define PTE12_PER_INS                   E
#define PTE12_BIT_POS                   12
#define PTE12_ALT_I2S0_TX_BCLK          PORT_PCR_MUX_Alt4
#define PTE12_ALT_FTM3_CH7              PORT_PCR_MUX_Alt6

#define PTE24_PER_INS                   E
#define PTE24_BIT_POS                   24
#define PTE24_ALT_CAN1_TX               PORT_PCR_MUX_Alt2
#define PTE24_ALT_UART4_TX              PORT_PCR_MUX_Alt3
#define PTE24_ALT_I2C0_SCL              PORT_PCR_MUX_Alt5
#define PTE24_ALT_EWM_OUT_b             PORT_PCR_MUX_Alt6

#define PTE25_PER_INS                   E
#define PTE25_BIT_POS                   25
#define PTE25_ALT_CAN1_RX               PORT_PCR_MUX_Alt2
#define PTE25_ALT_UART4_RX              PORT_PCR_MUX_Alt3
#define PTE25_ALT_I2C0_SDA              PORT_PCR_MUX_Alt5
#define PTE25_ALT_EWM_IN                PORT_PCR_MUX_Alt6

#define PTE26_PER_INS                   E
#define PTE26_BIT_POS                   26
#define PTE26_ALT_ENET_1588_CLKIN       PORT_PCR_MUX_Alt2
#define PTE26_ALT_UART4_CTS_b           PORT_PCR_MUX_Alt3
#define PTE26_ALT_RTC_CLKOUT            PORT_PCR_MUX_Alt6
#define PTE26_ALT_USB0_CLKIN            PORT_PCR_MUX_Alt7

#define PTE27_PER_INS                   E
#define PTE27_BIT_POS                   27
#define PTE27_ALT_UART4_RTS_b           PORT_PCR_MUX_Alt3

#define PTE28_PER_INS                   E
#define PTE28_BIT_POS                   28

#endif //MK66_MUX_144_MAPBGA_H_
