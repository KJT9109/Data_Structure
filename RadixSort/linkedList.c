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
    _new->data = 0xdeadbeef;

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

    _new->data = data;
    _local->next = _new;
    _new->next = NULL;

    return 0;
}

int linkedListGet_LIFO(Node *head, bool data_del)
{
    Node *_local = head;
    Node *_before_node = NULL;
    int ret = 0;

    while (_local != NULL &&_local->next != NULL)
    {
	_before_node = _local;
	_local = _local->next;
    }

    ret = _local->data;
    
    if( data_del == true &&_local != NULL &&_local->data != 0xdeadbeef)
    {
	if (_before_node)
	    _before_node->next = NULL;

	free(_local);
    }

    return ret;
}

int linkeListGet_FIFO(Node *head, bool data_del)
{
    Node *_local = head;
    int ret = 0;

    ret = head->data;

    if (ret == 0xdeadbeef && _local->next != NULL)
    {
	_local = _local->next;
	ret = _local->data;
    }

    if (data_del == true && _local->data != 0xdeadbeef)
    {
	head->next = _local->next;
	
	free(_local);
    }

    return ret;
}

