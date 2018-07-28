#ifndef _SysTick_H
#define _SysTick_H

#include "system.h"

void delay_ms(u16 nms);
void SysTick_Init(u8 SYSCLK);
void delay_s(u16 s);
	
#endif
