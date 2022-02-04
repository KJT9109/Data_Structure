
#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#define NEED_RX_ROTAION 0
#define NEED_LX_ROTAION 1
#define NEED_XR_ROTAION 2  
#define NEED_XL_ROTAION 3
#define NOT_ROTATION -1
#define ERROR_RETURN -2

void AVLTreeInsert(BTreeNode **root, BTData data);

#endif
