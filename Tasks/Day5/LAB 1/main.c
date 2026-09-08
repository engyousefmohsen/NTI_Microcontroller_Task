/*
* GccApplication1.c
*
* Created: 9/4/2026 7:11:37 PM
* Author : Yousef Mohsen Mohammed
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

#include "KEYPAD_int.h"


int main(void)
{
	DIO_voidInitialization();
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	
	
	/* Replace with your application code */
	while (1)
	{
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		_delay_ms(5000);
	}
}