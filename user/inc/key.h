#ifndef KEY_H
#define KEY_H

#include "stm32f10x.h"
#include "Delay.h"
#include <stdio.h>
void KEY_INIT(void);

/* *************************宏定义**************************/
/* KEY1 GPIO初始化*/
#define KEY1_GPIO_PORT    	GPIOA			              /* 端口 */
#define KEY1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* 时钟 */
#define KEY1_GPIO_PIN		    GPIO_Pin_0			        /* PIN脚编号 */


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define KEY_DOWN	1
#define KEY_UP	0

#define BUTTON_DEBOUNCE_TIME 	  2   //消抖时间      (n-1)*调用周期
#define BUTTON_CONTINUOS_CYCLE  10	  //连按触发周期时间  (n-1)*调用周期  
#define BUTTON_LONG_TIME 	      75		/* 持续n秒((n-1)*调用周期 ms)，认为长按事件 */
#define CONTINUOS_TRIGGER 0         //如果支持连续按下，则不再支持长按和双击
#define BUTTON_LONG_CYCLE 2         //连续长按阈值

#define PRINT_INFO_ENABLE 1

#if PRINT_INFO_ENABLE
#define PRINT_INFO(fmt, args...) 	 do{(printf("\n[INFO] >> "), printf(fmt, ##args));}while(0)     
#else
#define PRINT_INFO(fmt, args...)	       
#endif

/* *************************结构体定义**************************/
/* *************************枚举定义**************************/
typedef enum {
  BUTTON_DOWM = 0,
  BUTTON_UP,
  BUTTON_DOUBLE,
  BUTTON_LONG,
  BUTTON_LONG_FREE,
  BUTTON_CONTINUOS,
  BUTTON_CONTINUOS_FREE,
  BUTTON_ALL_RIGGER,
  number_of_event, /* 触发回调的事件 */
  NONE_TRIGGER
}Button_Event;

/* ************************extern外部变量声明**************************/
extern uint8_t first_press;
extern uint8_t DeBounce;

/* ************************外部函数声明**************************/
void Key_GPIO_Config(void);
uint8_t Key_Scan1(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
uint8_t Key_Scan2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
uint8_t Key_Scan3(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
void Key_Scan4(void);
#endif

