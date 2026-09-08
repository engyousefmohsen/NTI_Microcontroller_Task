/*
* GccApplication1.c
*
* Created: 9/1/2026 12:12:01 PM
* Author : Yousef Mohsen Mohammed
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

#include "KEYPAD_int.h"

#include "STEPMOTOR_int.h"


int main(void)
{
	DIO_voidInitialization();
	STEPMOTOR_init();
	
	while (1)
	{
		FULL_STEP(COUNTER_WISE);
	}
}