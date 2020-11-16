#include "postfix.h"

#include "stack.h"
#include "stdlib.h"

int Postfix_Calc(int *char_arr, int length)
{
	int index;
	int result;

	int operator_0;
	int operator_1;

	Stack LStack, NStack;

	StackInit(&LStack);
	StackInit(&NStack);

	/* 배열의 index 크기를 구한다. */
	for (index = 0; char_arr[index] != 0; index++)
		;

	/* 배열을 끝에서 부터 Stack 에 옮긴다 */
	while (index >= 0)
	{
		SPush(&LStack, char_arr[index--]);
	}

	/* 후위표현법으로 변경되어 저장된 Stack을 다음과 같이 처리한다..*/
	while (LStack.stack_ptr != 0)
	{
		/*일반 숫자라면  Stack에 PUSH 한다.*/
		if (SPeek(&LStack) != '*' && SPeek(&LStack) != '+'
				&& SPeek(&LStack) != '-' && SPeek(&LStack) != '/')
		{
			SPush(&NStack, SPop(&LStack));
		}
		else
		{
			/*연산 부호라면 다음과 같이 계산한다.*/
			switch (SPop(&LStack))
			{
			case '*':
				operator_0 = SPop(&NStack);
				operator_1 = SPop(&NStack);
				result = operator_1 * operator_0;
				SPush(&NStack, result);
				break;

			case '/':
				operator_0 = SPop(&NStack);
				operator_1 = SPop(&NStack);
				result = operator_1 / operator_0;
				SPush(&NStack, result);
				break;

			case '+':
				operator_0 = SPop(&NStack);
				operator_1 = SPop(&NStack);
				result = operator_1 + operator_0;
				SPush(&NStack, result);
				break;

			case '-':
				operator_0 = SPop(&NStack);
				operator_1 = SPop(&NStack);
				result = operator_1 - operator_0;
				SPush(&NStack, result);
				break;

			}
		}

	}
	/*Stack Pointer가 1개 남았으면 마지막 결과 값이므로 그 값을 Return 한다. */
	return SPop(&NStack);
}

/* ASCII 값을 INT형으로 변경한다. */
int STRtoINT(char *char_arr, int *local_arr)
{
	int num = 0;
	int arr = 0;
	int int_len = 0;

	while (*char_arr != '\0')
	{
		if (*char_arr > '0' && *char_arr <= '9')
		{
			num = strtoul(char_arr, &char_arr, 10);

			local_arr[arr++] = num;

			int_len++;
		}
		else
		{
			local_arr[arr++] = (int) *char_arr;
			char_arr += 1;

			int_len++;
		}

	}

	return int_len;
}

/* 연산부호의 우선순위를 Return 하는 함수. */
int calc_op_check(int num)
{
	switch (num)
	{
	case '(':
	case ')':
		return 1;

	case '+':
	case '-':
		return 3;

	case '*':
	case '/':
		return 5;

	default:
		return num;

	}
}

/*
 *  / : 47(INT)
 *  + : 43(INT)
 *  - : 45(INT)
 *  * : 42(INT)
 *
 *  ( : 40(INT)
 *  ) : 41(INT)
 *
 * */

/* 후위표현법으로 변경한다. */
int* Postfix_func(int *char_arr, int len)
{
	Stack Calc_Stack;
	int calc_array[ARRAY_SIZE];
	int index = 0;
	int arr = 0;
	int calc_len = 0;

	StackInit(&Calc_Stack);
	memset(calc_array, 0, ARRAY_SIZE);

	calc_len = len;

	while (len--)
	{
		/* 배열에 index 값이 그냥 숫자 라면 */
		if (calc_op_check(char_arr[arr]) == char_arr[arr])
		{
			/* 그냥 ARRAY에 집어 넣는다. */
			calc_array[index++] = char_arr[arr];
			/* INDEX를 증가시킨다. */
			arr++;

		}
		/* 연산 부호이고 현자 연산 스택에 저장된 값이 없으면  */
		else if (Calc_Stack.stack_ptr == -1)
		{
			SPush(&Calc_Stack, char_arr[arr]);
			arr++;
		}
		else
		{
			/* Stack에 들어있는 연산자 순위가 들어올 우선순위의 연산자 순위보다 높거나 같으면
			 * 계속 배열에 집어넣는다 (자기보다 낮은 우선순위 연산자가 나오거나 바닥일 때 까지!!)  */
			while (calc_op_check(SPeek(&Calc_Stack))
					>= calc_op_check(char_arr[arr])
					&& calc_op_check(char_arr[arr]) != 1)
			{
				/*연산 스택에서 제거 후 일반 배열에 넣는다. */
				calc_array[index++] = SPop(&Calc_Stack);
			}

			/* 그 다음 연산 스택에 집어 넣는다.*/
			SPush(&Calc_Stack, char_arr[arr]);

			/*집어 넣는 연산자가 닫는 괄호라면 */
			if (char_arr[arr] == ')')
			{
				/*제거 후 */
				SPop(&Calc_Stack);

				/* 여는 괄호가 나올 때 까지 연산자 스택에 있는 값들을 배열에 넣는다.*/
				while (SPeek(&Calc_Stack) != '(')
				{
					calc_array[index++] = SPop(&Calc_Stack);

				}

				/* 여는 괄호 제거 */
				SPop(&Calc_Stack);

				/*여는 괄호를 가리키고 있으므로 index +1을 한다.*/
				arr++;
			}
			else
			{
				/*일반 연산 기호이면 +1을 한다 여기서 하는 이유는 닫는 괄호 확인 후 처리 하기 위해*/
				arr++;
			}

		}

	}

	while (Calc_Stack.stack_ptr != -1)
	{
		calc_array[index++] = SPop(&Calc_Stack);
	}

	return (int*) memcpy(char_arr, calc_array, calc_len * (sizeof(int)));

}

