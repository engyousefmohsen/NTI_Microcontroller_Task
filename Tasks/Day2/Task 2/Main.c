#define F_CPU 1000000UL
#include <util/delay.h>
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "SevenSeg_int.h"

int main(void)
{
DIO_voidInitialization();
DIO_voidSetPortDirection(DPORTD, OUTPUT);

while (1)
{

for(u8 i=0; i <= 9; i++)
{

SevSegment_voidSetValue(i,DPORTD,1);
_delay_ms(1000);

}

}
}