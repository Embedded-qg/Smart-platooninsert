#include "led.h"

void GPIOC_Init()
{
	 GPIO_InitTypeDef GPIO_InitStructure;                   //定义结构体变量
	   
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	//使能APB2总线
	
	 GPIO_InitStructure.GPIO_Pin = GPIOC_PIN;               //选择要设置的IO口
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//输出方式，选择推挽输出
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //设置传输速率
	 GPIO_Init(GPIOC,&GPIO_InitStructure);               //初始化GPIO
	 
	 GPIO_SetBits(GPIOC,GPIOC_PIN);                           //将LED端口拉高，熄灭所有LED

	 PC5 = 0;
}
