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

/* @bref     Linked List 초기화 함수
 * @detail  첫 head를 구별하기 위해 head의 데이터는 deadbeef로 하였다.
 *
 * @retval  head의 주소
 */
Node *linkedListInit()
{
    Node *_new = malloc(sizeof(Node));

    _new->next = NULL;
    _new->data = 0xdeadbeef;

    return _new;
}

/* @bref    Linked List Insert 함수
 * @detail  Malloc으로 Node를 할당 받은 다음 연결한다.
 *          Malloc된 메모리에 데이터를 추가한다.
 *
 * @param   head: 연결 해야할 Node
 *          data: 추가해야 할 데이터
 *
 * @retval  None      
 */ 
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

/**
 * @bref     LinkedList 데이터 꺼내는 함수
 * @detail   LIFO 구조이므로 next가 엎을 때 까지
 *           찾은 다음 해당 데이터를 가지고 온 다음 free 한다.
 *           0xdeadbeef일 경우 header 이므로 제거하지 않고 return 한다.
 *
 * @retval   Data
 */          
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

/**
 * @bref     LinkedList 데이터 꺼내는 함수
 * @detail   FIFO 구조이므로 head의 첫번째 Node 값을 가지고 온다음 free 한다.
 *           데이터가 0xdeadbeef일 경우 header 이므로 제거하지 않는다.
 *
 * @retval   Data
 */          
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

