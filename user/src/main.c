#include "main.h"

extern volatile unsigned int TIM6_TIMING_FLAG ;//TIM6��ʱ����־
extern  const unsigned char gImage_2[] ;
extern ZHIXIN ZHIXIN_DATA;
#define NEED_WIFI 0 //��ʵ�����Ƿ���ҪWIFI
/*ʵ��  �� ��ˮ�� LED1*/
int main(void)
{
 NVIC_PriorityGroupConfig (NVIC_PriorityGroup_2);
	
	#if NEED_WIFI
	//WIFI��ʼ������
	WIFI_WEATHER_Init();
	#endif
	
	//LED��ʼ������
	LED_INIT();
	//��ʱ����ʼ������
  SysTick_Init(72);
	//UART��ʼ������
	UART1_INIT(115200);
	//������ʼ������
	Key_GPIO_Config();
  //TIM6��ʼ������ + TIM6�ж�
	Timer6_Init();
  //LCD��ʼ������
	LCD_Init();
  

	while(1)
	{
		printf("THIS IS A TEST\r\n");
    if( TIM6_TIMING_FLAG&TIM6TIMINGFlag_25ms)          //25ms����ʱ�䵽
    {
         TIM6_TIMING_FLAG&=(~TIM6TIMINGFlag_25ms);          //�����־λ
        Key_Scan4();
    }
	}
	
}

