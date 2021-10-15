/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed ElSayed ElKhouly
 */
#include "StdTypes.h"
#include "DIO.h"
#include "KEYPAD.h"

KEYPAD_t KEYPAD_GetKey(void)
{
	//ROWS
	DIO_WriteOnPin(PA,PIN0,LOWV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);

	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		return KEYONE;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		return KEYTWO;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		return KEYTHREE;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		return KEYA;
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,LOWV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);

	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		return KEYFOUR;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		return KEYFIVE;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		return KEYSIX;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		return KEYB;
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,LOWV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);

	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		return KEYSEVEN;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		return KEYEIGHT;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		return KEYNINE;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		return KEYC;
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,LOWV);

	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		return KEYSTAR;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		return KEYZERO;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		return KEYHASH;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		return KEYD;
	}
	return NOKEY;
}



/* An interface to get the pressed key by passing an array of 2 elements and the function saves in it the pressed key value in numeric and character. */

void KEYPAD_GetChar(uint8 * ch){


	DIO_WriteOnPin(PA,PIN0,LOWV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);

	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		ch[0] = '7';
		ch[1] = 7;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		ch[0] = '8';
		ch[1] = 8;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		ch[0] = '9';
		ch[1] = 9;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		ch[0] = '/';
		ch[1] = '0';
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,LOWV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);
	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		ch[0] = '4';
		ch[1] = 4;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		ch[0] = '5';
		ch[1] = 5;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		ch[0] = '6';
		ch[1] = 6;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		ch[0] = 'x';
		ch[1] = '0';
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,LOWV);
	DIO_WriteOnPin(PA,PIN3,HIGHV);
	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		ch[0] = '1';
		ch[1] = 1;
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		ch[0] = '2';
		ch[1] = 2;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		ch[0] = '3';
		ch[1] = 3;
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		ch[0] = '-';
		ch[1] = '0';
	}

	DIO_WriteOnPin(PA,PIN0,HIGHV);
	DIO_WriteOnPin(PA,PIN1,HIGHV);
	DIO_WriteOnPin(PA,PIN2,HIGHV);
	DIO_WriteOnPin(PA,PIN3,LOWV);
	if(DIO_ReadFromPin(PA,PIN4)==LOWV)
	{
		ch[0] = 'a';
		ch[1] = '0';
	}
	else if(DIO_ReadFromPin(PA,PIN5)==LOWV)
	{
		ch[0] = '0';
		ch[1] = 0;
	}
	else if(DIO_ReadFromPin(PA,PIN6)==LOWV)
	{
		ch[0] = '=';
		ch[1] = 'e';
	}
	else if(DIO_ReadFromPin(PA,PIN7)==LOWV)
	{
		ch[0] = '+';
		ch[1] = '0';
	}

}
