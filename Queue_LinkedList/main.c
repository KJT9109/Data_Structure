/*
 * main.c
 *
 *  Created on: 2020. 11. 23.
 *      Author: jitae
 */

#include "Linked_Queue.h"
#include "string.h"
#include "stdio.h"


int main(void)
{
	LQueue_Struct LQueue;

	LQueue_init(&LQueue);

	EnLQueue(&LQueue, 10);
	EnLQueue(&LQueue, 20);
	EnLQueue(&LQueue, 30);
	printf("Deleted Data is %d \r\n", DeLQueue(&LQueue));
	EnLQueue(&LQueue, 40);
	EnLQueue(&LQueue, 50);
	EnLQueue(&LQueue, 30);
	EnLQueue(&LQueue, 40);

	printf("Start\r\n");

	while(LQueue.front != LQueue.rear)
	printf("Deleted Data is %d \r\n", DeLQueue(&LQueue));

}




