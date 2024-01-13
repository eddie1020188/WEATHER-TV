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

/******************************连接阿里云服务器参数*********************************************/
#define Remote_IP   "iot-06z00evmgg3w7p8.mqtt.iothub.aliyuncs.com"
#define Remote_Port "1883"

#define ClientID    "hb7oII4cA2N.QIAOZHU|securemode=2,signmethod=hmacsha256,timestamp=1703817285034|"
#define Username    "QIAOZHU&hb7oII4cA2N"
#define Password    "d34616f5a9affeb48c6a15354b4d35c6dff55380f2de3cbe22b84f83f5f4a4b4"

/******************************连接天气服务器参数*********************************************/
#define Remote_WEATHERIP   "api.seniverse.com"
#define Remote_WEATHERPort "80"

u16 time=0;
u8 ret=0;
/****************************************************************************************************
 * Function  : WiFi模块初始化,连接天气服务器
 * Parameter : void
 * Return    : void
 * Comment   : WIFI_ENBALE -- PC9  
*****************************************************************************************************/

void WIFI_WEATHER_Init(void)
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
	
	//1、初始化GPIO，配置复用
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	USART3_Init();
	
	/*需要打开WIFI模块才能使用 根据硬件原理图设置*/
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
	ret = WiFi_SendAT("AT+CIPSEND\r\n",">");//进入透传成功返回0
	
	if(!ret){
	
	printf("发送成功\r\n");
	USART3_SendStr("GET https://api.seniverse.com/v3/weather/now.json?key=SNPRPSia_QjsXlBZ-&location=nanjing&language=en&unit=c\r\n");
	
}
}


/****************************************************************************************************
 * Function  : 向WiFi模块发送AT指令
 * Parameter : char *AT,AT指令; char *respond,期望接收到的回应
 * Return    : char
 * Comment   : 无
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
 * Function  : WiFi模块连接AP
 * Parameter : char *ssid,WIFI名称; char *pwd,WIFI密码
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
 * Function  : WiFi模块连接Server
 * Parameter : char *type,连接类型; char *remote_IP,域名; char* remote_Port,端口号
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
 * Function  : WiFi退出透传模式
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
函数：	
功能：	
参数： 	
返回值：
备注：{"results":[{"location":{"id":"WX4FBXXFKE4F",
"name":"Beijing","country":"CN","path":"Beijing,Beijing,China",
"timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":
"Clear","code":"1","temperature":"-5"},"last_update":"2024-01-07T20:52:11+08:00"}]}
涉及知识点：
1 直接return weather_data 因为它是局部变量 它这块地址会在函数执行结束被释放掉 所以我们动态分配一块内存 
***************************************************************************/

ZHIXIN ZHIXIN_DATA;
char* Parse_Cjson_Weather(char* buff) {
    // 寻找"text"以找到天气数据
	 
	
    char *sp = strstr(buff, "name");
    if(sp != NULL) {
        sp += 7;
        // 找到"的位置 用这个位置减去sp的位置 就是地址的长度
        char *ep = strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // 使用动态分配来避免返回局部变量的地址
             strncpy(ZHIXIN_DATA.LOCATION, sp, len);
                // 确保字符串以null结尾
                ZHIXIN_DATA.LOCATION[len] = '\0';
							printf("ZHIXIN_DATA.LOCATION: %s\r\n", ZHIXIN_DATA.LOCATION);
            }
        }
		    sp = strstr(buff, "text");
				if(sp != NULL) {
        sp += 7;
        // 在 C 语言中，如果在一个块内（比如 if 语句块）声明了一个变量，那么这个变量的作用域仅限于这个块。
        char *ep= strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // 使用动态分配来避免返回局部变量的地址
             strncpy(ZHIXIN_DATA.WEATHER, sp, len);
                // 确保字符串以null结尾
                ZHIXIN_DATA.WEATHER[len] = '\0';
							printf("ZHIXIN_DATA.WEATHER: %s\r\n", ZHIXIN_DATA.WEATHER);
            }
        }
				sp = strstr(buff, "temperature");
				if(sp != NULL) {
        sp += 14;
        // 在 C 语言中，如果在一个块内（比如 if 语句块）声明了一个变量，那么这个变量的作用域仅限于这个块。
        char *ep= strchr(sp,'\"');
        if (ep != NULL) {
            int len = ep - sp;
            // 使用动态分配来避免返回局部变量的地址
             strncpy(ZHIXIN_DATA.TEM, sp, len);
                // 确保字符串以null结尾
             ZHIXIN_DATA.TEM[len] = '\0';
						 printf("ZHIXIN_DATA.TEM: %s\r\n", ZHIXIN_DATA.TEM);
            }
        }
				
    }








