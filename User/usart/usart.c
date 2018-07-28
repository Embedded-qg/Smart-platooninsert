#include "usart.h"
#include "led.h"
#include <stdio.h>

//����1��ʼ��
void USART1_Init(u32 bound)
{
	GPIO_InitTypeDef    GPIO_InitStructure;
	USART_InitTypeDef   USART_InitStructure;
	NVIC_InitTypeDef    NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);      	//�ж����ȼ����飬��Ϊ����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);    //ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);   //ʹ��USART1ʱ��
  
	 /*  ����GPIO��ģʽ��IO(GPIOA������9������10) */								
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;                  //TX��PA9��
	 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;              //�����������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          //�ٶ�
	 GPIO_Init(GPIOA,&GPIO_InitStructure);                      //��ʼ����������IO

	 
	 GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;             //RX��PA10��
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;   //ģ������      
	 GPIO_Init(GPIOA,&GPIO_InitStructure);                    //��ʼ��GPIO
	
	
	 USART_InitStructure.USART_BaudRate   = bound;                   //����������
	 USART_InitStructure.USART_WordLength = USART_WordLength_8b;     //�ֳ�Ϊ8λ���ݸ�ʽ
	 USART_InitStructure.USART_StopBits   = USART_StopBits_1;        //һ��ֹͣλ
	 USART_InitStructure.USART_Parity     = USART_Parity_No;         //����żУ��λ
     USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //��Ӳ������������
     USART_InitStructure.USART_Mode       =  USART_Mode_Rx | USART_Mode_Tx;	          //�շ�ģʽ           
     USART_Init(USART1, &USART_InitStructure);       //��ʼ������1
	 
	 USART_Cmd(USART1, ENABLE);                      //ʹ�ܴ���1 

	 USART_ClearFlag(USART1,USART_FLAG_TC);          //����жϱ�־
     USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);    //���������ж�
   
	 NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;           //����1�ж�ͨ��          
	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;   //��ռ���ȼ�3
	 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;          //�����ȼ�3
	 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //IRQͨ��ʹ��
	 NVIC_Init(&NVIC_InitStructure);
}

void USART1_IRQHandler(void)                  //����1ִ�к���
{
	u8 r;
	if(USART_GetITStatus(USART1,USART_IT_RXNE) != RESET)     //�����ж�
	{
		r = USART_ReceiveData(USART1);      //��ȡ���յ�����
		if(r == 'A')  PC5 = 1;           //����Aʱ��PC5�ø�
		if(r == 'a')  PC5 = 0;
		if(r == 'B')  PC4 = 0;
		if(r == 'b')  PC4 = 1;
		USART_SendData(USART1,r);           //��ͨ�����ڽ����ݷ��ͳ�ȥ
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	}
	
	USART_ClearFlag(USART1,USART_FLAG_TC);          //����жϱ�־
	
}

//�ض���C�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(USART1, (uint8_t) ch);
		
		//�Ķ�һ�£��ض��򵽴���3
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

//�ض��򵽴���1
//�ض���c�⺯��scanf������,�ض�����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
		/* �ȴ������������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART1);
}
