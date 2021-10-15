/*
 * main.c
 *
 *  Created on: Mar 18, 2021
 *      Author: Ahmed ElSayed ElKhouly
 */
#include "StdTypes.h"
#include "DIO.h"
#include "Utils.h"
#include "Memmap.h"
#include <util/delay.h>
#include "LCD_Interface.h"
#include "KEYPAD.h"
#include "calc.h"



int main(void)
{

	/* Initializing Keypad. */
	DIO_SetPortDirection(PA,0b00001111);
	DIO_WriteOnPort(PA,0b11110000);

	/* Configuering Port direction for LCD. */
	DIO_SetPortDirection(PC, 0b11111111);
	DIO_SetPortDirection(PD, 0b11111111);

	LCD_vidInit(); /* LCD initialization function */


	uint8 ops[10] = {0}; /* Buffer to save result. */
	uint8 size = 0; /* saves the length of result inside the buffer. */
	uint8 flag = 1; /* Flag to know when to reset the calculator. */
	uint8 syntx[] = "Syntax";
	uint8 syntx1[] = "Error";

	while(1)
	{
		uint8 key[2] = {0}; /* Saves the pressed key value */
		KEYPAD_GetChar(key); /* Getting value of pressed key */


		if(key[0] != 0){ /* Check if there is any key was pressed */

			if(!flag) /* Check if we need to reset calculater by erase LCD */
			{
				LCD_vidSendCommand(0x01);
				flag = 1;
			} if(key[1] <= 9){ /* check if the key pressed was a numbre */
				Create_op(key[1]); /* Calling a function which creates a new operand and passing the value of key to it. */
				LCD_vidWriteChar(key[0]); /* calling a function which displays the key value on LCD by passing the key value in character format. */
			}else if(key[1] == '0'){  /* check if the key pressed was an operator. */
				Operation(key[0]);  /* calling function which create an operator by passing the value of the key containing the operation. */
				if(key[0] == 'a'){ /* Check if the key pressed is for resetting calculator */
					LCD_vidSendCommand(0x01); /* Calling a function which clears LCD. */
				}else{
					LCD_vidWriteChar(key[0]); /* Calling a function which diplays the operator pressed by passing its value to it. */
				}
			}else if(key[1] == 'e'){ /* Check if the = key was pressed. */
				if(error){  /* Check if there is any syntax error. */
					/* Printing "Syntax Error" on LCD. */
					LCD_vidSendCommand(0x01);
					LCD_vidWriteString(syntx, 6);
					LCD_vidSendCommand(0xc4);
					LCD_vidWriteString(syntx1, 5);
					flag = 0; /* Setting a flag to reset calculater in the next itiration. */
					error = 0; /* Clearing syntax error flag. */
					restart(); /* Calling a function that restarts the calculator. */
				}else{
					size = Equal(key[0], ops);/* Calling a function which calculates the equation by passing the value of '=' key, and an array as a buffer to save the value and returning the size of it. */
					/* Printing the equation final value on LCD in case of there is no syntax error. */
					LCD_vidSendCommand(0xc0);
					LCD_vidWriteChar(key[0]);
					LCD_vidWriteString(ops, size);
					flag = 0; /* Setting a flag to reset calculater in the next itiration. */
				}
			}else{
				/* Nothing to do */
			}
		}else{
			/* Nothing to do */
		}



		_delay_ms(200); /* Delay for sense one key press. */

	}
}
