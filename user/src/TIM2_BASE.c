#include "TIM_BASE.h"

///*
//  ******************************************************************************
//  * @file    bsp_TimBase.c
//  * @author  xuegong
//  * @version V1.0
//  * @date    2022-xx-xx
//  * @brief   ledӦ�ú����ӿ�
//  ******************************************************************************
//  * @attention
//  *
//  * Ƕ��ʽ
//  *
//  ******************************************************************************
//*/
//  
// static void BASIC_TIM_Mode_Config(void)
//{
//    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//		
//		// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
//    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
//		// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
//    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	//ARRֵ 1000
//	  // ʱ��Ԥ��Ƶ��Ϊ
//    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;//Ԥ��Ƶֵ72 1000000hz
//	  // ��ʼ����ʱ��
//    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);
//		// ����������жϱ�־λ
//    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);
//		// �����������ж�
//    TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);
//		// ʹ�ܼ�����
//    TIM_Cmd(BASIC_TIM, ENABLE);	
//}

//// �ж����ȼ�����
//static void BASIC_TIM_NVIC_Config(void)
//{
//    NVIC_InitTypeDef NVIC_InitStructure; 
//    // �����ж���Ϊ0
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
//    // �����ж���Դ
//    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
//    // ���������ȼ�Ϊ 0
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
//    // ������ռ���ȼ�Ϊ3
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
//}

//void basic_tim_init(void)
//{
//  BASIC_TIM_Mode_Config();
//  BASIC_TIM_NVIC_Config();
//}


/*********************************************END OF FILE**********************/


 
void Timer6_Init(void)
{
	// ��RCC����ʱ�ӿ��ƴ򿪶�ʱ���Ļ�׼ʱ�Ӻ�����Ĺ���ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	// ����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;	// ����ʱ�ӷ�ƵƵ�ʣ����ڲ����˲�������������ȡֵ����Ҫ��ȡ��һ�������ԣ�
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	// ���ü���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period = 10 - 1;	// ���ڣ����Զ���װ�Ĵ�����ֵARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;	// Ԥ��Ƶϵ��PSC���������PSC����Ϊ0�������������жϣ��������������У����ҵ�оƬBug���⣩
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;	// �ظ������Ĵ������߼���ʱ�����е�ģ�飬��������Ϊ0
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

//	// ��TIM_TimeBaseInit��������󣬻���������һ�������¼���������װ��Ԥ��Ƶ�����ظ���������ֵ
//	// Ԥ��Ƶ���л���Ĵ���������д���PSC��ARRֻ���ڸ����¼�ʱ�Ż�������
//	// Ϊ����д���ֵ���������ã����ں���������ֶ�������һ�������¼�
//	// ���Ǹ����¼��͸����ж���ͬʱ�����ģ������жϻ��ø����жϱ�־λ���ֶ�����һ�������¼������൱���ڳ�ʼ��ʱ���̽�����º���ִ��һ��
//	// �ڿ����ж�֮ǰ�ֶ����һ�θ����жϱ�־λ���Ϳ��Ա���ճ�ʼ����ɾͽ����жϺ���������
	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	
	// �����ж�������ƣ������ж������NVIC
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

	// ��ʼ��NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;	// ����NVIC�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	// �ж�ͨ������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	// ��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	// ��ռ���ȼ�
	NVIC_Init(&NVIC_InitStructure);
//	
	                     
	// �������п���
	TIM_Cmd(TIM6, ENABLE);
}
 

 



