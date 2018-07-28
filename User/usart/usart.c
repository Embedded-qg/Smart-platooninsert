#include "usart.h"
#include "led.h"
#include <stdio.h>

//串口1初始化
void USART1_Init(u32 bound)
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	USART_InitTypeDef   USART_InitStructure;
	NVIC_InitTypeDef    NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);      	//中断优先级分组，分为两组
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);    //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);   //使能USART1时钟
  
	 /*  配置GPIO的模式和IO(GPIOA的引脚9和引脚10) */								
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                  //TX（PA9）
	 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;              //复用推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          //速度
	 GPIO_Init(GPIOA,&GPIO_InitStructure);                      //初始化串口输入IO

	 
	 GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;             //RX（PA10）
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;   //模拟输入      
	 GPIO_Init(GPIOA,&GPIO_InitStructure);                    //初始化GPIO
	
	
	 USART_InitStructure.USART_BaudRate   = bound;                   //波特率设置
	 USART_InitStructure.USART_WordLength = USART_WordLength_8b;     //字长为8位数据格式
	 USART_InitStructure.USART_StopBits   = USART_StopBits_1;        //一个停止位
	 USART_InitStructure.USART_Parity     = USART_Parity_No;         //无奇偶校验位
     USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //无硬件数据流控制
     USART_InitStructure.USART_Mode       =  USART_Mode_Rx | USART_Mode_Tx;	          //收发模式           
     USART_Init(USART1, &USART_InitStructure);       //初始化串口1
	 
	 USART_Cmd(USART1, ENABLE);                      //使能串口1 

	 USART_ClearFlag(USART1,USART_FLAG_TC);          //清除中断标志
     USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);    //开启接收中断
   
	 NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //串口1中断通道          
	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;   //抢占优先级3
	 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;          //子优先级3
	 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQ通道使能
	 NVIC_Init(&NVIC_InitStructure);
}

void USART1_IRQHandler(void)                  //串口1执行函数
{
	u8 r;
	if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)     //接收中断
	{
		r = USART_ReceiveData(USART1);      //读取接收的数据
		if(r == 'A')  PC5 = 1;           //发送A时，PC5置高
		if(r == 'a')  PC5 = 0;
		if(r == 'B')  PC4 = 0;
		if(r == 'b')  PC4 = 1;
		USART_SendData(USART1,r);           //又通过串口将数据发送出去
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	}
	
	USART_ClearFlag(USART1,USART_FLAG_TC);          //清除中断标志
	
}

//重定向C库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USART1, (uint8_t) ch);
		
		//改动一下，重定向到串口3
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

//重定向到串口1
//重定向c库函数scanf到串口,重定向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		/* 等待串口输入数据 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART1);
}
