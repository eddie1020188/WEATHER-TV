#include "key.h"



 void KEY_INIT(void)
 {
   // 1 ��APB2��ʱ��
		  RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE );
	 
	 // 2 ����GPIOΪ���ģʽ   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING  ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_0;
	    GPIO_Init  (GPIOA,&GPIO_InitStruct );
 }

 
uint8_t first_press=0;
uint8_t DeBounce=0;
uint8_t Button_Last_Level;	//��ȡ�ϴΰ���״̬
uint8_t Button_State;
uint8_t Debounce_Time;		/* ����ʱ�� */
uint8_t Button_Trigger_Event;     /* ���������¼���������˫���������� */
uint8_t Long_Time;					/*��������ʱ��*/
uint8_t Button_Cycle;	           /* ������������ */

 
/**************************************************************************
������	 void Key_GPIO_Config(void) 
���ܣ�	 KEY��ʼ�����ó���
������ 	 ��
����ֵ�� ��
��ע��   KEY1 -- PA0   �����Ǹߵ�ƽ  
***************************************************************************/
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);

	Button_Last_Level=GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
	printf("\rButton_Last_Level:%d",Button_Last_Level);
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
uint8_t Key_Scan1(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);   
		return 	KEY_DOWN;	 
	}
	else
		return KEY_UP;
}

uint8_t Key_Scan2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		Delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
		{  
			return 	KEY_DOWN;	 
		}
		return KEY_UP;
	}
	else
		return KEY_UP;
}

uint8_t Key_Scan3(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		if(first_press==0)
		{
			first_press=1;
			DeBounce=20;
		}
		else
		{
			if(DeBounce==0)		//����ʱ�䵽
			{
				first_press=0;
				return KEY_DOWN;
			}
		}
		return KEY_UP;
	}
	else
		return KEY_UP;
}

/**************************************************************************
������	
���ܣ�	
������ 	
����ֵ��
��ע�� 
Button_Last_Level: ��һ�μ�⵽�İ�����ƽ��
Debounce_Time: ����ʱ���������
Button_State: ��¼�����ĵ�ǰ״̬���簴�¡��ɿ��ȣ���
Button_Cycle: �������������ڼ�������
Button_Trigger_Event: ��¼�������¼����ͣ���̰���������������������
Long_Time: ����ʱ���������      
***************************************************************************/
void Key_Scan4(void)
{			
	/*1 ��ȡ��ǰ����*/
	uint8_t current_level = GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
	
	/*2 �������ͷ���������*/
	//�����ǰ������ƽ���ϴβ�ͬ�����ҷ�����ʱ���ﵽԤ��ķ���ʱ�䣨BUTTON_DEBOUNCE_TIME��������°�����ƽ�����÷�����ʱ����
	if((current_level != Button_Last_Level)&&(++(Debounce_Time) >= BUTTON_DEBOUNCE_TIME)) //������ƽ�����仯������
  	{
      	Button_Last_Level = current_level; 	//���µ�ǰ������ƽ
      	Debounce_Time = 0;                 	//ȷ�����ǰ��� Debounce_Time ָ��������ʱ��
		    if(Button_State == NONE_TRIGGER)	  //����û�б�����
      	{
        	Button_State = BUTTON_DOWM;		//�л���BUTTON_DOWM״̬
      	}
      	//�ͷŰ���
      	else if(Button_State == BUTTON_DOWM)
      	{
        	Button_State = BUTTON_UP;
      	}
	}
		
		
	/*3 ����״̬�л� ״̬�ж��봦��*/
	switch(Button_State)
  	{
    	case BUTTON_DOWM :            // ����״̬
    	{
			if(Button_Last_Level == KEY_DOWN) //���������ڰ���״̬
      		{
				  
					#if CONTINUOS_TRIGGER     //֧���������� ��������ָ���ǰ������³�������ĳ���¼� ����˵һֱ������

					if(++(Button_Cycle) >= BUTTON_CONTINUOS_CYCLE)
					{
						Button_Cycle = 0;
						Button_Trigger_Event = BUTTON_CONTINUOS; 
						printf("\rButton continuously Pressed");
					}
        	#else		//֧�ֳ���
					//������ʱ�䳬����BUTTON_LONG_TIME��ʱ���϶�Ϊ����
					if(++Long_Time >= BUTTON_LONG_TIME)  {
					Long_Time=0;
					Button_Cycle = 0;
					Button_Trigger_Event = BUTTON_LONG; 
					printf("\rButton Long Pressed");
					//����ʱ�����
					if(Long_Time == 0xFF)  {
					Long_Time = BUTTON_LONG_TIME;}
					}
					else{
					//���ְ���״̬
					Button_Trigger_Event = BUTTON_DOWM;}
				  #endif	
			}
			break;
		}
			
		case BUTTON_UP :        // ����״̬�����״̬
    	 
		if(Button_Trigger_Event == BUTTON_DOWM){
					Button_State = NONE_TRIGGER;  	//�ָ�����ʼ״̬
					Button_Last_Level=KEY_UP;
					Long_Time=0;
					printf("\rButton Pressed");}
		//����֮���ɿ���״̬�ָ�
		else if(Button_Trigger_Event == BUTTON_LONG) {
				  Long_Time = 0;
				  Button_State = NONE_TRIGGER;} 
		#if CONTINUOS_TRIGGER
			else if(Button_Trigger_Event == BUTTON_CONTINUOS)  //֧����������
			{
				Button_Cycle = 0;
				Button_State = NONE_TRIGGER;
			} 
		#endif
			break;
		
	   default :
      	break;
	}
}



/*********************************************END OF FILE**********************/
