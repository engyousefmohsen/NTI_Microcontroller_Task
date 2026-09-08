/*
* GccApplication1.c
*
* Created: 9/7/2026 8:24:07 PM
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
	LCD_init();
	ADC_voidInit();
	
	DIO_voidSetPinDirection(DPORTD,PIN3,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN4,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN5,OUTPUT);
	DIO_voidSetPinDirection(DPORTD,PIN6,OUTPUT);
	
	
	/* Replace with your application code */
	while (1)
	{
		u32 temp= (((u32)ADC_u16Read(0)*5000)/1024)/10;
		LCD_voidWriteNumber(temp);
		_delay_ms(500);
		
		if(temp<20)
		{
			DIO_voidSetPinValue(DPORTD,PIN3,HIGH);
			DIO_voidSetPinValue(DPORTD,PIN4,LOW);
			DIO_voidSetPinValue(DPORTD,PIN5,LOW);
			DIO_voidSetPinValue(DPORTD,PIN6,LOW);
		}
		
		else if(temp>=20 && temp<40)
		{
			DIO_voidSetPinValue(DPORTD,PIN3,LOW);
			DIO_voidSetPinValue(DPORTD,PIN4,HIGH);
			DIO_voidSetPinValue(DPORTD,PIN5,LOW);
			DIO_voidSetPinValue(DPORTD,PIN6,LOW);
		}
		
		else if(temp>=40)
		{
			DIO_voidSetPinValue(DPORTD,PIN3,LOW);
			DIO_voidSetPinValue(DPORTD,PIN4,LOW);
			DIO_voidSetPinValue(DPORTD,PIN5,HIGH);
			DIO_voidSetPinValue(DPORTD,PIN6,HIGH);
		}
		
		LCD_SendCommand(0x01);
		_delay_ms(2);
		
		
	}
		
	
}



