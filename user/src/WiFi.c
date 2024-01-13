#include "main.h"

#define IPHONE 1
#define HOME   0
#if HOME
#define WiFi_SSID   "Xiaomi_BB25"
#define WiFi_PWD    "sjw110807xqz"
#endif

#if IPHONE
#define WiFi_SSID   "Eddie"
#define WiFi_PWD    "sjw19980807"
#endif

/******************************���Ӱ����Ʒ���������*********************************************/
#define Remote_IP   "iot-06z00evmgg3w7p8.mqtt.iothub.aliyuncs.com"
#define Remote_Port "1883"

#define ClientID    "hb7oII4cA2N.QIAOZHU|securemode=2,signmethod=hmacsha256,timestamp=1703817285034|"
#define Username    "QIAOZHU&hb7oII4cA2N"
#define Password    "d34616f5a9affeb48c6a15354b4d35c6dff55380f2de3cbe22b84f83f5f4a4b4"

/******************************������������������*********************************************/
#define Remote_WEATHERIP   "api.seniverse.com"
#define Remote_WEATHERPort "80"

u16 time=0;
u8 ret=0;
/****************************************************************************************************
 * Function  : WiFiģ���ʼ��,��������������
 * Parameter : void
 * Return    : void
 * Comment   : WIFI_ENBALE -- PC9  
*****************************************************************************************************/

void WIFI_WEATHER_Init(void)
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
	
	//1����ʼ��GPIO�����ø���
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	USART3_Init();
	
	/*��Ҫ��WIFIģ�����ʹ�� ����Ӳ��ԭ��ͼ����*/
	WIFI_DISABLE;
	Delay_ms(500);
	WIFI_ENABLE ;
  	
  WiFi_ExitTransmit();
	Delay_ms(1000);
	WiFi_SendAT("AT\r\n","OK");
  WiFi_SendAT("AT+CWMODE=1\r\n","OK");
  WiFi_ConnectAP(WiFi_SSID,WiFi_PWD);
	WiFi_ConnectServer("TCP",Remote_WEATHERIP ,Remote_WEATHERPort);
	WiFi_SendAT("AT+CIPMODE=1\r\n","OK");
	ret = WiFi_SendAT("AT+CIPSEND\r\n",">");//����͸���ɹ�����0
	
	if(!ret){
	
	printf("���ͳɹ�\r\n");
	USART3_SendStr("GET https://api.seniverse.com/v3/weather/now.json?key=SNPRPSia_QjsXlBZ-&location=nanjing&language=en&unit=c\r\n");
	
}
}


/****************************************************************************************************
 * Function  : ��WiFiģ�鷢��ATָ��
 * Parameter : char *AT,ATָ��; char *respond,�������յ��Ļ�Ӧ
 * Return    : char
 * Comment   : ��
*****************************************************************************************************/
char WiFi_SendAT(char *AT,char *respond)
{
	USART3_SendStr(AT);
	while(!WiFi_Rev.Rev_Flag)
	{
		Delay_ms(1);
		time++;
		if(time>500)
		{
			printf("-----TIME OUT-----!\r\n");
			return 1;
		}
	}
	Delay_ms(50);
	if(WiFi_Rev.Rev_Flag)
	{
		WiFi_Rev.Rev_Flag=0;
		if(strstr(WiFi_Rev.Rev_Buff,respond)==NULL)
		{
			return 2;
		}
  }
	return 0;
}

/****************************************************************************************************
 * Function  : WiFiģ������AP
 * Parameter : char *ssid,WIFI����; char *pwd,WIFI����
 * Return    : void
 * Comment   : "AT+CWJAP=\"ssid\",\"pwd\"\r\n"
*****************************************************************************************************/
void WiFi_ConnectAP(char *ssid,char *pwd)
{
	ret = WiFi_SendAT("AT+CIFSR\r\n","0.0.0.0");
	if(ret==0)
	{
		char buff[50]="AT+CWJAP=";
		strcat(buff,"\"");
		strcat(buff,ssid);
		strcat(buff,"\",\"");
		strcat(buff,pwd);
		strcat(buff,"\"\r\n");
		USART3_SendStr(buff);
		Delay_ms(100);
		while(WiFi_Rev.Rev_Flag==1)
		{
			Delay_ms(10);
		  ret++;
		  if(ret==200) 
			{
				WiFi_Rev.Rev_Flag=0;
				return;
			}
			if(strstr(WiFi_Rev.Rev_Buff,"WIFI GOT IP")!=NULL)
			{
				printf("--AP Connect Succeed!--\r\n");
				WiFi_Rev.Rev_Flag=0;
				return;
			}
		}
	}
	else
	{
		printf("--AP Have Connected!--\r\n");
	}
}

/****************************************************************************************************
 * Function  : WiFiģ������Server
 * Parameter : char *type,��������; char *remote_IP,����; char* remote_Port,�˿ں�
 * Return    : void
 * Comment   : "AT+CIPSTART=\"type\",\"remote_IP\",remote_Port\r\n"
*****************************************************************************************************/
void WiFi_ConnectServer(char *type,char *remote_IP,char* remote_Port)
{
	ret=0;
	char buff[80]="AT+CIPSTART=";
	strcat(buff,"\"");
	strcat(buff,type);
	strcat(buff,"\",\"");
	strcat(buff,remote_IP);
	strcat(buff,"\",");
	strcat(buff,remote_Port);
	strcat(buff,"\r\n");
	USART3_SendStr(buff);
	Delay_ms(100);
	while(WiFi_Rev.Rev_Flag==1)
	{
		Delay_ms(10);
		ret++;
		if(ret==200) 
		{
			WiFi_Rev.Rev_Flag=0;
			return;
		}
		if(strstr(WiFi_Rev.Rev_Buff,"CONNECT")!=NULL)
		{
			printf("--Server Connect Succeed!--\r\n");
			WiFi_Rev.Rev_Flag=0;
			return;
		}
	}
}

/****************************************************************************************************
 * Function  : WiFi�˳�͸��ģʽ
 * Parameter : void
 * Return    : void
 * Comment   : "+++"
*****************************************************************************************************/
void WiFi_ExitTransmit(void)
{
	ret=0;
	USART3_SendStr("+++");
	Delay_ms(600);
	Delay_ms(600);
	WiFi_SendAT("AT\r\n","OK");
	WiFi_SendAT("AT\r\n","OK");
	
	USART3_SendStr("AT+RST\r\n");
	Delay_ms(500);

	while(WiFi_Rev.Rev_Flag)
	{
		Delay_ms(50);
		ret++;
		if(ret==200) 
	  {
			WiFi_Rev.Rev_Flag=0;
			return;
		}
		if(strstr(WiFi_Rev.Rev_Buff,"WIFI GOT IP")!=NULL)
		{
			printf("--WIFI RESET SUCCEED--!\r\n");
			WiFi_Rev.Rev_Flag=0;
			return;
		}
	}
}

/**************************************************************************
������	
���ܣ�	
������ 	
����ֵ��
��ע��{"results":[{"location":{"id":"WX4FBXXFKE4F",
"name":"Beijing","country":"CN","path":"Beijing,Beijing,China",
"timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":
"Clear","code":"1","temperature":"-5"},"last_update":"2024-01-07T20:52:11+08:00"}]}
�漰֪ʶ�㣺
1 ֱ��return weather_data ��Ϊ���Ǿֲ����� ������ַ���ں���ִ�н������ͷŵ� �������Ƕ�̬����һ���ڴ� 
***************************************************************************/

ZHIXIN ZHIXIN_DATA;
char* Parse_Cjson_Weather(char* buff) {
    // Ѱ��"text"���ҵ���������
	 
	
    char *sp = strstr(buff, "name");
    if(sp != NULL) {
        sp += 7;
        // �ҵ�"��λ�� �����λ�ü�ȥsp��λ�� ���ǵ�ַ�ĳ���
        char *ep = strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // ʹ�ö�̬���������ⷵ�ؾֲ������ĵ�ַ
             strncpy(ZHIXIN_DATA.LOCATION, sp, len);
                // ȷ���ַ�����null��β
                ZHIXIN_DATA.LOCATION[len] = '\0';
							printf("ZHIXIN_DATA.LOCATION: %s\r\n", ZHIXIN_DATA.LOCATION);
            }
        }
		    sp = strstr(buff, "text");
				if(sp != NULL) {
        sp += 7;
        // �� C �����У������һ�����ڣ����� if ���飩������һ����������ô������������������������顣
        char *ep= strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // ʹ�ö�̬���������ⷵ�ؾֲ������ĵ�ַ
             strncpy(ZHIXIN_DATA.WEATHER, sp, len);
                // ȷ���ַ�����null��β
                ZHIXIN_DATA.WEATHER[len] = '\0';
							printf("ZHIXIN_DATA.WEATHER: %s\r\n", ZHIXIN_DATA.WEATHER);
            }
        }
				sp = strstr(buff, "temperature");
				if(sp != NULL) {
        sp += 14;
        // �� C �����У������һ�����ڣ����� if ���飩������һ����������ô������������������������顣
        char *ep= strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // ʹ�ö�̬���������ⷵ�ؾֲ������ĵ�ַ
             strncpy(ZHIXIN_DATA.TEM, sp, len);
                // ȷ���ַ�����null��β
             ZHIXIN_DATA.TEM[len] = '\0';
						 printf("ZHIXIN_DATA.TEM: %s\r\n", ZHIXIN_DATA.TEM);
            }
        }
				
    }








