/*
 * main.c
 *
 *  Created on: 2022. 01. 2.
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "string.h"
#include "BinaryTree.h"
#include "AVLTree.h"

//int array[] = {17, 9, 25, 11, 29, 10, 22, 18, 21};
int array[] = {17, 15, 13, 12, 11, 19};


int main(void)
{
    printf("Binary Tree !! \r\n");

    BTreeNode *root = MakeBTreeNode();
   
    for (int idx = 0; idx < (sizeof(array) / sizeof(int)); idx++)
    {
	printf("Insert Data: %d \r\n", array[idx]);
	AVLTreeInsert(&root, array[idx]);
    }

    BTreeNode *findNode = BTreeSearch(root, 22);

    if (findNode == NULL)
	printf("Can not find Data \r\n");

    else
	printf("findData: %d \r\n", findNode->data);

    BTreeDelete(root, 25);
    
    return 0;
}

