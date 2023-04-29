/*
 * REGISTERS.h
 *
 *  Created on: Mar 23, 2023
 *      Author: youss
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PORTA	*((volatile u8 *)0x3B)
#define PORTB	*((volatile u8 *)0x38)
#define PORTC	*((volatile u8 *)0x35)
#define PORTD	*((volatile u8 *)0x32)

#define DDRA	*((volatile u8 *)0x3A)
#define DDRB	*((volatile u8 *)0x37)
#define DDRC	*((volatile u8 *)0x34)
#define DDRD	*((volatile u8 *)0x31)

#define PINA	*((volatile u8 *)0x39)
#define PINB	*((volatile u8 *)0x36)
#define PINC	*((volatile u8 *)0x33)
#define PIND	*((volatile u8 *)0x30)

#define SFIOR	*((volatile u8 *)0x50) // pull up enable

#define SREG	*((volatile u8 *)0x5F) //status register
#define SREG_I	7					   //global interrupt enable bit

#define MCUCR	*((volatile u8 *)0x55) //sense control for int0, int1
#define MCUCSR	*((volatile u8 *)0x54) //sense control for int2
#define GICR	*((volatile u8 *)0x5B) //interrupt enable
#define GIFR	*((volatile u8 *)0x5A) //interrupt flag

#define GIFR_INTF1	7
#define GIFR_INTF0	6
#define GIFR_INTF2	5

#define GICR_INT1	7
#define GICR_INT0	6
#define GICR_INT2	5

#define MCUCSR_ISC2	6

#define MCUCR_ISC11	3
#define MCUCR_ISC10	2
#define MCUCR_ISC01	1
#define MCUCR_ISC00	0



#endif /* REGISTERS_H_ */
