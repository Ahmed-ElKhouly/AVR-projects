/*
 * DIO.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed ElSayed ElKhouly
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

typedef enum {
	KEYZERO = 0,
	KEYONE,
	KEYTWO,
	KEYTHREE,
	KEYFOUR,
	KEYFIVE,
	KEYSIX,
	KEYSEVEN,
	KEYEIGHT,
	KEYNINE,
	KEYA,
	KEYB,
	KEYC,
	KEYD,
	KEYSTAR,
	KEYHASH,
	NOKEY
}KEYPAD_t;

extern KEYPAD_t KEYPAD_GetKey(void);
extern void KEYPAD_GetChar(uint8 * ch);

#endif /* KEYPAD_H_ */
