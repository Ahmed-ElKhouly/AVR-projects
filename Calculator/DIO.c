/*
 * DIO.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed ElSayed ElKhouly
 */

#include "StdTypes.h"
#include "Utils.h"
#include "Memmap.h"
#include "DIO.h"

extern void DIO_SetPinDirection(PortID_t Port, PinID_t Pin, uint8 direction)
{
	if((Port <= PD) && (Pin <= PIN7))
	{
		switch(Port)
		{
		case PA:
			switch(direction)
			{
			case OUT:
				SET_BIT(DDRA,Pin);
				break;
			case INFREE:
				CLR_BIT(DDRA,Pin);
				break;
			case INPULLUP:
				CLR_BIT(DDRA,Pin);
				SET_BIT(PORTA,Pin);
				break;
			}
			break;
		case PB:
			switch(direction)
			{
			case OUT:
				SET_BIT(DDRB,Pin);
				break;
			case INFREE:
				CLR_BIT(DDRB,Pin);
				break;
			case INPULLUP:
				CLR_BIT(DDRB,Pin);
				SET_BIT(PORTB,Pin);
				break;
			}
			break;
		case PC:
			switch(direction)
			{
			case OUT:
				SET_BIT(DDRC,Pin);
				break;
			case INFREE:
				CLR_BIT(DDRC,Pin);
				break;
			case INPULLUP:
				CLR_BIT(DDRC,Pin);
				SET_BIT(PORTC,Pin);
				break;
			}
			break;
		case PD:
			switch(direction)
			{
			case OUT:
				SET_BIT(DDRD,Pin);
				break;
			case INFREE:
				CLR_BIT(DDRD,Pin);
				break;
			case INPULLUP:
				CLR_BIT(DDRD,Pin);
				SET_BIT(PORTD,Pin);
				break;
			}
			break;
		}
	}
	else{

	}
}


extern void DIO_SetPortDirection(PortID_t Port, uint8 direction)
{
	if(Port <= PD)
	{
		switch(Port)
		{
		case PA:
			DDRA=direction;
			break;
		case PB:
			DDRB=direction;
			break;
		case PC:
			DDRC=direction;
			break;
		case PD:
			DDRD=direction;
			break;
		}
	}
	else{

	}
}


extern void DIO_WriteOnPin(PortID_t Port, PinID_t Pin, uint8 value)
{
	if((Port <= PD) && (Pin <= PIN7))
	{
		switch(Port)
		{
		case PA:
			if(value == HIGHV)
			{
				SET_BIT(PORTA,Pin);
			}
			else
			{
				CLR_BIT(PORTA,Pin);
			}
			break;

		case PB:
			if(value == HIGHV)
			{
				SET_BIT(PORTB,Pin);
			}
			else
			{
				CLR_BIT(PORTB,Pin);
			}
			break;

		case PC:
			if(value == HIGHV)
			{
				SET_BIT(PORTC,Pin);
			}
			else
			{
				CLR_BIT(PORTC,Pin);
			}
			break;

		case PD:
			if(value == HIGHV)
			{
				SET_BIT(PORTD,Pin);
			}
			else
			{
				CLR_BIT(PORTD,Pin);
			}
			break;
		}
	}
	else{

	}
}


extern void DIO_WriteOnPort(PortID_t Port, uint8 value)
{
	if(Port <= PD)
	{
		switch(Port)
		{
		case PA:
			PORTA=value;
			break;

		case PB:
			PORTB=value;
			break;

		case PC:
			PORTC=value;
			break;

		case PD:
			PORTD=value;
			break;
		}
	}
	else{

	}
}


extern uint8 DIO_ReadFromPin(PortID_t Port, PinID_t Pin)
{
	uint8 result = 0;

	if((Port <= PD) && (Pin <= PIN7))
	{
		switch(Port)
		{
		case PA:
			result = GET_BIT(PINA,Pin);
			break;

		case PB:
			result = GET_BIT(PINB,Pin);
			break;

		case PC:
			result = GET_BIT(PINC,Pin);
			break;

		case PD:
			result = GET_BIT(PIND,Pin);
			break;
		}
	}
	else{

	}
	return result;
}


extern uint8 DIO_ReadFromPort(PortID_t Port)
{
	uint8 result = 0;

	if(Port <= PD)
	{
		switch(Port)
		{
		case PA:
			result = PINA;
			break;

		case PB:
			result = PINB;
			break;

		case PC:
			result = PINC;
			break;

		case PD:
			result = PIND;
			break;
		}
	}
	else{

	}
	return result;
}
