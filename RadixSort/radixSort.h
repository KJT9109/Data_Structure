/*
 * radixSort.h
 *
 *  Created on: 2021. 12.06.
 *      Author: Jitae Kim
 */
#ifndef RADIXSORT_H_
#define RADIXSORT_H_

#include "linkedList.h"

typedef int Data;
typedef int Array;
typedef int Notation;

#define TR_FUNC(_value_)  \
    if(_value_)            \
    printf("TRACE FUNC: QuickSort\r\n")

int radixSort(Data *arr, int len, Notation notation);

#endif
