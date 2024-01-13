#include "uart.h"
#include <stdio.h>

/***************************************
������	UART_INIT
���ܣ�	UART��ʼ��
������ 	������
����ֵ����
��ע��  U1_RX  ---- PA10
        U1_TX  ---- PA9     
****************************************/

void UART1_INIT(int BAURDRATE)
{
//1 ��ʱ��  (GPIOA + USART1)
  RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE );
  RCC_APB2PeriphClockCmd (RCC_APB2Periph_USART1, ENABLE );
	
//2 GPIO�ĳ�ʼ��  PA10 -- ��������  PA9 -- �����������   
	GPIO_InitTypeDef GPIO_InitStruct ; 
	GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_AF_PP ;
	GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_9;
	GPIO_Init  (GPIOA,&GPIO_InitStruct );//��PA9��ʼ�����
  
	GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_10;
	GPIO_Init  (GPIOA,&GPIO_InitStruct );//��PA10��ʼ�����
	
//3 USART�ĳ�ʼ�� 
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate = BAURDRATE;
	USART_InitStruct.USART_HardwareFlowControl = 0;//USART_HardwareFlowControl_None
	USART_InitStruct.USART_Mode = USART_Mode_Rx |USART_Mode_Tx; 
	USART_InitStruct.USART_Parity= USART_Parity_No ;
	USART_InitStruct.USART_StopBits= USART_StopBits_1 ;
	USART_InitStruct.USART_WordLength= USART_WordLength_8b;
	USART_Init  (USART1,&USART_InitStruct); 
	
//4 UARTʹ�ܺ�ſ���ʹ��
  USART_Cmd (USART1, ENABLE);
}

/***************************************
������	UART_SENDBYTE
���ܣ�	UART�����ֽ�
������ 	char byte��Ҫ���͵�����
����ֵ����
��ע��    
****************************************/
void UART_SENDBYTE(char byte)
{
//�ȴ�TXE��1 
	while(USART_GetFlagStatus (USART1, USART_FLAG_TXE)==0);
//��������
	USART_SendData (USART1, byte);
}


//����printf����
int fputc(int ch, FILE * Stream)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	USART_SendData(USART1, ch);
	return ch;
}







/***************************************
������	UART_RECBYTE
���ܣ�	UART�����ֽ�
������ 	char byte;
����ֵ����
��ע��    
****************************************/
void UART_RECBYTE(char byte)
{
//�ȴ�RXNE��1
	
//��������
}