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
    //TODO: 해당 Data에 맞는 bucket에 데이터를 삽입한다.
    //만약 데이터가 있을시 링크드 리스트로 만들어 계속 삽입한다.
    linkedListInsert(arr, data);

    return 0;
}

int arrayGet(Array *arr)
{
    TR_FUNC(TRACE);
    //TODO: Return Data 후 데이터 삭제
    return 0;
}

//TODO: 정렬해야 할 자릿수도 포함??
int radixSort(Data arr[], int len,  Notation notation)
{
    TR_FUNC(TRACE);

    Node *_bucket[notation];
   // int _bucket_size = sizeof(Node) * notation;
    Data *_local_arr = arr; 
    //notaion이 10진수 이므로 10개만 만든다.
    for (int index = 0; index < notation; index++)
    {
	_bucket[index] = linkedListInit();
    }
    
    for (int index = 0; index < len; index++) 
    {
	Data _1st_val = _local_arr[index] % 10;
	arrayInsert(_bucket[_1st_val], _local_arr[index]);
    }	


    //TODO: arr index 처음으로

	//TODO: 데이터를 다시 꺼냄
	
    return 0;


}

