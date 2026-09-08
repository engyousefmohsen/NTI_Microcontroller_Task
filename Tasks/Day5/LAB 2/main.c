/*
* GccApplication1.c
*
* Created: 9/2/2026 6:10:02 PM
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
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN3,OUTPUT);
	
	
	/* Replace with your application code */
	while (1)
	{
		DIO_voidSetPinValue(DPORTC,PIN0,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN2,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN0,LOW);
		DIO_voidSetPinValue(DPORTC,PIN2,LOW);
		DIO_voidSetPinValue(DPORTC,PIN1,HIGH);
		DIO_voidSetPinValue(DPORTC,PIN3,HIGH);
		_delay_ms(5000);
		DIO_voidSetPinValue(DPORTC,PIN1,LOW);
		DIO_voidSetPinValue(DPORTC,PIN3,LOW);
	}
}