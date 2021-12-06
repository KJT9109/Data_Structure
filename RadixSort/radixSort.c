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

int arrayInsert(Array *arr, Data data)
{
    //TODO: 해당 Data에 맞는 bucket에 데이터를 삽입한다.
    //만약 데이터가 있을시 링크드 리스트로 만들어 계속 삽입한다.
    return 0;

}

int arrayGet(Array *arr)
{
    //TODO: Return Data 후 데이터 삭제
    return 0;
}


int radixSort(Data *arr, Notation notation)
{
    TR_FUNC(TRACE);

    int **_bucket;
    int _bucket_size = sizeof(int) * notation;
    Data *_local_arr = arr; 

    _bucket = (int **)malloc(sizeof(int) * notation);

    do
    {
	//TODO: 데이터 값에 맞는 버킷에 삽입

    }while(*arr != NULL);

    //TODO: arr index 처음으로

    do
    {
	//TODO: 데이터를 다시 꺼냄
	
    }while(*arr != NULL);

    return 0;


}

