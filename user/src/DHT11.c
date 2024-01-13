#include "DHT11.h"


/**************************************************************************
������	 void DHT11_INIT(void) 
���ܣ�	 DHT11��ʼ������
������ 	
����ֵ��
��ע��   ����վ
         DHT11--PC1
***************************************************************************/
void DHT11_IN(void)
 {
   // 1 ��APB2��ʱ��
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 ����GPIOΪ���ģʽ   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_IN_FLOATING  ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_1;
	    GPIO_Init(GPIOC,&GPIO_InitStruct);
 }

 void DHT11_OUT(void)
 {
   // 1 ��APB2��ʱ��
		 RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE );
	 
	 // 2 ����GPIOΪ���ģʽ   
	    GPIO_InitTypeDef GPIO_InitStruct ; 
	    GPIO_InitStruct.GPIO_Mode   =  GPIO_Mode_Out_PP   ;
	    GPIO_InitStruct.GPIO_Speed  =  GPIO_Speed_50MHz ;
	    GPIO_InitStruct.GPIO_Pin    =  GPIO_Pin_1;
	    GPIO_Init  (GPIOC,&GPIO_InitStruct );
 }

 #define DHT11_H GPIO_SetBits(GPIOC,GPIO_Pin_1)
 #define DHT11_L GPIO_ResetBits(GPIOC,GPIO_Pin_1)
 #define READ_DHT11 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)
 
 //���ݴ�������
 int TEMP_HUMI[2];//ȫ������ --->PYY.C
 uint8_t Dht11_ReadData(void)
{
	uint8_t retury = 0;
	uint8_t i = 0;
	uint8_t Data[5] = {0};
	
	DHT11_OUT();
	
	
	//������ʼ�ź�
	DHT11_L;
	Delay_ms(18);
	DHT11_H;
	
	//�ı�DHT11���ݴ��䷽��
	DHT11_IN();
	
	//�ȴ�DHT11��Ӧ
	while(READ_DHT11)
	{
		retury++;
		Delay_us(1);
		if(retury > 100)	return 0;
	}
	retury = 0;
	
	//�ȴ���Ӧ����
	while(READ_DHT11 == 0)
	{
		retury++;
		Delay_us(1);
		if(retury > 100)	return 0;
	}
	retury = 0;
	
	for(i=0; i<40; i++)
	{
		//�жϵ͵�ƽ�Ƿ���
		while(READ_DHT11)
		{
			retury++;
			Delay_us(1);
			if(retury > 100)	return 0;
		}
		retury = 0;	
		//�ȴ��͵�ƽ����
		while(READ_DHT11 == 0)
		{
			retury++;
			Delay_us(1);
			if(retury > 100)	return 0;
		}
		retury = 0;	
		
		Delay_us(30);
		//�ж�����
		if(READ_DHT11)//�յ�����1
		{
			Data[i/8] |= (1<<(7-i%8));
		}
		else
		{
			Data[i/8] &= ~(1<<(7-i%8));
		}
	}
	//У��
	if(Data[4] == Data[0]+Data[1]+Data[2]+Data[3])
	{
		TEMP_HUMI[0] = Data[0];//ʪ��
		TEMP_HUMI[1] = Data[2];//�¶�
		return 1;
	}
	else
	{
		printf("Dht11 Err\r\n");
		return 0;
	}
}
