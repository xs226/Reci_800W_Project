#ifndef __FLASH_H
#define __FLASH_H

#include "stm32f10x.h"

#define WriteFlashAddress    ((u32)0x08040000)//??????(??flash????????0x08000000??)


extern u8 Flash_OK;
extern u8 Flash_Tab[20];

extern u8 Write_Flash(u16 *buff, u8 len);
extern void Read_Flash(u16 *buff, u8 len);

extern void Write_Parameter_ToFLASH();
extern void Read_Parameter_ToRAM();

#endif
