/*
 * HeapAPI.h
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#ifndef HEAPAPI_H_
#define HEAPAPI_H_

#include "HeapRaw.h"

void HeapInit(HeapStruct *useHstr);
void HeapInsert(HeapStruct *useHstr, HData inData);
int HeapDelete(HeapStruct *useHstr, HData inData);
HData HeapCount(HeapStruct useHstr);
HData HeapTakeOut(HeapStruct *useHstr);
void HeapSort(HeapStruct *useHstr, HData *contArr);

#endif /* HEAPAPI_H_ */
