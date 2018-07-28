#include "led.h"

void GPIOC_Init()
{
	 GPIO_InitTypeDef GPIO_InitStructure;                   //����ṹ�����
	   
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	//ʹ��APB2����
	
	 GPIO_InitStructure.GPIO_Pin = GPIOC_PIN;               //ѡ��Ҫ���õ�IO��
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//�����ʽ��ѡ���������
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //���ô�������
	 GPIO_Init(GPIOC,&GPIO_InitStructure);               //��ʼ��GPIO
	 
	 GPIO_SetBits(GPIOC,GPIOC_PIN);                           //��LED�˿����ߣ�Ϩ������LED

	 PC5 = 0;
}
