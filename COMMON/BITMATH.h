#include "STD_TYPES.h"

#define		SetBit(REG,BIT)		 (REG |= (1<<BIT));
#define		ClrBit(REG,BIT)		 (REG &= ~(1<<BIT));
#define		ToggleBit(REG,BIT)	 (REG ^= (1<<BIT));
#define		GetBit(REG,BIT)		 (REG = (REG>>BIT)&1);