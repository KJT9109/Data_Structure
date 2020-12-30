#include <stdio.h>
#include "BinaryTree.h"
#include "stack.h"
#include "postfix.h"
#include "CalculatorTree.h"

int main(void)
{
	printf("start CalcTree\r\n");

	char *calcEqualtion1 =
	{ "1+2*3+4*5" };
	char *calcEqualtion2 =
	{ "51-8/(3+4*2/8)*3+2" };
	char *calcEqualtion3 =
	{ "51-8/(3*4-4)-20" };
	char *calcEqualtion4 =
	{ "50+400/(401+400-800+(400+400-800))" };

	printf("TEST is %d \n", ResultPostfixToTree(calcEqualtion1));
	printf("TEST is %d \n", ResultPostfixToTree(calcEqualtion2));
	printf("TEST is %d \n", ResultPostfixToTree(calcEqualtion3));
	printf("TEST is %d \n\r", ResultPostfixToTree(calcEqualtion4));

	printf("exit\n");
}
