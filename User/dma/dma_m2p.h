#ifndef _dma_m2p_H
#define _dma_m2p_H

#include "system.h"
#include  <stdio.h>
#define send_buf_len     5000

void Send_Data(u8 *p);                                                        //�����������ݺ���
void DMAx_Enable(DMA_Channel_TypeDef *DMAy_Channelx,u16 ndtr);                //����DMA��������
void DMAx_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 par,u32 mar,u16 ndtr);  //����DMA��ʼ������

#endif
