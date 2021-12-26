/*
 * radixSort.c
 *
 *  Created on: 2021. 12. 06
 *      Author: Jitae Kim
 */


#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "radixSort.h"

#define DEBUG 0
#define TRACE 0 


/* @bref     bucket 기수의 판단 기준
 * @detail   각 자릿수의 맞게 bucket index를 구한다.
 * 
 * @param    digit: 자릿수
 *           data: 판단해야할 data
 *
 * @retval   bucket index
 */
Data bucketIndex(int digit, Data data)
{
    Data ret = 0;
    Data tmp1 = 0;
    Data tmp2 = 0;
    
    switch (digit)
    {
	case 1:
	    ret = data % 10;
	    break;
	case 2:
	    tmp1 = data % 10; 
	    tmp2 = (data - tmp1) / 10; 
	    ret = tmp2 % 10;
	    break;
	case 3:
	    tmp1 = data % 100; 
	    tmp2 = (data - tmp1) / 100;
	    ret = tmp2;
	    break;

	default:
	    break;
    }

    return ret;
}


/* @bref     기수 정렬
 * @detail   기수 정렬을 한다 현재 구현은 3자릿수 까지만 구현 되어 있다.
 * 
 * @param    notation: 버킷의 갯수를 만드는 기준
 *           len: 정렬해야할 데이터 갯수
 *           arr[]: 정렬해야할 배열 주소
 *
 * @retval   bucket index
 */
int radixSort(Data arr[], int len,  Notation notation)
{
    TR_FUNC(TRACE);
    int array_start = 0;
    Node *_bucket[notation];
    Data *_local_arr = arr; 
    //notaion이 10진수 이므로 10개만 만든다.
    for (int index = 0; index < notation; index++)
    {
	_bucket[index] = linkedListInit();
    }
    // 정렬해야할 자릿수만 큼 돌린다.
    // TODO: digit 역시 arg로 받게 만들 필요 있다. 
    for (int digit = 1; digit < 4; digit++)
    {
	array_start = 0;
	// array의 데이터를 index에 맞게 삽입한다.
	for (int index = 0; index < len; index++) 
	{
	    Data insert_index = bucketIndex(digit, _local_arr[index]);
	    linkedListInsert(_bucket[insert_index], _local_arr[index]);
	}

	// array의 데이터를 다시 꺼낸다. 
	for (int bucket_index = 0; bucket_index < len; bucket_index++)
	{
	    while (linkeListGet_FIFO(_bucket[bucket_index], false) != 0xdeadbeef)
		arr[array_start++] = linkeListGet_FIFO(_bucket[bucket_index], true);
	}
    }
	
    return 0;

}



