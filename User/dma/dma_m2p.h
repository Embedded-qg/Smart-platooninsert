#ifndef _dma_m2p_H
#define _dma_m2p_H

#include "system.h"
#include  <stdio.h>
#define send_buf_len     5000

void Send_Data(u8 *p);                                                        //声明发送数据函数
void DMAx_Enable(DMA_Channel_TypeDef *DMAy_Channelx,u16 ndtr);                //声明DMA开启函数
void DMAx_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 par,u32 mar,u16 ndtr);  //声明DMA初始化函数

#endif
