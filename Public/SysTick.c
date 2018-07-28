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
	SysTick->LOAD=(u32)nms*fac_ms;			    	//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;							          //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//开始倒数
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		  //等待时间到达 
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//关闭计数器
	SysTick->VAL =0X00;       					      //清空计数器    
} 

void delay_s(u16 s)
{
	u8 i;
	for(i = 0;i < s;i++)
	{
		delay_ms(1000);
	}
}
