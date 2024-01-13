#include "DHT11.h"


/**************************************************************************
函数：	 void DHT11_INIT(void) 
功能：	 DHT11初始化程序
参数： 	
返回值：
备注：   气象站
         DHT11--PC1
***************************************************************************/
void DHT11_IN(void)
 {
   // 1 打开APB2的时钟
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 设置GPIO为输出模式   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING  ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_1;
	    GPIO_Init(GPIOC,&GPIO_InitStruct);
 }

 void DHT11_OUT(void)
 {
   // 1 打开APB2的时钟
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 设置GPIO为输出模式   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_Out_PP   ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_1;
	    GPIO_Init  (GPIOC,&GPIO_InitStruct );
 }

 #define DHT11_H GPIO_SetBits(GPIOC,GPIO_Pin_1)
 #define DHT11_L GPIO_ResetBits(GPIOC,GPIO_Pin_1)
 #define READ_DHT11 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)
 
 //数据传输流程
 int TEMP_HUMI[2];//全局数组 --->PYY.C
 uint8_t Dht11_ReadData(void)
{
	uint8_t retury = 0;
	uint8_t i = 0;
	uint8_t Data[5] = {0};
	
	DHT11_OUT();
	
	
	//发送起始信号
	DHT11_L;
	Delay_ms(18);
	DHT11_H;
	
	//改变DHT11数据传输方向
	DHT11_IN();
	
	//等待DHT11响应
	while(READ_DHT11)
	{
		retury++;
		Delay_us(1);
		if(retury > 100)	return 0;
	}
	retury = 0;
	
	//等待响应结束
	while(READ_DHT11 == 0)
	{
		retury++;
		Delay_us(1);
		if(retury > 100)	return 0;
	}
	retury = 0;
	
	for(i=0; i<40; i++)
	{
		//判断低电平是否到来
		while(READ_DHT11)
		{
			retury++;
			Delay_us(1);
			if(retury > 100)	return 0;
		}
		retury = 0;	
		//等待低电平结束
		while(READ_DHT11 == 0)
		{
			retury++;
			Delay_us(1);
			if(retury > 100)	return 0;
		}
		retury = 0;	
		
		Delay_us(30);
		//判断数据
		if(READ_DHT11)//收到数据1
		{
			Data[i/8] |= (1<<(7-i%8));
		}
		else
		{
			Data[i/8] &= ~(1<<(7-i%8));
		}
	}
	//校验
	if(Data[4] == Data[0]+Data[1]+Data[2]+Data[3])
	{
		TEMP_HUMI[0] = Data[0];//湿度
		TEMP_HUMI[1] = Data[2];//温度
		return 1;
	}
	else
	{
		printf("Dht11 Err\r\n");
		return 0;
	}
}
