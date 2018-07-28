#ifndef  _led_H
#define  _led_H

#include "system.h"                               //见主函数注释

#define GPIOC_PIN  GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7    //宏定义各个引脚的或运算

void GPIOC_Init(void);               //声明LED初始化函数

#define PC0 PCout(0)             //用位带定义PC1-8
#define PC1 PCout(1)
#define PC2 PCout(2)
#define PC3 PCout(3)
#define PC4 PCout(4)
#define PC5 PCout(5)
#define PC6 PCout(6)
#define PC7 PCout(7)

#endif
