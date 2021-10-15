/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed ElSayed ElKhouly
 */

#define HIGHV 1
#define LOWV 0
#define INFREE 0
#define INPULLUP 1
#define OUT 2

typedef enum
{
	PA = 0,
	PB,
	PC,
	PD
}PortID_t;


typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PinID_t;


extern void DIO_SetPinDirection(PortID_t Port, PinID_t Pin, uint8 direction);
extern void DIO_SetPortDirection(PortID_t Port, uint8 direction);
extern void DIO_WriteOnPin(PortID_t Port, PinID_t Pin, uint8 value);
extern void DIO_WriteOnPort(PortID_t Port, uint8 value);
extern uint8 DIO_ReadFromPin(PortID_t Port, PinID_t Pin);
extern uint8 DIO_ReadFromPort(PortID_t Port);
