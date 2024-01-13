#include "font.h"


 //汉字库：

const char hzk[] = "城市温度天气";
//字符库

const char zfk[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~!@#$%^&*():\"<>° abcdefghijklmnopqrstuvwxyz";

//汉字模
const  char hzm[] = {
	

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x03,0x00,0x07,0x00,
0x03,0x00,0x04,0xC0,0x03,0x00,0x04,0x60,0x03,0x00,0x04,0x20,0x03,0x08,0x04,0x18,
0x03,0x07,0xFF,0xFC,0x03,0x04,0x06,0x00,0x03,0x24,0x06,0x00,0x7F,0xF4,0x06,0x00,
0x03,0x0C,0x06,0x18,0x03,0x04,0x26,0x38,0x03,0x07,0xFE,0x30,0x03,0x04,0x36,0x30,
0x03,0x0C,0x22,0x20,0x03,0x0C,0x22,0x60,0x03,0x0C,0x22,0x60,0x03,0x0C,0x23,0xC0,
0x03,0x3C,0x23,0xC0,0x03,0xCC,0x61,0x80,0x1F,0x08,0x61,0x80,0x38,0x18,0x63,0x80,
0x30,0x1B,0xE3,0x84,0x00,0x11,0xC6,0xC4,0x00,0x30,0x8C,0x64,0x00,0x60,0x10,0x34,
0x00,0x40,0x60,0x3C,0x00,0x80,0x80,0x1C,0x01,0x01,0x00,0x04,0x00,0x00,0x00,0x00,/*"城",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x03,0x00,0x00,
0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x10,0x00,0x01,0x80,0x38,0x3F,0xFF,0xFF,0xFC,
0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x02,0x01,0x80,0x80,
0x03,0xFF,0xFF,0xE0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,
0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,
0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0,
0x03,0x01,0x90,0xC0,0x03,0x01,0x8F,0xC0,0x03,0x01,0x83,0x80,0x02,0x01,0x81,0x00,
0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,/*"市",1*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x08,0x00,0x80,
0x06,0x0F,0xFF,0xC0,0x03,0x0C,0x00,0x80,0x03,0x0C,0x00,0x80,0x00,0x2C,0x00,0x80,
0x00,0x4C,0x00,0x80,0x00,0x4F,0xFF,0x80,0x00,0x4C,0x00,0x80,0x30,0x4C,0x00,0x80,
0x18,0x8C,0x00,0x80,0x0C,0x8C,0x00,0x80,0x08,0x8F,0xFF,0x80,0x01,0x0C,0x00,0x80,
0x01,0x08,0x00,0x00,0x01,0x00,0x00,0x00,0x03,0x20,0x00,0x20,0x02,0x3F,0xFF,0xF0,
0x02,0x31,0x8C,0x60,0x06,0x31,0x8C,0x60,0x3E,0x31,0x8C,0x60,0x0E,0x31,0x8C,0x60,
0x0C,0x31,0x8C,0x60,0x0C,0x31,0x8C,0x60,0x0C,0x31,0x8C,0x60,0x0C,0x31,0x8C,0x60,
0x0C,0x31,0x8C,0x6C,0x0D,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"温",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0xC0,0x00,
0x00,0x00,0xE0,0x10,0x04,0x00,0x40,0x38,0x07,0xFF,0xFF,0xFC,0x06,0x04,0x04,0x00,
0x06,0x07,0x07,0x00,0x06,0x06,0x06,0x00,0x06,0x06,0x06,0x30,0x07,0xFF,0xFF,0xF8,
0x06,0x06,0x06,0x00,0x06,0x06,0x06,0x00,0x06,0x06,0x06,0x00,0x06,0x06,0x06,0x00,
0x06,0x07,0xFE,0x00,0x06,0x06,0x06,0x00,0x04,0x00,0x01,0x00,0x04,0x3F,0xFF,0x80,
0x0C,0x04,0x03,0x80,0x0C,0x02,0x07,0x00,0x0C,0x03,0x06,0x00,0x08,0x01,0x0C,0x00,
0x08,0x00,0xD8,0x00,0x18,0x00,0x70,0x00,0x10,0x00,0xF8,0x00,0x10,0x03,0x9E,0x00,
0x20,0x0E,0x07,0xF8,0x20,0x70,0x00,0xF8,0x47,0x80,0x00,0x10,0x00,0x00,0x00,0x00,/*"度",1*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x00,0x00,0x01,0xC0,0x07,0xFF,0xFF,0xE0,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,
0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,
0x00,0x03,0x00,0x20,0x00,0x03,0x00,0x70,0x3F,0xFF,0xFF,0xF8,0x00,0x03,0x40,0x00,
0x00,0x02,0x40,0x00,0x00,0x06,0x40,0x00,0x00,0x06,0x20,0x00,0x00,0x06,0x20,0x00,
0x00,0x0C,0x10,0x00,0x00,0x0C,0x18,0x00,0x00,0x18,0x08,0x00,0x00,0x30,0x0C,0x00,
0x00,0x30,0x06,0x00,0x00,0x60,0x03,0x00,0x00,0xC0,0x03,0xC0,0x01,0x00,0x01,0xF0,
0x06,0x00,0x00,0x7E,0x08,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"天",2*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0xE0,0x00,0x00,
0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,0x00,0x01,0x80,0x00,0x60,0x01,0xFF,0xFF,0xF0,
0x03,0x00,0x00,0x00,0x03,0x00,0x01,0x00,0x06,0xFF,0xFF,0x80,0x04,0x00,0x00,0x00,
0x0C,0x00,0x00,0x00,0x18,0x00,0x02,0x00,0x17,0xFF,0xFF,0x00,0x20,0x00,0x06,0x00,
0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x06,0x00,
0x00,0x00,0x06,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x03,0x00,
0x00,0x00,0x03,0x08,0x00,0x00,0x03,0x08,0x00,0x00,0x01,0x88,0x00,0x00,0x01,0xC8,
0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,/*"气",3*/






};

//字符模
const char zfm[] = {
	
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x04,0xC0,0x04,0xC0,0x04,0xC0,0x04,0xC0,0x0C,0x40,0x08,0x60,
0x08,0x60,0x08,0x60,0x18,0x20,0x1F,0xF0,0x10,0x30,0x10,0x30,0x10,0x30,0x20,0x18,
0x20,0x18,0x20,0x18,0x60,0x1C,0xF8,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"A",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x18,0x38,
0x18,0x18,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x18,0x18,0x30,
0x1F,0xE0,0x18,0x18,0x18,0x0C,0x18,0x04,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,
0x18,0x06,0x18,0x0C,0x18,0x18,0x7F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"B",1*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0x06,0x1C,
0x08,0x0C,0x18,0x06,0x30,0x02,0x30,0x02,0x30,0x00,0x60,0x00,0x60,0x00,0x60,0x00,
0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x30,0x02,0x30,0x02,
0x10,0x04,0x18,0x08,0x0C,0x10,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C",2*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xC0,0x18,0x70,
0x18,0x18,0x18,0x08,0x18,0x0C,0x18,0x0C,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,
0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x04,0x18,0x0C,0x18,0x0C,
0x18,0x18,0x18,0x18,0x18,0x60,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"D",3*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFC,0x18,0x0C,
0x18,0x04,0x18,0x02,0x18,0x02,0x18,0x00,0x18,0x00,0x18,0x10,0x18,0x10,0x18,0x30,
0x1F,0xF0,0x18,0x30,0x18,0x10,0x18,0x10,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x02,
0x18,0x02,0x18,0x04,0x18,0x0C,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"E",4*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFC,0x18,0x1C,
0x18,0x04,0x18,0x02,0x18,0x02,0x18,0x00,0x18,0x00,0x18,0x10,0x18,0x10,0x18,0x30,
0x1F,0xF0,0x18,0x30,0x18,0x10,0x18,0x10,0x18,0x10,0x18,0x00,0x18,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"F",5*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x0C,0x30,
0x08,0x10,0x18,0x18,0x30,0x08,0x30,0x08,0x20,0x00,0x60,0x00,0x60,0x00,0x60,0x00,
0x60,0x00,0x60,0x00,0x60,0x7E,0x60,0x18,0x60,0x18,0x20,0x18,0x30,0x18,0x30,0x18,
0x10,0x18,0x18,0x18,0x0C,0x20,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"G",6*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x3F,0x30,0x0C,
0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,
0x3F,0xFC,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,
0x30,0x0C,0x30,0x0C,0x30,0x0C,0xFC,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"H",7*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF8,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"I",8*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFE,0x00,0x60,
0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,
0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,
0x00,0x60,0x00,0x60,0x00,0x60,0x00,0x60,0x70,0x60,0x70,0xC0,0x71,0x80,0x3F,0x00,/*"J",9*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7C,0x18,0x30,
0x18,0x20,0x18,0x60,0x18,0x40,0x18,0x80,0x18,0x80,0x19,0x00,0x19,0x00,0x1B,0x00,
0x1D,0x80,0x1D,0x80,0x18,0xC0,0x18,0xC0,0x18,0x60,0x18,0x60,0x18,0x30,0x18,0x30,
0x18,0x30,0x18,0x18,0x18,0x18,0x7E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"K",10*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x02,
0x18,0x02,0x18,0x04,0x18,0x0C,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"L",11*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x0F,0x38,0x1C,
0x38,0x1C,0x38,0x1C,0x38,0x1C,0x38,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x4C,
0x2C,0x4C,0x26,0x4C,0x26,0x4C,0x26,0x4C,0x26,0x8C,0x22,0x8C,0x23,0x8C,0x23,0x8C,
0x23,0x0C,0x23,0x0C,0x21,0x0C,0xF1,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"M",12*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x1F,0x38,0x04,
0x38,0x04,0x2C,0x04,0x2C,0x04,0x26,0x04,0x26,0x04,0x23,0x04,0x23,0x04,0x21,0x84,
0x21,0x84,0x20,0xC4,0x20,0xC4,0x20,0x64,0x20,0x64,0x20,0x34,0x20,0x34,0x20,0x1C,
0x20,0x1C,0x20,0x0C,0x20,0x0C,0xF8,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"N",13*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x0C,0x30,
0x18,0x18,0x10,0x08,0x30,0x0C,0x30,0x0C,0x60,0x04,0x60,0x06,0x60,0x06,0x60,0x06,
0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x20,0x06,0x30,0x0C,0x30,0x0C,
0x10,0x08,0x18,0x18,0x0C,0x30,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"O",14*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xF0,0x18,0x18,
0x18,0x0C,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x06,0x18,0x0C,
0x18,0x18,0x1F,0xE0,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"P",15*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x0C,0x30,
0x18,0x18,0x10,0x08,0x30,0x0C,0x30,0x0C,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,
0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x60,0x06,0x27,0x84,0x38,0xCC,
0x38,0x6C,0x18,0x78,0x0C,0x70,0x03,0xE0,0x00,0x32,0x00,0x3C,0x00,0x1C,0x00,0x00,/*"Q",16*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x18,0x38,
0x18,0x18,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x18,0x18,0x30,
0x1F,0xE0,0x18,0xC0,0x18,0xC0,0x18,0x60,0x18,0x60,0x18,0x60,0x18,0x30,0x18,0x30,
0x18,0x30,0x18,0x18,0x18,0x18,0x7E,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"R",17*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC8,0x18,0x78,
0x30,0x18,0x60,0x18,0x60,0x08,0x60,0x08,0x60,0x00,0x70,0x00,0x3C,0x00,0x1F,0x00,
0x07,0xC0,0x01,0xF0,0x00,0x78,0x00,0x18,0x00,0x1C,0x40,0x0C,0x40,0x0C,0x60,0x0C,
0x20,0x0C,0x30,0x18,0x38,0x30,0x27,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"S",18*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x31,0x84,
0x21,0x86,0x41,0x82,0x41,0x82,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"T",19*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x3E,0x30,0x08,
0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,
0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,0x30,0x08,
0x30,0x08,0x18,0x10,0x1C,0x20,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"U",20*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x1E,0x18,0x0C,
0x18,0x08,0x18,0x08,0x18,0x08,0x0C,0x10,0x0C,0x10,0x0C,0x10,0x0C,0x10,0x0C,0x20,
0x06,0x20,0x06,0x20,0x06,0x20,0x06,0x40,0x03,0x40,0x03,0x40,0x03,0x40,0x03,0x80,
0x01,0x80,0x01,0x80,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"V",21*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0xCF,0x61,0x86,
0x61,0x84,0x21,0x84,0x20,0x84,0x30,0xC4,0x31,0xC4,0x31,0xC4,0x31,0xC8,0x31,0xC8,
0x11,0xC8,0x12,0x48,0x1A,0x68,0x1A,0x68,0x1A,0x70,0x1C,0x70,0x0C,0x70,0x0C,0x70,
0x0C,0x30,0x0C,0x20,0x08,0x20,0x08,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"W",22*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x3E,0x18,0x08,
0x18,0x10,0x0C,0x10,0x0C,0x20,0x06,0x20,0x06,0x40,0x03,0x40,0x03,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0xC0,0x02,0xC0,0x02,0x60,0x04,0x60,0x04,0x70,0x08,0x30,
0x08,0x30,0x18,0x18,0x10,0x1C,0x7C,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"X",23*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x3E,0x38,0x08,
0x18,0x08,0x18,0x10,0x0C,0x10,0x0C,0x10,0x0C,0x20,0x06,0x20,0x06,0x20,0x03,0x40,
0x03,0x40,0x03,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"Y",24*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFE,0x1C,0x0C,
0x18,0x0C,0x30,0x18,0x20,0x18,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0xC0,0x00,0xC0,
0x01,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,0x18,0x02,
0x18,0x06,0x30,0x04,0x30,0x1C,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"Z",25*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x80,
0x1F,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x03,0xC0,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"1",26*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x08,0x38,
0x10,0x18,0x20,0x0C,0x20,0x0C,0x30,0x0C,0x30,0x0C,0x00,0x0C,0x00,0x18,0x00,0x18,
0x00,0x30,0x00,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,0x02,0x00,0x04,0x04,0x08,0x04,
0x10,0x04,0x20,0x0C,0x3F,0xF8,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"2",27*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC0,0x18,0x60,
0x30,0x30,0x30,0x18,0x30,0x18,0x30,0x18,0x00,0x18,0x00,0x18,0x00,0x30,0x00,0x60,
0x03,0xC0,0x00,0x70,0x00,0x18,0x00,0x08,0x00,0x0C,0x00,0x0C,0x30,0x0C,0x30,0x0C,
0x30,0x08,0x30,0x18,0x18,0x30,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"3",28*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x60,
0x00,0xE0,0x00,0xE0,0x01,0x60,0x01,0x60,0x02,0x60,0x04,0x60,0x04,0x60,0x08,0x60,
0x08,0x60,0x10,0x60,0x30,0x60,0x20,0x60,0x40,0x60,0x7F,0xFC,0x00,0x60,0x00,0x60,
0x00,0x60,0x00,0x60,0x00,0x60,0x03,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"4",29*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFC,0x0F,0xFC,
0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x13,0xE0,0x14,0x30,
0x18,0x18,0x10,0x08,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x30,0x0C,0x30,0x0C,
0x20,0x18,0x20,0x18,0x18,0x30,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"5",30*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0x06,0x18,
0x0C,0x18,0x08,0x18,0x18,0x00,0x10,0x00,0x10,0x00,0x30,0x00,0x33,0xE0,0x36,0x30,
0x38,0x18,0x38,0x08,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x18,0x0C,
0x18,0x08,0x0C,0x18,0x0E,0x30,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"6",31*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFC,0x1F,0xFC,
0x10,0x08,0x30,0x10,0x20,0x10,0x20,0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x40,
0x00,0x80,0x00,0x80,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"7",32*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x0C,0x30,
0x18,0x18,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x38,0x0C,0x38,0x08,0x1E,0x18,0x0F,0x20,
0x07,0xC0,0x18,0xF0,0x30,0x78,0x30,0x38,0x60,0x1C,0x60,0x0C,0x60,0x0C,0x60,0x0C,
0x60,0x0C,0x30,0x18,0x18,0x30,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"8",33*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC0,0x18,0x20,
0x30,0x10,0x30,0x18,0x60,0x08,0x60,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x0C,
0x70,0x1C,0x30,0x2C,0x18,0x6C,0x0F,0x8C,0x00,0x0C,0x00,0x18,0x00,0x18,0x00,0x10,
0x30,0x30,0x30,0x60,0x30,0xC0,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"9",34*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x06,0x20,
0x0C,0x30,0x18,0x18,0x18,0x18,0x18,0x08,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,
0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x18,0x08,0x18,0x18,
0x18,0x18,0x0C,0x30,0x06,0x20,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"0",35*/

0x00,0x00,0x1E,0x00,0x23,0x00,0x41,0x82,0x40,0x82,0x00,0xE4,0x00,0x38,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"~",36*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x03,0xC0,
0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x01,0xC0,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x80,0x03,0xC0,0x03,0xC0,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"!",37*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0x06,0x10,
0x0C,0x08,0x18,0x04,0x30,0xD4,0x31,0xB2,0x21,0x32,0x63,0x32,0x63,0x22,0x66,0x22,
0x66,0x22,0x66,0x22,0x66,0x62,0x66,0x64,0x66,0x64,0x26,0xE8,0x33,0x30,0x30,0x02,
0x10,0x04,0x18,0x0C,0x0C,0x18,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"@",38*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x04,0x08,
0x04,0x08,0x04,0x08,0x04,0x08,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x08,0x10,0x08,0x10,
0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x18,0x30,
0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"#",39*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x03,0xC0,0x0D,0x30,
0x09,0x18,0x19,0x18,0x19,0x38,0x19,0x38,0x1D,0x00,0x0D,0x00,0x0F,0x00,0x07,0x00,
0x03,0xC0,0x01,0xE0,0x01,0xF0,0x01,0x30,0x01,0x38,0x01,0x18,0x39,0x18,0x39,0x18,
0x31,0x18,0x31,0x30,0x19,0x60,0x07,0xC0,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,/*"$",40*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x10,0x6C,0x10,
0x44,0x20,0xC6,0x20,0xC6,0x40,0xC6,0x40,0xC6,0x40,0xC6,0x80,0xC6,0x80,0x44,0x80,
0x6D,0x38,0x39,0x6C,0x02,0x44,0x02,0xC6,0x02,0xC6,0x04,0xC6,0x04,0xC6,0x08,0xC6,
0x08,0xC6,0x08,0x44,0x10,0x6C,0x10,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"%",41*/

0x00,0x00,0x00,0x00,0x03,0xC0,0x03,0xE0,0x06,0x20,0x08,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"^",42*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x19,0x00,
0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x00,0x33,0x00,0x3A,0x00,0x1C,0x00,
0x38,0x7C,0x3C,0x10,0x4C,0x10,0xCE,0x10,0xC6,0x20,0xC7,0x20,0xC3,0x20,0xC1,0xC0,
0xC1,0xC2,0x60,0xE6,0x31,0x7C,0x1E,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"&",43*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0xC0,0x01,0xC0,0x01,0xC0,0x30,0xC6,0x38,0x8E,0x1C,0x9C,0x06,0xB0,0x01,0xC0,
0x01,0xC0,0x06,0xB0,0x1C,0x9C,0x38,0x8E,0x31,0x86,0x01,0xC0,0x01,0xC0,0x01,0xC0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"*",44*/

0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x04,0x00,0x08,0x00,0x18,0x00,0x30,0x00,0x20,
0x00,0x60,0x00,0x40,0x00,0xC0,0x00,0xC0,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0xC0,0x00,0xC0,0x00,0x40,
0x00,0x60,0x00,0x20,0x00,0x30,0x00,0x18,0x00,0x08,0x00,0x04,0x00,0x02,0x00,0x00,/*"(",45*/

0x00,0x00,0x00,0x00,0x40,0x00,0x20,0x00,0x10,0x00,0x18,0x00,0x0C,0x00,0x04,0x00,
0x06,0x00,0x02,0x00,0x03,0x00,0x03,0x00,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x03,0x00,
0x06,0x00,0x04,0x00,0x0C,0x00,0x18,0x00,0x10,0x00,0x20,0x00,0x40,0x00,0x00,0x00,/*")",46*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0xC0,0x03,0xC0,
0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x80,0x03,0xC0,0x03,0xC0,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*":",47*/

0x00,0x00,0x00,0x00,0x03,0x18,0x07,0x38,0x07,0x38,0x0E,0x70,0x0C,0x60,0x18,0xC0,
0x31,0x80,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*""",48*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x08,
0x00,0x10,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,0x02,0x00,0x04,0x00,0x08,0x00,
0x10,0x00,0x10,0x00,0x08,0x00,0x04,0x00,0x02,0x00,0x01,0x00,0x00,0x80,0x00,0x40,
0x00,0x20,0x00,0x10,0x00,0x08,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"<",49*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x10,0x00,
0x08,0x00,0x04,0x00,0x02,0x00,0x01,0x00,0x00,0x80,0x00,0x40,0x00,0x20,0x00,0x10,
0x00,0x08,0x00,0x08,0x00,0x10,0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00,0x02,0x00,
0x04,0x00,0x08,0x00,0x10,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*">",50*/


0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x18,0x30,0x30,0x18,
0x30,0x18,0x30,0x18,0x00,0x38,0x07,0xD8,0x1C,0x18,0x30,0x18,0x60,0x18,0x60,0x18,
0x60,0x18,0x60,0x19,0x30,0x79,0x1F,0x8E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"a",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x78,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x19,0xE0,0x1A,0x38,0x1C,0x18,
0x1C,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,
0x18,0x08,0x1C,0x18,0x1C,0x30,0x13,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"b",1*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0x0E,0x10,0x0C,0x18,
0x18,0x18,0x30,0x18,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x04,
0x18,0x04,0x18,0x08,0x0C,0x10,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"c",2*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x78,0x00,0x18,
0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x07,0xD8,0x0C,0x38,0x18,0x18,
0x18,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,
0x10,0x18,0x18,0x38,0x0C,0x5E,0x07,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"d",3*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x0C,0x30,0x08,0x18,
0x18,0x08,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x3F,0xFC,0x30,0x00,0x30,0x00,0x30,0x00,
0x18,0x04,0x18,0x08,0x0E,0x18,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"e",4*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x01,0x86,
0x01,0x06,0x03,0x06,0x03,0x00,0x03,0x00,0x03,0x00,0x3F,0xF8,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x1F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"f",5*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xEE,0x0C,0x36,0x08,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x08,0x18,0x0C,0x30,0x0F,0xE0,0x18,0x00,0x18,0x00,
0x1F,0xC0,0x0F,0xF8,0x18,0x1C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x18,0x18,0x07,0xE0,/*"g",6*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x78,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x19,0xE0,0x1A,0x30,0x1C,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"h",7*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0xC0,
0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x1F,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"i",8*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x78,
0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x03,0xF0,0x00,0x30,0x00,0x30,
0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,
0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x18,0x60,0x18,0x40,0x0F,0x80,/*"j",9*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x78,0x00,0x18,0x00,
0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x18,0x7C,0x18,0x30,0x18,0x20,
0x18,0x40,0x18,0x80,0x19,0x80,0x1B,0x80,0x1E,0xC0,0x1C,0xC0,0x18,0x60,0x18,0x30,
0x18,0x30,0x18,0x18,0x18,0x1C,0x7E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"k",10*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x1F,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
0x01,0x80,0x01,0x80,0x01,0x80,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"l",11*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0xEF,0x3C,0x71,0xC6,0x61,0x86,
0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,0x61,0x86,
0x61,0x86,0x61,0x86,0x61,0x86,0xF3,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"m",12*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,0x7A,0x30,0x1C,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"n",13*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x0C,0x30,0x08,0x18,
0x18,0x18,0x10,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,
0x18,0x18,0x18,0x18,0x0C,0x30,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"o",14*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,0x7A,0x30,0x1C,0x18,
0x18,0x08,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x18,0x0C,
0x18,0x18,0x1C,0x18,0x1E,0x30,0x19,0xE0,0x18,0x00,0x18,0x00,0x18,0x00,0x7E,0x00,/*"p",15*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC8,0x0C,0x78,0x18,0x38,
0x18,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,
0x10,0x18,0x18,0x38,0x0C,0x78,0x07,0x98,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x7E,/*"q",16*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x1C,0x7E,0x66,0x06,0x86,
0x07,0x80,0x07,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"r",17*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE4,0x06,0x1C,0x0C,0x0C,
0x0C,0x04,0x0C,0x04,0x0E,0x00,0x07,0xC0,0x01,0xF0,0x00,0x78,0x00,0x1C,0x10,0x0C,
0x10,0x0C,0x18,0x0C,0x1C,0x18,0x13,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"s",18*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x07,0x00,0x3F,0xF8,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
0x03,0x04,0x03,0x04,0x01,0x88,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"t",19*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x78,0x78,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
0x18,0x18,0x18,0x38,0x0C,0x5E,0x07,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"u",20*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x3E,0x18,0x0C,0x18,0x08,
0x18,0x18,0x0C,0x10,0x0C,0x10,0x04,0x20,0x06,0x20,0x06,0x20,0x03,0x40,0x03,0x40,
0x03,0xC0,0x01,0x80,0x01,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"v",21*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFB,0xCF,0x61,0x86,0x21,0x84,
0x31,0x84,0x31,0x84,0x31,0xC8,0x11,0xC8,0x1A,0xC8,0x1A,0x48,0x1A,0x70,0x0E,0x70,
0x0C,0x70,0x0C,0x30,0x0C,0x20,0x04,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"w",22*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x7C,0x0C,0x10,0x0E,0x10,
0x06,0x20,0x03,0x40,0x03,0x40,0x01,0x80,0x01,0x80,0x01,0xC0,0x02,0x60,0x04,0x60,
0x04,0x30,0x08,0x18,0x18,0x18,0x7C,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"x",23*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x3E,0x18,0x18,0x18,0x10,
0x08,0x10,0x0C,0x10,0x04,0x20,0x06,0x20,0x06,0x20,0x02,0x40,0x03,0x40,0x01,0x40,
0x01,0x80,0x01,0x80,0x01,0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x3E,0x00,0x3C,0x00,/*"y",24*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,0x30,0x38,0x30,0x30,
0x20,0x60,0x20,0xE0,0x00,0xC0,0x01,0x80,0x03,0x80,0x03,0x00,0x06,0x00,0x0E,0x04,
0x0C,0x04,0x18,0x0C,0x30,0x18,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"z",25*/

	
};

