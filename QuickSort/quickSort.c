/*
 * main.c
 *
 *  Created on: 2021. 11. 20
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "stdint.h"
#include "quickSort.h"

#define DEBUG 0
#define TRACE 0

void _changeData(Data *Arg_1, Data *Arg_2)
{
    Data tmp;
    tmp = *Arg_1;
    *Arg_1 = *Arg_2;
    *Arg_2 = tmp;
}

int SortAndFindPivot(Data *arr, int startIdx, int endIdx, compFunc comp)
{
    int _pivotIdx = startIdx;
    int _leftIdx = _pivotIdx + 1;
    int _rightIdx = endIdx;
#if DEBUG
    printf("pivot Idx %d, pivot Data: %d  \
	    leftIdx: %d, rightIdx: %d \r\n",\
	    _pivotIdx, arr[_pivotIdx], \
	    _leftIdx, _rightIdx);
    
    printf("start Sort: ");
    for (int i = startIdx; i <= endIdx; i++)
    {
	printf(" %d",arr[i]);
    }
    printf("\r\n");
#endif
    /* == 1. Pivot을 기준으로 왼쪽, 오른쪽 배열을 정렬하면서 나눈다. == */
    while (_leftIdx < _rightIdx) 
    {
	/* == pivot 보다 큰 데이터를 찾는다. == */
	while ((arr[_pivotIdx] != comp(arr[_leftIdx], arr[_pivotIdx])) && \
		(_leftIdx <= _rightIdx))
	    _leftIdx++;

	/* == pivot 보다 작은 데이터를 찾는다. == */
	while ((arr[_rightIdx] != comp(arr[_rightIdx], arr[_pivotIdx])) && \
		(_leftIdx <= _rightIdx))
	    _rightIdx--;

	_changeData(&arr[_pivotIdx], &arr[_rightIdx]);
#if DEBUG
	printf("Finish Sort: ");
	for (int i = startIdx; i <= endIdx; i++)
	{
	    printf(" %d",arr[i]);
	}
	printf("\r\n");
	printf("leftIdx: %d, rightIdx: %d \r\n", _leftIdx, _rightIdx);
#endif
    }

    return _leftIdx;

}

int quickSort(Data *arr, int startIdx, int endIdx, compFunc comp)
{
    TR_FUNC(TRACE);
    int pivotIdx = SortAndFindPivot(arr, startIdx, endIdx, comp);

    if (pivotIdx > 0 && (endIdx - startIdx > 0))
    {
	quickSort(arr, startIdx, pivotIdx - 1, comp);
	quickSort(arr, pivotIdx, endIdx, comp);
    }

    return 0;

}
