#ifndef UART2_H
#define UART2_H

#include "stm32f10x.h"
#include "stdio.h"


typedef struct{
	char Rev_Buff[500];    //保存接收的数据
	u8 Rev_Flag;           //判断接收完成
	u16 Rev_Cnt;	         //接收的数据长度
}WiFi_REV;

extern WiFi_REV WiFi_Rev;

void USART3_Init(void);
void USART3_SendByte(u8 data);
void USART3_SendStr(char *Buff);

#endif
