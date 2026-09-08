/*
* GccApplication1.c
*
* Created: 9/1/2026 4:26:44 PM
* Author : Yousef Mohsen Mohammed
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

#include "KEYPAD_int.h"

#include "STEPMOTOR_int.h"

#include "INTERRUPT_int.h"


int main(void)
{
	DIO_voidInitialization();
	INTERRUPT_init();
	
	DIO_voidSetPinDirection(DPORTD, PIN3, INPUT);
	DIO_voidSetPortDirection(DPORTA,OUTPUT);
	
	DIO_voidSetPinValue(DPORTD, PIN3, HIGH);
	
	
	while (1)
	{
		
	}
	
}



ISR(INT1_vect)
{
	u8 mode1[8]={1,0,1,1,1,0,0,1};
	u8 mode2[8]={0,1,0,0,0,1,1,0};
	if (DIO_u8ReadPinValue(DPORTD, PIN3) == 0)
	{
		for(int i=0;i<8;i++)
		{
			DIO_voidSetPinValue(DPORTA,i,mode1[i]);
			_delay_ms(500);
		}
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			DIO_voidSetPinValue(DPORTA,i,mode2[i]);
			_delay_ms(500);
		}
	}
	
}

