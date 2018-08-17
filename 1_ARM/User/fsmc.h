//#include "system.h"
#include "stm32f10x.h"

#ifdef _FSMC

#define CS0_BASE									(0x60000000)
#define CS1_BASE									(0x60000000 + (1 << 23))
#define CS2_BASE									(0x60000000 + (2 << 23))
#define CS3_BASE									(0x60000000 + (3 << 23))

#define FSMC_WRITE(address,data)	(*((_IO_UINT16*)(CS0_BASE + (address << 17))) = data)
#define FSMC_READ(address)				*((_IO_UINT16*)(CS0_BASE + (address << 17)))

typedef struct {
	void (* Initialize)(void);
	void (* Finalize)(void);
	void (* Write)(_BYTE,_UINT16);
	void (* Read)(_BYTE,_UINT16*);
} FSMC_T;

extern FSMC_T fsmc;

#endif
