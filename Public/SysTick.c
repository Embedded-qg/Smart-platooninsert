#include "SysTick.h"

static u8 fac_us = 0;
static u16 fac_ms = 0;

void SysTick_Init(u8 SYSCLK)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); 
	fac_us = SYSCLK/8;					
	fac_ms = (u16)fac_us*1000;				   
}


void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;			    	//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;							          //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		  //�ȴ�ʱ�䵽�� 
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;       					      //��ռ�����    
} 

void delay_s(u16 s)
{
	u8 i;
	for(i = 0;i < s;i++)
	{
		delay_ms(1000);
	}
}
