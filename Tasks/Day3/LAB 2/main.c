/*
* GccApplication1.c
*
* Created: 9/1/2026 7:33:10 AM
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
	
	DIO_voidSetPortDirection(DPORTA,INPUT);
	
	DIO_voidSetPinDirection(DPORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(DPORTC,PIN2,OUTPUT);
	
	
	DIO_viodSetPinValue(DPORTA,PIN0,HIGH);
	DIO_viodSetPinValue(DPORTA,PIN1,HIGH);
	DIO_viodSetPinValue(DPORTA,PIN2,HIGH);
	DIO_viodSetPinValue(DPORTA,PIN7,HIGH);

	while (1)
	{
		if(DIO_u8ReadPinValue(DPORTA,PIN0)==0){
			
			DIO_viodSetPinValue(DPORTC,PIN0,HIGH);
		}
		else{
			DIO_viodSetPinValue(DPORTC,PIN0,LOW);
		}
		
		if(DIO_u8ReadPinValue(DPORTA,PIN1)==0){
			
			DIO_viodSetPinValue(DPORTC,PIN1,HIGH);
		}
		else{
			DIO_viodSetPinValue(DPORTC,PIN1,LOW);
		}
		
		if(DIO_u8ReadPinValue(DPORTA,PIN2)==0){
			
			DIO_viodSetPinValue(DPORTC,PIN2,HIGH);
		}
		else{
			DIO_viodSetPinValue(DPORTC,PIN2,LOW);
		}
		
		if(DIO_u8ReadPinValue(DPORTA,PIN7)==0){
			
			DIO_viodSetPinValue(DPORTC,PIN0,HIGH);
			DIO_viodSetPinValue(DPORTC,PIN1,HIGH);
			DIO_viodSetPinValue(DPORTC,PIN2,HIGH);
		}
		else{
			DIO_viodSetPinValue(DPORTC,PIN0,LOW);
			DIO_viodSetPinValue(DPORTC,PIN1,LOW);
			DIO_viodSetPinValue(DPORTC,PIN2,LOW);
		}
		
	}
}
