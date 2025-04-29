#include "main.h"

extern volatile unsigned int TIM6_TIMING_FLAG ;//TIM6��ʱ����־
extern  const unsigned char gImage_2[] ;
extern ZHIXIN ZHIXIN_DATA;
extern uint8_t Button_Trigger_Event;
#define NEED_WIFI 0 //��ʵ�����Ƿ���ҪWIFI
/*ʵ��  �� ��ˮ�� LED1*/
//你好世界！
//你好新分支！
//嘿嘿嘿
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

    if( TIM6_TIMING_FLAG&TIM6TIMINGFlag_25ms)          //25ms����ʱ�䵽
    {
        TIM6_TIMING_FLAG&=(~TIM6TIMINGFlag_25ms);          //�����־λ
        Key_Scan4();
			  if(Button_Trigger_Event ==  BUTTON_LONG ){
        WIFI_WEATHER_Init();
				}
				else if(Button_Trigger_Event ==  BUTTON_DOWM)
				{
				LED1_FZ;
				LED2_FZ;
				}
    }
	}
	
}

