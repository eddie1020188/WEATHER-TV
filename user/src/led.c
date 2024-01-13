#include "led.h"

/**************************************************************************
������	 void LED_INIT(void) 
���ܣ�	 LED��ʼ������
������ 	
����ֵ��
��ע��   ����վ
         LED1 -- PC5
         LED2 -- PC4
				 
				 ѭ��С��
				 LED1 -- PC0
				 LED2 -- PC1
				 LED3 -- PC2
***************************************************************************/



 void LED_INIT(void)
 {
   // 1 ��APB2��ʱ��
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 ����GPIOΪ���ģʽ   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_Out_PP ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_4|GPIO_Pin_5;
	    GPIO_Init  (GPIOC,&GPIO_InitStruct );
	 
	 // 3 ���һ���͵�ƽ SET����  RESET����
	    GPIO_SetBits  ( GPIOC, GPIO_Pin_4|GPIO_Pin_5);
 }







