/*
 * linkedList.h
 *
 *  Created on: 2021. 12.06
 *      Author: Jitae Kim
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct _Node {
    struct _Node *next;
    int data;
}Node;

Node *linkedListInit();
int linkedListInsert(Node *head, int data);

#endif
