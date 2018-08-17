#include "Globle.h"

u16 Reg_Ctrl_Value=0;

void FSMC_Configuration(void)  
{  
    GPIO_InitTypeDef GPIO_InitStructure;   
    FSMC_NORSRAMTimingInitTypeDef p;  
    FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;  
      
      
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE); //开启FSMC时钟 

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE   , ENABLE);  
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , DISABLE);
    //FSMC相关的IO配置  
    //数据线  
    //PD口  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
    GPIO_Init(GPIOD, &GPIO_InitStructure);   
    //PE口  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;  
    GPIO_Init(GPIOE, &GPIO_InitStructure);  
      
    //地址线     
    //PD口  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;   
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
    //PE口  
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 |GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6;  
    GPIO_Init(GPIOE, &GPIO_InitStructure); 
	   
    //NOE和NWE配置   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;  
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
  
    //NE1配置  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;   
    GPIO_Init(GPIOD, &GPIO_InitStructure);      
  
    //FSMC配置  
    //地址建立时间  
    p.FSMC_AddressSetupTime = 0;  
    //地址保持时间  
    p.FSMC_AddressHoldTime = 0;  
    //数据建立时间  
    p.FSMC_DataSetupTime =5;  
    //总线恢复时间  
    p.FSMC_BusTurnAroundDuration = 0;  
    //时钟分频因子  
    p.FSMC_CLKDivision = 0;  
    //数据产生时间  
    p.FSMC_DataLatency = 0;  
    //控制器时序  
    p.FSMC_AccessMode = FSMC_AccessMode_A;  
      
    //总线参数配置  
    //使用FSMC的Bank1的字块2  
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;  
    //禁止地址数据线复用  
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;  
    //存储类型为sram  
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;  
    //存储器位宽16位  
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;  
    //关闭突发模式访问  
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;  
    //使能突发访问模式后才有效,等待信号极性  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;  
    //使能突发访问模式后才有效,非对齐成组模式  
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;  
    //使能突发访问模式后才有效,配置等待时序  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
    //使能写操作  
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;  
    //使能突发访问模式后才有效,关闭等待信号  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;  
    //扩展模式使能  
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;  
    //成组写使能位  
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;  
    //读操作时序操作 	
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;  
    //写操作时序参数		
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;  
    //初始化FSMC总线  
    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  
    //使能FSMC Bank1_SRAM Bank  
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);    
}  

/********************************************************************* 
*                           写入半字数据 
*输入:WriteAddr:写入数据地址 
*     data:数据 
*返回:无 
**********************************************************************/  
  
void FSMC_WRITE(uint32_t WriteAddr, uint16_t data)  
{  
    //*(u16 *)(Bank1_SRAM1_ADDR + WriteAddr<<17) = data; 
	(*((vu16*)(Bank1_SRAM1_ADDR + (WriteAddr << 17))) = data);   
}  
  
/********************************************************************* 
*                           读取半字数据 
*输入:ReadAddr:读取数据地址 
*返回:读取的数据 
**********************************************************************/  
  
uint16_t FSMC_READ(uint32_t ReadAddr)  
{  
  //return (*(vu16 *)((Bank1_SRAM1_ADDR + ReadAddr<<17))); 
  return  *((vu16*)(Bank1_SRAM1_ADDR + (ReadAddr << 17))); 
} 


void Sample_Mode_Set(u8 mode)
{	
	if(mode==0)	Reg_Ctrl_Value&=0xe7ff;
	else if(mode==1)	{Reg_Ctrl_Value&=0xe7ff; Reg_Ctrl_Value|=0x0800;}
	else if(mode==2)  {Reg_Ctrl_Value&=0xe7ff; Reg_Ctrl_Value|=0x1000;}
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}

void LD_Ready_Set(u8 cmd)
{
	if(cmd==1) Reg_Ctrl_Value|=0x0200;
	else if(cmd==0) Reg_Ctrl_Value&=~0x0200;
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}   

void PWM_Mode_Set(u8 mode)
{
	Reg_Ctrl_Value&=~0x0006;
	if(mode==0) Reg_Ctrl_Value&=~0x0006;
	else if(mode==1) Reg_Ctrl_Value|=0x0002;
	else if(mode==2) Reg_Ctrl_Value|=0x0004;
	else if(mode==3) Reg_Ctrl_Value|=0x0006;
	if(mode==3) Mode_LED_SET(0);
	else  Mode_LED_SET(1); 
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}

void TDK_Power_Set(u8 cmd)
{
	if(cmd==1) Reg_Ctrl_Value|=0x0100;
	else if(cmd==0) Reg_Ctrl_Value&=~0x0100;
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}

void WMT_Set(u8 cmd)
{
	if(cmd==1) Reg_Ctrl_Value|=0x0001;
	else if(cmd==0) Reg_Ctrl_Value&=~0x0001;
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}

void Run_Mode_Set(u8 cmd)
{
	if(cmd==1) Reg_Ctrl_Value|=0x8000;
	else if(cmd==0) Reg_Ctrl_Value&=~0x8000;
	FSMC_WRITE(ADDR_CTRL,Reg_Ctrl_Value);
}




 