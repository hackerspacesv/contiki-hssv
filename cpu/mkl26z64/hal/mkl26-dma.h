//+------------------------------------------------------------------------------------------------+
//| DMA peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_DMA_H_
#define MKL26_DMA_H_

#include <stdint.h>

struct DMA_CHANNEL {
  uint32_t SAR;       //Source address register
  uint32_t DAR;       //Destination address register
  uint32_t DSR_BCR;   //Status register / Byte count register
  uint32_t DCR;       //Control register
};

struct DMA_type {
  struct DMA_CHANNEL CH[4];
};

#define DMA ((volatile struct DMA_type *) 0x40008100)

//Status register / Byte count register bitfields
#define DMA_DSR_BCR_BCR_Msk           0x00FFFFFF  //Byte count register
#define DMA_DSR_BCR_BCR_Pos           0
#define DMA_DSR_BCR_DONE_Msk          0x01000000  //Transacion done
#define DMA_DSR_BCR_DONE_Pending      (0 << 24)
#define DMA_DSR_BCR_DONE_Finished     (1 << 24)
#define DMA_DSR_BCR_BSY_Msk           0x02000000  //Busy
#define DMA_DSR_BCR_BSY_Inactive      (0 << 25)
#define DMA_DSR_BCR_BSY_Active        (1 << 25)
#define DMA_DSR_BCR_REQ_Msk           0x04000000  //Request
#define DMA_DSR_BCR_REQ_Not_Pending   (0 << 26)
#define DMA_DSR_BCR_REQ_Pending       (1 << 26)
#define DMA_DSR_BCR_BED_Msk           0x10000000  //Bus error on destination
#define DMA_DSR_BCR_BED_Clear         (0 << 28)
#define DMA_DSR_BCR_BED_Set           (1 << 28)
#define DMA_DSR_BCR_BES_Msk           0x20000000  //Bus error on source
#define DMA_DSR_BCR_BES_Clear         (0 << 29)
#define DMA_DSR_BCR_BES_Set           (1 << 29)
#define DMA_DSR_BCR_CE_Msk            0x40000000  //Configuration error
#define DMA_DSR_BCR_CE_Clear          (0 << 30)
#define DMA_DSR_BCR_CE_Set            (1 << 30)

//Control register bitfields
#define DMA_DCR_LCH2_Channel_0      (0 << 0)    //Link channel 2
#define DMA_DCR_LCH2_Channel_1      (1 << 0)
#define DMA_DCR_LCH2_Channel_2      (2 << 0)
#define DMA_DCR_LCH2_Channel_3      (3 << 0)
#define DMA_DCR_LCH1_Channel_0      (0 << 2)    //Link channel 1
#define DMA_DCR_LCH1_Channel_1      (1 << 2)
#define DMA_DCR_LCH1_Channel_2      (2 << 2)
#define DMA_DCR_LCH1_Channel_3      (3 << 2)
#define DMA_DCR_LINKCC_No_Linking   (0 << 4)    //Link channel control
#define DMA_DCR_LINKCC_LCH1_LCH2    (1 << 4)
#define DMA_DCR_LINKCC_LCH1_Steal   (2 << 4)
#define DMA_DCR_LINKCC_LCH1_BCR_0   (3 << 4)
#define DMA_DCR_D_REQ_No_Wr_ERQ     (0 << 7)    //Disable request
#define DMA_DCR_D_REQ_Clear_ERQ     (1 << 7)
#define DMA_DCR_DMOD_Disabled       (0 << 8)    //Destination address modulo
#define DMA_DCR_DMOD_16             (1 << 8)
#define DMA_DCR_DMOD_32             (2 << 8)
#define DMA_DCR_DMOD_64             (3 << 8)
#define DMA_DCR_DMOD_128            (4 << 8)
#define DMA_DCR_DMOD_256            (5 << 8)
#define DMA_DCR_DMOD_512            (6 << 8)
#define DMA_DCR_DMOD_1K             (7 << 8)
#define DMA_DCR_DMOD_2K             (8 << 8)
#define DMA_DCR_DMOD_4K             (9 << 8)
#define DMA_DCR_DMOD_8K             (10 << 8)
#define DMA_DCR_DMOD_16K            (11 << 8)
#define DMA_DCR_DMOD_32K            (12 << 8)
#define DMA_DCR_DMOD_64K            (13 << 8)
#define DMA_DCR_DMOD_128K           (14 << 8)
#define DMA_DCR_DMOD_256K           (15 << 8)
#define DMA_DCR_SMOD_Disabled       (0 << 12)   //Source address modulo
#define DMA_DCR_SMOD_16             (1 << 12)
#define DMA_DCR_SMOD_32             (2 << 12)
#define DMA_DCR_SMOD_64             (3 << 12)
#define DMA_DCR_SMOD_128            (4 << 12)
#define DMA_DCR_SMOD_256            (5 << 12)
#define DMA_DCR_SMOD_512            (6 << 12)
#define DMA_DCR_SMOD_1K             (7 << 12)
#define DMA_DCR_SMOD_2K             (8 << 12)
#define DMA_DCR_SMOD_4K             (9 << 12)
#define DMA_DCR_SMOD_8K             (10 << 12)
#define DMA_DCR_SMOD_16K            (11 << 12)
#define DMA_DCR_SMOD_32K            (12 << 12)
#define DMA_DCR_SMOD_64K            (13 << 12)
#define DMA_DCR_SMOD_128K           (14 << 12)
#define DMA_DCR_SMOD_256K           (15 << 12)
#define DMA_DCR_START_Disabled      (0 << 16)   //Start transfer
#define DMA_DCR_START_Enabled       (1 << 16)
#define DMA_DCR_DSIZE_32_Bit        (0 << 17)   //Destination size
#define DMA_DCR_DSIZE_8_Bit         (1 << 17)
#define DMA_DCR_DSIZE_16_Bit        (2 << 17)
#define DMA_DCR_DINC_No_Change      (0 << 19)   //Destination increment
#define DMA_DCR_DINC_Increment      (1 << 19)
#define DMA_DCR_SSIZE_32_Bit        (0 << 20)   //Source size
#define DMA_DCR_SSIZE_8_Bit         (1 << 20)
#define DMA_DCR_SSIZE_16_Bit        (2 << 20)
#define DMA_DCR_SINC_No_Change      (0 << 22)   //Source increment
#define DMA_DCR_SINC_Increment      (1 << 22)
#define DMA_DCR_EADREQ_Disabled     (0 << 23)   //Enable asynchronous DMA requests
#define DMA_DCR_EADREQ_Enabled      (1 << 23)
#define DMA_DCR_AA_Disabled         (0 << 28)   //Auto align
#define DMA_DCR_AA_Enabled          (1 << 28)
#define DMA_DCR_CS_Continuous       (0 << 29)   //Cycle steal
#define DMA_DCR_CS_Single           (1 << 29)
#define DMA_DCR_ERQ_Disabled        (0 << 30)   //Enable peripheral request
#define DMA_DCR_ERQ_Enabled         (1 << 30)
#define DMA_DCR_EINT_Disabled       (0 << 31)   //Enable interrupt on completion of transfer
#define DMA_DCR_EINT_Enabled        (1 << 31)

#endif //MKL26_DMA_H_
