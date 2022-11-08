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
	int counter = 0;
	int flag = 1;


	DIO_u8SetPinDirection(PORTB_Idx,B0,INPUT);


	DIO_u8SetPinDirection(PORTC_Idx,C0,OUTPUT);
	DIO_u8SetPinDirection(PORTC_Idx,C1,OUTPUT);
	DIO_u8SetPinDirection(PORTC_Idx,C2,OUTPUT);

	DIO_u8SetPinDirection(PORTD_Idx,D0,OUTPUT);
	DIO_u8SetPinDirection(PORTD_Idx,D1,OUTPUT);
	DIO_u8SetPinDirection(PORTD_Idx,D2,OUTPUT);

	
	while(1)
	{	
		
		//Car_LEDs
		//RED
		if (counter % 4 == 0)
		{
			DIO_u8setPinValue(PORTD_Idx,D0,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
		}
		//YELLOW-GREEN
		else if (counter % 4 == 1)
		{
			DIO_u8setPinValue(PORTD_Idx,D0,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
		}
		//GREEN
		else if (counter % 4 == 2)
		{
			DIO_u8setPinValue(PORTD_Idx,D0,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8HIGH);
		}
		//YELLOW-RED
		else if (counter % 4 == 3)
		{
			DIO_u8setPinValue(PORTD_Idx,D0,DIO_u8LOW);
			DIO_u8setPinValue(PORTD_Idx,D1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTD_Idx,D2,DIO_u8LOW);
		}
		
		//Walk_LEDs
		//GREEN
		if (counter % 4 == 0)
		{
			DIO_u8setPinValue(PORTC_Idx,C0,DIO_u8HIGH);
			DIO_u8setPinValue(PORTC_Idx,C1,DIO_u8LOW);
			DIO_u8setPinValue(PORTC_Idx,C2,DIO_u8LOW);
		}
		//YELLOW-RED
		else if (counter % 4 == 1)
		{
			DIO_u8setPinValue(PORTC_Idx,C0,DIO_u8LOW);
			DIO_u8setPinValue(PORTC_Idx,C1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTC_Idx,C2,DIO_u8LOW);
		}
		//RED
		else if (counter % 4 == 2)
		{
			DIO_u8setPinValue(PORTC_Idx,C0,DIO_u8LOW);
			DIO_u8setPinValue(PORTC_Idx,C1,DIO_u8LOW);
			DIO_u8setPinValue(PORTC_Idx,C2,DIO_u8HIGH);
		}
		//YELLOW-GREEN
		else if (counter % 4 == 3)
		{
			DIO_u8setPinValue(PORTC_Idx,C0,DIO_u8LOW);
			DIO_u8setPinValue(PORTC_Idx,C1,DIO_u8HIGH);
			DIO_u8setPinValue(PORTC_Idx,C2,DIO_u8LOW);
		}		
		
		counter++;

		for(int i=0;i<1000;i++)
		{
			TIMER0_Normal_1024_Prescaler();
			TIMER0_Set_Period(0xB2);
			while(TIMER0_Get_Trigger(0x01)==0);
			TCCR0 = 0;
			TIFR = 0x1;
			int val = 	DIO_u8getPin(PORTB_Idx,B0);
			
					
			if (val == 0)
			{
				if (flag == 1)
				{
					flag = 0;
					if (counter % 4 == 0 || counter % 4 == 1)
					{
						continue;
					}
					else
					{
						counter = 3;
						break;
					}
				}
				
			}
			else
			{
				flag = 1;
			}			
		}
		

		
		


	}

}


/*void main()
{
	
	int flag = 1;
	
	
	


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
}*/