#include "uart.h"
#include <stdio.h>

/***************************************
函数：	UART_INIT
功能：	UART初始化
参数： 	波特率
返回值：无
备注：  U1_RX  ---- PA10
        U1_TX  ---- PA9     
****************************************/

void UART1_INIT(int BAURDRATE)
{
//1 开时钟  (GPIOA + USART1)
  RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE );
  RCC_APB2PeriphClockCmd (RCC_APB2Periph_USART1, ENABLE );
	
//2 GPIO的初始化  PA10 -- 浮空输入  PA9 -- 复用推挽输出   
	GPIO_InitTypeDef GPIO_InitStruct ; 
	GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_AF_PP ;
	GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_9;
	GPIO_Init  (GPIOA,&GPIO_InitStruct );//将PA9初始化完成
  
	GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_10;
	GPIO_Init  (GPIOA,&GPIO_InitStruct );//将PA10初始化完成
	
//3 USART的初始化 
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate = BAURDRATE;
	USART_InitStruct.USART_HardwareFlowControl = 0;//USART_HardwareFlowControl_None
	USART_InitStruct.USART_Mode = USART_Mode_Rx |USART_Mode_Tx; 
	USART_InitStruct.USART_Parity= USART_Parity_No ;
	USART_InitStruct.USART_StopBits= USART_StopBits_1 ;
	USART_InitStruct.USART_WordLength= USART_WordLength_8b;
	USART_Init  (USART1,&USART_InitStruct); 
	
//4 UART使能后才可以使用
  USART_Cmd (USART1, ENABLE);
}

/***************************************
函数：	UART_SENDBYTE
功能：	UART发送字节
参数： 	char byte需要发送的数据
返回值：无
备注：    
****************************************/
void UART_SENDBYTE(char byte)
{
//等待TXE置1 
	while(USART_GetFlagStatus (USART1, USART_FLAG_TXE)==0);
//发送数据
	USART_SendData (USART1, byte);
}


//构造printf函数
int fputc(int ch, FILE * Stream)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	USART_SendData(USART1, ch);
	return ch;
}







/***************************************
函数：	UART_RECBYTE
功能：	UART接受字节
参数： 	char byte;
返回值：无
备注：    
****************************************/
void UART_RECBYTE(char byte)
{
//等待RXNE置1
	
//接受数据
}