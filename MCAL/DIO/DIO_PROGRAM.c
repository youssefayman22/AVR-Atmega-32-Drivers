/*
 * DIO_PROGRAM.c
 *
 *  Created on: Mar 23, 2023
 *      Author: youss
 */

#include "STD_TYPES.h"
#include "BITMATH.h"
#include "DIO_INTERFACE.h"
#include "REGISTERS.h"


DIO_ERROR_STATUS DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection)
{
	u8 Error_Status = DIO_NO_ERROR;

	if((Copy_u8PortDirection != DIO_PORT_INPUT) || (Copy_u8PortDirection != DIO_PORT_OUTPUT)){

		Error_Status = DIO_DIRECTION_ERROR;
	}
	else{


		switch(Copy_u8Port){

		case DIO_PORTA:
			DDRA = Copy_u8PortDirection;
			break;
		case DIO_PORTB:
			DDRB = Copy_u8PortDirection;
			break;
		case DIO_PORTC:
			DDRC = Copy_u8PortDirection;
			break;
		case DIO_PORTD:
			DDRD = Copy_u8PortDirection;
			break;
		default: Error_Status = DIO_PORT_ERROR;

		}
	}
	return Error_Status;
}


DIO_ERROR_STATUS DIO_u8SetPINDirection(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8PinDirection)
{

	u8 Error_Status = DIO_NO_ERROR;

	if((Copy_u8Pin <= DIO_PIN7) && (Copy_u8Pin >= DIO_PIN0)){

		switch(Copy_u8Port){

		case DIO_PORTA:
			if(Copy_u8PinDirection == DIO_PIN_OUTPUT){
				SetBit(DDRA,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinDirection == DIO_PIN_INPUT){
				ClrBit(DDRA,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_DIRECTION_ERROR;
				break;
			}
		case DIO_PORTB:
			if(Copy_u8PinDirection == DIO_PIN_OUTPUT){
				SetBit(DDRB,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinDirection == DIO_PIN_INPUT){
				ClrBit(DDRB,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_DIRECTION_ERROR;
				break;
			}
		case DIO_PORTC:
			if(Copy_u8PinDirection == DIO_PIN_OUTPUT){
				SetBit(DDRC,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinDirection == DIO_PIN_INPUT){
				ClrBit(DDRC,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_DIRECTION_ERROR;
				break;
			}
		case DIO_PORTD:
			if(Copy_u8PinDirection == DIO_PIN_OUTPUT){
				SetBit(DDRD,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinDirection == DIO_PIN_INPUT){
				ClrBit(DDRD,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_DIRECTION_ERROR;
				break;
			}
		default: Error_Status = DIO_PORT_ERROR;

		}
	}
	else{

		Error_Status = DIO_PIN_ERROR;
	}
	return Error_Status;
}

DIO_ERROR_STATUS DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)
{
	u8 Error_Status = DIO_NO_ERROR;

	if((Copy_u8PortValue == DIO_PORT_HIGH) || (Copy_u8PortValue == DIO_PORT_LOW)){
		switch(Copy_u8Port){

		case DIO_PORTA:
			PORTA = Copy_u8PortValue;
			break;
		case DIO_PORTB:
			PORTB = Copy_u8PortValue;
			break;
		case DIO_PORTC:
			PORTC = Copy_u8PortValue;
			break;
		case DIO_PORTD:
			PORTB = Copy_u8PortValue;
			break;
		default: Error_Status = DIO_PORT_ERROR;

		}
	}
	else{
		Error_Status = DIO_VALUE_ERROR;
	}
	return Error_Status;
}

DIO_ERROR_STATUS DIO_u8SetPINValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
	u8 Error_Status = DIO_NO_ERROR;

	if((Copy_u8Pin <= DIO_PIN7) && (Copy_u8Pin >= DIO_PIN0)){

		switch(Copy_u8Port){

		case DIO_PORTA:
			if(Copy_u8PinValue == DIO_PIN_HIGH){
				SetBit(PORTA,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinValue == DIO_PIN_LOW){
				ClrBit(PORTA,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_VALUE_ERROR;
				break;
			}
		case DIO_PORTB:
			if(Copy_u8PinValue == DIO_PIN_HIGH){
				SetBit(PORTB,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinValue == DIO_PIN_LOW){
				ClrBit(PORTB,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_VALUE_ERROR;
				break;
			}
		case DIO_PORTC:
			if(Copy_u8PinValue == DIO_PIN_HIGH){
				SetBit(PORTC,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinValue == DIO_PIN_LOW){
				ClrBit(PORTC,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_VALUE_ERROR;
				break;
			}
		case DIO_PORTD:
			if(Copy_u8PinValue == DIO_PIN_HIGH){
				SetBit(PORTD,Copy_u8Pin);
				break;
			}
			else if(Copy_u8PinValue == DIO_PIN_LOW){
				ClrBit(PORTD,Copy_u8Pin);
				break;
			}
			else{
				Error_Status = DIO_VALUE_ERROR;
				break;
			}
		default: Error_Status = DIO_PORT_ERROR;

		}
	}
	else{

		Error_Status = DIO_PIN_ERROR;
	}
	return Error_Status;

}

DIO_ERROR_STATUS DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_u8PortValue)
{
	u8 Error_Status = DIO_NO_ERROR;

	switch(Copy_u8Port){

	case DIO_PORTA:
		*Copy_u8PortValue = DDRA;
		break;
	case DIO_PORTB:
		*Copy_u8PortValue = DDRB;
		break;
	case DIO_PORTC:
		*Copy_u8PortValue = DDRC;
		break;
	case DIO_PORTD:
		*Copy_u8PortValue = DDRD;
		break;
	default: Error_Status = DIO_PORT_ERROR;


	}
	return Error_Status;


}

DIO_ERROR_STATUS DIO_u8GetPINValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8PinValue)
{

	u8 Error_Status = DIO_NO_ERROR;

	if((Copy_u8Pin <= DIO_PIN7) && (Copy_u8Pin >= DIO_PIN0)){

		switch(Copy_u8Port){

		case DIO_PORTA:
			*Copy_u8PinValue = GetBit(PORTA,Copy_u8Pin);
			break;
		case DIO_PORTB:
			*Copy_u8PinValue = GetBit(PORTB,Copy_u8Pin);
			break;
		case DIO_PORTC:
			*Copy_u8PinValue = GetBit(PORTC,Copy_u8Pin);
			break;
		case DIO_PORTD:
			*Copy_u8PinValue = GetBit(PORTD,Copy_u8Pin);
			break;
		default: Error_Status = DIO_PORT_ERROR;

		}
	}
	else{
		Error_Status = DIO_PIN_ERROR;
	}
	return Error_Status;
}

