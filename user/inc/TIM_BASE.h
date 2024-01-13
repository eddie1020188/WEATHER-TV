#ifndef TIMBASE_H
#define TIMBASE_H

#include "stm32f10x.h"

/********************基本定时器TIM参数定义，只限TIM6、7************/
#define BASIC_TIM6 // 如果使用TIM7，注释掉这个宏即可

#ifdef  BASIC_TIM6 // 使用基本定时器TIM6
#define            BASIC_TIM                   TIM6
#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM_Period            1000-1
// #define            BASIC_TIM_Period            200-1			//加快5倍
#define            BASIC_TIM_Prescaler         71
#define            BASIC_TIM_IRQ               TIM6_IRQn
#define            BASIC_TIM_IRQHandler        TIM6_IRQHandler

#else  // 使用基本定时器TIM7
#define            BASIC_TIM                   TIM7
#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM7
#define            BASIC_TIM_Period            1000-1
#define            BASIC_TIM_Prescaler         71
#define            BASIC_TIM_IRQ               TIM7_IRQn
#define            BASIC_TIM_IRQHandler        TIM7_IRQHandler

#endif
/********************不同时间间隔标志位定义************/
#define TIM6TIMINGFlag_1ms			0x00000001
#define TIM6TIMINGFlag_3ms			0x00000002
#define TIM6TIMINGFlag_5ms			0x00000004
#define TIM6TIMINGFlag_10ms		  0x00000008
#define TIM6TIMINGFlag_25ms		  0x00000010
#define TIM6TIMINGFlag_50ms		  0x00000020
#define TIM6TIMINGFlag_100ms		0x00000040
#define TIM6TIMINGFlag_333ms		0x00000080
#define TIM6TIMINGFlag_500ms		0x00000100
#define TIM6TIMINGFlag_1s	      0x00000200
#define TIM6TIMINGFlag_30s	    0x00000400
#define TIM6TIMINGFlag_1min		  0x00000800
#define TIM6TIMINGFlag_5500ms	  0x00001000
#define TIM6TIMINGFlag_5s	      0x00002000
#define TIM6TIMINGFlag_1hour		0x00004000
/**************************函数声明********************************/

void basic_tim_init(void);
void Timer6_Init(void);





#endif
