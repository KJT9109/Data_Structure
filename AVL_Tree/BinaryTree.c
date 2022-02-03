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

int DeleteTree(BTreeNode *bt)
{
    if (bt == NULL) {
	printf("Delete Error #0 \r\n");
	return -1;
    }
    else if (bt->left != NULL || bt->right != NULL) {
	printf("Delete Error #1 \r\n");
	return -2;
    }
    else {
	bt->data = 0xdeadbeef;
	free(bt);
	return 0;
    }
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
    if (main->left != NULL) {
	printf("left free !! \r\n");
	free(main->left);
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if (main->right != NULL) {
	printf("right free !! \r\n");
	free(main->right);
    }
    main->right = sub;
}

void BTreeInsert(BTreeNode *root, BTData data)
{
    TR_FUNC(TRACE);

    if (GetData(root) == 0xdeadbeef) { 
	SetData(root, data);
	return;
    }

    BTreeNode *_localRoot = root;

    /* == Node 찾기 == */
    if ((GetLeftSubTree(_localRoot) != NULL) && (data < GetData(_localRoot))) {
	BTreeInsert(GetLeftSubTree(_localRoot), data);
	return;
    }
    else if ((GetRightSubTree(_localRoot) != NULL) && (data > GetData(_localRoot))) {
	BTreeInsert(GetRightSubTree(_localRoot), data);
	return;
    }

    /* == 데이터 삽입 == */
    if ((GetLeftSubTree(_localRoot) == NULL) && (data < GetData(_localRoot))) {
	BTreeNode *leftNode = MakeBTreeNode();
	MakeLeftSubTree(_localRoot, leftNode);
	SetData(leftNode, data);
    }
    else if ((GetRightSubTree(_localRoot) == NULL) && (data > GetData(_localRoot))) {
	BTreeNode *rightNode = MakeBTreeNode();
	MakeRightSubTree(_localRoot, rightNode);
	SetData(rightNode, data);
    }
    else {
	printf("BTree Insert Error\r\n");
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

    printf("BTree Search No Data #0\r\n");
    return NULL;
}
#define NONODE        0
#define LEFTONENODE   1
#define RIGHTONENODE  2
#define TWONODE       3

static int _checkChildNode(BTreeNode node)
{
    if((node.left != NULL) && (node.right != NULL)) {
	printf(" TWONODE \r\n");
	return TWONODE;
    }
    else if (node.left == NULL && node.right == NULL) {
	printf(" NONODE \r\n");
	return NONODE;
    }
    else if (node.left != NULL && node.right == NULL) {
	printf(" Left ONENODE \r\n");
	return LEFTONENODE;
    }
    else if (node.left == NULL && node.right != NULL) {
	printf(" Right ONENODE \r\n");
	return RIGHTONENODE;
    }
    else {
	printf(" _checkChildNode ERROR !! \r\n");
	return -1;
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

    printf("BTree Search No Data #1\r\n");
    return NULL;
}

static BTreeNode *findLargeValueTree(BTreeNode *Node)
{
    while (Node->right)
	Node = findLargeValueTree(Node->right);

    printf("Find Large Value: %d \r\n", Node->data);

    return Node;
}


BTData BTreeDelete(BTreeNode *root, BTData findData)
{
    TR_FUNC(TRACE);

    BTreeNode *_local_pNode = root;
    BTreeNode *_local_findNode = NULL;

    /* == Find Data == */
    if((_local_findNode = _BTreeSearchWithPNode(&_local_pNode, findData)) == NULL) {
	printf("BTree Search No Data #2\r\n");
	return 0xdeadbeef;
    }
    /* == Delete Data == */
    else {
	int check = _checkChildNode(*_local_findNode);

	if (check < 0) {
	    printf(" BTreeDelete ERROR \r\n");
	}
	/* == 삭제 할 노드의 자식 노드가 left만 있을 때 == */
	else if (check == LEFTONENODE) {
	    _local_pNode->left = _local_findNode->left;
	    if (!(DeleteTree(_local_findNode) < 0)) {
		printf(" Delete Sucess !! (left one Node) \r\n");
	    }
	}
	/* == 삭제 할 노드의 자식 노드가 right만 있을 때 == */
	else if (check == RIGHTONENODE) {
	    _local_pNode->right = _local_findNode->right;
	    if (!(DeleteTree(_local_findNode) < 0)) {
		printf(" Delete Sucess !! (right one Node) \r\n");
	    }
	}
	/* == 삭제 할 노드의 자식 노드가 둘다 있을 때 == */
	else if (check == TWONODE) {
	    BTreeNode *_largeNode = findLargeValueTree(_local_findNode->left); 
	    /* == largeNode의rightNode가 있을 순 없다 (더 큰수 이기 때문에) == */
	    if (_largeNode->left) {
		_local_findNode->left = _largeNode->left;
		_largeNode->left = NULL;
	    }	

	    _local_findNode->data = _largeNode->data;
	    if (!(DeleteTree(_largeNode) < 0)) {
		printf(" Delete Sucess !! (Two Node) \r\n");
	    }
	}
	else if (check == NONODE) {
	    if (!(DeleteTree(_local_findNode) < 0)) {
		printf(" Delete Sucess !! (No Node) \r\n");
	    }
	}
    }

    return 0xdeadbeef;
}

