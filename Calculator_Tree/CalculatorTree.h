/*
 * CalculatorTree.h
 *
 *  Created on: 2020. 12. 29.
 *      Author: jitae
 */

#ifndef CALCULATORTREE_H_
#define CALCULATORTREE_H_

void PostfixToTree(BTreeNode *curNode, int *char_arr);
BTData CalcOperator(BTData operator_0, BTData operator_1, int opCode);
BTData CalcPostfixToTree(BTreeNode *bt);
BTData ResultPostfixToTree(void);

#endif /* CALCULATORTREE_H_ */
