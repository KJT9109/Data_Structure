/*
 * mergeSort.c
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "mergeSort.h"


int insertBurst(int startIdx, int finIdx, int *out_arr, int *in_arr)
{
	if(startIdx >= finIdx)
	{
		printf("Idx Error \n");
	}

	while(startIdx < finIdx)
	{
		in_arr[startIdx] = out_arr[startIdx];
		startIdx++;
	}

	return 0;
}

int mergeComp(int *arr, int size, compFunc comp)
{
	int *local_arr = malloc(size * sizeof(int));
	int compIdx = (size / 2);
	int compIdxFin = size;
	int startIdx = 0;
	int startIdxFin = compIdx;
	int localIdx = 0;

#if 1
	if(*arr == 10)
	{
		printf("Debug code %d \n", *arr);
	}
#endif

	while((startIdx < startIdxFin) && (compIdx < compIdxFin))
	{
		if (arr[startIdx] == comp(arr[startIdx], arr[compIdx]))
		{
			local_arr[localIdx++] = arr[startIdx++];

			if (startIdx == startIdxFin)
			{
				insertBurst(compIdx, compIdxFin, arr, local_arr);
			}
		}
		else
		{
			local_arr[localIdx++] = arr[compIdx++];

			if (compIdx == compIdxFin)
			{
				insertBurst(startIdx, startIdxFin, arr, &local_arr[localIdx]);
			}
		}
	}

	memcpy(arr, local_arr, size * sizeof(int));
	free(local_arr);

	return 0;
}


int mergeSort(int *arr, int size, compFunc comp)
{

	int startIdx = 0;
	int centerIdx = (size / 2);

	if (startIdx < centerIdx)
	{
		mergeSort(arr, size/2, comp);
		mergeSort(arr+centerIdx, size/2, comp);

		mergeComp(arr, size, comp);
	}

	return 1;
}

