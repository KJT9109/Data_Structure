
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

#define DEBUG 0
#define TRACE 1

int insertBurst(int startIdx, int finIdx, int *out_arr, int *in_arr)
{
    int _localIdx = 0;

    while(startIdx <= finIdx)
    {
	in_arr[_localIdx] = out_arr[startIdx];
	startIdx++;
	_localIdx++;
    }

    return _localIdx;
}

int mergeComp(int *arr, int startIdx, int midIdx, int endIdx, compFunc comp)
{
    int localIdx = 0; //Malloc 으로 잡은 배열의 위치를 가리키는 Index
    int _1st_startIdx = startIdx; // Merge해야할 첫번째 배열의 시작 Index
    int _2nd_startIdx = midIdx; // Merge해야할 두번째 배열의 시작 Index
    int _1st_endIdx = midIdx == 0 ? 0 : midIdx - 1; // Merge 해야할 첫번쨰 배열의 end Index
    int _2nd_endIdx = endIdx; // Merge 해야할 두번째 배열의 end Index
    int *local_arr = malloc((_2nd_endIdx - startIdx + 1) * sizeof(int)); //1, 2배열의 결합 결과


    /* == 첫번째 배열 또는 두번쨰 배열의 시작 인덱스가 end 인덱스를 넘지 않으면 결합한다 == */
    while ((_1st_startIdx <= _1st_endIdx) && (_2nd_startIdx <= _2nd_endIdx))
    {
	if (arr[_1st_startIdx] == comp(arr[_1st_startIdx], arr[_2nd_startIdx]))
	{
	    local_arr[localIdx++] = arr[_1st_startIdx++];
	    /* == 첫번째 배열의 start Index가 증가 되었기 때문에 End Index를 넘었는지 확인한다. == */
	    if (_1st_endIdx < _1st_startIdx)
	    {
		/* == 넘었다면 2번째 배열값들을 local 배열에 집어 넣은 후 break 한다 == */
		localIdx += insertBurst(_2nd_startIdx, _2nd_endIdx, arr, &local_arr[localIdx]);
		break;
	    }
	}
	else
	{
	    local_arr[localIdx++] = arr[_2nd_startIdx++];
	    /* == 두번째 배열의 start Index가 증가 되었기 때문에 End Index를 넘었는지 확인한다. == */
	    if (_2nd_endIdx < _2nd_startIdx)
	    {
		/* == 넘었다면 1번째 배열값들을 local 배열에 집어 넣은 후 break 한다 == */
		localIdx += insertBurst(_1st_startIdx, _1st_endIdx, arr, &local_arr[localIdx]);
		break;
	    }
	}
    }
    /* == localIdx 가 0 이라면 따로 정렬을 하지 않았기에 memory copy를 하지 않는다 == */
    if (localIdx)
    {
	memcpy(&arr[startIdx], local_arr, (localIdx) * sizeof(int));
    }


    free(local_arr);
    return 0;
}

void mergeSort(int *arr, int startIdx, int endIdx, compFunc comp)
{
    TR_FUNC(TRACE);
    int midIdx = (startIdx + endIdx) / 2;

#if DEBUG    
    printf("array value: ");
    for (int i = startIdx; i <=endIdx; i++)
    {
	printf(" %d ", arr[i]);
    }
    printf("\r\n");
#endif

    if (startIdx < endIdx)
    {
	mergeSort(arr, startIdx, midIdx, comp);
	mergeSort(arr, midIdx+1, endIdx, comp);

	mergeComp(arr, startIdx, midIdx+1, endIdx, comp);
    }
}





