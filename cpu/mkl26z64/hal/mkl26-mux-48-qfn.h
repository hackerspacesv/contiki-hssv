//+------------------------------------------------------------------------------------------------+
//| Port mux definitions for Kinetis MKL26 MCU.                                                    |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_MUX_48_QFN_H_
#define MKL26_MUX_48_QFN_H_

#define PTA0_PER_INS                A
#define PTA0_BIT_POS                0
#define PTA0_ALT_TPM0_CH5           PORT_PCR_MUX_Alt3
#define PTA0_ALT_SWD_CLK            PORT_PCR_MUX_Alt7

#define PTA1_PER_INS                A
#define PTA1_BIT_POS                1
#define PTA1_ALT_UART0_RX           PORT_PCR_MUX_Alt2
#define PTA1_ALT_TPM2_CH0           PORT_PCR_MUX_Alt3

#define PTA2_PER_INS                A
#define PTA2_BIT_POS                2
#define PTA2_ALT_UART0_TX           PORT_PCR_MUX_Alt2
#define PTA2_ALT_TPM2_CH1           PORT_PCR_MUX_Alt3

#define PTA3_PER_INS                A
#define PTA3_BIT_POS                3
#define PTA3_ALT_I2C1_SCL           PORT_PCR_MUX_Alt2
#define PTA3_ALT_TPM0_CH0           PORT_PCR_MUX_Alt3
#define PTA3_ALT_SWD_DIO            PORT_PCR_MUX_Alt7

#define PTA4_PER_INS                A
#define PTA4_BIT_POS                4
#define PTA4_ALT_I2C1_SDA           PORT_PCR_MUX_Alt2
#define PTA4_ALT_TPM0_CH1           PORT_PCR_MUX_Alt3
#define PTA4_ALT_NMI_b              PORT_PCR_MUX_Alt7

#define PTA18_PER_INS               A
#define PTA18_BIT_POS               18
#define PTA18_ALT_UART1_RX          PORT_PCR_MUX_Alt3
#define PTA18_ALT_TPM_CLKIN0        PORT_PCR_MUX_Alt4

#define PTA19_PER_INS               A
#define PTA19_BIT_POS               19
#define PTA19_UART1_TX              PORT_PCR_MUX_Alt3
#define PTA19_TPM_CLKIN1            PORT_PCR_MUX_Alt4
#define PTA19_LPTMR0_ALT1           PORT_PCR_MUX_Alt6

#define PTA20_PER_INS               A
#define PTA20_BIT_POS               20
#define PTA20_ALT_RESET_b           PORT_PCR_MUX_Alt7

#define PTB0_PER_INS                B
#define PTB0_BIT_POS                0
#define PTB0_ALT_I2C0_SCL           PORT_PCR_MUX_Alt2
#define PTB0_ALT_TPM1_CH0           PORT_PCR_MUX_Alt3

#define PTB1_PER_INS                B
#define PTB1_BIT_POS                1
#define PTB1_ALT_I2C0_SDA           PORT_PCR_MUX_Alt2
#define PTB1_ALT_TPM1_CH1           PORT_PCR_MUX_Alt3

#define PTB2_PER_INS                B
#define PTB2_BIT_POS                2
#define PTB2_ALT_I2C0_SCL           PORT_PCR_MUX_Alt2
#define PTB2_ALT_TPM2_CH0           PORT_PCR_MUX_Alt3

#define PTB3_PER_INS                B
#define PTB3_BIT_POS                3
#define PTB3_ALT_I2C0_SDA           PORT_PCR_MUX_Alt2
#define PTB3_ALT_TPM2_CH1           PORT_PCR_MUX_Alt3

#define PTB16_PER_INS               B
#define PTB16_BIT_POS               16
#define PTB16_ALT_SPI1_MOSI         PORT_PCR_MUX_Alt2
#define PTB16_ALT_UART0_RX          PORT_PCR_MUX_Alt3
#define PTB16_ALT_TPM_CLKIN0        PORT_PCR_MUX_Alt4
#define PTB16_ALT_SPI1_MISO         PORT_PCR_MUX_Alt5

#define PTB17_PER_INS               B
#define PTB17_BIT_POS               17
#define PTB17_ALT_SPI1_MISO         PORT_PCR_MUX_Alt2
#define PTB17_ALT_UART0_TX          PORT_PCR_MUX_Alt3
#define PTB17_ALT_TPM_CLKIN1        PORT_PCR_MUX_Alt4
#define PTB17_ALT_SPI1_MOSI         PORT_PCR_MUX_Alt5

#define PTC0_PER_INS                C
#define PTC0_BIT_POS                0
#define PTC0_ALT_EXTRG_IN           PORT_PCR_MUX_Alt3
#define PTC0_ALT_audioUSB_SOF_OUT   PORT_PCR_MUX_Alt4
#define PTC0_ALT_CMP0_OUT           PORT_PCR_MUX_Alt5
#define PTC0_ALT_I2S0_TXD0          PORT_PCR_MUX_Alt6

#define PTC1_PER_INS                C
#define PTC1_BIT_POS                1
#define PTC1_ALT_I2C1_SCL           PORT_PCR_MUX_Alt2
#define PTC1_ALT_TMP0_CH0           PORT_PCR_MUX_Alt4
#define PTC1_ALT_I2S0_TXD0          PORT_PCR_MUX_Alt6

#define PTC2_PER_INS                C
#define PTC2_BIT_POS                2
#define PTC2_ALT_I2C1_SDA           PORT_PCR_MUX_Alt2
#define PTC2_ALT_TPM0_CH1           PORT_PCR_MUX_Alt4
#define PTC2_ALT_I2S0_TX_FS         PORT_PCR_MUX_Alt6

#define PTC3_PER_INS                C
#define PTC3_BIT_POS                3
#define PTC3_ALT_UART1_RX           PORT_PCR_MUX_Alt3
#define PTC3_ALT_TPM0_CH2           PORT_PCR_MUX_Alt4
#define PTC3_ALT_CLKOUT             PORT_PCR_MUX_Alt5
#define PTC3_ALT_I2S0_TX_BCLK       PORT_PCR_MUX_Alt6

#define PTC4_PER_INS                C
#define PTC4_BIT_POS                4
#define PTC4_ALT_SPI0_PCS0          PORT_PCR_MUX_Alt2
#define PTC4_ALT_UART1_TX           PORT_PCR_MUX_Alt3
#define PTC4_ALT_TPM0_CH3           PORT_PCR_MUX_Alt4
#define PTC4_ALT_I2S0_MCLK          PORT_PCR_MUX_Alt5

#define PTC5_PER_INS                C
#define PTC5_BIT_POS                5
#define PTC5_ALT_SPI0_SCK           PORT_PCR_MUX_Alt2
#define PTC5_ALT_LPTMR0_ALT2        PORT_PCR_MUX_Alt3
#define PTC5_ALT_I2S0_RXD0          PORT_PCR_MUX_Alt4
#define PTC5_ALT_CMP0_OUT           PORT_PCR_MUX_Alt6

#define PTC6_PER_INS                C
#define PTC6_BIT_POS                6
#define PTC6_ALT_SPI0_MOSI          PORT_PCR_MUX_Alt2
#define PTC6_ALT_EXTRG_IN           PORT_PCR_MUX_Alt3
#define PTC6_ALT_I2S0_RX_BCLK       PORT_PCR_MUX_Alt4
#define PTC6_ALT_SPI0_MISO          PORT_PCR_MUX_Alt5
#define PTC6_ALT_I2S0_MCLK          PORT_PCR_MUX_Alt6

#define PTC7_PER_INS                C
#define PTC7_BIT_POS                7
#define PTC7_ALT_SPI0_MISO          PORT_PCR_MUX_Alt2
#define PTC7_ALT_audioUSB_SOF_OUT   PORT_PCR_MUX_Alt3
#define PTC7_ALT_I2S0_RX_FS         PORT_PCR_MUX_Alt4
#define PTC7_ALT_SPI0_MOSI          PORT_PCR_MUX_Alt5

#define PTD0_PER_INS                D
#define PTD0_BIT_POS                0
#define PTD0_ALT_SPI0_PCS0          PORT_PCR_MUX_Alt2
#define PTD0_ALT_TPM0_CH0           PORT_PCR_MUX_Alt4

#define PTD1_PER_INS                D
#define PTD1_BIT_POS                1
#define PTD1_ALT_SPI0_SCK           PORT_PCR_MUX_Alt2
#define PTD1_ALT_TPM0_CH1           PORT_PCR_MUX_Alt4

#define PTD2_PER_INS                D
#define PTD2_BIT_POS                2
#define PTD2_ALT_SPI0_MOSI          PORT_PCR_MUX_Alt2
#define PTD2_ALT_UART2_RX           PORT_PCR_MUX_Alt3
#define PTD2_ALT_TPM0_CH2           PORT_PCR_MUX_Alt4
#define PTD2_ALT_SPI0_MISO          PORT_PCR_MUX_Alt5

#define PTD3_PER_INS                D
#define PTD3_BIT_POS                3
#define PTD3_ALT_SPI0_MISO          PORT_PCR_MUX_Alt2
#define PTD3_ALT_UART2_TX           PORT_PCR_MUX_Alt3
#define PTD3_ALT_TPM0_CH3           PORT_PCR_MUX_Alt4
#define PTD3_ALT_SPI0_MOSI          PORT_PCR_MUX_Alt5

#define PTD4_PER_INS                D
#define PTD4_BIT_POS                4
#define PTD4_ALT_SPI1_PCS0          PORT_PCR_MUX_Alt2
#define PTD4_ALT_UART2_RX           PORT_PCR_MUX_Alt3
#define PTD4_ALT_TPM0_CH4           PORT_PCR_MUX_Alt4

#define PTD5_PER_INS                D
#define PTD5_BIT_POS                5
#define PTD5_ALT_SPI1_SCK           PORT_PCR_MUX_Alt2
#define PTD5_ALT_UART2_TX           PORT_PCR_MUX_Alt3
#define PTD5_ALT_TPM0_CH5           PORT_PCR_MUX_Alt4

#define PTD6_PER_INS                D
#define PTD6_BIT_POS                6
#define PTD6_ALT_SPI1_MOSI          PORT_PCR_MUX_Alt2
#define PTD6_ALT_UART0_RX           PORT_PCR_MUX_Alt3
#define PTD6_ALT_SPI1_MISO          PORT_PCR_MUX_Alt5

#define PTD7_PER_INS                D
#define PTD7_BIT_POS                7
#define PTD7_ALT_SPI1_MISO          PORT_PCR_MUX_Alt2
#define PTD7_ALT_UART0_TX           PORT_PCR_MUX_Alt3
#define PTD7_ALT_SPI1_MOSI          PORT_PCR_MUX_Alt5

#define PTE20_PER_INS               E
#define PTE20_BIT_POS               20
#define PTE20_ALT_TPM1_CH0          PORT_PCR_MUX_Alt3
#define PTE20_ALT_UART0_TX          PORT_PCR_MUX_Alt4

#define PTE21_PER_INS               E
#define PTE21_BIT_POS               21
#define PTE21_ALT_TPM1_CH1          PORT_PCR_MUX_Alt3
#define PTE21_ALT_UART0_RX          PORT_PCR_MUX_Alt4

#define PTE24_PER_INS               E
#define PTE24_BIT_POS               24
#define PTE24_ALT_TPM0_CH0          PORT_PCR_MUX_Alt3
#define PTE24_ALT_I2C0_SCL          PORT_PCR_MUX_Alt5

#define PTE25_PER_INS               E
#define PTE25_BIT_POS               25
#define PTE25_ALT_TPM0_CH1          PORT_PCR_MUX_Alt3
#define PTE25_ALT_I2C0_SDA          PORT_PCR_MUX_Alt5

#define PTE29_PER_INS               E
#define PTE29_BIT_POS               29
#define PTE29_ALT_TPM0_CH2          PORT_PCR_MUX_Alt3
#define PTE29_ALT_TPM_CLKIN0        PORT_PCR_MUX_Alt4

#define PTE30_PER_INS               E
#define PTE30_BIT_POS               30
#define PTE30_ALT_TPM0_CH3          PORT_PCR_MUX_Alt3
#define PTE30_ALT_TPM_CLKIN1        PORT_PCR_MUX_Alt4

#endif //MKL26_MUX_48_QFN_H_
