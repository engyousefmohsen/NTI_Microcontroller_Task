/*
* GccApplication1.c
*
* Created: 9/5/2026 1:52:50 PM
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
	
	LCD_init();
	
	while (1)
	{
		LCD_SendString((u8*)"Yousef Mohsen");
		GoToXY(0,1);
		LCD_voidWriteNumber(01155969555);
		GoToXY(0,0);

		
	}
}
