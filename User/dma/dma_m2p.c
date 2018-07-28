#include "dma_m2p.h"
															
/*  
     DMAy_Channelx :ѡ��DMA��ͨ��
		 par           �������ַ
		 mar           ���洢Ƶ��ַ
		 ndrt          �����ݴ�����
*/
/*Memory -> Peripheral (USART -> DR)*/
void DMAx_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 par,u32 mar,u16 ndtr)
{
	DMA_InitTypeDef DMA_InitStruct;                       							 //�����ʼ���ṹ��
	  
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);    							 //DMA1ʱ��ʹ��
	
	DMA_InitStruct.DMA_PeripheralBaseAddr = par;      								   //DMA�����ַ
	DMA_InitStruct.DMA_MemoryBaseAddr     = mar;			                   //DMA �洢��0��ַ
	DMA_InitStruct.DMA_DIR                = DMA_DIR_PeripheralDST;     	 //�洢��������ģʽ
	 
	DMA_InitStruct.DMA_BufferSize         = ndtr;                        //���ݴ�����
	
	DMA_InitStruct.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;   //���������ģʽ
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; //�������ݳ��ȣ�8λ
  DMA_InitStruct.DMA_MemoryInc          = DMA_MemoryInc_Enable;        //�洢������ģʽ
	DMA_InitStruct.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;     //�洢�����ݳ��ȣ�8λ

	DMA_InitStruct.DMA_Mode               = DMA_Mode_Circular  ;             //ʹ����ͨģʽ
	DMA_InitStruct.DMA_Priority           = DMA_Priority_High;           //�е����ȼ�
	DMA_InitStruct.DMA_M2M                = DMA_M2M_Disable;             //���ڴ浽�ڴ�
	
	DMA_Init(DMAy_Channelx, &DMA_InitStruct);                            //��ʼ��DMA
}

void DMAx_Enable(DMA_Channel_TypeDef *DMAy_Channelx,u16 ndtr)
{
	DMA_Cmd(DMAy_Channelx,DISABLE);              //�ر�DMA����
	DMA_SetCurrDataCounter(DMAy_Channelx,ndtr);  //���ݴ�����
	DMA_Cmd(DMAy_Channelx,ENABLE);               //����DMA����
}

void Send_Data(u8 *p)                         //�ú�������Ҫ���͵����ݴ浽�洢����
{
	 u16 i;
	 for(i = 0;i < send_buf_len;i++)            //����ĸ�ֵ����
	 {
		 *p = '6';
		  p++;
	 }
}

