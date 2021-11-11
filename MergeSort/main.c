/*
 * main.c
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "string.h"
#include "mergeSort.h"

int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int comp(int val1, int val2)
{
	int temp = 0;

	return temp = val1 > val2 ? val1 : val2;
}

int main(void)
{
	printf("Start Merge Sort \r");

	printf("Before array value: ");
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		printf(" %d", array[i]);
	}
    printf("\r\n");

	mergeSort(array, sizeof(array)/sizeof(int), comp);

	printf("After array value: ");

    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		printf(" %d", array[i]);
	}
    printf("\r\n");

	return 0;
}

