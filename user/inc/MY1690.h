#ifndef _MY1690_H_
#define _MY1690_H_

#include "stm32f10x.h"
#include "stdio.h"

/*********************MY1690�ײ�ӿں궨��************************************/
#define MY1690_USART					UART5
#define MY1690_UART_CLKCMD		RCC_APB1PeriphClockCmd
#define MY1690_UART_CLK				RCC_APB1Periph_UART5

#define MY1690_TX_CLK					RCC_APB2Periph_GPIOC
#define MY1690_TX_PORT				GPIOC
#define MY1690_TX_PIN					GPIO_Pin_12

#define MY1690_RX_CLK					RCC_APB2Periph_GPIOD
#define MY1690_RX_PORT				GPIOD
#define MY1690_RX_PIN					GPIO_Pin_2

#define MY1690_BUSY_CLK				RCC_APB2Periph_GPIOB
#define MY1690_BUSY_PORT			GPIOB
#define MY1690_BUSY_PIN				GPIO_Pin_8

#define MY1690_EN_CLK					RCC_APB2Periph_GPIOB
#define MY1690_EN_PORT				GPIOB
#define MY1690_EN_PIN					GPIO_Pin_9

#define MY1690_DISABLE()			(GPIO_ResetBits(MY1690_EN_PORT, MY1690_EN_PIN))
#define MY1690_ENABLE()				(GPIO_SetBits(MY1690_EN_PORT, MY1690_EN_PIN))



#define MY1690_ENToggle()			(MY1690_EN_PORT->ODR ^= MY1690_EN_PIN)

/**********************MY1690����궨��*******************************/

#define CMD_PLAY 		  		0x11            //����
#define CMD_STOP 		  		0x12            //��ͣ
#define CMD_NEXT 	 	  		0x13            //��һ��
#define CMD_PREV 					0x14            //��һ��
#define CMD_VOICEADD  		0x15            //������
#define CMD_VOICESUB  		0x16            //������
#define CMD_RESET     		0x19            //��λ
#define CMD_SPEED     		0x1A            //���
#define CMD_SLOW      		0x1B            //����
#define CMD_STARTorSTOP 	0x1C            //����/��ͣ
#define CMD_END         	0x1E            //ֹͣ
#define CMD_ROOTCHO_MUSIC 0x41            //��Ŀ¼ѡ�����
#define CMD_CHOOSE_MUSIC 	0x42            //����Ŀ¼ѡ�����

//����֡�ṹ��
typedef struct
{
	u8 frame_head;//֡ͷ
	u8 lenth;     //���ݳ���
	u8 cmd;       //����
	u8 arg[3];    //��������0 1 2   arg[2] -- �����ĸ��� arg[0] -- ��һ������ arg[1] -- �ڶ�������
	u8 xorcheck;  //У����
	u8 frame_end; //֡β
}VOICE_DEV;

//æ״̬���
#define VoicePlay_Busy()	(GPIO_ReadInputDataBit(MY1690_BUSY_PORT, MY1690_BUSY_PIN))



void MY1690_UARTConfig(u32 brr);
void MY1690_Init(void);
void MY1690_SendString(u8 *str,u8 lenth);
u8 Voice_XorCheck(u8 *pdata,u8 lenth);
void Voice_SendCmd(u8 cmd,u8 arg1,u8 arg2,u8 arg_lenth);	
void Voice_PlayDirectoryMusic(u8 directorynum, u8 musicnum);
void Voice_Stop(void);
void Voice_ControlVOL(u8 VOL);

void Voice_PlayRoom_Temperature(uint8_t num);
void Voice_PlayRoom_Hum(uint8_t num);
void Voice_PlayOutdoor_Temperature(uint8_t num);
void Voice_Batval(uint8_t val);
void Voice_PlayWeather(uint8_t weather_code);

#endif

