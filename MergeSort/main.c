/*
 * main.c
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "string.h"
#include "mergeSort.h"

int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

int comp(int val1, int val2)
{
	int temp = 0;

	return temp = val1 > val2 ? val2 : val1;
}

int main(void)
{
	printf("Start Merge Sort \r");

	mergeSort(array, sizeof(array)/sizeof(int), comp);

	return 0;
}
