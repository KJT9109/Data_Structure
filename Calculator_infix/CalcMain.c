/*
 * Calcmain.c
 *
 *  Created on: 2020. 11. 3.
 *      Author: jitae
 */

#include "stdio.h"
#include "stdint.h"

#include "infx.h"
#include "stack.h"

Stack Normal_Stack;
Stack Calc_Stack;

int main(void)
{

	int result;

	StackInit(&Normal_Stack);

	char *calc_equal =
	//{ "10*5-8/4+2*3" };
	{"2+9+(9-3)"};

	infix_form(calc_equal, &Normal_Stack);

	result = infix_calculator(&Normal_Stack);

	printf( "calculator result is %d \r\n",result);

	return result;

}
