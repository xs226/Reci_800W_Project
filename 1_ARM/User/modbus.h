#ifndef __MODBUS_H
#define	__MODBUS_H

#include "stm32f10x.h"

extern u8 auchCRCHi[];
extern u8 auchCRCLo[];
extern u16 crc16(u8 *puchMsg,u8 usDataLen); 

#endif 