#ifndef KEY_H
#define KEY_H

#include "stm32f10x.h"
#include "Delay.h"
#include <stdio.h>
void KEY_INIT(void);

/* *************************�궨��**************************/
/* KEY1 GPIO��ʼ��*/
#define KEY1_GPIO_PORT    	GPIOA			              /* �˿� */
#define KEY1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* ʱ�� */
#define KEY1_GPIO_PIN		    GPIO_Pin_0			        /* PIN�ű�� */


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define KEY_DOWN	1
#define KEY_UP	0

#define BUTTON_DEBOUNCE_TIME 	  2   //����ʱ��      (n-1)*��������
#define BUTTON_CONTINUOS_CYCLE  10	  //������������ʱ��  (n-1)*��������  
#define BUTTON_LONG_TIME 	      75		/* ����n��((n-1)*�������� ms)����Ϊ�����¼� */
#define CONTINUOS_TRIGGER 0         //���֧���������£�����֧�ֳ�����˫��
#define BUTTON_LONG_CYCLE 2         //����������ֵ

#define PRINT_INFO_ENABLE 1

#if PRINT_INFO_ENABLE
#define PRINT_INFO(fmt, args...) 	 do{(printf("\n[INFO] >> "), printf(fmt, ##args));}while(0)     
#else
#define PRINT_INFO(fmt, args...)	       
#endif

/* *************************�ṹ�嶨��**************************/
/* *************************ö�ٶ���**************************/
typedef enum {
  BUTTON_DOWM = 0,
  BUTTON_UP,
  BUTTON_DOUBLE,
  BUTTON_LONG,
  BUTTON_LONG_FREE,
  BUTTON_CONTINUOS,
  BUTTON_CONTINUOS_FREE,
  BUTTON_ALL_RIGGER,
  number_of_event, /* �����ص����¼� */
  NONE_TRIGGER
}Button_Event;

/* ************************extern�ⲿ��������**************************/
extern uint8_t first_press;
extern uint8_t DeBounce;

/* ************************�ⲿ��������**************************/
void Key_GPIO_Config(void);
uint8_t Key_Scan1(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
uint8_t Key_Scan2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
uint8_t Key_Scan3(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
void Key_Scan4(void);
#endif

