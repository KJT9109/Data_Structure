/*
 * HeapAPI.c
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#include "HeapAPI.h"
#include "string.h"

void HeapInit(HeapStruct *useHstr)
{
  useHstr->HPriorityFunc = HPriorityCheck;
  useHstr->heapNode = 0;
  memset(useHstr->heapData, 0, sizeof(useHstr->heapData) / sizeof(int));
}

HData HeapCount(HeapStruct useHstr)
{
  return useHstr.heapNode;
}

void HeapInsert(HeapStruct *useHstr, HData inData)
{
  HData tmpBuff;
  HNode tmpNode;
  useHstr->heapData[++useHstr->heapNode] = inData;

  tmpNode = useHstr->heapNode;

  /* 부모노드가 존재하고 부모노드와의 우선순위를 비교 했을 때 부모노드가 우선순위가 낮다면 */
  while (HReadParentNode(tmpNode) != 0
      && useHstr->HPriorityFunc(HReadParentData(*useHstr, tmpNode), HReadData(*useHstr, tmpNode))
          != HReadParentData(*useHstr, tmpNode))
  {
    /* 부모 노드의 데이터를 임시 버퍼에 저장한다. */
    tmpBuff = HReadParentData(*useHstr, tmpNode);
    /* 부모 노드에 현재 노드의 데이터를 저장한다. */
    useHstr->heapData[HReadParentNode(tmpNode)] = useHstr->heapData[tmpNode];
    /* 현재 노드에 부모 노드의 데이터를 저장한다. */
    useHstr->heapData[tmpNode] = tmpBuff;
    /* 현재 노드를 부모노드로 변경한다. */
    tmpNode = HReadParentNode(tmpNode);
  }

}

int HeapDelete(HeapStruct *useHstr, HData inData)
{
  HNode curNode;
  HNode childNode;

  HData tmpBuff;

  /* 해당 데이터가 Heap Node에  존재 하는지 찾는다.*/
  if (HFindNode(*useHstr, inData) != 0)
  {
    /* Heap의 마지막 노드(우선순위가 낮은)를 삭제된 노드로 옮긴다 */
    curNode = HFindNode(*useHstr, inData);
    useHstr->heapData[curNode] = useHstr->heapData[useHstr->heapNode];
    /* Heap의 마지막 노드를 삭제한다.*/
    useHstr->heapData[useHstr->heapNode--] = 0;

    /* 자식 노드있는지 확인한다.*/
    while (HReadChildLeftNode(curNode) < useHstr->heapNode)
    {
      /* 자식 노드들과 우선순위를 비교 후 낮은 우선순위의 자식 노드를 구한다. */
      if (useHstr->HPriorityFunc(HReadChildLeftData(*useHstr, curNode),
          HReadChildRightData(*useHstr, curNode)) == HReadChildLeftData(*useHstr, curNode))
      {
        childNode = HReadChildLeftNode(curNode);
      }
      else
      {
        childNode = HReadChildRightNode(curNode);
      }

      /* 현재노드가 자식노드보다 우선순위가 작다면 */
      if (useHstr->HPriorityFunc(HReadData(*useHstr, curNode), HReadData(*useHstr, childNode))
          == HReadData(*useHstr, childNode))
      {
        /* 현재 노드와 자식노드를 바꿔준다. */

        /* 자식 노드를 저장한다. */
        tmpBuff = HReadData(*useHstr, childNode);
        /* 자식 노드에 현재 노드의 데이터를 저장한다. */
        useHstr->heapData[childNode] = useHstr->heapData[curNode];
        /* 현재 노드에 자식 노드의 데이터를 저장한다. */
        useHstr->heapData[curNode] = tmpBuff;
        /* 현재 노드를 자식노드로 변경한다. */
        curNode = childNode;

      }
      /* 현재노드가 자식노드보다 우선순위가 크다면 이대로 종료한다. */
      else
      {
        return 0;
      }
    }
    /* 정상적으로 종료 */
    return 0;
  }
  else
  {
    /* 데이터가 존재하지 않음 */
    return -1;
  }

}

HData HeapTakeOut(HeapStruct *useHstr)
{
  HData retData;
  retData = useHstr->heapData[1];

  if (HeapDelete(useHstr, retData) != -1)
  {
    return retData;
  }

  return -1;
}

void HeapSort(HeapStruct *useHstr, HData *contArr)
{
  int idx = useHstr->heapNode;

  if (useHstr->heapNode > 0)
  {
    for (int i = 0; i < idx; i++)
    {
      contArr[i] = HeapTakeOut(useHstr);
    }
  }
}

