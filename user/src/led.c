#include "led.h"

/**************************************************************************
函数：	 void LED_INIT(void) 
功能：	 LED初始化程序
参数： 	
返回值：
备注：   气象站
         LED1 -- PC5
         LED2 -- PC4
				 
				 循迹小车
				 LED1 -- PC0
				 LED2 -- PC1
				 LED3 -- PC2
***************************************************************************/



 void LED_INIT(void)
 {
   // 1 打开APB2的时钟
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 设置GPIO为输出模式   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_Out_PP ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_4|GPIO_Pin_5;
	    GPIO_Init  (GPIOC,&GPIO_InitStruct );
	 
	 // 3 输出一个低电平 SET拉高  RESET拉低
	    GPIO_SetBits  ( GPIOC, GPIO_Pin_4|GPIO_Pin_5);
 }







