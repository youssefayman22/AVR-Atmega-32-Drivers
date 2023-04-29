/*
 * DIO_INTERFACE.h
 *
 *  Created on: Mar 23, 2023
 *      Author: youss
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_PORTA	(0u)
#define DIO_PORTB	(1u)
#define DIO_PORTC	(2u)
#define DIO_PORTD	(3u)

#define DIO_PIN0	(0u)
#define DIO_PIN1	(1u)
#define DIO_PIN2	(2u)
#define DIO_PIN3	(3u)
#define DIO_PIN4	(4u)
#define DIO_PIN5	(5u)
#define DIO_PIN6	(6u)
#define DIO_PIN7	(7u)

#define DIO_PORT_INPUT		(0u)
#define DIO_PORT_OUTPUT		(1u)

#define DIO_PIN_INPUT		(0u)
#define DIO_PIN_OUTPUT		(1u)

#define DIO_PORT_LOW		(0u)
#define DIO_PORT_HIGH		(1u)

#define DIO_PIN_LOW			(0u)
#define DIO_PIN_HIGH		(1u)

typedef enum{

	DIO_NO_ERROR,
	DIO_PORT_ERROR,
	DIO_PIN_ERROR,
	DIO_VALUE_ERROR,
	DIO_DIRECTION_ERROR,

}DIO_ERROR_STATUS;

DIO_ERROR_STATUS DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection);
DIO_ERROR_STATUS DIO_u8SetPINDirection(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8PinDirection);

DIO_ERROR_STATUS DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue);
DIO_ERROR_STATUS DIO_u8SetPINValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);

DIO_ERROR_STATUS DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_u8PortValue);
DIO_ERROR_STATUS DIO_u8GetPINValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8PinValue);



#endif /* DIO_INTERFACE_H_ */
