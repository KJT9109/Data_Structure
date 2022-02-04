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
	return NEED_RX_ROTAION;
    else
	return NEED_LX_ROTAION;

    return ERROR_RETURN;

}

static int AVL_CheckSecondRotation(BTreeNode *rootNode)
{
    TR_FUNC(TRACE);

    if (AVL_CheckDepth(rootNode->left)) 
	return NEED_XL_ROTAION;
    else if (AVL_CheckDepth(rootNode->right))
	return NEED_XR_ROTAION;

    return NOT_ROTATION;
}

static int AVL_ChangeRR(BTreeNode **root, int second_result)
{

    return 0;
}

static int AVL_ChangeLL(BTreeNode **root, int second_result)
{

    return 0;
}

static int AVL_Balance(BTreeNode **root)
{
    TR_FUNC(TRACE);

    int result_1 = AVL_CheckRotation(*root);

    if (result_1 == NEED_RX_ROTAION) {
	printf("RX ROTATION \r\n");
	AVL_ChangeRR(root, AVL_CheckSecondRotation((*root)->right));
    } else if (result_1 == NEED_LX_ROTAION) {
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


