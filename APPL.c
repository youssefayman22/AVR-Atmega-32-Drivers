/*
 * APPL.c
 *
 *  Created on: Mar 25, 2023
 *      Author: youss
 */

#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "GI_INTERFACE.h"
#include "EXTI_INTERFACE.h"

void LED(void);

void main(void)
{
	DIO_u8SetPINDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPINDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_INPUT);// pull up activation
	DIO_u8SetPINValue(DIO_PORTB, DIO_PIN2, DIO_PIN_HIGH); // pull up activation

	while(1){

	EXTI_InitINT2(EXTI_FallingEdge, &LED);
	GI_VidEnableGlobalInterrupt();
}
}
void LED(void){

DIO_u8SetPINValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
}


