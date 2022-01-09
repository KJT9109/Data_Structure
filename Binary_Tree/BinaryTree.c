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
    if (bt != NULL)
	return bt->data;
    else
	return 0xdeadbeef;

}

void SetData(BTreeNode *bt, BTData data)
{
    if (bt != NULL)
	bt->data = data;
}

void DeleteTree(BTreeNode *bt)
{
	if (bt !=NULL)
	    free(bt);
}

BTreeNode* GetLeftSubTree(BTreeNode *bt)
{
    if (bt !=NULL)
	return bt->left;
    else
	return NULL;
}

BTreeNode* GetRightSubTree(BTreeNode *bt)
{
    if (bt !=NULL)
	return bt->right;
    else
	return NULL;
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
#define NONODE  0
#define ONENODE 1
#define TWONODE 2

static int _checkChildNode(BTreeNode node)
{
    if((node.left != NULL) && (node.right != NULL))
    {
	printf(" TWONODE \r\n");
	return TWONODE;
    }
    else if (node.left == NULL && node.right == NULL)
    {
	printf(" NONODE \r\n");
	return NONODE;
    }
    else
    {
	printf(" ONENODE \r\n");
	return ONENODE;
    }
}

static BTreeNode *_BTreeSearchWithPNode(BTreeNode **pNode, BTData findData)
{
    TR_FUNC(TRACE);

    BTreeNode *_local_parent_node = *pNode;

    if (GetData(GetLeftSubTree(_local_parent_node)) == findData)
	return GetLeftSubTree(_local_parent_node);

    else if (GetData(GetRightSubTree(_local_parent_node)) == findData)
	return GetRightSubTree(_local_parent_node);

    else if (((*pNode = GetLeftSubTree(_local_parent_node)) != NULL) && (findData < GetData(_local_parent_node)))
	return _BTreeSearchWithPNode(pNode, findData);

    else if (((*pNode = GetRightSubTree(_local_parent_node)) != NULL) && (findData > GetData(_local_parent_node)))
	return _BTreeSearchWithPNode(pNode, findData);

	printf("BTree Search No Data\r\n");
	return NULL;
}

BTData BTreeDelete(BTreeNode *root, BTData findData)
{
    TR_FUNC(TRACE);

    BTreeNode *_local_pNode = root;
    BTreeNode *_local_findNode = NULL;

    /* == Find Data == */
   if((_local_findNode = _BTreeSearchWithPNode(&_local_pNode, findData)) == NULL)
   {
       printf("BTree Search No Data \r\n");
       return 0xdeadbeef;
   }
   else /* == Delete Data == */
   {
       int check = _checkChildNode(*_local_findNode);
       if (check == ONENODE)
       {
       }
       else if (check == TWONODE)
       {
       }
       else if (check == NONODE)
       {
       }
   }
   

   return 0xdeadbeef;
}

