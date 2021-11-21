/*
 * quickSort.h
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#define TR_FUNC(_value_)  \
    if(_value_)            \
    printf("TRACE FUNC: QuickSort\r\n")

typedef int Data;

typedef Data (*compFunc)(Data val1, Data val2);

Data quickSort(Data *arr, Data startIdx, Data endIdx, compFunc comp);

#endif
