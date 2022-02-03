#include "BinaryTree.h"
#include "AVLTree.h"

#define TRACE 0

static int AVLcheckDepth(BTreeNode *rootNode)
{
    int depth = 1;

    if (!rootNode)
	return 0;
    else if (rootNode->left == NULL && rootNode->right == NULL)
	return 0;
    else if (rootNode->left != NULL)
	depth += AVLcheckDepth(rootNode->left);
    else if (rootNode->right != NULL)
	depth += AVLcheckDepth(rootNode->right);

    return depth;
}

static int AVLcheckRotation(BTreeNode *rootNode)
{
    TR_FUNC(TRACE);

    int left_val = 0;
    int right_val = 0;
    int diff_val = 0;

    BTreeNode *leftNode = rootNode->left;
    BTreeNode *rightNode = rootNode->right;

    left_val = AVLcheckDepth(leftNode);
    printf("left depth is %d \r\n", left_val);

    right_val = AVLcheckDepth(rightNode);
    printf("right depth is %d \r\n", right_val);

    diff_val = abs(left_val - right_val);

    if (diff_val < 2)
	return NOT_ROTATION;

    return 0;
}

static int AVLBalance(BTreeNode **root)
{
    TR_FUNC(TRACE);

    switch(AVLcheckRotation(*root)) {
	case NEED_RR_ROTAION:
	    printf("RR ROTATION \r\n");
	    break;
	case NEED_LL_ROTAION:
	    printf("LL ROTATION \r\n");
	    break;
	case NOT_ROTATION:
	    printf("NOT ROTATION \r\n");
	    break;
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
    } else if (AVLBalance(rootPointer) < 0 || *rootPointer == NULL) {
	printf("AVLTreeInsert ERROR #1 \r\n");
    }
}


