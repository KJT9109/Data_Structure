/*
 * Queue.h
 *
 *  Created on: 2020. 11. 22.
 *      Author: Jitae
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_SIZE 256

typedef struct __Queue
{
	int Buf[QUEUE_SIZE];
	int Rear_ptr;
	int Front_ptr;

} Queue;


void Queue_Init(Queue *lqueue);
void EnQueue(Queue *lqueue, int data);
int Dequeue(Queue *lqueue);


#endif /* QUEUE_H_ */
