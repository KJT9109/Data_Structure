/*
 * linkedList.c
 *
 *  Created on: 2021. 12. 08
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "linkedList.h"

#define DEBUG 0
#define TRACE 0

Node *linkedListInit()
{
     Node *_new = malloc(sizeof(Node));

    _new->next = NULL;
    _new->data = 0;

    return _new;
}

int linkedListInsert(Node *head, int data)
{
     Node *_new = malloc(sizeof( Node));
     Node *_local = head;


    while (_local->next != NULL)
    {
	_local = _local->next;
    }

    _local->data = data;
    _local->next = _new;
    _new->next = NULL;

    return 0;
}
