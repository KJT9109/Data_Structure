/*
 * Calcmain.c
 *
 *  Created on: 2020. 11. 3.
 *      Author: jitae
 */

#include "stdio.h"
#include "stdint.h"
#include "postfix.h"
#include "stack.h"

Stack Normal_Stack;
int normal_array[ARRAY_SIZE];

/*
 *
 */

int main(void)
{
	int length = 0;
	memset(normal_array, 0, ARRAY_SIZE);

	char *calc_equal =
//	{ "51-8/(3+4*2/8)*3+2" };
			{"51-8/(3*4-4)-20"};
	length = STRtoINT(calc_equal, normal_array);

	Postfix_func(normal_array, length);

	printf("calc result is: %d \r\n", Postfix_Calc(normal_array, length));

}
