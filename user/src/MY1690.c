#include "MY1690.h"
#include "delay.h"

VOICE_DEV voice1={.frame_head = 0x7E,.frame_end = 0xEF};
	
//MY1690ͨ�Žӿڳ�ʼ��
void MY1690_UARTConfig(u32 brr)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//��ʱ��
	RCC_APB2PeriphClockCmd(MY1690_TX_CLK | MY1690_RX_CLK, ENABLE);
	MY1690_UART_CLKCMD(MY1690_UART_CLK, ENABLE);
	//�ṹ�帳ֵ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = MY1690_TX_PIN;
	GPIO_Init(MY1690_TX_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = MY1690_RX_PIN;
	GPIO_Init(MY1690_RX_PORT, &GPIO_InitStructure);
	
	//��ʼ��USART  ������brr �򿪷��ͺͽ�����  ����żУ��  һ��ֹͣλ  8������λ
	USART_InitStructure.USART_BaudRate = brr;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(MY1690_USART, &USART_InitStructure);
	USART_Cmd(MY1690_USART, ENABLE);//ʹ��USART
}

//MY1690�������ݺ���
void MY1690_SendString(u8 *str,u8 lenth)
{
	for(u8 i=0; i<lenth; i++)
	{
		while(USART_GetFlagStatus(MY1690_USART, USART_FLAG_TC) == RESET);
		USART_SendData(MY1690_USART, str[i]);		
	}
}


/********************************************************
�������ƣ�MY1690_Init
�������ܣ�MY1690��ʼ��
�������Σ���
��������ֵ����
**********************************/
void MY1690_Init(void)
{
	//BUSY�ܽų�ʼ��
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

	//USART��ʼ��
	MY1690_UARTConfig(9600);
}

/********************************************************
 *�������ƣ�Voice_XorCheck
 *�������ܣ�^��� 
 *�������Σ�
 *			*pdata -- У׼����
 *			lenth  -- �����ĸ���
 *��������ֵ��^�����
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
 *�������ƣ�Voice_SendCmd
 *�������ܣ��������� 
 *�������Σ�
 *				cmd -- ����
 *				arg_lenth -- ��������
 *				arg1 -- ��һ������
 *				arg2 -- �ڶ�������
 *��������ֵ����
 **********************************************************/
void Voice_SendCmd(u8 cmd,u8 arg1,u8 arg2,u8 arg_lenth)
{
	//��voice1���ݲ���
	//�������
	voice1.cmd = cmd;
	//�������
	voice1.arg[0] = arg1;
	voice1.arg[1] = arg2;
	voice1.arg[2] = arg_lenth;
	//�������
	voice1.lenth = 3+arg_lenth;//���� + cmd + xor + ��������
	voice1.xorcheck = Voice_XorCheck(&voice1.lenth,2+arg_lenth);//lenth+cmd + ����
	//����
	MY1690_SendString(&voice1.frame_head,3);//֡��ʼ+����+����
	MY1690_SendString(voice1.arg,arg_lenth);//���Ͳ���
	MY1690_SendString(&voice1.xorcheck,2);//���ֵ+֡β
}

//����ָ��Ŀ¼�ļ��µ�����
//directorynum��Ŀ¼���
//musicnum�����ֱ��
void Voice_PlayDirectoryMusic(u8 directorynum, u8 musicnum)
{
	MY1690_ENABLE();
	Voice_SendCmd(CMD_CHOOSE_MUSIC,directorynum, musicnum,2);
//	Delay_ms(200);//�������ʱ������������׼ȷ�ж������Ƿ񲥷����
	Delay_ms(500);
	while((VoicePlay_Busy() == Bit_SET))
	{}
	MY1690_DISABLE();
}

//��������
//
//musicnum�����ֱ��
void Voice_ControlVOL(u8 VOL)
{

	Voice_SendCmd(0X31,VOL,0X00,1);

}

void Voice_Stop(void)
{
	uint8_t CMD[] = {0x7E, 0x03, 0x1E, 0x1D, 0xEF};
	MY1690_SendString(CMD, 5);
}

//���������±�
//										 0 1 2 3 4 5 6 . . . 10 �� ������ ����ʪ		�����¶�  ��  ��  ��  ��   ��  ��  ��  Ŀǰ��   %
uint8_t num_mp3[24] = {0,1,2,3,4,5,6,7,8,9,10,11,12,		13,			14,				15, 16, 17, 18,  19, 20, 21, 22     ,23};

//����ʮ������λ��
//ע�⴫�� 0-99
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

//���������¶�
void Voice_PlayRoom_Temperature(uint8_t num)
{
	//�����¶�
	Voice_PlayDirectoryMusic(00, num_mp3[12]);
	Voice_PlayNumMusic(num);//��������
	//��
	Voice_PlayDirectoryMusic(00, num_mp3[11]);
}

//��������ʪ��
void Voice_PlayRoom_Hum(uint8_t num)
{
	//����ʪ��
	Voice_PlayDirectoryMusic(00, num_mp3[13]);
	//%
	Voice_PlayDirectoryMusic(00, num_mp3[23]);
	Voice_PlayNumMusic(num);//��������
}

void Voice_PlayOutdoor_Temperature(uint8_t num)
{
	Voice_PlayDirectoryMusic(00, num_mp3[14]);
	Voice_PlayNumMusic(num);
	Voice_PlayDirectoryMusic(00, num_mp3[11]);
}


//������ص���
void Voice_Batval(uint8_t val)
{
	//%
	Voice_PlayDirectoryMusic(00, num_mp3[23]);
	Voice_PlayNumMusic(val);//��������
}


