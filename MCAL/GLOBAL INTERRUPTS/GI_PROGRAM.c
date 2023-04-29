/*
 * GI_PROGRAM.c
 *
 *  Created on: Apr 24, 2023
 *      Author: youss
 */

#include "STD_TYPES.h"
#include "GI_INTERFACE.h"
#include "BITMATH.h"
#include "REGISTERS.h"


void GI_VidEnableGlobalInterrupt(void){

	SetBit(SREG,SREG_I);
}

void GI_VidDisableGlobalInterrupt(void){

	ClrBit(SREG,SREG_I);
}
