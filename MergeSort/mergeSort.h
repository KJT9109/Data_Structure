/*
 * mergeSort.h
 *
 *  Created on: 2021. 11. 9.
 *      Author: Jitae Kim
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

typedef int (*compFunc)(int val1, int val2);

void mergeSort(int *arr, int startIdx, int endIdx, compFunc comp);

#endif /* MERGESORT_H_ */
