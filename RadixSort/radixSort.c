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
	    printf("data:%d, tmp1:%d, tmp2:%d ret:%d\r\n", data, tmp1, tmp2, ret);
	    break;
	case 3:

	    tmp1 = data % 100; 
	    tmp2 = (data - tmp1) / 100;
	    ret = tmp2;
	    printf("data:%d, tmp1:%d, tmp2:%d \r\n", data, tmp1, tmp2);
	    break;

	default:
	    break;
    }

    return ret;
}


int radixSort(Data arr[], int len,  Notation notation)
{
    TR_FUNC(TRACE);
    int array_start = 0;
    Node *_bucket[notation];
   // int _bucket_size = sizeof(Node) * notation;
    Data *_local_arr = arr; 
    //notaion이 10진수 이므로 10개만 만든다.
    for (int index = 0; index < notation; index++)
    {
	_bucket[index] = linkedListInit();
    }
 
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



