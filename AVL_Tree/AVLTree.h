
#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#define NEED_RR_ROTAION 0
#define NEED_LL_ROTAION 1
#define NEED_LR_ROTAION 2
#define NEED_RL_ROTAION 3 
#define NOT_ROTATION 4

void AVLTreeInsert(BTreeNode **root, BTData data);

#endif
