#ifndef __LCD_H
#define __LCD_H

#include "stm32f10x.h"

#define USE_HORIZONTAL 2  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
#define Chip_Selection 1   //设置芯片初始化 0为ILI9341  1为ST7789

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 320

#else
#define LCD_W 320
#define LCD_H 240
#endif


//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

void LCD_Init(void);
void LCD_Fill(u16 xsta, u16 ysta, u16 xend, u16 yend, u16 color);
void LCD_WR_DATA(u16 dat);
void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_ShowPic(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,u8 *ch);
void LCD_ShowString(unsigned short x, unsigned short y, unsigned char *str, unsigned short pin_color, unsigned short back_color, unsigned char sizey);
void LCD_showch(u16 x1,u16 y1,u16 pin_color,u16 back_color,u8 ch,u8 size);
void LCD_showZW(u16 x1,u16 y1,u16 pin_color,u16 back_color,u8 *ch,u8 size);
void LCD_showchar(u16 x1,u16 y1,u16 pin_color,u16 back_color,u8 *ch,u8 size);
void LCD_Show_String(u8 es,u8 ys,u8 size,u16 color,u8 *buffer);

#endif
