/*
 * main.c
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#include "HeapAPI.h"
#include "stdio.h"
#include "string.h"

HeapStruct HeapStructure;

int main(void)
{
	printf("Start Heap Structure\r");
	HeapInit(&HeapStructure);

	HeapInsert(&HeapStructure, 'B');
	HeapInsert(&HeapStructure, 'D');
	HeapInsert(&HeapStructure, 'G');
	HeapInsert(&HeapStructure, 'E');
	HeapInsert(&HeapStructure, 'C');
	HeapInsert(&HeapStructure, 'A');
	HeapInsert(&HeapStructure, 'F');

	HeapDelete(&HeapStructure, 'A');
	HeapDelete(&HeapStructure, 'B');


}

