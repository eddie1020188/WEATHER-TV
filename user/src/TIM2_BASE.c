#include "TIM_BASE.h"

///*
//  ******************************************************************************
//  * @file    bsp_TimBase.c
//  * @author  xuegong
//  * @version V1.0
//  * @date    2022-xx-xx
//  * @brief   led应用函数接口
//  ******************************************************************************
//  * @attention
//  *
//  * 嵌入式
//  *
//  ******************************************************************************
//*/
//  
// static void BASIC_TIM_Mode_Config(void)
//{
//    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//		
//		// 开启定时器时钟,即内部时钟CK_INT=72M
//    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
//		// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
//    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	//ARR值 1000
//	  // 时钟预分频数为
//    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;//预分频值72 1000000hz
//	  // 初始化定时器
//    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);
//		// 清除计数器中断标志位
//    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);
//		// 开启计数器中断
//    TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);
//		// 使能计数器
//    TIM_Cmd(BASIC_TIM, ENABLE);	
//}

//// 中断优先级配置
//static void BASIC_TIM_NVIC_Config(void)
//{
//    NVIC_InitTypeDef NVIC_InitStructure; 
//    // 设置中断组为0
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
//    // 设置中断来源
//    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
//    // 设置主优先级为 0
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
//    // 设置抢占优先级为3
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
	// 用RCC外设时钟控制打开定时器的基准时钟和外设的工作时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	// 配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;	// 配置时钟分频频率（用于采样滤波，在这里它的取值不重要，取哪一个都可以）
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	// 配置计数模式
	TIM_TimeBaseInitStructure.TIM_Period = 10 - 1;	// 周期，即自动重装寄存器的值ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;	// 预分频系数PSC（这里如果PSC设置为0，会连续触发中断，导致主程序不运行，是我的芯片Bug问题）
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;	// 重复计数寄存器，高级定时器才有的模块，这里配置为0
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStructure);

//	// 在TIM_TimeBaseInit函数的最后，会立刻生成一个更新事件，来重新装载预分频器和重复计数器的值
//	// 预分频器有缓冲寄存器，我们写入的PSC和ARR只有在更新事件时才会起作用
//	// 为了让写入的值立刻起作用，故在函数的最后手动生成了一个更新事件
//	// 但是更新事件和更新中断是同时发生的，更新中断会置更新中断标志位，手动生成一个更新事件，就相当于在初始化时立刻进入更新函数执行一次
//	// 在开启中断之前手动清除一次更新中断标志位，就可以避免刚初始化完成就进入中断函数的问题
	TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	
	// 配置中断输出控制，允许中断输出到NVIC
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

	// 初始化NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;	// 配置NVIC中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	// 中断通道命令
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	// 响应优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	// 抢占优先级
	NVIC_Init(&NVIC_InitStructure);
//	
	                     
	// 配置运行控制
	TIM_Cmd(TIM6, ENABLE);
}
 

 



