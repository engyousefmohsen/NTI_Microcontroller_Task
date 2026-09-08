#include <util/delay.h>
#define F_CPU 8000000UL
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

int main(void)
{

DIO_voidInitialization();
DIO_voidSetPortDirection(DPORTB, OUTPUT);


while (1)
{

}

DIO_viodSetPinValue(DPORTB, PIN7,HIGH);
_delay_ms(1000);
DIO_viodSetPinValue(DPORTB,PIN7,LOW);
_delay_ms(1000);

}