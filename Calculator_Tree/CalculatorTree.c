/*
 * CalculatorTree.c
 *
 *  Created on: 2020. 12. 29.
 *      Author: jitae
 */

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "CalculatorTree.h"
#include "stack.h"
#include "postfix.h"

void PostfixToTree(BTreeNode *curNode, int *char_arr)
{
	BTreeNode *changeNode;
	int index;
	/* 배열의 index 크기를 구한다. */
	index = GetIndex(char_arr);
	/* 배열의 Data가 숫자이고 right Node가  NULL 값이 이라면 */
	if ((char_arr[index] > 0 && curNode->right == NULL) && index >= 0)
	{
		BTreeNode *bt_num = MakeBTreeNode();
		SetData(bt_num, char_arr[index]);
		MakeRightSubTree(curNode, bt_num);
		char_arr[index] = 0;
		PostfixToTree(curNode, char_arr);
	}
	/* 배열의 Data가 숫자이고 right Node에 값이 채워져 있다면 */
	else if ((char_arr[index] > 0 && curNode->left == NULL) && index >= 0)
	{
		BTreeNode *bt2_num = MakeBTreeNode();
		SetData(bt2_num, char_arr[index]);
		MakeLeftSubTree(curNode, bt2_num);
		char_arr[index] = 0;
		return;
	}

	/* 배열의 Data가 연산자라면 */
	else if (char_arr[index] < 0 && index >= 0)
	{
		BTreeNode *bt_op = MakeBTreeNode();
		SetData(bt_op, char_arr[index]);

		/* Left Node가 비어 있다면. */
		if (curNode->left == NULL)
		{
			/* Left Node에 넣어준다. */
			MakeLeftSubTree(curNode, bt_op);
		}
		else
		{	/* Left Node에 비어있지 않다면 오른쪽에 넣어준다.. */
			MakeRightSubTree(curNode, bt_op);
		}
		char_arr[index] = 0;
		PostfixToTree(bt_op, char_arr);
	}

	index = GetIndex(char_arr);

	/* 재귀함수를 종료하기 위한 조건문 */
	if ((curNode->left != NULL && curNode->right != NULL) || index < 0)
	{
		return;
	}

	/* 위 조건문을 만족하지 못했다면 비어있는노드가 있다는 뜻이므로 연산순서를 위해 바꿔준다. */
	changeNode = curNode->left;
	curNode->left = curNode->right;
	curNode->right = changeNode;

	/*다시 함수를 호출하여 비어있는 노드에 숫자나 연산자를 채워준다. */
	PostfixToTree(curNode, char_arr);

	return;

}


BTData CalcOperator(BTData operator_1, BTData operator_0, int opCode)
{
#define result 0
	switch (opCode)
	{
	case MULTI:

		return operator_1 * operator_0;

	case DIVID:

		return operator_1 / operator_0;

	case PLUS:

		return operator_1 + operator_0;

	case MINUS:

		return operator_1 - operator_0;

	case result:
		return operator_1;

	default:
		printf("opCode ERROR #! \r");
		return 0;
	}

}

BTData CalcPostfixToTree(BTreeNode *bt)
{
	BTData LeftData, RightData;

	/* Left 노드가 NULL 값이 아니고 data가 연산자 일 경우 숫자가 나올 때 까지 들어간다. */
	if (bt->left != NULL && bt->left->data < 0)
	{
		CalcPostfixToTree(bt->left);
	}
	/* Right 노드가 NULL 값이 아니고 data가 연산자 일 경우 숫자가 나올 때 까지 들어간다. */
	if (bt->right != NULL && bt->right->data < 0)
	{
		CalcPostfixToTree(bt->right);
	}
	/* 제일 바닥까지 왔으면 연산을 시작한다. */
	if (bt->left != NULL && bt->right != NULL)
	{
		LeftData = GetData(bt->left);
		DeleteTree(bt->left);
		RightData = GetData(bt->right);
		DeleteTree(bt->right);
		bt->data = CalcOperator(LeftData, RightData, bt->data);
	}

	/* 최종 결과 값을 Return 한다. */
	return bt->left->data;
}

BTData ResultPostfixToTree(char *calc_equal)
{
	BTreeNode *RootNode = MakeBTreeNode();

	int length = 0;
	int normal_array[ARRAY_SIZE];
	memset(normal_array, 0, ARRAY_SIZE);

	/* String 문자를 INT 형으로 변환 */
	length = STRtoINT(calc_equal, normal_array);

	/* 후기표현법으로 수식 변환 */
	Postfix_func(normal_array, length);

	/* 후기표현한 식을 트리로 변환 */
	PostfixToTree(RootNode, normal_array);

	/* 변환한 트리를 계산하여 결과값을 Return 한다. */
	return CalcPostfixToTree(RootNode);

}

