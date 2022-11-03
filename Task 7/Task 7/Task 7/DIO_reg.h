/*
* DIO_reg.h
*
* Created: 11/3/2022 1:36:48 AM
*  Author: Mario
*/

#ifndef DIO_REG_
#define DIO_REG_

#define	DDRA	*((u8 *)0x3A)
#define DDRB	*((u8 *)0x37)
#define DDRC	*((u8 *)0x34)
#define DDRD	*((u8 *)0x31)

#define	PORTA	*((u8 *)0x3B)
#define	PORTB	*((u8 *)0x38)
#define	PORTC	*((u8 *)0x35)
#define	PORTD	*((u8 *)0x32)

#define	PINA	*((u8 *)0x39)
#define	PINB	*((u8 *)0x36)
#define	PINC	*((u8 *)0x33)
#define	PIND	*((u8 *)0x30)

#define	ADMUX	*((u8 *)0x27)
#define	ADCSRA	*((u8 *)0x26)
#define	ADCL	*((u16 *)0x24)
#define	SREG	*((u8 *)0x5F)
#define TCCR0	*((u8 *)0x53)
#define TCNT0	*((u8 *)0x52)
#define TIFR	*((u8 *)0x58)
#define TIMSK	*((u8 *)0x59)
#define OCR0	*((u8 *)0x5C)
#endif
