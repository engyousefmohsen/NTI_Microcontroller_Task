/*
* GccApplication1.c
*
* Created: 9/4/2026 5:03:43 PM
* Author : Yousef Mohsen Mohammed
*/

#define F_CPU 1000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"


int main(void)
{
	DIO_voidInitialization();
	
	DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
	
	DIO_voidSetPinDirection(DPORTA,PIN1,OUTPUT);
	
	
	DIO_voidSetPinValue(DPORTA,PIN0,HIGH);

	/* Replace with your application code */
	while (1)
	{
		if(DIO_u8ReadPinValue(DPORTA,PIN0)==0){
			
			DIO_voidSetPinValue(DPORTA,PIN1,HIGH);
		}
		else{
			DIO_voidSetPinValue(DPORTA,PIN1,LOW);
		}
		
	}
}