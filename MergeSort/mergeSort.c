/*
 * mergeSort.c
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#include "mergeSort.h"

int mergeSort(int *arr, int size, compFunc comp)
{

	int leftIdx = 0;
	int rightIdx = (size / 2);

	if (leftIdx < rightIdx)
	{
		mergeSort(arr, size/2, comp);
		mergeSort(arr+rightIdx, size/2, comp);

		if (*(arr) == 7)
			return 2;
	}

	return 1;
}

