#include "Globle.h"

u16 Reg_Ctrl_Value=0;

void FSMC_Configuration(void)  
{  
    GPIO_InitTypeDef GPIO_InitStructure;   
    FSMC_NORSRAMTimingInitTypeDef p;  
    FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;  
      
      
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE); //����FSMCʱ�� 

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE   , ENABLE);  
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , DISABLE);
    //FSMC��ص�IO����  
    //������  
    //PD��  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
    GPIO_Init(GPIOD, &GPIO_InitStructure);   
    //PE��  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;  
    GPIO_Init(GPIOE, &GPIO_InitStructure);  
      
    //��ַ��     
    //PD��  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;   
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
    //PE��  
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 |GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6;  
    GPIO_Init(GPIOE, &GPIO_InitStructure); 
	   
    //NOE��NWE����   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;  
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
  
    //NE1����  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;   
    GPIO_Init(GPIOD, &GPIO_InitStructure);      
  
    //FSMC����  
    //��ַ����ʱ��  
    p.FSMC_AddressSetupTime = 0;  
    //��ַ����ʱ��  
    p.FSMC_AddressHoldTime = 0;  
    //���ݽ���ʱ��  
    p.FSMC_DataSetupTime =5;  
    //���߻ָ�ʱ��  
    p.FSMC_BusTurnAroundDuration = 0;  
    //ʱ�ӷ�Ƶ����  
    p.FSMC_CLKDivision = 0;  
    //���ݲ���ʱ��  
    p.FSMC_DataLatency = 0;  
    //������ʱ��  
    p.FSMC_AccessMode = FSMC_AccessMode_A;  
      
    //���߲�������  
    //ʹ��FSMC��Bank1���ֿ�2  
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;  
    //��ֹ��ַ�����߸���  
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;  
    //�洢����Ϊsram  
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;  
    //�洢��λ��16λ  
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;  
    //�ر�ͻ��ģʽ����  
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;  
    //ʹ��ͻ������ģʽ�����Ч,�ȴ��źż���  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;  
    //ʹ��ͻ������ģʽ�����Ч,�Ƕ������ģʽ  
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;  
    //ʹ��ͻ������ģʽ�����Ч,���õȴ�ʱ��  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;  
    //ʹ��д����  
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;  
    //ʹ��ͻ������ģʽ�����Ч,�رյȴ��ź�  
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;  
    //��չģʽʹ��  
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;  
    //����дʹ��λ  
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;  
    //������ʱ����� 	
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;  
    //д����ʱ�����		
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;  
    //��ʼ��FSMC����  
    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  
    //ʹ��FSMC Bank1_SRAM Bank  
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);    
}  

/********************************************************************* 
*                           д��������� 
*����:WriteAddr:д�����ݵ�ַ 
*     data:���� 
*����:�� 
**********************************************************************/  
  
void FSMC_WRITE(uint32_t WriteAddr, uint16_t data)  
{  
    //*(u16 *)(Bank1_SRAM1_ADDR + WriteAddr<<17) = data; 
	(*((vu16*)(Bank1_SRAM1_ADDR + (WriteAddr << 17))) = data);   
}  
  
/********************************************************************* 
*                           ��ȡ�������� 
*����:ReadAddr:��ȡ���ݵ�ַ 
*����:��ȡ������ 
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




 