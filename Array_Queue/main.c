/*
 * main.c
 *
 *  Created on: 2020. 11. 22.
 *      Author: Jitae
 */


#include "stdio.h"
#include "stdint.h"

#include "Queue.h"


Queue KQueue;

int main(void)
{

	Queue_Init(&KQueue);

	printf("Data is %d \r\n", Dequeue(&KQueue));


	for(int i = 0; i < QUEUE_SIZE; i++)
		EnQueue(&KQueue, i);


	for(int i = 0; i < QUEUE_SIZE; i++)
	printf("Data is %d \r\n", Dequeue(&KQueue));



	printf("Data is %d \r\n", Dequeue(&KQueue));
	printf("Data is %d \r\n", Dequeue(&KQueue));


}
