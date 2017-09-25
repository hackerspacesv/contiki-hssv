//+------------------------------------------------------------------------------------------------+
//| SPI peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_SPI_H_
#define MKL26_SPI_H_

#include <stdint.h>

struct SPI_type {
  uint8_t S;              //Status register
  uint8_t BR;             //Baud rate register
  uint8_t C2;             //Control register 2
  uint8_t C1;             //Control register 1
  uint8_t ML;             //Match register low
  uint8_t MH;             //Match register high
  uint8_t DL;             //Data register low
  uint8_t DH;             //Data register high
  uint8_t CI;             //Clear interrupt register
  uint8_t C3;             //Control register 3
};

#define SPI0 ((volatile struct SPI_type *) 0x40076000)
#define SPI1 ((volatile struct SPI_type *) 0x40077000)

//Status register bitfields
#define SPI_S_RFIFOEF_Has_Data    (0 << 0)  //SPI read FIFO empty flag
#define SPI_S_RFIFOEF_Empty       (1 << 0)
#define SPI_S_TXFULLF_Has_SPace   (0 << 1)  //Transmit FIFO full flag
#define SPI_S_TXFULLF_Full        (1 << 1)
#define SPI_S_TNEAREF_Has_Data    (0 << 2)  //Transmit FIFO nearly empty flag
#define SPI_S_TNEAREF_Near_Empty  (1 << 2)
#define SPI_S_RNFULLF_Has_Space   (0 << 3)  //Receive FIFO nearly full flag
#define SPI_S_RNFULLF_Near_Full   (1 << 3)
#define SPI_S_MODF_Clear          (0 << 4)  //Master mode fault flag
#define SPI_S_MODF_Set            (1 << 4)
#define SPI_S_SPTEF_Not_Empty     (0 << 5)  //SPI transmit buffer/FIFO empty flag
#define SPI_S_SPTEF_Empty         (1 << 5)
#define SPI_S_SPMF_Clear          (0 << 6)  //SPI match flag
#define SPI_S_SPMF_Set            (1 << 6)
#define SPI_S_SPRF_Not_Full       (0 << 7)  //SPI read buffer/FIFO full flag
#define SPI_S_SPRF_Full           (1 << 7)

//Baud rate register bitfields
#define SPI_BR_SPR_Msk      0x0F  //SPI baud rate divisor
#define SPI_BR_SPR_Pos      0
#define SPI_BR_SPR_Div_2    0
#define SPI_BR_SPR_Div_4    1
#define SPI_BR_SPR_Div_8    2
#define SPI_BR_SPR_Div_16   3
#define SPI_BR_SPR_Div_32   4
#define SPI_BR_SPR_Div_64   5
#define SPI_BR_SPR_Div_128  6
#define SPI_BR_SPR_Div_256  7
#define SPI_BR_SPR_Div_512  8
#define SPI_BR_SPPR_Msk     0x70  //SPI Baud rate prescale divisor
#define SPI_BR_SPPR_Pos     4
#define SPI_BR_SPPR_Div_1   0
#define SPI_BR_SPPR_Div_2   1
#define SPI_BR_SPPR_Div_3   2
#define SPI_BR_SPPR_Div_4   3
#define SPI_BR_SPPR_Div_5   4
#define SPI_BR_SPPR_Div_6   5
#define SPI_BR_SPPR_Div_7   6
#define SPI_BR_SPPR_Div_8   7

//Control register 2 bitfields
#define SPI_C2_SPC0_Normal          (0 << 0)  //SPI pin control 0
#define SPI_C2_SPC0_Bidirectional   (1 << 0)
#define SPI_C2_SPISWAI_Continue     (0 << 1)  //SPI stop in wait mode
#define SPI_C2_SPISWAI_Stop         (1 << 1)
#define SPI_C2_RXDMAE_DisDMA_EnIRQ  (0 << 2)  //Receive DMA enable
#define SPI_C2_RXDMAE_EnDMA_DisIRQ  (1 << 2)
#define SPI_C2_BIDIROE_Input        (0 << 3)  //Bidirectional mode output enable
#define SPI_C2_BIDIROE_Output       (1 << 3)
#define SPI_C2_MODFEN_Disabled      (0 << 4)  //Master mode fault function enable
#define SPI_C2_MODFEN_Enabled       (1 << 4)
#define SPI_C2_TXDMAE_DisDMA_EnIRQ  (0 << 5)  //Transmit DMA enable
#define SPI_C2_TXDMAE_EnDMA_DisIRQ  (1 << 5)
#define SPI_C2_SPIMODE_8_Bit        (0 << 6)  //SPI 8-bit or 16-bit mode
#define SPI_C2_SPIMODE_16_Bit       (1 << 6)
#define SPI_C2_SPMIE_Disabled       (0 << 7)  //SPI match interrupt enable
#define SPI_C2_SPMIE_Enabled        (1 << 7)

//Control register 1 bitfields
#define SPI_C1_LSBFE_MSB_First      (0 << 0)  //LSB first (shifter direction)
#define SPI_C1_LSBFE_LSB_First      (1 << 0)
#define SPI_C1_SSOE_In_Mode_Fault   (0 << 1)  //Slave select output enable
#define SPI_C1_SSOE_Out_Auto_SS     (1 << 1)
#define SPI_C1_CPHA_0               (0 << 2)  //Clock phase
#define SPI_C1_CPHA_1               (1 << 2)
#define SPI_C1_CPOL_0               (0 << 3)  //Clock polarity
#define SPI_C1_CPOL_1               (1 << 3)
#define SPI_C1_MSTR_Slave           (0 << 4)  //Master/slave mode select
#define SPI_C1_MSTR_Master          (1 << 4)
#define SPI_C1_SPTIE_Disabled       (0 << 5)  //SPI transmit interrupt enable
#define SPI_C1_SPTIE_Enabled        (1 << 5)
#define SPI_C1_SPE_Disabled         (0 << 6)  //SPI system enable
#define SPI_C1_SPE_Enabled          (1 << 6)
#define SPI_C1_SPIE_Disabled        (0 << 7)  //SPI interrupt enable
#define SPI_C1_SPIE_Enabled         (1 << 7)

//Clear interrupt register bitfields
#define SPI_CI_SPRFCI_Clear     (0 << 0)  //Receive FIFO full flag clear interrupt
#define SPI_CI_SPRFCI_Set       (1 << 0)
#define SPI_CI_SPTEFCI_Clear    (0 << 1)  //Transmit FIFO empty flag clear interrupt
#define SPI_CI_SPTEFCI_Set      (1 << 1)
#define SPI_CI_RNFULLFCI_Clear  (0 << 2)  //Receive FIFO nearly full flag clear interrupt
#define SPI_CI_RNFULLFCI_Set    (1 << 2)
#define SPI_CI_TNEAREFCI_Clear  (0 << 3)  //Transmit FIFO nearly empty flag clear interrupt
#define SPI_CI_TNEAREFCI_Set    (1 << 3)
#define SPI_CI_RXFOF_Clear      (0 << 4)  //Receive FIFO overflow flag
#define SPI_CI_RXFOF_Set        (1 << 4)
#define SPI_CI_TXFOF_Clear      (0 << 5)  //Transmit FIFO overflow flag
#define SPI_CI_TXFOF_Set        (1 << 5)
#define SPI_CI_RXFERR_Clear     (0 << 6)  //Receive FIFO error flag
#define SPI_CI_RXFERR_Set       (1 << 6)
#define SPI_CI_TXFERR_Clear     (0 << 7)  //Transmit FIFO error flag
#define SPI_CI_TXFERR_Set       (1 << 7)

//Control register 3 bitfields
#define SPI_C3_FIFOMODE_Disabled      (0 << 0)  //FIFO mode enable
#define SPI_C3_FIFOMODE_Enabled       (1 << 0)
#define SPI_C3_RNFULLIEN_Disabled     (0 << 1)  //Receive FIFO nearly full interrupt enable
#define SPI_C3_RNFULLIEN_Enabled      (1 << 1)
#define SPI_C3_TNEARIEN_Disabled      (0 << 2)  //Transmit FIFO nearly empty interrupt enable
#define SPI_C3_TNEARIEN_Enabled       (1 << 2)
#define SPI_C3_INTCLR_Automatic       (0 << 3)  //Interrupt clearing mechanism select
#define SPI_C3_INTCLR_Manual          (1 << 3)
#define SPI_C3_RNFULLF_MARK_48_Bits   (0 << 4)  //Receive FIFO nearly full watermark
#define SPI_C3_RNFULLF_MARK_32_Bits   (1 << 4)
#define SPI_C3_TNEAREF_MARK_16_Bits   (0 << 5)  //Transmit FIFO nearly empty watermark
#define SPI_C3_TNEAREF_MARK_32_Bits   (1 << 5)

#endif //MKL26_SPI_H_
