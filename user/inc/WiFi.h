#ifndef WiFi_H
#define WiFi_H


#include "stm32f10x.h"
#include "string.h"

#define ALIYUN 0 //需要使用阿里云时置1

#define WIFI_ENABLE     GPIO_SetBits  ( GPIOC, GPIO_Pin_9)
#define WIFI_DISABLE    GPIO_ResetBits  ( GPIOC, GPIO_Pin_9)

typedef struct
{
  char LOCATION[20];
	char WEATHER[20];
	char TEM[20];
}ZHIXIN;

#if ALIYUN
#define Publish_Topic    "/sys/hb7oII4cA2N/QIAOZHU/thing/event/property/post"
#define Subscribe_Topic  "/sys/hb7oII4cA2N/QIAOZHU/thing/service/property/set"
void WiFi_TCP_Init(void);

#endif
void WIFI_WEATHER_Init(void);
char WiFi_SendAT(char *AT,char *respond);
void WiFi_ConnectAP(char *ssid,char *pwd);
void WiFi_ConnectServer(char *type,char *remote_IP,char* remote_Port);
void WiFi_ExitTransmit(void);
char* Parse_Cjson_Weather(char* buff);
#endif
