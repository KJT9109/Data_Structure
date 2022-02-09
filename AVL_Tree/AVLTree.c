#include "BinaryTree.h"
#include "AVLTree.h"

#define TRACE 0

static int AVL_CheckDepth(BTreeNode *rootNode)
{
    int depth = 1;

    if (!rootNode)
	return 0;
    else if (rootNode->left == NULL && rootNode->right == NULL)
	return 0;
    else if (rootNode->left != NULL)
	depth += AVL_CheckDepth(rootNode->left);
    else if (rootNode->right != NULL)
	depth += AVL_CheckDepth(rootNode->right);

    return depth;
}

static int AVL_CheckRotation(BTreeNode *rootNode)
{
    TR_FUNC(TRACE);

    int left_val = 0;
    int right_val = 0;
    int diff_val = 0;

    BTreeNode *leftNode = rootNode->left;
    BTreeNode *rightNode = rootNode->right;

    left_val = AVL_CheckDepth(leftNode);
    printf("left depth is %d \r\n", left_val);

    right_val = AVL_CheckDepth(rightNode);
    printf("right depth is %d \r\n", right_val);

    diff_val = abs(left_val - right_val);

    if (diff_val < 2)
	return NOT_ROTATION;
    else if (right_val > left_val)
	return NEED_RX_ROTATION;
    else
	return NEED_LX_ROTATION;

    return ERROR_RETURN;

}

static int AVL_CheckSecondRotation(BTreeNode *rootNode)
{
    TR_FUNC(TRACE);

    if (AVL_CheckDepth(rootNode->left)) 
	return NEED_XL_ROTATION;
    else if (AVL_CheckDepth(rootNode->right))
	return NEED_XR_ROTATION;

    return NOT_ROTATION;
}

static int AVL_ChangeRR(BTreeNode **root, int second_result)
{
    
    BTreeNode **returnRoot = root;
    BTreeNode *checkRoot = (*root)->right; 
    BTreeNode *originRoot = *root;

    if (!(checkRoot)) {
	return -1;
    } else if (second_result == NEED_XR_ROTATION) {
	/* == Change ReBalance == */
	BTreeNode *newRoot = (*root)->right; 

	originRoot->right = newRoot->left;
	newRoot->left = originRoot;
	*returnRoot = newRoot;
    } else if (second_result == NEED_XL_ROTATION) {
	/* == Change R -> L == */
	BTreeNode *originPNode = originRoot->right;
	BTreeNode *originCNode = originPNode->left;
	BTreeNode *mvNode = originCNode->right;

	originRoot->right = originCNode;
	originCNode->right = originPNode;
	originPNode->left = mvNode;

	/* == Change ReBalance == */
	BTreeNode *newRoot = (*root)->right; 

	originRoot->right = newRoot->left;
	newRoot->left = originRoot;
	*returnRoot = newRoot;
    }

    return 0;
}

static int AVL_ChangeLL(BTreeNode **root, int second_result)
{
    BTreeNode **returnRoot = root;
    BTreeNode *originRoot = *root;
    BTreeNode *checkRoot = (*root)->left; 

    if (!(checkRoot)) {
	return -1;
    } else if (second_result == NEED_XL_ROTATION) {
	/* == Change ReBalance == */
	BTreeNode *newRoot = (*root)->left; 

	originRoot->left = newRoot->right;
	newRoot->right = originRoot;
	*returnRoot = newRoot;
    } else if (second_result == NEED_XR_ROTATION) {
	/* == Change L -> R == */
	BTreeNode *originPNode = originRoot->left;
	BTreeNode *originCNode = originPNode->right;
	BTreeNode *mvNode = originCNode->left;

	originRoot->left = originCNode;
	originCNode->left = originPNode;
	originPNode->right = mvNode;

	/* == Change ReBalance == */
	BTreeNode *newRoot = (*root)->left; 

	originRoot->left = newRoot->right;
	newRoot->right = originRoot;
	*returnRoot = newRoot;
    }

    return 0;
}

static int AVL_Balance(BTreeNode **root)
{
    TR_FUNC(TRACE);

    int result_1 = AVL_CheckRotation(*root);

    if (result_1 == NEED_RX_ROTATION) {
	printf("RX ROTATION \r\n");
	AVL_ChangeRR(root, AVL_CheckSecondRotation((*root)->right));
    } else if (result_1 == NEED_LX_ROTATION) {
	printf("LX ROTATION \r\n");
	AVL_ChangeLL(root, AVL_CheckSecondRotation((*root)->left));
    } else {
	printf("NOT ROTATION \r\n");
    }

    return 0;
}

void AVLTreeInsert(BTreeNode **root, BTData data)
{
    TR_FUNC(TRACE);

    BTreeNode **rootPointer = root;
    BTreeNode *rootNode = *root;

    BTreeInsert(rootNode, data);
    /* == Re Balance == */
    if (!rootPointer) {
	printf("AVLTreeInsert ERROR #0 \r\n");
    } else if (AVL_Balance(rootPointer) < 0 || *rootPointer == NULL) {
	printf("AVLTreeInsert ERROR #1 \r\n");
    }
}


