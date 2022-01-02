#include "BinaryTree.h"

#define TRACE 0

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode*) malloc(sizeof(BTreeNode));
	nd->data = 0xdeadbeef;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode *bt)
{
	return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

void DeleteTree(BTreeNode *bt)
{
	if(bt !=NULL)
		free(bt);
}

BTreeNode* GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL)
	{
	    printf("left free !! \r\n");
	    free(main->left);
	}

	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL)
	{
	    printf("right free !! \r\n");
	    free(main->right);
	}
	main->right = sub;
}

void BTreeInsert(BTreeNode *root, BTData data)
{
    TR_FUNC(TRACE);

    if (GetData(root) == 0xdeadbeef)
    { 
	SetData(root, data);
	return;
    }

    BTreeNode *_localRoot = root;

    /* == Node 찾기 == */
    if ((GetLeftSubTree(_localRoot) != NULL) && (data < GetData(_localRoot)))
    {
	BTreeInsert(GetLeftSubTree(_localRoot), data);
	return;
    }
    else if ((GetRightSubTree(_localRoot) != NULL) && (data > GetData(_localRoot)))
    {
	BTreeInsert(GetRightSubTree(_localRoot), data);
	return;
    }

    /* == 데이터 삽입 == */
    if ((GetLeftSubTree(_localRoot) == NULL) && (data < GetData(_localRoot)))
    {
	BTreeNode *leftNode = MakeBTreeNode();
	MakeLeftSubTree(_localRoot, leftNode);
	SetData(leftNode, data);
    }
    else if ((GetRightSubTree(_localRoot) == NULL) && (data > GetData(_localRoot)))
    {
	BTreeNode *rightNode = MakeBTreeNode();
	MakeRightSubTree(_localRoot, rightNode);
	SetData(rightNode, data);
    }
    else
    {
	printf("BTree Insert Error\r\n");
	while(1);
    }
}

BTreeNode *BTreeSearch(BTreeNode *root, BTData findData)
{
    TR_FUNC(TRACE);

    BTreeNode *_localRoot = root;

    if (GetData(_localRoot) == findData)
	return root;

    else if ((GetLeftSubTree(_localRoot) != NULL) && (findData < GetData(_localRoot)))
	return BTreeSearch(GetLeftSubTree(_localRoot), findData);

    else if ((GetRightSubTree(_localRoot) != NULL) && (findData > GetData(_localRoot)))
	return BTreeSearch(GetRightSubTree(_localRoot), findData);

	printf("BTree Search No Data\r\n");
	return NULL;
}


