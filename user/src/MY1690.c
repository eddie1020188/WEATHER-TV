#include "MY1690.h"
#include "delay.h"

VOICE_DEV voice1={.frame_head = 0x7E,.frame_end = 0xEF};
	
//MY1690通信接口初始化
void MY1690_UARTConfig(u32 brr)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//开时钟
	RCC_APB2PeriphClockCmd(MY1690_TX_CLK | MY1690_RX_CLK, ENABLE);
	MY1690_UART_CLKCMD(MY1690_UART_CLK, ENABLE);
	//结构体赋值
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = MY1690_TX_PIN;
	GPIO_Init(MY1690_TX_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = MY1690_RX_PIN;
	GPIO_Init(MY1690_RX_PORT, &GPIO_InitStructure);
	
	//初始化USART  波特率brr 打开发送和接收器  无奇偶校验  一个停止位  8个数据位
	USART_InitStructure.USART_BaudRate = brr;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(MY1690_USART, &USART_InitStructure);
	USART_Cmd(MY1690_USART, ENABLE);//使能USART
}

//MY1690发送数据函数
void MY1690_SendString(u8 *str,u8 lenth)
{
	for(u8 i=0; i<lenth; i++)
	{
		while(USART_GetFlagStatus(MY1690_USART, USART_FLAG_TC) == RESET);
		USART_SendData(MY1690_USART, str[i]);		
	}
}


/********************************************************
函数名称：MY1690_Init
函数功能：MY1690初始化
函数传参：无
函数返回值：无
**********************************/
void MY1690_Init(void)
{
	//BUSY管脚初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(MY1690_BUSY_CLK | MY1690_EN_CLK, ENABLE);
	
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = MY1690_BUSY_PIN;
	GPIO_Init(MY1690_BUSY_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = MY1690_EN_PIN;
	GPIO_Init(MY1690_EN_PORT, &GPIO_InitStructure);	
	MY1690_ENABLE();

	//USART初始化
	MY1690_UARTConfig(9600);
}

/********************************************************
 *函数名称：Voice_XorCheck
 *函数功能：^检测 
 *函数传参：
 *			*pdata -- 校准参数
 *			lenth  -- 参数的个数
 *函数返回值：^后的数
 ********************************************************/
u8 Voice_XorCheck(u8 *pdata, u8 lenth)
{
	u8 r_value = *pdata;
	u8 i = 0;
	for(i=1;i<lenth;i++)
	{
		r_value ^= pdata[i];
	}
	return r_value;
}

/**********************************************************
 *函数名称：Voice_SendCmd
 *函数功能：发送命令 
 *函数传参：
 *				cmd -- 命令
 *				arg_lenth -- 参数个数
 *				arg1 -- 第一个参数
 *				arg2 -- 第二个参数
 *函数返回值：无
 **********************************************************/
void Voice_SendCmd(u8 cmd,u8 arg1,u8 arg2,u8 arg_lenth)
{
	//给voice1传递参数
	//命令填充
	voice1.cmd = cmd;
	//参数填充
	voice1.arg[0] = arg1;
	voice1.arg[1] = arg2;
	voice1.arg[2] = arg_lenth;
	//长度填充
	voice1.lenth = 3+arg_lenth;//长度 + cmd + xor + 参数长度
	voice1.xorcheck = Voice_XorCheck(&voice1.lenth,2+arg_lenth);//lenth+cmd + 参数
	//发送
	MY1690_SendString(&voice1.frame_head,3);//帧起始+长度+命令
	MY1690_SendString(voice1.arg,arg_lenth);//发送参数
	MY1690_SendString(&voice1.xorcheck,2);//异或值+帧尾
}

//播放指定目录文件下的音乐
//directorynum：目录编号
//musicnum：音乐编号
void Voice_PlayDirectoryMusic(u8 directorynum, u8 musicnum)
{
	MY1690_ENABLE();
	Voice_SendCmd(CMD_CHOOSE_MUSIC,directorynum, musicnum,2);
//	Delay_ms(200);//必须加延时，用于阻塞并准确判断音乐是否播放完成
	Delay_ms(500);
	while((VoicePlay_Busy() == Bit_SET))
	{}
	MY1690_DISABLE();
}

//控制音量
//
//musicnum：音乐编号
void Voice_ControlVOL(u8 VOL)
{

	Voice_SendCmd(0X31,VOL,0X00,1);

}

void Voice_Stop(void)
{
	uint8_t CMD[] = {0x7E, 0x03, 0x1E, 0x1D, 0xEF};
	MY1690_SendString(CMD, 5);
}

//数字语音下标
//										 0 1 2 3 4 5 6 . . . 10 ℃ 室内温 室内湿		室外温度  年  月  号  周   天  点  分  目前是   %
uint8_t num_mp3[24] = {0,1,2,3,4,5,6,7,8,9,10,11,12,		13,			14,				15, 16, 17, 18,  19, 20, 21, 22     ,23};

//播放十进制两位数
//注意传参 0-99
void Voice_PlayNumMusic(uint8_t num)
{
	if(num > 99)	return;
	uint8_t shi,ge;
	shi = num / 10;
	ge = num % 10;
	if(num == 0)
	{
		Voice_PlayDirectoryMusic(00, num_mp3[0]);
		return;
	}
	if(shi){
		if(shi > 1)	Voice_PlayDirectoryMusic(00, num_mp3[shi]);
		Voice_PlayDirectoryMusic(00, num_mp3[10]);
	}
	if(ge){
		Voice_PlayDirectoryMusic(00, num_mp3[ge]);
	}
}

//播报室内温度
void Voice_PlayRoom_Temperature(uint8_t num)
{
	//室内温度
	Voice_PlayDirectoryMusic(00, num_mp3[12]);
	Voice_PlayNumMusic(num);//播报数据
	//℃
	Voice_PlayDirectoryMusic(00, num_mp3[11]);
}

//播报室内湿度
void Voice_PlayRoom_Hum(uint8_t num)
{
	//室内湿度
	Voice_PlayDirectoryMusic(00, num_mp3[13]);
	//%
	Voice_PlayDirectoryMusic(00, num_mp3[23]);
	Voice_PlayNumMusic(num);//播报数据
}

void Voice_PlayOutdoor_Temperature(uint8_t num)
{
	Voice_PlayDirectoryMusic(00, num_mp3[14]);
	Voice_PlayNumMusic(num);
	Voice_PlayDirectoryMusic(00, num_mp3[11]);
}


//播报电池电量
void Voice_Batval(uint8_t val)
{
	//%
	Voice_PlayDirectoryMusic(00, num_mp3[23]);
	Voice_PlayNumMusic(val);//播报数据
}


