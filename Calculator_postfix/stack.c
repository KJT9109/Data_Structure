/*
 * stack.c
 *
 *  Created on: 2020. 10. 21.
 *      Author: jitae
 */


#include "stack.h"



void StackInit(Stack *pstack)
{

	for (int i = 0; i < STACK_SIZE; i++)
	{
		pstack->buf[i] = 0;
	}


	pstack->stack_ptr = -1;
}

int sIsEmpty(Stack *pstack)
{
	return pstack->stack_ptr;
}

void Show_Stack(Stack *pstack)
{
	printf("Show Stack \r\n");

	for(int i = 0; i < STACK_SIZE; i++)
	{
		printf("%d ", pstack->buf[i]);
	}
	printf("\r\n");
}

void SPush(Stack *pstack, Data data)
{
	pstack->stack_ptr++;

	if (pstack->stack_ptr < STACK_SIZE)
	{
		printf("Push Stack \r\n");
		pstack->buf[pstack->stack_ptr] = data;
	}
	else
	{
		printf("Stack is Full \r\n");
		pstack->stack_ptr--;
	}
}

Data SPop(Stack *pstack)
{
	Data local_buf;

	if (sIsEmpty(pstack) < 0)
	{
		printf("Stack is Empty \r\n");
		return 0;
	}
	else
	{
		printf("Pop Stack \r\n");
		local_buf = pstack->buf[pstack->stack_ptr];
		pstack->buf[pstack->stack_ptr--] = 0;

		return local_buf;
	}
}

Data SPeek(Stack *pstack)
{
	if (sIsEmpty(pstack) < 0)
	{
		printf("Stack is Empty \r\n");
		return -1;
	}
	else
	{
		return pstack->buf[pstack->stack_ptr];
	}

}

