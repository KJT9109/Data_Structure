#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define TR_FUNC(_value_)  \
    if(_value_)            \
    printf("FILENAME:%s, FUNCNAME: %s, LINENUM: %d \r\n" \
	    , __FILE__, __FUNCTION__, __LINE__)

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;


BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);

void DeleteTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);


void BTreeInsert(BTreeNode *root, BTData data);
BTreeNode *BTreeSearch(BTreeNode *root, BTData findData);
BTData BTreeDelete(BTreeNode *root, BTData findData);
#endif
