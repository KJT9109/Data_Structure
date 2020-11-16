/*
 * postifx.h
 *
 *  Created on: 2020. 11. 4.
 *      Author: jitae
 */

#include "stack.h"

typedef enum
{
	OPCODE_NONE = 0x0U, OPCODE_SET = 0x1U

} OpCode_Checkdef;

typedef enum
{
	OPERAND_1 = 0x0U,
	OPERAND_2 = 0x1U,
	OPERAND_3 = 0x2U,
	OPERAND_ERR = 0x4U

}Operand_Checkdef;

int infix_form(char *buf, Stack *AStack);
int infix_calc(Stack *LStack);
int infix_calculator(Stack *LStack);

