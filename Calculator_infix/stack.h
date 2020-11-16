/*
 * stack.h
 *
 *  Created on: 2020. 10. 21.
 *      Author: jitae
 */

#ifndef STACK_H_
#define STACK_H_

#include "stdio.h"
#include "stddef.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"



#define STACK_SIZE 50

typedef int Data;

typedef struct __Stack
{
	int buf[STACK_SIZE];
	int stack_ptr;

} Stack;

void StackInit(Stack *pstack);
void Show_Stack(Stack *pstack);
void SPush(Stack *pstack, Data data);

int sIsEmpty(Stack *pstack);

Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif /* STACK_H_ */
