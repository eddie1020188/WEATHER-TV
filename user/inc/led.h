//����˺궨�� �������� �ȵ�

#ifndef _LED_H
#define _LED_H
#include "stm32f10x.h"//STM32F1�ٷ�ͷ�ļ�

//�Ժ� ������Ҫ����ͷ�ļ��еĳ��� 
//������#define _XXX_H֮��    #endif֮ǰ

void LED_INIT(void);

#define KEY1_PRESS  GPIO_ReadInputDataBit (GPIOA, GPIO_Pin_0) == 1


#define LED1_ON  GPIO_ResetBits  ( GPIOC,GPIO_Pin_5)
#define LED1_OFF  GPIO_SetBits  ( GPIOC,GPIO_Pin_5)
#define LED2_ON  GPIO_ResetBits  ( GPIOC,GPIO_Pin_4)
#define LED2_OFF  GPIO_SetBits  ( GPIOC,GPIO_Pin_4)




#endif
