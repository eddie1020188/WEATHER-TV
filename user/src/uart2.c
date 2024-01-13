#include "uart2.h"


/**************************************************************************
函数：	void USART3_Init(void)
功能：  USART3初始化代码
参数： 	无
返回值：无
备注：  U3_TX -- PB10 U3_RX -- PB11  
***************************************************************************/
void USART3_Init(void)
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_USART3, ENABLE);
	
	//1、初始化GPIO，配置复用
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
  GPIO_Init(GPIOB, &GPIO_InitStruct);

	//3、USART1初始化
	USART_InitTypeDef  USART_InitStruct;
	
	USART_InitStruct.USART_BaudRate             = 115200;//波特率
	USART_InitStruct.USART_HardwareFlowControl  = USART_HardwareFlowControl_None;//无硬件流控制
	USART_InitStruct.USART_Mode                 = USART_Mode_Tx|USART_Mode_Rx;//全双工
	USART_InitStruct.USART_Parity               = USART_Parity_No;
	USART_InitStruct.USART_StopBits             = USART_StopBits_1;
	USART_InitStruct.USART_WordLength           = USART_WordLength_8b;
	
	USART_Init(USART3,&USART_InitStruct);
	
	//4、使能USART1的接收中断
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	USART_ITConfig(USART3,USART_IT_IDLE,ENABLE);
	
	//5、NVIC初始化
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel    = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	//6、USART使能
	USART_Cmd(USART3,ENABLE);
}


/*************************************************************************************
 * Function  : USART3中断服务函数
 * Parameter : void
 * Return    : void
 * Comment   : 无
**************************************************************************************/
WiFi_REV WiFi_Rev={0};
void USART3_IRQHandler(void)
{
	u8 data;
	if(USART_GetITStatus(USART3,USART_IT_RXNE))
	{
//		printf("接收到数据");
		data=USART_ReceiveData(USART3);
		if(data==0)
		{
			WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt++]=' ';
		}
		else
		{
			WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt++]=data;
		}
	}
	else if(USART_GetITStatus(USART3,USART_IT_IDLE))
	{
		USART3->SR;
		USART3->DR;
		WiFi_Rev.Rev_Buff[WiFi_Rev.Rev_Cnt]='\0';
		printf("%s\r\n",WiFi_Rev.Rev_Buff);
		WiFi_Rev.Rev_Cnt=0;
		WiFi_Rev.Rev_Flag=1;
	}
}

/*************************************************************************************
 * Function  : USART3发送单字节
 * Parameter : u8 data
 * Return    : void
 * Comment   : 无
**************************************************************************************/
void USART3_SendByte(u8 data)
{
	while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET);
	USART_SendData(USART3,data);
}

/*************************************************************************************
 * Function  : USART3发送字符串
 * Parameter : char *Buff
 * Return    : void
 * Comment   : 无
**************************************************************************************/
void USART3_SendStr(char *Buff)
{
	do
	{
		USART3_SendByte(*Buff);
		Buff++;
	}while(*Buff != '\0');
}










