/*
 * calc.c
 *
 *  Created on: Mar 18, 2021
 *      Author: Ahmed ElSayed ElKhouly
 */


#include "StdTypes.h"
#include "DIO.h"
#include "Utils.h"
#include "Memmap.h"
#include "calc.h"

static void multiply(void);
static void divide(void);
static void add(void);
static void subtract(void);
static void add_op(void);
static void concat(uint8 int2);
static void intTOchar(uint8 * ints, uint8 leng);
static void reverse(uint8 * ints, uint8 len);
static uint8 separate_digits(uint8 * ints, float32 ans);



float32 operands[15] = {0}; /* A buffer to save all opernads and operators. ***** The result of equation will be saved in the first index. */
uint8 counter = 0; /* Counter to count number of operands and operators. */
uint16 op = 0; /* Each operand will be created here before being saved to the operands buffer. */
uint8 error = 0; /* Error flag to chech any syntax error. */

/* An interface that resets all calculater settings. */
/* Has no arguments or return. */
void restart(void){
	op = 0;
	counter = 0;
	operands[0] = 0;
	error = 0;
}

/* An interface that creates a new operand by passing the value of pressed key */
/* Has no return. */
void Create_op(uint8 digit){
	if(digit <= 9 && digit != '0'){
		if(error){
			error --;
		}else{
			error = 0;
		}
		concat(digit);
	}else{
		/* Nothing to do. */
	}
}

/* A function that adds the new operand to the array of operands. */
/* Has no arguments or return. */
static void add_op(void){
	operands[counter] = op;
	op = 0;
	counter ++;
}


/* An interface that adds the new oerator to the array of operands by passing the operator value. */
/* Has no return. */
void Operation (uint8 operator){
	add_op();
	error ++;
	if(operator == 'x'){
		operands[counter] = 'x';
		counter ++;
	}else if(operator == '/'){
		operands[counter] = '/';
		counter ++;
	}else if(operator == '+'){
		operands[counter] = '+';
		counter ++;
	}else if(operator == '-'){
		operands[counter] = '-';
		counter ++;
	}else if(operator == 'a' || error > 1){
		restart();
	}else{
		/* Nothing to do */
	}
}


/* An interface that calculates the equation and saves the result in an array by passing this array and ther value of '=' as a checkup. */
/* Returns the size of the result array. */
uint8 Equal(uint8 operator, uint8 * ans){
	uint8 size = 0;
	add_op();
	if(operator == '='){
		/* Running all operations and result will be saved in the first index of the operands buffer. */
		divide();
		multiply();
		subtract();
		add();


		/* Converting the result to array of characters to be displayed on LCD. */
		size = separate_digits(ans, operands[0]);
		reverse(ans, size);
		intTOchar(ans, size);
		restart();
	}else{
		/* Nothing to do. */
	}
	return size;
}





/* A function that cocatinate a new digit to the operand by passing the value of the digit. */
/* Has no return. */
static void concat(uint8 int2){
	uint8 pow = 10;
	while(int2 >= pow){
		pow *= 10;
	}
	op = ((op * pow) + int2);
}


/* A function that makes any multipliction operation between operands. */
/* Has no arguments or return. */
static void multiply(void){
	uint8 max, min;
	for(uint8 i = 1; i < counter; i++){
		if(operands[i] == 'x'){
			min = i - 1;
			while(operands[min] == 'n' || operands[min] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				min --;
			}
			max = i + 1;
			while(operands[max] == 'n' || operands[max] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				max ++;
			}

			operands[min] = operands[min] * operands[max];
			operands[max] = 'n';
		}
	}
}



/* A function that makes any division operation between operands. */
/* Has no arguments or return. */
static void divide(void){
	uint8 max, min;
	for(uint8 i = 1; i < counter; i++){
		if(operands[i] == '/'){
			min = i - 1;
			while(operands[min] == 'n' || operands[min] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				min --;
			}
			max = i + 1;
			while(operands[max] == 'n' || operands[max] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				max ++;
			}

			operands[min] = operands[min] / operands[max];
			operands[max] = 'n';
		}
	}
}


/* A function that makes any addition operation between operands. */
/* Has no arguments or return. */
static void add(void){
	uint8 max, min;
	for(uint8 i = 1; i < counter; i++){
		if(operands[i] == '+'){
			min = i - 1;
			while(operands[min] == 'n' || operands[min] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				min --;
			}
			max = i + 1;
			while(operands[max] == 'n' || operands[max] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				max ++;
			}

			operands[min] = operands[min] + operands[max];
			operands[max] = 'n';
		}
	}
}


/* A function that makes any subtraction operation between operands. */
/* Has no arguments or return. */
static void subtract(void){
	uint8 max, min;
	for(uint8 i = 1; i < counter; i++){
		if(operands[i] == '-'){
			min = i - 1;
			while(operands[min] == 'n' || operands[min] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				min --;
			}
			max = i + 1;
			while(operands[max] == 'n' || operands[max] == 'x' || operands[min] == '/' || operands[min] == '+' || operands[min] == '-')
			{
				max ++;
			}

			operands[min] = operands[min] - operands[max];
			operands[max] = 'n';
		}
	}
}


/* A function that converts numeric value into characters by passing the array of digits and its lenghth. */
/* Has no return. */
static void intTOchar(uint8 * ints, uint8 leng){
	for(uint8 i = 0; i < leng; i++){
		switch(ints[i]){
		case 0:
			ints[i] = '0';
			break;
		case 1:
			ints[i] = '1';
			break;
		case 2:
			ints[i] = '2';
			break;
		case 3:
			ints[i] = '3';
			break;
		case 4:
			ints[i] = '4';
			break;
		case 5:
			ints[i] = '5';
			break;
		case 6:
			ints[i] = '6';
			break;
		case 7:
			ints[i] = '7';
			break;
		case 8:
			ints[i] = '8';
			break;
		case 9:
			ints[i] = '9';
			break;
		case '-':
			ints[i] = '-';
			break;
		case '.':
			ints[i] = '.';
			break;
		default:
			/* Nothing to do. */
			break;
		}
	}
}


/* A function that separates each digit in numeric value inside elemente of array by passing the array and the numeric value. */
/* Returns the length of array. */
static uint8 separate_digits(uint8 * ints, float32 ans){
	uint8 leng = 0;
	uint8 flag = 0;
	if(ans < 0){
		ans *= (-1);
		flag = 1;
	}
	sint32 beforePoint = (sint32)ans;
	float32 afterPoint = ans - (float32)beforePoint;

	if(afterPoint != 0){
		afterPoint = afterPoint * (10000000);

		do{
			ints[leng] = ((sint32)afterPoint %10);
			afterPoint = (uint32)afterPoint / 10;
			leng++;

		}while(afterPoint>0);
		ints[leng] = '.';
		leng ++;
	}

	do{
		ints[leng] = (beforePoint%10);
		beforePoint /= 10;
		leng++;

	}while(beforePoint>0);

	if(flag){
		ints[leng] = '-';
		leng ++;
	}
	return leng;

}


/* A function that reverse the order of an array by passing the array and its lenght. */
/* Has no return */
static void reverse(uint8 * ints, uint8 len){
	for(uint8 i = 0; i < len/2;i++){
		uint8 temp = ints[len-i-1];
		ints[len-i-1] = ints[i];
		ints[i] = temp;
	}
}









