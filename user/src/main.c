#include "main.h"

extern volatile unsigned int TIM6_TIMING_FLAG ;//TIM6定时器标志
extern  const unsigned char gImage_2[] ;
extern ZHIXIN ZHIXIN_DATA;
#define NEED_WIFI 0 //本实验中是否需要WIFI
/*实验  ： 流水灯 LED1*/
int main(void)
{
 NVIC_PriorityGroupConfig (NVIC_PriorityGroup_2);
	
	#if NEED_WIFI
	//WIFI初始化代码
	WIFI_WEATHER_Init();
	#endif
	
	//LED初始化代码
	LED_INIT();
	//定时器初始化代码
  SysTick_Init(72);
	//UART初始化代码
	UART1_INIT(115200);
	//按键初始化代码
	Key_GPIO_Config();
  //TIM6初始化代码 + TIM6中断
	Timer6_Init();
  //LCD初始化代码
	LCD_Init();
  

	while(1)
	{
		printf("THIS IS A TEST\r\n");
    if( TIM6_TIMING_FLAG&TIM6TIMINGFlag_25ms)          //25ms任务时间到
    {
         TIM6_TIMING_FLAG&=(~TIM6TIMINGFlag_25ms);          //清除标志位
        Key_Scan4();
    }
	}
	
}

