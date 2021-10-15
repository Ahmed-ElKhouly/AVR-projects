/*
 * calc.h
 *
 *  Created on: Mar 18, 2021
 *      Author: Ahmed ElSayed ElKhouly
 */

#ifndef CALC_H_
#define CALC_H_

extern void Create_op(uint8 digit);
extern void Operation (uint8 opra);
extern uint8 Equal(uint8 opra, uint8 * ans);
extern void restart(void);

extern uint16 op;
extern uint8 error;

#endif /* CALC_H_ */
