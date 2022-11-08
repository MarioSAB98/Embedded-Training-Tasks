/*
* DIO_Functions.h
*
* Created: 11/3/2022 1:36:25 AM
*  Author: Mario
*/

#ifndef DIO_FUNCTIONS_H_
#define DIO_FUNCTIONS_H_
/***********************PORTS********************/
#define PORTA_Idx		0
#define PORTB_Idx		1
#define PORTC_Idx		2
#define PORTD_Idx		3
#define A0 				0
#define A1 				1
#define A2 				2
#define A3 				3
#define A4 				4
#define A5 				5
#define A6 				6
#define A7 				7
#define B0 				0
#define B1 				1
#define B2 				2
#define B3 				3
#define B4 				4
#define B5 				5
#define B6 				6
#define B7 				7
#define C0 				0
#define C1 				1
#define C2 				2
#define C3 				3
#define C4 				4
#define C5 				5
#define C6 				6
#define C7 				7
#define D0 				0
#define D1 				1
#define D2 				2
#define D3 				3
#define D4 				4
#define D5 				5
#define D6 				6
#define D7 				7
#define PORT_HIGH		255
#define PORT_LOW		0
#define PORTS_SIZE		4
#define PortNumberIdx	3
#define PinNumberIdx	7
#define DIO_u8HIGH		1
#define DIO_u8LOW		0
#define OUTPUT			1
#define	INPUT			0
#define NULL			0
#define ADEN			7
#define ADSC			6
#define ADATE			5
#define ADIF			4
#define ADIE			3
#define REFS1			7
#define REFS0			6
#define ADLAR			5
#define Vref			2.56
enum Boolean {
	ERROR,
	OK
}check;

/********************Functions Prototypes*****************/

/*COMMENT: Set Pin Direction */
extern u8 DIO_u8SetPinDirection(u8 , u8 , u8 );

/*COMMENT: Set Port Direction */
extern u8 DIO_u8SetPortDirection(u8 u8PortNBCpy ,u8 PortDirectionCpy);

/*COMMENT: Set Pin Value */
extern u8 DIO_u8setPinValue(u8 u8PortNBCpy, u8 u8PinNBCpy, u8 PinValueCpy);

/*COMMENT: Set Port By Value */
extern u8 DIO_u8setPort(u8 u8PortNBCpy, u8 PortValueCpy);

/*COMMENT: Get a value of a pin in certain Port */
extern u8 DIO_u8getPin (u8 u8PortNBCpy, u8 PinIndexCpy);

/*COMMENT: Get All Port value */
extern u8 DIO_u8getPort(u8 u8PortNBCpy);    

#endif /* DIO_FUNCTIONS_H_ */
