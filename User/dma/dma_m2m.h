#ifndef _dma_mtm_H
#define _dma_mtm_H

#include "stm32f10x.h"

// Ҫ���͵����ݴ�С
#define  BUFFER_SIZE       32   

#define  MTM_DMA_CLA       RCC_AHBPeriph_DMA1
#define  MTM_DMA_CHANNEL   DMA1_Channel6
#define  MTM_DMA_FLAG_TC   DMA1_FLAG_TC6

void MtM_DMA_Config(void);        //��ʼ������

u8 Buffercmp(const u32* pBuffer,                 //�ȽϺ���
                  u32* pBuffer1, u16 BufferLength);

#endif
