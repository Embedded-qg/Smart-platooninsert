#ifndef _dma_mtm_H
#define _dma_mtm_H

#include "stm32f10x.h"

// 要发送的数据大小
#define  BUFFER_SIZE       32   

#define  MTM_DMA_CLA       RCC_AHBPeriph_DMA1
#define  MTM_DMA_CHANNEL   DMA1_Channel6
#define  MTM_DMA_FLAG_TC   DMA1_FLAG_TC6

void MtM_DMA_Config(void);        //初始化函数

u8 Buffercmp(const u32* pBuffer,                 //比较函数
                  u32* pBuffer1, u16 BufferLength);

#endif
