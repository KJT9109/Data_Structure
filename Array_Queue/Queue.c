/*
 * Queue.c
 *
 *  Created on: 2020. 11. 22.
 *      Author: Jitae
 */

#include "Queue.h"
#include "string.h"
#include "stdio.h"

void Queue_Init(Queue *lqueue)
{
	memset(lqueue->Buf, 0, QUEUE_SIZE);

	lqueue->Front_ptr = 0;
	lqueue->Rear_ptr = 0;
}

int Qptr_increase(int tmp)
{
	if (tmp + 1 == QUEUE_SIZE)
	{
		return 0;
	}
	else
	{

		return ++tmp;
	}

}

void EnQueue(Queue *lqueue, int data)
{

	if (Qptr_increase(lqueue->Rear_ptr) == lqueue->Front_ptr)
	{
		printf("QUEUE Buf is FULL \r\n");
		return;
	}
	else
	{
		lqueue->Rear_ptr = Qptr_increase(lqueue->Rear_ptr);
		lqueue->Buf[lqueue->Rear_ptr] = data;
	}

}

int Dequeue(Queue *lqueue)
{

	if (lqueue->Front_ptr == lqueue->Rear_ptr)
	{
		printf("QUEUE Buf is EMPTY \r\n");
		return -1;
	}
	else
	{
		lqueue->Front_ptr = Qptr_increase(lqueue->Front_ptr);

		return lqueue->Buf[lqueue->Front_ptr];
	}

	return 0;
}
