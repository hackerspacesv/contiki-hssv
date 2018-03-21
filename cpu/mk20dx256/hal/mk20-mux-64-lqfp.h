//+------------------------------------------------------------------------------------------------+
//| Port mux definitions for Kinetis MK20 MCU.                                                     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK20_MUX_64_LQFP_H_
#define MK20_MUX_64_LQFP_H_

#define PTA0_PER_INS            A
#define PTA0_BIT_POS            0
#define PTA0_ALT_UART0_CTS_b    PORT_PCR_MUX_Alt2
#define PTA0_ALT_UART0_COL_b    PORT_PCR_MUX_Alt2
#define PTA0_ALT_FTM0_CH5       PORT_PCR_MUX_Alt3
#define PTA0_ALT_JTAG_TCLK      PORT_PCR_MUX_Alt7
#define PTA0_ALT_SWD_CLK        PORT_PCR_MUX_Alt7

#define PTA1_PER_INS            A
#define PTA1_BIT_POS            1
#define PTA1_ALT_UART0_RX       PORT_PCR_MUX_Alt2
#define PTA1_ALT_FTM0_CH6       PORT_PCR_MUX_Alt3
#define PTA1_ALT_JTAG_TDI       PORT_PCR_MUX_Alt7

#define PTA2_PER_INS            A
#define PTA2_BIT_POS            2
#define PTA2_ALT_UART0_TX       PORT_PCR_MUX_Alt2
#define PTA2_ALT_FTM0_CH7       PORT_PCR_MUX_Alt3
#define PTA2_ALT_JTAG_TDO       PORT_PCR_MUX_Alt7
#define PTA2_ALT_TRACE_SWO      PORT_PCR_MUX_Alt7

#define PTA3_PER_INS            A
#define PTA3_BIT_POS            3
#define PTA3_ALT_UART0_RTS_b    PORT_PCR_MUX_Alt2
#define PTA3_ALT_FTM0_CH0       PORT_PCR_MUX_Alt3
#define PTA3_ALT_JTAG_TMS       PORT_PCR_MUX_Alt7
#define PTA3_ALT_SWD_DIO        PORT_PCR_MUX_Alt7

#define PTA4_PER_INS            A
#define PTA4_BIT_POS            4
#define PTA4_ALT_FTM0_CH1       PORT_PCR_MUX_Alt3
#define PTA4_ALT_NMI_b          PORT_PCR_MUX_Alt7

#define PTA5_PER_INS            A
#define PTA5_BIT_POS            5
#define PTA5_ALT_USB_CLKIN      PORT_PCR_MUX_Alt2
#define PTA5_ALT_FTM0_CH2       PORT_PCR_MUX_Alt3
#define PTA5_ALT_CMP2_OUT       PORT_PCR_MUX_Alt5
#define PTA5_ALT_I2S0_TX_BCLK   PORT_PCR_MUX_Alt6
#define PTA5_ALT_JTAG_TRST_b    PORT_PCR_MUX_Alt7

#define PTA12_PER_INS           A
#define PTA12_BIT_POS           12
#define PTA12_ALT_CAN0_TX       PORT_PCR_MUX_Alt2
#define PTA12_ALT_FTM1_CH0      PORT_PCR_MUX_Alt3
#define PTA12_ALT_I2S0_TXD0     PORT_PCR_MUX_Alt6
#define PTA12_ALT_FTM1_QD_PHA   PORT_PCR_MUX_Alt7

#define PTA13_PER_INS           A
#define PTA13_BIT_POS           13
#define PTA13_ALT_CAN0_RX       PORT_PCR_MUX_Alt2
#define PTA13_ALT_FTM1_CH1      PORT_PCR_MUX_Alt3
#define PTA13_ALT_I2S0_TX_FS    PORT_PCR_MUX_Alt6
#define PTA13_ALT_FTM1_QD_PHB   PORT_PCR_MUX_Alt7

#define PTA18_PER_INS           A
#define PTA18_BIT_POS           18
#define PTA18_ALT_FTM0_FLT2     PORT_PCR_MUX_Alt3
#define PTA18_ALT_FTM_CLKIN0    PORT_PCR_MUX_Alt4

#define PTA19_PER_INS           A
#define PTA19_BIT_POS           19
#define PTA19_ALT_FTM1_FLT0     PORT_PCR_MUX_Alt3
#define PTA19_ALT_FTM_CLKIN1    PORT_PCR_MUX_Alt4
#define PTA19_ALT_LPTMR0_ALT1   PORT_PCR_MUX_Alt6

#define PTB0_PER_INS            B
#define PTB0_BIT_POS            0
#define PTB0_ALT_I2C0_SCL       PORT_PCR_MUX_Alt2
#define PTB0_ALT_FTM1_CH0       PORT_PCR_MUX_Alt3
#define PTB0_ALT_FTM1_QD_PHA    PORT_PCR_MUX_Alt6

#define PTB1_PER_INS            B
#define PTB1_BIT_POS            1
#define PTB1_ALT_I2C0_SDA       PORT_PCR_MUX_Alt2
#define PTB1_ALT_FTM1_CH1       PORT_PCR_MUX_Alt3
#define PTB1_ALT_FTM1_QD_PHB    PORT_PCR_MUX_Alt6

#define PTB2_PER_INS            B
#define PTB2_BIT_POS            2
#define PTB2_ALT_I2C0_SCL       PORT_PCR_MUX_Alt2
#define PTB2_ALT_UART0_RTS_b    PORT_PCR_MUX_Alt3
#define PTB2_ALT_FTM0_FLT3      PORT_PCR_MUX_Alt6

#define PTB3_PER_INS            B
#define PTB3_BIT_POS            3
#define PTB3_ALT_I2C0_SDA       PORT_PCR_MUX_Alt2
#define PTB3_ALT_UART0_CTS_b    PORT_PCR_MUX_Alt3
#define PTB3_ALT_UART0_COL_b    PORT_PCR_MUX_Alt3
#define PTB3_ALT_FTM0_FLT0      PORT_PCR_MUX_Alt6

#define PTB16_PER_INS           B
#define PTB16_BIT_POS           16
#define PTB16_ALT_SPI1_SOUT     PORT_PCR_MUX_Alt2
#define PTB16_ALT_UART0_RX      PORT_PCR_MUX_Alt3
#define PTB16_ALT_FB_AD17       PORT_PCR_MUX_Alt5
#define PTB16_ALT_EWM_IN        PORT_PCR_MUX_Alt6

#define PTB17_PER_INS           B
#define PTB17_BIT_POS           17
#define PTB17_ALT_SPI1_SIN      PORT_PCR_MUX_Alt2
#define PTB17_ALT_UART0_TX      PORT_PCR_MUX_Alt3
#define PTB17_ALT_FB_AD16       PORT_PCR_MUX_Alt5
#define PTB17_ALT_EWM_OUT_b     PORT_PCR_MUX_Alt6

#define PTB18_PER_INS           B
#define PTB18_BIT_POS           18
#define PTB18_ALT_CAN0_TX       PORT_PCR_MUX_Alt2
#define PTB18_ALT_FTM2_CH0      PORT_PCR_MUX_Alt3
#define PTB18_ALT_I2S0_TX_BCLK  PORT_PCR_MUX_Alt4
#define PTB18_ALT_FB_AD15       PORT_PCR_MUX_Alt5
#define PTB18_ALT_FTM2_QD_PHA   PORT_PCR_MUX_Alt6

#define PTB19_PER_INS           B
#define PTB19_BIT_POS           19
#define PTB19_ALT_CAN0_RX       PORT_PCR_MUX_Alt2
#define PTB19_ALT_FTM2_CH1      PORT_PCR_MUX_Alt3
#define PTB19_ALT_I2S0_TX_FS    PORT_PCR_MUX_Alt4
#define PTB19_ALT_FB_OE_b       PORT_PCR_MUX_Alt5
#define PTB19_ALT_FTM2_QD_PHB   PORT_PCR_MUX_Alt6

#define PTC0_PER_INS            C
#define PTC0_BIT_POS            0
#define PTC0_ALT_SPI0_PCS4      PORT_PCR_MUX_Alt2
#define PTC0_ALT_PDB0_EXTRG     PORT_PCR_MUX_Alt3
#define PTC0_ALT_FB_AD14        PORT_PCR_MUX_Alt5
#define PTC0_ALT_I2S0_TXD1      PORT_PCR_MUX_Alt6

#define PTC1_PER_INS            C
#define PTC1_BIT_POS            1
#define PTC1_ALT_SPI0_PCS3      PORT_PCR_MUX_Alt2
#define PTC1_ALT_UART1_RTS_b    PORT_PCR_MUX_Alt3
#define PTC1_ALT_FTM0_CH0       PORT_PCR_MUX_Alt4
#define PTC1_ALT_FB_AD13        PORT_PCR_MUX_Alt5
#define PTC1_ALT_I2S0_TXD0      PORT_PCR_MUX_Alt6

#define PTC2_PER_INS            C
#define PTC2_BIT_POS            2
#define PTC2_ALT_SPI0_PCS2      PORT_PCR_MUX_Alt2
#define PTC2_ALT_UART1_CTS_b    PORT_PCR_MUX_Alt3
#define PTC2_ALT_FTM0_CH1       PORT_PCR_MUX_Alt4
#define PTC2_ALT_FB_AD12        PORT_PCR_MUX_Alt5
#define PTC2_ALT_I2S0_TX_FS     PORT_PCR_MUX_Alt6

#define PTC3_PER_INS            C
#define PTC3_BIT_POS            3
#define PTC3_ALT_SPI0_PCS1      PORT_PCR_MUX_Alt2
#define PTC3_ALT_UART1_RX       PORT_PCR_MUX_Alt3
#define PTC3_ALT_FTM0_CH2       PORT_PCR_MUX_Alt4
#define PTC3_ALT_CLKOUT         PORT_PCR_MUX_Alt5
#define PTC3_ALT_I2S0_TX_BCLK   PORT_PCR_MUX_Alt6

#define PTC4_PER_INS            C
#define PTC4_BIT_POS            4
#define PTC4_ALT_SPI0_PCS0      PORT_PCR_MUX_Alt2
#define PTC4_ALT_UART1_TX       PORT_PCR_MUX_Alt3
#define PTC4_ALT_FTM0_CH3       PORT_PCR_MUX_Alt4
#define PTC4_ALT_FB_AD11        PORT_PCR_MUX_Alt5
#define PTC4_ALT_CMP1_OUT       PORT_PCR_MUX_Alt6

#define PTC5_PER_INS            C
#define PTC5_BIT_POS            5
#define PTC5_ALT_SPI0_SCK       PORT_PCR_MUX_Alt2
#define PTC5_ALT_LPTMR0_ALT2    PORT_PCR_MUX_Alt3
#define PTC5_ALT_I2S0_RXD0      PORT_PCR_MUX_Alt4
#define PTC5_ALT_FB_AD10        PORT_PCR_MUX_Alt5
#define PTC5_ALT_CMP0_OUT       PORT_PCR_MUX_Alt6

#define PTC6_PER_INS            C
#define PTC6_BIT_POS            6
#define PTC6_ALT_SPI0_SOUT      PORT_PCR_MUX_Alt2
#define PTC6_ALT_PDB0_EXTRG     PORT_PCR_MUX_Alt3
#define PTC6_ALT_I2S0_RX_BCLK   PORT_PCR_MUX_Alt4
#define PTC6_ALT_FB_AD9         PORT_PCR_MUX_Alt5
#define PTC6_ALT_I2S0_MCLK      PORT_PCR_MUX_Alt6

#define PTC7_PER_INS            C
#define PTC7_BIT_POS            7
#define PTC7_ALT_SPI0_SIN       PORT_PCR_MUX_Alt2
#define PTC7_ALT_USB_SOF_OUT    PORT_PCR_MUX_Alt3
#define PTC7_ALT_I2S0_RX_FS     PORT_PCR_MUX_Alt4
#define PTC7_ALT_FB_AD8         PORT_PCR_MUX_Alt5

#define PTC8_PER_INS            C
#define PTC8_BIT_POS            8
#define PTC8_ALT_I2S0_MCLK      PORT_PCR_MUX_Alt4
#define PTC8_ALT_FB_AD7         PORT_PCR_MUX_Alt5

#define PTC9_PER_INS            C
#define PTC9_BIT_POS            9
#define PTC9_ALT_I2S0_RX_BCLK   PORT_PCR_MUX_Alt4
#define PTC9_ALT_FB_AD6         PORT_PCR_MUX_Alt5
#define PTC9_ALT_FTM2_FLT0      PORT_PCR_MUX_Alt6

#define PTC10_PER_INS           C
#define PTC10_BIT_POS           10
#define PTC10_ALT_I2C1_SCL      PORT_PCR_MUX_Alt2
#define PTC10_ALT_I2S0_RX_FS    PORT_PCR_MUX_Alt4
#define PTC10_ALT_FB_AD5        PORT_PCR_MUX_Alt5

#define PTC11_PER_INS           C
#define PTC11_BIT_POS           11
#define PTC11_ALT_I2C1_SDA      PORT_PCR_MUX_Alt2
#define PTC11_ALT_I2S0_RXD1     PORT_PCR_MUX_Alt4
#define PTC11_ALT_FB_RW_b       PORT_PCR_MUX_Alt5

#define PTD0_PER_INS            D
#define PTD0_BIT_POS            0
#define PTD0_ALT_SPI0_PCS0      PORT_PCR_MUX_Alt2
#define PTD0_ALT_UART2_RTS_b    PORT_PCR_MUX_Alt3
#define PTD0_ALT_FB_ALE         PORT_PCR_MUX_Alt5
#define PTD0_ALT_FB_CS1_b       PORT_PCR_MUX_Alt5
#define PTD0_ALT_FB_TS_b        PORT_PCR_MUX_Alt5

#define PTD1_PER_INS            D
#define PTD1_BIT_POS            1
#define PTD1_ALT_SPI0_SCK       PORT_PCR_MUX_Alt2
#define PTD1_ALT_UART2_CTS_b    PORT_PCR_MUX_Alt3
#define PTD1_ALT_FB_CS0_b       PORT_PCR_MUX_Alt5

#define PTD2_PER_INS            D
#define PTD2_BIT_POS            2
#define PTD2_ALT_SPI0_SOUT      PORT_PCR_MUX_Alt2
#define PTD2_ALT_UART2_RX       PORT_PCR_MUX_Alt3
#define PTD2_ALT_FB_AD4         PORT_PCR_MUX_Alt5

#define PTD3_PER_INS            D
#define PTD3_BIT_POS            3
#define PTD3_ALT_SPI0_SIN       PORT_PCR_MUX_Alt2
#define PTD3_ALT_UART2_TX       PORT_PCR_MUX_Alt3
#define PTD3_ALT_FB_AD3         PORT_PCR_MUX_Alt5

#define PTD4_PER_INS            D
#define PTD4_BIT_POS            4
#define PTD4_ALT_SPI0_PCS1      PORT_PCR_MUX_Alt2
#define PTD4_ALT_UART0_RTS_b    PORT_PCR_MUX_Alt3
#define PTD4_ALT_FTM0_CH4       PORT_PCR_MUX_Alt4
#define PTD4_ALT_FB_AD2         PORT_PCR_MUX_Alt5
#define PTD4_ALT_EWM_IN         PORT_PCR_MUX_Alt6

#define PTD5_PER_INS            D
#define PTD5_BIT_POS            5
#define PTD5_ALT_SPI0_PCS2      PORT_PCR_MUX_Alt2
#define PTD5_ALT_UART0_CTS_b    PORT_PCR_MUX_Alt3
#define PTD5_ALT_UART0_COL_b    PORT_PCR_MUX_Alt3
#define PTD5_ALT_FTM0_CH5       PORT_PCR_MUX_Alt4
#define PTD5_ALT_FB_AD1         PORT_PCR_MUX_Alt5
#define PTD5_ALT_EWM_OUT_b      PORT_PCR_MUX_Alt6

#define PTD6_PER_INS            D
#define PTD6_BIT_POS            6
#define PTD6_ALT_SPI0_PCS3      PORT_PCR_MUX_Alt2
#define PTD6_ALT_UART0_RX       PORT_PCR_MUX_Alt3
#define PTD6_ALT_FTM0_CH6       PORT_PCR_MUX_Alt4
#define PTD6_ALT_FB_AD0         PORT_PCR_MUX_Alt5
#define PTD6_ALT_FTM0_FLT0      PORT_PCR_MUX_Alt6

#define PTD7_PER_INS            D
#define PTD7_BIT_POS            7
#define PTD7_ALT_CMT_IRO        PORT_PCR_MUX_Alt2
#define PTD7_ALT_UART0_TX       PORT_PCR_MUX_Alt3
#define PTD7_ALT_FTM0_CH7       PORT_PCR_MUX_Alt4
#define PTD7_ALT_FTM0_FLT1      PORT_PCR_MUX_Alt6

#define PTE0_PER_INS            E
#define PTE0_BIT_POS            0
#define PTE0_ALT_SPI1_PCS1      PORT_PCR_MUX_Alt2
#define PTE0_ALT_UART1_TX       PORT_PCR_MUX_Alt3
#define PTE0_ALT_I2C1_SDA       PORT_PCR_MUX_Alt6
#define PTE0_ALT_RTC_CLKOUT     PORT_PCR_MUX_Alt7

#define PTE1_PER_INS            E
#define PTE1_BIT_POS            1
#define PTE1_ALT_SPI1_SOUT      PORT_PCR_MUX_Alt2
#define PTE1_ALT_UART1_RX       PORT_PCR_MUX_Alt3
#define PTE1_ALT_I2C1_SCL       PORT_PCR_MUX_Alt6
#define PTE1_ALT_SPI1_SIN       PORT_PCR_MUX_Alt7

#endif //MK20_MUX_64_LQFP_H_
