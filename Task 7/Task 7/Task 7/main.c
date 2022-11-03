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
#include "TIMERS_Functions.h"


void main()
{
	DIO_u8SetPinDirection(PORTD_Idx,D1,OUTPUT);
	
	while(1)
	{
		for(int i=0;i<60;i++)
		{
			TIMER0_Normal_1024_Prescaler();
			TIMER0_Set_Period(0xB2);
			while(TIMER0_Get_Trigger(0x01)==0);
			TCCR0 = 0;
			TIFR = 0x1;
			
		}
		
		
		DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);

		for(int i=0;i<60;i++)
		{
			TIMER0_Normal_1024_Prescaler();
			TIMER0_Set_Period(0xB2);
			while(TIMER0_Get_Trigger(0x01)==0);
			TCCR0 = 0;
			TIFR = 0x1;
			
		}
		
		DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8LOW);


	}

}
