#include "dma_m2p.h"
															
/*  
     DMAy_Channelx :选择DMA和通道
		 par           ：外设地址
		 mar           ：存储频地址
		 ndrt          ：数据传输量
*/
/*Memory -> Peripheral (USART -> DR)*/
void DMAx_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 par,u32 mar,u16 ndtr)
{
	DMA_InitTypeDef DMA_InitStruct;                       							 //定义初始化结构体
	  
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);    							 //DMA1时钟使能
	
	DMA_InitStruct.DMA_PeripheralBaseAddr = par;      								   //DMA外设地址
	DMA_InitStruct.DMA_MemoryBaseAddr     = mar;			                   //DMA 存储器0地址
	DMA_InitStruct.DMA_DIR                = DMA_DIR_PeripheralDST;     	 //存储器到外设模式
	 
	DMA_InitStruct.DMA_BufferSize         = ndtr;                        //数据传输量
	
	DMA_InitStruct.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;   //外设非增量模式
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //外设数据长度：8位
  DMA_InitStruct.DMA_MemoryInc          = DMA_MemoryInc_Enable;        //存储器增量模式
	DMA_InitStruct.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;     //存储器数据长度：8位

	DMA_InitStruct.DMA_Mode               = DMA_Mode_Circular  ;             //使用普通模式
	DMA_InitStruct.DMA_Priority           = DMA_Priority_High;           //中等优先级
	DMA_InitStruct.DMA_M2M                = DMA_M2M_Disable;             //非内存到内存
	
	DMA_Init(DMAy_Channelx, &DMA_InitStruct);                            //初始化DMA
}

void DMAx_Enable(DMA_Channel_TypeDef *DMAy_Channelx,u16 ndtr)
{
	DMA_Cmd(DMAy_Channelx,DISABLE);              //关闭DMA传输
	DMA_SetCurrDataCounter(DMAy_Channelx,ndtr);  //数据传输量
	DMA_Cmd(DMAy_Channelx,ENABLE);               //开启DMA传输
}

void Send_Data(u8 *p)                         //该函数将需要发送的数据存到存储器中
{
	 u16 i;
	 for(i = 0;i < send_buf_len;i++)            //数组的赋值操作
	 {
		 *p = '6';
		  p++;
	 }
}

