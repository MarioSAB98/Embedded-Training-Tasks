/*
* main.c
*
* Created: 11/3/2022 1:33:16 AM
*  Author: Mario
*/

#include <xc.h>

#include "std_type.h"
#include "DIO_utilites.h"
#include "DIO_Functions.h"
#include "DIO_reg.h"
#include "avr/delay.h"
#include "avr/interrupt.h"


void main()
{
	
	int flag = 1;
	int counter = 0;
	
	DIO_u8SetPinDirection(PORTC_Idx,C0,INPUT);

	DIO_u8SetPinDirection(PORTD_Idx,D1,OUTPUT);
	DIO_u8SetPinDirection(PORTD_Idx,D2,OUTPUT);
	DIO_u8SetPinDirection(PORTD_Idx,D3,OUTPUT);
	


	_delay_us(15);
	
	while(1)
	{
		int val = 	DIO_u8getPin(PORTC_Idx,C0);
		
		if (val == 0)
		{
			if (flag == 1)
			{
				counter ++;
				flag = 0;		
			}
			
		}
		else
		{
			flag = 1;
		}
		
		if (counter % 6 == 0)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8LOW);				
		}
		else if (counter % 6 == 1)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8LOW);	
		}
		
		else if (counter % 6 == 2)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8LOW);
		}
		
		else if (counter % 6 == 3)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8HIGH);
		}
		
		else if (counter % 6 == 4)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8LOW);
		}
		
		else if (counter % 6 == 5)
		{
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D3,DIO_u8LOW);
		}
		
	}
}
