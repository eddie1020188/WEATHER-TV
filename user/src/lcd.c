#include "lcd.h"
#include "spi.h"
#include "delay.h"
#include "font.h"
#include "string.h"
extern const char hzk[];
extern const char zfk[];
extern const  char hzm[]; 
extern const char zfm[];


void LCD_Writ_Bus(u8 dat) 
{	
	LCD_CS_CMD(0);
	SPI2_ReadWriteByte(dat);
	LCD_CS_CMD(1);
}


void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}

void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


void LCD_WR_REG(u8 dat)
{
	LCD_DC_CMD(0);//д����
	LCD_Writ_Bus(dat);
	LCD_DC_CMD(1);//д����
}


void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_WR_REG(0x2a);//�е�ַ����
	LCD_WR_DATA(x1);
	LCD_WR_DATA(x2);
	LCD_WR_REG(0x2b);//�е�ַ����
	LCD_WR_DATA(y1);
	LCD_WR_DATA(y2);
	LCD_WR_REG(0x2c);//������д
}


void LCD_Init(void)
{
	SPI2_Init();
	LCD_RES_CMD(0);
	Delay_ms(100);
	LCD_RES_CMD(1);
	Delay_ms(100);
	
	LCD_BL_CMD(1);
	Delay_ms(500);
	if(Chip_Selection==0)  //��ʼ��ILI9341
	{
		//************* Start Initial Sequence **********//
		LCD_WR_REG(0x11); //Sleep out 
		Delay_ms(120);              //Delay 120ms 
		//************* Start Initial Sequence **********// 
		LCD_WR_REG(0xCF);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0xC1);
		LCD_WR_DATA8(0X30);
		LCD_WR_REG(0xED);
		LCD_WR_DATA8(0x64);
		LCD_WR_DATA8(0x03);
		LCD_WR_DATA8(0X12);
		LCD_WR_DATA8(0X81);
		LCD_WR_REG(0xE8);
		LCD_WR_DATA8(0x85);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x79);
		LCD_WR_REG(0xCB);
		LCD_WR_DATA8(0x39);
		LCD_WR_DATA8(0x2C);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x34);
		LCD_WR_DATA8(0x02);
		LCD_WR_REG(0xF7);
		LCD_WR_DATA8(0x20);
		LCD_WR_REG(0xEA);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x00);
		LCD_WR_REG(0xC0); //Power control
		LCD_WR_DATA8(0x1D); //VRH[5:0]
		LCD_WR_REG(0xC1); //Power control
		LCD_WR_DATA8(0x12); //SAP[2:0];BT[3:0]
		LCD_WR_REG(0xC5); //VCM control
		LCD_WR_DATA8(0x33);
		LCD_WR_DATA8(0x3F);
		LCD_WR_REG(0xC7); //VCM control
		LCD_WR_DATA8(0x92);
		LCD_WR_REG(0x3A); // Memory Access Control
		LCD_WR_DATA8(0x55);
		LCD_WR_REG(0x36); // Memory Access Control
		if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x08);
		else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC8);
		else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x78);
		else LCD_WR_DATA8(0xA8);
		LCD_WR_REG(0xB1);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x12);
		LCD_WR_REG(0xB6); // Display Function Control
		LCD_WR_DATA8(0x0A);
		LCD_WR_DATA8(0xA2);

		LCD_WR_REG(0x44);
		LCD_WR_DATA8(0x02);

		LCD_WR_REG(0xF2); // 3Gamma Function Disable
		LCD_WR_DATA8(0x00);
		LCD_WR_REG(0x26); //Gamma curve selected
		LCD_WR_DATA8(0x01);
		LCD_WR_REG(0xE0); //Set Gamma
		LCD_WR_DATA8(0x0F);
		LCD_WR_DATA8(0x22);
		LCD_WR_DATA8(0x1C);
		LCD_WR_DATA8(0x1B);
		LCD_WR_DATA8(0x08);
		LCD_WR_DATA8(0x0F);
		LCD_WR_DATA8(0x48);
		LCD_WR_DATA8(0xB8);
		LCD_WR_DATA8(0x34);
		LCD_WR_DATA8(0x05);
		LCD_WR_DATA8(0x0C);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x0F);
		LCD_WR_DATA8(0x07);
		LCD_WR_DATA8(0x00);
		LCD_WR_REG(0XE1); //Set Gamma
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x23);
		LCD_WR_DATA8(0x24);
		LCD_WR_DATA8(0x07);
		LCD_WR_DATA8(0x10);
		LCD_WR_DATA8(0x07);
		LCD_WR_DATA8(0x38);
		LCD_WR_DATA8(0x47);
		LCD_WR_DATA8(0x4B);
		LCD_WR_DATA8(0x0A);
		LCD_WR_DATA8(0x13);
		LCD_WR_DATA8(0x06);
		LCD_WR_DATA8(0x30);
		LCD_WR_DATA8(0x38);
		LCD_WR_DATA8(0x0F);
		LCD_WR_REG(0x29); //Display on
	}
	else          //��ʼ��ST7789
	{
		LCD_WR_REG(0x11);
		Delay_ms(100); //Delay 120ms
		//------------------------------display and color format setting--------------------------------//
		LCD_WR_REG(0X36);// Memory Access Control
		if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
		else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
		else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
		else LCD_WR_DATA8(0xA0);
		LCD_WR_REG(0X3A);
		LCD_WR_DATA8(0X05);
		//--------------------------------ST7789S Frame rate setting-------------------------
		LCD_WR_REG(0xb2);
		LCD_WR_DATA8(0x0c);
		LCD_WR_DATA8(0x0c);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x33);
		LCD_WR_DATA8(0x33);
		LCD_WR_REG(0xb7);
		LCD_WR_DATA8(0x35);
		//---------------------------------ST7789S Power setting-----------------------------
		LCD_WR_REG(0xbb);
		LCD_WR_DATA8(0x35);
		LCD_WR_REG(0xc0);
		LCD_WR_DATA8(0x2c);
		LCD_WR_REG(0xc2);
		LCD_WR_DATA8(0x01);
		LCD_WR_REG(0xc3);
		LCD_WR_DATA8(0x13);
		LCD_WR_REG(0xc4);
		LCD_WR_DATA8(0x20);
		LCD_WR_REG(0xc6);
		LCD_WR_DATA8(0x0f);
		LCD_WR_REG(0xca);
		LCD_WR_DATA8(0x0f);
		LCD_WR_REG(0xc8);
		LCD_WR_DATA8(0x08);
		LCD_WR_REG(0x55);
		LCD_WR_DATA8(0x90);
		LCD_WR_REG(0xd0);
		LCD_WR_DATA8(0xa4);
		LCD_WR_DATA8(0xa1);
		//--------------------------------ST7789S gamma setting------------------------------
		LCD_WR_REG(0xe0);
		LCD_WR_DATA8(0xd0);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x06);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x0b);
		LCD_WR_DATA8(0x2a);
		LCD_WR_DATA8(0x3c);
		LCD_WR_DATA8(0x55);
		LCD_WR_DATA8(0x4b);
		LCD_WR_DATA8(0x08);
		LCD_WR_DATA8(0x16);
		LCD_WR_DATA8(0x14);
		LCD_WR_DATA8(0x19);
		LCD_WR_DATA8(0x20);
		LCD_WR_REG(0xe1);
		LCD_WR_DATA8(0xd0);
		LCD_WR_DATA8(0x00);
		LCD_WR_DATA8(0x06);
		LCD_WR_DATA8(0x09);
		LCD_WR_DATA8(0x0b);
		LCD_WR_DATA8(0x29);
		LCD_WR_DATA8(0x36);
		LCD_WR_DATA8(0x54);
		LCD_WR_DATA8(0x4b);
		LCD_WR_DATA8(0x0d);
		LCD_WR_DATA8(0x16);
		LCD_WR_DATA8(0x14);
		LCD_WR_DATA8(0x21);
		LCD_WR_DATA8(0x20);
		LCD_WR_REG(0x29);
	}
	LCD_Fill(0,0,319,239,WHITE);
}


//X����ʼ���� Y����ʼ����   X��������  Y��������
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}


void LCD_DrawPoint(u16 x,u16 y,u16 color)
{
	LCD_Address_Set(x,y,x,y);//���ù��λ�� 
	LCD_WR_DATA(color);
} 


/*********************************************************************************************************
* �� �� �� : LCD_ShowPic
* ����˵�� : ��ʾͼƬ
* ��    �� : ��ʼ���꣺x1 y1  �������� x2 y2 
             *pic  ͼ��ȡģ��ַ
* �� �� ֵ : ��
* ��    ע : 
*********************************************************************************************************/ 
void LCD_ShowPic(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,u8 *ch)
{
	u32 i;
	LCD_Address_Set(x1,y1,x2,y2);
	for(i=0;i<(x2-x1)*(y2-y1);i++)
	{
		LCD_WR_DATA(ch[i*2]<<8|ch[i*2+1]);
	}
}


//��ʾ����
//u8 size(���ֵ��ֿ�/�ָ�)

void  LCD_Show_GB2312(u8 xs ,u8 ys,u8 size,u16 color,const char *buff)
{
	
	LCD_Address_Set(xs,ys,xs+size-1,ys+size-1);//������ʾ����
	for(u16 i = 0;i<size*size/8;i++)//����������ȡģ����
	{
		for(int j = 7;j>=0;j--)
		{
			if(buff[i] &(1<<j) )//�ж�8λ���� ��һλΪ1 ����ɫ������䵽��һλ
			{
				
				LCD_WR_DATA(color);
				
			}
			else
				LCD_WR_DATA(0XFFFF);
			
		}
	}
}



//��ʾ�ַ�

//u8 size(�ַ����ֿ�/�ָ�)

void  LCD_Show_ASCII(u8 xs ,u8 ys,u8 size,u16 color,const char *buff)
{
	
	LCD_Address_Set(xs,ys,xs+size/2-1,ys+size-1);//������ʾ����
	for(u16 i = 0;i<size*size/16;i++)//����������ȡģ����
	{
		for(int j = 7;j>=0;j--)
		{
			if(buff[i] &(1<<j) )//�ж�8λ���� ��һλΪ1 ����ɫ������䵽��һλ
			{
				
				LCD_WR_DATA(color);
				
			}
			else  
				LCD_WR_DATA(0XFFFF);
			
		}
	}
}

//��ʾ�ַ���
//u8 *buffer :ָ��ʵ�ʷ��͵��ַ���  �����Ͼ���ã�nanjingnihao1234��
//���֣�GB2312: 0XA1A1---0XFEFE

void LCD_Show_String(u8 es,u8 ys,u8 size,u16 color,u8 *buffer)
{
	
	while(*buffer!='\0')
	{
		
		//��ʾ����
		if((*buffer>=0xA1) && (*(buffer+1)>=0xA1))//������һ������
		{
			for(u8 i = 0;i<strlen(hzk)/2;i++)//�ڵ�ǰ���ֿ���������ʾ�ĺ���
			{
				if(es+size>319)
				{
					es = 0;
					ys+=size;
				}
				if((*buffer == hzk[i*2])&&(*(buffer+1) == hzk[i*2+1]))
				{
					
					LCD_Show_GB2312(es,ys,size,color,&hzm[i*(size*size/8)]);
					break;
				}
				
			}
			
			buffer +=2;//���ƫ�������ֽڣ���ʾ��һ������
		  es +=size;  //��ʾλ�����ƫ��
		}
		//��ʾ�ַ�
		else if((*buffer>=0) && (*(buffer)<=0x7F))//������һ���ַ�
		{
			for(u8 i = 0;i<strlen(zfk);i++)//�ڵ�ǰ�ַ�����������ʾ���ַ�
			{
				if(es+size/2>319)
				{
					es = 0;
					ys+=size;
				}
				if(*buffer == zfk[i])
				{
					
					LCD_Show_ASCII(es,ys,size,color,&zfm[i*(size*size/16)]);
					break;
				}
				
			}
			
			buffer +=1;//���ƫ��1���ֽڣ���ʾ��һ���ַ�
		  es +=size/2;  //��ʾλ�����ƫ��
		}	
	}	
}



