#include "infx.h"

#include "stack.h"
#include "stdlib.h"

extern Stack Normal_Stack;
extern Stack Calc_Stack;

int calc_op_check(int op)
{
	switch (op)
	{

	case '*':
	case '/':
		return 1;

	default:
		return -1;
	}
}


int infix_form(char *buf, Stack *CurrentStack)
{
	int num = 0;

	Stack Local_Stack;
	StackInit(&Local_Stack);

	while (1)
	{
		num = strtoul(buf, &buf, 10);

		if (num != 0)
		{
			SPush(&Local_Stack, num);
		}
		else
		{
			if (calc_op_check(*buf) != -1)
			{
				SPush(&Local_Stack, *buf);
				buf += 1;

			}
			else
			{
				printf(" Format OK !! \r\n");
				break;
			}

		}
	}

	while (Local_Stack.stack_ptr != -1)
		SPush(CurrentStack, SPop(&Local_Stack));

	return 0;
}


int multi_div_calc(int operator, int operand_0, int operand_1)
{

	int calc_result = 0;

	/*곱하기 or 나누기 */
	if (operator == '/' || operator == '*')
	{

		if (operator == '*')
		{
			calc_result = operand_0 * operand_1;
		}
		else
		{
			calc_result = operand_0 / operand_1;
		}
	}
	else
	{
		printf("ERROR CODE #1\r\n");
	}

	return calc_result;
}

Operand_Checkdef Opcode_Check(Stack *LStack)
{
	int local_buf_1 = 0;
	int local_buf_2 = 0;

	if (SPeek(LStack) == '/' || SPeek(LStack) == '*')
	{
		return OPERAND_1;
	}

	local_buf_1 = SPop(LStack);

	if (SPeek(LStack) == '/' || SPeek(LStack) == '*')
	{
		SPush(LStack, local_buf_1);
		return OPERAND_2;
	}

	local_buf_2 = SPop(LStack);

	if (SPeek(LStack) == '/' || SPeek(LStack) == '*')
	{
		SPush(LStack, local_buf_2);
		SPush(LStack, local_buf_1);
		return OPERAND_3;
	}

	SPush(LStack, local_buf_2);
	SPush(LStack, local_buf_1);

	return OPERAND_ERR;
}

int infix_calc(Stack *LStack)
{

	int operator = 0;
	int operand_1 = 0;
	int operand_2 = 0;
	int operand_3 = 0;
	int calc_result = 0;

	switch (Opcode_Check(LStack))
	{
	case OPERAND_1:

		printf("calc_equal ERROR !!");

		return -1;

	case OPERAND_2:
		operand_1 = SPop(LStack);
		operator = SPop(LStack);
		operand_2 = SPop(LStack);

		calc_result = multi_div_calc(operator, operand_1, operand_2);

		SPush(LStack, calc_result);
		break;

	case OPERAND_3:
		operand_1 = SPop(LStack);
		operand_2 = SPop(LStack);
		operator = SPop(LStack);
		operand_3 = SPop(LStack);

		calc_result = multi_div_calc(operator, operand_2, operand_3);

		SPush(LStack, calc_result);
		SPush(LStack, operand_1);

		break;
	default:
		operand_1 = SPop(LStack);
		operand_2 = SPop(LStack);

		calc_result = operand_1 + operand_2;

		SPush(LStack, calc_result);

		return calc_result;

	}

	return 0xff;
}

int infix_calculator(Stack *LStack)
{
	int result = 0;

	while (LStack->stack_ptr != 0)
	{
		result = infix_calc(LStack);
	}

	return result;

}

