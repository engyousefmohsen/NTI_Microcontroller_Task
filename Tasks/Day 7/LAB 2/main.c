/*
* GccApplication1.c
*
* Created: 9/7/2026 7:27:51 PM
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
	
	
	while (1)
	{
		LCD_voidWriteNumber(((u32)ADC_u16Read(0)*5000)/1024);
		_delay_ms(1000);
		LCD_SendCommand(0x01);
		_delay_ms(2);
	}
		
	
}



