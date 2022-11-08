/*
* TIMERS_Functions.c
*
* Created: 11/3/2022 3:14:02 AM
*  Author: Mario
*/

#include "std_type.h"
#include "DIO_utilites.h"
#include "DIO_Functions.h"
#include "DIO_reg.h"
#include "TIMERS_Functions.h"
#include "avr/interrupt.h"

void TIMER0_Normal_No_Prescaler(void)
{
		assigning_reg(TCCR0,0X01);
		clr_reg(TCNT0);
		set_bit(TIFR,TOV0);
}
void TIMER0_Normal_8_Prescaler(void)
{
		assigning_reg(TCCR0,0X02);
		clr_reg(TCNT0);
		set_bit(TIFR,TOV0);
}
void TIMER0_Normal_64_Prescaler(void)
{
		assigning_reg(TCCR0,0X03);
		clr_reg(TCNT0);
		set_bit(TIFR,TOV0);
}
void TIMER0_Normal_256_Prescaler(void)
{
		assigning_reg(TCCR0,0X04);
		clr_reg(TCNT0);
		set_bit(TIFR,TOV0);
}
void TIMER0_Normal_1024_Prescaler(void)
{
		assigning_reg(TCCR0,0X05);
		clr_reg(TCNT0);
		set_bit(TIFR,TOV0);
}
void TIMER0_Set_Period(int period){
	
			assigning_reg(TCNT0,period);
}

extern u8 TIMER0_Get_Trigger(u8 TimerConfig){
	
		return (TIFR&TimerConfig);
}