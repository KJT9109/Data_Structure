/*
 * postifx.h
 *
 *  Created on: 2020. 11. 4.
 *      Author: jitae
 */




enum __opCodeChange
{
	OPEN_BACKET = -9,
	CLOSE_BACKET = -10,
	MULTI = -8,
	DIVID = -5,
	PLUS = -7,
	MINUS = -6

}opCodeChange;

int* Postfix_func(int *char_arr, int len);
int Postfix_Calc(int *char_arr, int length);

int STRtoINT(char *char_arr, int *local_arr);
int calc_op_check(int num);
