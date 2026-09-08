#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

u8 matrix[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};

void KEYPAD_init(void)
{

	DIO_voidSetPinDirection(DPORTA,PIN0,INPUT);
	DIO_voidSetPinDirection(DPORTA,PIN1,INPUT);
	DIO_voidSetPinDirection(DPORTA,PIN2,INPUT);
	DIO_voidSetPinDirection(DPORTA,PIN3,INPUT);
	DIO_voidSetPinDirection(DPORTA,PIN4,OUTPUT);
	DIO_voidSetPinDirection(DPORTA,PIN5,OUTPUT);
	DIO_voidSetPinDirection(DPORTA,PIN6,OUTPUT);
	DIO_voidSetPinDirection(DPORTA,PIN7,OUTPUT);

	DIO_voidSetPinValue(DPORTA,PIN0,HIGH);
	DIO_voidSetPinValue(DPORTA,PIN1,HIGH);
	DIO_voidSetPinValue(DPORTA,PIN2,HIGH);
	DIO_voidSetPinValue(DPORTA,PIN3,HIGH);

}

u8 KEYPAD_get(void)
{

	u8 row=0,col=0;
	for(row=0;row<4;row++)
		{
			DIO_voidSetPinValue(DPORTA,row+4,LOW);
			for(col=0;col<4;col++)
				{
					if(DIO_u8ReadPinValue(DPORTA,col)==LOW)
						{
							while(DIO_u8ReadPinValue(DPORTA,col)==LOW);
							DIO_voidSetPinValue(DPORTA,row+4,HIGH);
							return (matrix[col][row]);
						}
				}
			DIO_voidSetPinValue(DPORTA,row+4,HIGH);
		}
 	return 0xFF ;

}