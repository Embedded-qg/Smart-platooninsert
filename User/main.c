#include "stm32f10x.h"
#include "led.h"
#include "dma_m2p.h"
#include "Systick.h"
#include "usart.h"
#include "key.h"
#include "adc.h"

/*  
system.h 头文件：包含各个端口的位带宏定义，端口的地址，
                 还有"stm32f10x.h"头文件，因此每一个
				 新的函数只需要把这个头文件包含进去就
				 可以轻松使用位带操作。
*/

extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];    //两者皆为储存数据的数组

float ADC_ConvertedValueLocal[NOFCHANEL];  

int main()
{
		SysTick_Init(72);                          //时钟初始化
	    GPIOC_Init();                              //GPIOC初始化           
		ADCx_Init();		                       //ADC采集电压初始化
		USART1_Init(9600);                         //串口1初始化
	    

		while (1)
		{	
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;           //电压采集赋值
			 ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			  ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			   ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			    ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			    ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
		
			    printf("\r\n CH0 voltage = %f V \r\n",ADC_ConvertedValueLocal[0]);        //打印电压
			    printf("\r\n CH1 voltage = %f V \r\n",ADC_ConvertedValueLocal[1]);
			   printf("\r\n CH2 voltage = %f V \r\n",ADC_ConvertedValueLocal[2]);
			  printf("\r\n CH3 voltage = %f V \r\n",ADC_ConvertedValueLocal[3]);
			 printf("\r\n CH4 voltage = %f V \r\n",ADC_ConvertedValueLocal[4]);
			printf("\r\n CH5 voltage = %f V \r\n",ADC_ConvertedValueLocal[5]);

			printf("\r\n\r\n");	
			delay_s(10);
				
		}
}

















