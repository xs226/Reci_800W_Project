#include "Globle.h"

u8 Flash_OK=0;
u8 Flash_Tab[20]={0};

u8 Write_Flash(u16 *buff, u8 len)
{    
    volatile FLASH_Status FLASHStatus;
    u8 k=0;
    u32 Address;

    Address = WriteFlashAddress;
    FLASHStatus = FLASH_COMPLETE;
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
    FLASHStatus = FLASH_ErasePage(WriteFlashAddress);
    if(FLASHStatus == FLASH_COMPLETE)
    {
        for(k=0;(k<len) && (FLASHStatus == FLASH_COMPLETE);k++)
        {
            FLASHStatus = FLASH_ProgramHalfWord(Address, buff[k]);
            Address = Address + 2;
        }        
        FLASH_Lock();
    }
    else
    {
        return 0;
    }
    if(FLASHStatus == FLASH_COMPLETE)
    {
        return 1;
    }
    return 0;
}

void Read_Flash(u16 *buff, u8 len)
{
    u8 k;
    u32 Address;
    
    Address = WriteFlashAddress;
    for(k=0;k<len;k++)
    {
        buff[k] =  (*(vu16*) Address);
        Address += 2;   
    }
} 



void Write_Parameter_ToFLASH()
{
	u16 tab2[20]={0};

	tab2[0]=CCS1_MAXADC_VALUE;
	tab2[1]=CCS2_MAXADC_VALUE;
	tab2[2]=OPP_MAXADC_VALUE;
	tab2[3]=ERR_CHECK_VALUE;
	tab2[4]=ANG_KAD_VALUE;
  tab2[5]=LD_Frequence;
	tab2[6]=LD_Duty;
  tab2[7]=0;
	tab2[8]=0;

  Write_Flash(tab2,9);
}

void Read_Parameter_ToRAM()
{
	u16 tab2[20]={0};
  u32 temp=0;
	Read_Flash(tab2, 9);

  CCS1_MAXADC_VALUE=tab2[0];
	CCS2_MAXADC_VALUE=tab2[1];
  OPP_MAXADC_VALUE=tab2[2];
	ERR_CHECK_VALUE=tab2[3]&0xFb8C;
	ANG_KAD_VALUE=tab2[4];
	LD_Frequence=tab2[5];
	LD_Duty=tab2[6];

  
}




























 