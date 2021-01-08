/*
 * HeapRaw.c
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#include "HeapRaw.h"
#include "string.h"

HNode HReadParentNode(HNode curNode)
{
	return curNode / 2;
}

HNode HReadChildLeftNode(HNode curNode)
{
	return curNode * 2;
}

HNode HReadChildRightNode(HNode curNode)
{
	return (curNode * 2) + 1;
}

HNode HFindNode(HeapStruct useHstr, HData wantData)
{
	HNode findNode = 0;

	while (strcmp(&(useHstr.heapData[++findNode]), &wantData))
	{
		return findNode;
	}

	return 0;
}

HData HPriorityCheck(HData data_A, HData data_B)
{
	if (data_A <= data_B)
		return data_A;

	else
		return data_B;

}

HData HReadData(HeapStruct useHstr, HNode curNode)
{
	return useHstr.heapData[curNode];
}


HData HReadParentData(HeapStruct useHstr, HNode curNode)
{
	return useHstr.heapData[curNode / 2];
}

HData HReadChildLeftData(HeapStruct useHstr, HNode curNode)
{
	return useHstr.heapData[curNode * 2];
}

HData HReadChildRightData(HeapStruct useHstr, HNode curNode)
{
	return useHstr.heapData[(curNode * 2) + 1];
}

