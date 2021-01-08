/*
 * HeapRaw.h
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#ifndef HEAPRAW_H_
#define HEAPRAW_H_

#define MAXIMUM_SIZE 255

typedef char HData;
typedef int HNode;

typedef HData (*HPriorityCompare)(HData, HData);

typedef struct
{
	int heapNode;
	HPriorityCompare HPriorityFunc;
	HData heapData[MAXIMUM_SIZE];

}HeapStruct;


HNode HReadParentNode(HNode curIndex);
HNode HReadChildLeftNode(HNode curIndex);
HNode HReadChildRightNode(HNode curIndex);
HNode HFindNode(HeapStruct useHstr, HData wantData);

HData HReadData(HeapStruct useHstr, HNode curNode);
HData HReadParentData(HeapStruct useHstr, HNode curIndex);
HData HReadChildLeftData(HeapStruct useHstr, HNode curIndex);
HData HReadChildRightData(HeapStruct useHstr, HNode curIndex);
HData HPriorityCheck(HData data_A, HData data_B);

#endif /* HEAPRAW_H_ */
