#ifndef _BSP_ADC_H
#define __BSP_ADC_H
#include "stm32f10x.h"

//ADC采集端口C的数据
#define    ADC_PORT                      GPIOC
// 转换通道个数
#define    NOFCHANEL										 6

#define    ADC_PIN1                      GPIO_Pin_0
#define    ADC_CHANNEL1                  ADC_Channel_10

#define    ADC_PIN2                      GPIO_Pin_1
#define    ADC_CHANNEL2                  ADC_Channel_11

#define    ADC_PIN3                      GPIO_Pin_2
#define    ADC_CHANNEL3                  ADC_Channel_12

#define    ADC_PIN4                      GPIO_Pin_3
#define    ADC_CHANNEL4                  ADC_Channel_13

#define    ADC_PIN5                      GPIO_Pin_4
#define    ADC_CHANNEL5                  ADC_Channel_14

#define    ADC_PIN6                      GPIO_Pin_5
#define    ADC_CHANNEL6                  ADC_Channel_15

// ADC1 对应 DMA1通道1，ADC3对应DMA2通道5，ADC2没有DMA功能
#define    ADC_x                         ADC1
#define    ADC_DMA_CHANNEL               DMA1_Channel1

void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void ADCx_Init(void);
#endif
