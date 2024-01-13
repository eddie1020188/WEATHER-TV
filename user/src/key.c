#include "key.h"



 void KEY_INIT(void)
 {
   // 1 打开APB2的时钟
		  RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE );
	 
	 // 2 设置GPIO为输出模式   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING  ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_0;
	    GPIO_Init  (GPIOA,&GPIO_InitStruct );
 }

 
uint8_t first_press=0;
uint8_t DeBounce=0;
uint8_t Button_Last_Level;	//读取上次按键状态
uint8_t Button_State;
uint8_t Debounce_Time;		/* 消抖时间 */
uint8_t Button_Trigger_Event;     /* 按键触发事件，单击，双击，长按等 */
uint8_t Long_Time;					/*按键长按时间*/
uint8_t Button_Cycle;	           /* 连续按键周期 */

 
/**************************************************************************
函数：	 void Key_GPIO_Config(void) 
功能：	 KEY初始化配置程序
参数： 	 无
返回值： 无
备注：   KEY1 -- PA0   按下是高电平  
***************************************************************************/
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*开启按键端口的时钟*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
	
	//选择按键的引脚
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	// 设置按键的引脚为浮空输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//使用结构体初始化按键
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);

	Button_Last_Level=GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
	printf("\rButton_Last_Level:%d",Button_Last_Level);
}

 /*
 * 函数名：Key_Scan
 * 描述  ：检测是否有按键按下
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：KEY_OFF(没按下按键)、KEY_ON（按下按键）
 */
uint8_t Key_Scan1(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN);   
		return 	KEY_DOWN;	 
	}
	else
		return KEY_UP;
}

uint8_t Key_Scan2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测是否有按键按下 */
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
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_DOWN )  
	{	 
		if(first_press==0)
		{
			first_press=1;
			DeBounce=20;
		}
		else
		{
			if(DeBounce==0)		//防抖时间到
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
函数：	
功能：	
参数： 	
返回值：
备注： 
Button_Last_Level: 上一次检测到的按键电平。
Debounce_Time: 防抖时间计数器。
Button_State: 记录按键的当前状态（如按下、松开等）。
Button_Cycle: 连续触发的周期计数器。
Button_Trigger_Event: 记录触发的事件类型（如短按、长按、连续触发）。
Long_Time: 长按时间计数器。      
***************************************************************************/
void Key_Scan4(void)
{			
	/*1 读取当前按键*/
	uint8_t current_level = GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
	
	/*2 按键检测和防抖动处理*/
	//如果当前按键电平与上次不同，并且防抖计时器达到预设的防抖时间（BUTTON_DEBOUNCE_TIME），则更新按键电平并重置防抖计时器。
	if((current_level != Button_Last_Level)&&(++(Debounce_Time) >= BUTTON_DEBOUNCE_TIME)) //按键电平发生变化，消抖
  	{
      	Button_Last_Level = current_level; 	//更新当前按键电平
      	Debounce_Time = 0;                 	//确定了是按下 Debounce_Time 指的是消抖时间
		    if(Button_State == NONE_TRIGGER)	  //按键没有被触发
      	{
        	Button_State = BUTTON_DOWM;		//切换到BUTTON_DOWM状态
      	}
      	//释放按键
      	else if(Button_State == BUTTON_DOWM)
      	{
        	Button_State = BUTTON_UP;
      	}
	}
		
		
	/*3 按键状态切换 状态判断与处理*/
	switch(Button_State)
  	{
    	case BUTTON_DOWM :            // 按下状态
    	{
			if(Button_Last_Level == KEY_DOWN) //按键保持在按下状态
      		{
				  
					#if CONTINUOS_TRIGGER     //支持连续触发 连续触发指的是按键按下持续触发某种事件 比如说一直加音量

					if(++(Button_Cycle) >= BUTTON_CONTINUOS_CYCLE)
					{
						Button_Cycle = 0;
						Button_Trigger_Event = BUTTON_CONTINUOS; 
						printf("\rButton continuously Pressed");
					}
        	#else		//支持长按
					//当按下时间超出了BUTTON_LONG_TIME的时候被认定为长按
					if(++Long_Time >= BUTTON_LONG_TIME)  {
					Long_Time=0;
					Button_Cycle = 0;
					Button_Trigger_Event = BUTTON_LONG; 
					printf("\rButton Long Pressed");
					//更新时间溢出
					if(Long_Time == 0xFF)  {
					Long_Time = BUTTON_LONG_TIME;}
					}
					else{
					//保持按下状态
					Button_Trigger_Event = BUTTON_DOWM;}
				  #endif	
			}
			break;
		}
			
		case BUTTON_UP :        // 弹起状态，清除状态
    	 
		if(Button_Trigger_Event == BUTTON_DOWM){
					Button_State = NONE_TRIGGER;  	//恢复到初始状态
					Button_Last_Level=KEY_UP;
					Long_Time=0;
					printf("\rButton Pressed");}
		//长按之后松开，状态恢复
		else if(Button_Trigger_Event == BUTTON_LONG) {
				  Long_Time = 0;
				  Button_State = NONE_TRIGGER;} 
		#if CONTINUOS_TRIGGER
			else if(Button_Trigger_Event == BUTTON_CONTINUOS)  //支持连续触发
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
