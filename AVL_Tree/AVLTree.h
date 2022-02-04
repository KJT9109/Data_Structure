
#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#define NEED_RX_ROTATION 0
#define NEED_LX_ROTATION 1
#define NEED_XR_ROTATION 2  
#define NEED_XL_ROTATION 3
#define NOT_ROTATION -1
#define ERROR_RETURN -2

void AVLTreeInsert(BTreeNode **root, BTData data);

#endif
