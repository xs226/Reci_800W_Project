#include "Globle.h"
//unsigned char time_buf1[8] = {20,9,3,13,18,51,00,6};//空年月日时分秒周
//unsigned char time_buf[8] ;                         //空年月日时分秒周
#define Yanshi 5

TimeStruct Writetime,Writetime_Temp;
TimeStruct Readtime;

void DS1302_GPIO_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
													   
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);		  	 
}
void RTC_Delay_1us(__IO u16 i)
{ 
	u16 j;
	while(i--)
	{
		for(j=0;j<7;j++);
	}		  
}

void IO_Output(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin =	GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;  //PB0 --DS18B20_SCLK
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void IO_Input(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_2;  //PC5 DS1302 数据接口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}	
		
//BCD处理
void BCDconvert1(TimeStruct*p)
{
	Writetime_Temp.year	=(((p->year) /10)<<4)+(p->year) %10;
	Writetime_Temp.month=(((p->month)/10)<<4)+(p->month)%10;
	Writetime_Temp.day	=(((p->day)	 /10)<<4)+(p->day)  %10;
	Writetime_Temp.week	=(((p->week) /10)<<4)+(p->week) %10;
	Writetime_Temp.hour	=(((p->hour) /10)<<4)+(p->hour) %10;
	Writetime_Temp.min	=(((p->min)  /10)<<4)+(p->min)  %10;
	Writetime_Temp.sec	=(((p->sec)	 /10)<<4)+(p->sec)  %10;

}
void BCDconvert2(TimeStruct*p)
{
	
	Readtime.year	=(((p->year) /16)*10)+(p->year) %16;
	Readtime.month=(((p->month)/16)*10)+(p->month)%16;
	Readtime.day	=(((p->day)	 /16)*10)+(p->day)  %16;
	Readtime.week	=(((p->week) /16)*10)+(p->week) %16;
	Readtime.hour	=(((p->hour) /16)*10)+(p->hour) %16;
	Readtime.min	=(((p->min)	 /16)*10)+(p->min)	%16;
	Readtime.sec	=(((p->sec)	 /16)*10)+(p->sec)	%16;

}

/*------------------------------------------------
           向DS1302写入一字节数据
------------------------------------------------*/
void Ds1302_Write_Byte(unsigned char addr, unsigned char d)
{

	unsigned char i;
	IO_Output();
	RST_SET;	
	
	//写入目标地址：addr
	addr = addr & 0xFE;     //最低位置零
	for (i = 0; i < 8; i ++) 
	{ 
		if (addr & 0x01) 	IO_SET;
		else 		IO_CLR;
		RTC_Delay_1us(Yanshi);
		SCK_SET;
		SCK_CLR;
		RTC_Delay_1us(Yanshi);
		addr = addr >> 1;
	}
	
	//写入数据：d
	for (i = 0; i < 8; i ++) 
	{
		if (d & 0x01) IO_SET;
		else	IO_CLR;
		RTC_Delay_1us(Yanshi);
		SCK_SET;
		SCK_CLR;
		RTC_Delay_1us(Yanshi);
		d = d >> 1;
	}
	RST_CLR;					//停止DS1302总线
}
/*------------------------------------------------
           从DS1302读出一字节数据
------------------------------------------------*/

unsigned char Ds1302_Read_Byte(unsigned char addr) 
{
	unsigned char i;
	unsigned char temp;
	IO_Output();
	RST_SET;	

	//写入目标地址：addr
	addr = addr | 0x01;//最低位置高
	for (i = 0; i < 8; i ++) 
  {   
		if (addr & 0x01) IO_SET;
		else	IO_CLR;
		RTC_Delay_1us(Yanshi);
		SCK_SET;
		SCK_CLR;
		RTC_Delay_1us(Yanshi);
		addr = addr >> 1;
	}
	//IO口设置为输入模式，从DS1302读取数据
	IO_Input();
	RTC_Delay_1us(8);
	for (i = 0; i < 8; i ++) 
	{
		temp = temp >> 1;
		if (IO_R) temp |= 0x80;
		else 	temp &= 0x7F;
		RTC_Delay_1us(Yanshi);
		SCK_SET;
		SCK_CLR;
		RTC_Delay_1us(Yanshi);
	}
	RST_CLR;	//停止DS1302总线
	return temp;
}

/*------------------------------------------------
           向DS1302写入时钟数据
------------------------------------------------*/
void Ds1302_Write_Time(void) 
{
	BCDconvert1(&Writetime);

	Ds1302_Write_Byte(ds1302_control_add,0x00);			//关闭写保护 
	Ds1302_Write_Byte(ds1302_sec_add,0x80);				//暂停 
	//Ds1302_Write_Byte(ds1302_charger_add,0xa9);			//涓流充电 
	Ds1302_Write_Byte(ds1302_year_add,	Writetime_Temp.year);		//年 
	Ds1302_Write_Byte(ds1302_month_add,	Writetime_Temp.month);	//月 
	Ds1302_Write_Byte(ds1302_date_add,	Writetime_Temp.day);		//日 
	Ds1302_Write_Byte(ds1302_day_add,	Writetime_Temp.week);		//周 
	Ds1302_Write_Byte(ds1302_hr_add,	Writetime_Temp.hour);		//时 
	Ds1302_Write_Byte(ds1302_min_add,	Writetime_Temp.min);		//分
	Ds1302_Write_Byte(ds1302_sec_add,	Writetime_Temp.sec);		//秒
	//Ds1302_Write_Byte(ds1302_day_add,time_buf[7]);		//周 
	Ds1302_Write_Byte(ds1302_control_add,0x80);			//打开写保护 
}

/*------------------------------------------------
           从DS1302读出时钟数据
------------------------------------------------*/
void Ds1302_Read_Time(void)  
{ 
	TimeStruct Temptime;
	Temptime.year =Ds1302_Read_Byte(ds1302_year_add);		//年 
	Temptime.month=Ds1302_Read_Byte(ds1302_month_add);		//月 
	Temptime.day  =Ds1302_Read_Byte(ds1302_date_add);		//日 
	Temptime.hour =Ds1302_Read_Byte(ds1302_hr_add);			//时 
	Temptime.min  =Ds1302_Read_Byte(ds1302_min_add);		//分 
	Temptime.sec  =Ds1302_Read_Byte(ds1302_sec_add);		//秒 
	Temptime.week =Ds1302_Read_Byte(ds1302_day_add);		//周 

	BCDconvert2(&Temptime);
}

/*------------------------------------------------
                DS1302初始化
------------------------------------------------*/
void Ds1302_Init(void)
{
	DS1302_GPIO_Config();
	RST_CLR;			//RST脚置低
	SCK_CLR;			//SCK脚置低
  Ds1302_Write_Byte(ds1302_sec_add,0x00);				 
}



void RTC_Parameter_Set(u8 Type,u8 value)
{
	u16 temp;
	switch (Type)
	{
		case 0:{ Writetime.year=value; break; }
		case 1:{ Writetime.month=value;  break; }
		case 2:{ Writetime.day =value; break; }
		case 3:{ Writetime.week=value;break; }
		case 4:{ Writetime.hour=value;break; }
		case 5:{ Writetime.min =value; break; }
		case 6:{ Writetime.sec =value; break; }
		default:break;
	}
	Ds1302_Write_Time();
}









