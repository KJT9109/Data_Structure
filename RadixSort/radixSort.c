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

int arrayInsert(Node *arr, Data data)
{
    TR_FUNC(TRACE);
    linkedListInsert(arr, data);

    return 0;
}

int arrayGet(Node *arr, bool data_del)
{
    TR_FUNC(TRACE);
    return linkedListGet(arr, data_del);
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
    
    // array의 데이터를 index에 맞게 삽입한다.
    for (int index = 0; index < len; index++) 
    {
	Data _1st_val = _local_arr[index] % 10;
	arrayInsert(_bucket[_1st_val], _local_arr[index]);
    }	

    for (int bucket_index = 0; bucket_index < len; bucket_index++)
    {
	while (arrayGet(_bucket[bucket_index], false) != 0xdeadbeef)
		arr[array_start++] = arrayGet(_bucket[bucket_index], true);
    }


    //TODO: 데이터를 다시 꺼냄
	
    return 0;

}

