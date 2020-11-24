/*
 * Link_Queue.c
 *
 *  Created on: 2020. 11. 23.
 *      Author: jitae
 */

#include "LinkedList.h"
#include "Linked_Queue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void LQueue_init(LQueue_Struct *lqueue)
{
	lqueue->body = (LinkedList*) malloc(sizeof(LinkedList));
	lqueue->body->data = '\0';
	lqueue->front = lqueue->body;
	lqueue->rear = lqueue->body;
}

void EnLQueue(LQueue_Struct *lqueue, int data)
{
	lqueue->rear = (LinkedList*) malloc(sizeof(LinkedList));  //1번

	lqueue->rear->data = data; //2번

	lqueue->body->next = lqueue->rear; //3번

	lqueue->body = lqueue->rear; //4번

}

int DeLQueue(LQueue_Struct *lqueue)
{
	LinkedList *DelList;

	DelList = lqueue->front;   //1번

	lqueue->front = lqueue->front->next;  //2번

	free(DelList); //3번

	return lqueue->front->data; //4번

}



