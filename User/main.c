#include "stm32f10x.h"
#include "led.h"
#include "dma_m2p.h"
#include "Systick.h"
#include "usart.h"
#include "key.h"
#include "adc.h"

/*  
system.h ͷ�ļ������������˿ڵ�λ���궨�壬�˿ڵĵ�ַ��
                 ����"stm32f10x.h"ͷ�ļ������ÿһ��
				 �µĺ���ֻ��Ҫ�����ͷ�ļ�������ȥ��
				 ��������ʹ��λ��������
*/

extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];    //���߽�Ϊ�������ݵ�����

float ADC_ConvertedValueLocal[NOFCHANEL];  

int main()
{
		SysTick_Init(72);                          //ʱ�ӳ�ʼ��
	    GPIOC_Init();                              //GPIOC��ʼ��           
		ADCx_Init();		                       //ADC�ɼ���ѹ��ʼ��
		USART1_Init(9600);                         //����1��ʼ��
	    

		while (1)
		{	
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;           //��ѹ�ɼ���ֵ
			 ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			  ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			   ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			    ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			    ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		
			    printf("\r\n CH0 voltage = %f V \r\n",ADC_ConvertedValueLocal[0]);        //��ӡ��ѹ
			    printf("\r\n CH1 voltage = %f V \r\n",ADC_ConvertedValueLocal[1]);
			   printf("\r\n CH2 voltage = %f V \r\n",ADC_ConvertedValueLocal[2]);
			  printf("\r\n CH3 voltage = %f V \r\n",ADC_ConvertedValueLocal[3]);
			 printf("\r\n CH4 voltage = %f V \r\n",ADC_ConvertedValueLocal[4]);
			printf("\r\n CH5 voltage = %f V \r\n",ADC_ConvertedValueLocal[5]);

			printf("\r\n\r\n");	
			delay_s(10);
				
		}
}

















