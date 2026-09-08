/*
* GccApplication1.c
*
* Created: 9/4/2026 3:53:57 PM
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
	LCD_init();
	KEYPAD_init();
	
	u8 string[16];
	u8 idx=0;
	
	u8 pressed_key;
	
	/* Replace with your application code */
	while (1)
	{
		pressed_key=KEYPAD_get();
		
		if(pressed_key == 'c')
		{
			LCD_SendCommand(0x01); // Clear
			GoToXY(0,0);
			idx=0;
		}
		else if((pressed_key>='0'&& pressed_key<='9') || pressed_key=='+' || pressed_key=='/' || pressed_key=='*' || pressed_key=='-')
		{
			LCD_sendChar(pressed_key);
			string[idx]=pressed_key;
			idx++;
		}
		else if(pressed_key=='=')
		{
			if(string[0]=='*' || string[0]=='/' || string[idx-1]=='*' || string[idx-1]=='/' || string[idx-1]=='+' || string[idx-1]=='-')
			{
				GoToXY(0,1);
				LCD_SendString("Syntax ERROR");
			}
			else
			{
				s32 num=0,neg=0,equ[16],eidx=0;
				for(u8 i=0;i<idx;i++)
				{
					if(string[i]>='0' && string[i]<='9')
					{
						num = (num * 10) + (string[i] - '0');
					}
					else
					{
						if(i > 0 && (string[i-1] < '0' || string[i-1] > '9'))
						{
							if(string[i] == '-')
							{
								if(neg == 1) neg = 0;
								else neg = 1;
							}
						}
						else{
							if(neg==1)
							{ 
								num*=-1;
								neg=0;
							}
							equ[eidx]=num;
							eidx++;
							if(string[i]=='-')
							{
								if(neg == 1) neg = 0;
								else neg = 1;
								equ[eidx] = '+';
								eidx++;
							}
							else
							{
								equ[eidx]=string[i];
								eidx++;
							}
							num=0;
						}
					}
				}
				if(neg == 1) num *= -1;
				equ[eidx] = num;
				eidx++;
				
				for(u8 i = 0; i < eidx; i++)
				{
					if(equ[i] == '*' || equ[i] == '/')
					{
						s32 left = equ[i-1];
						s32 right = equ[i+1];
						s32 res = 0;
						
						if(equ[i] == '*')
						{
							res = left * right;
						}
						else if(equ[i] == '/')
						{
							if(right != 0) res = left / right;
							else
							{
								GoToXY(0,1);
								LCD_SendString("Math ERROR");
							}
						}
						
						equ[i-1] = 'd'; // deleted
						equ[i] = 'd'; // deleted
						equ[i+1] =  res; 
					}
				}

				s32 final_result = 0;
				for(u8 i = 0; i < eidx; i++)
				{
					// egma3 elba2y
					if(equ[i] != '+' && equ[i] != 'd')
					{
						final_result += equ[i];
					}
				}
				u8 result_string[16];
				ltoa(final_result, (char*)result_string, 10);

				GoToXY(16-strlen((char*)result_string), 1);
				LCD_voidWriteNumber(final_result);
			}
		}
	}
}