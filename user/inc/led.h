//存放了宏定义 函数声明 等等

#ifndef _LED_H
#define _LED_H
#include "stm32f10x.h"//STM32F1官方头文件

//以后 所有需要放在头文件中的程序 
//必须在#define _XXX_H之后    #endif之前

void LED_INIT(void);
void GPIO_TOGGLEBITS(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
#define KEY1_PRESS  GPIO_ReadInputDataBit (GPIOA, GPIO_Pin_0) == 1


#define LED1_ON  GPIO_ResetBits  ( GPIOC,GPIO_Pin_5)
#define LED1_OFF  GPIO_SetBits  ( GPIOC,GPIO_Pin_5)
#define LED2_ON  GPIO_ResetBits  ( GPIOC,GPIO_Pin_4)
#define LED2_OFF  GPIO_SetBits  ( GPIOC,GPIO_Pin_4)
#define LED1_FZ   GPIOC->ODR ^=(1<<5)
#define LED2_FZ   GPIOF->ODR ^=(1<<4)



#endif
