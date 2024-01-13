#ifndef _UART_H
#define _UART_H
#include "stm32f10x.h"//STM32F1官方头文件

void UART1_INIT(int BAURDRATE);
void UART_SENDBYTE(char byte);


#endif
