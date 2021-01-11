/*
 * main.c
 *
 *  Created on: 2021. 1. 7.
 *      Author: jitae
 */

#include "HeapAPI.h"
#include "stdio.h"
#include "string.h"

HeapStruct HeapStructure;

HData HeapSortArray[MAXIMUM_SIZE] = {0,};

int main(void)
{
  printf("Start Heap Structure\r");
  HeapInit(&HeapStructure);

  HeapInsert(&HeapStructure, 'B');
  HeapInsert(&HeapStructure, 'D');
  HeapInsert(&HeapStructure, 'G');
  HeapInsert(&HeapStructure, 'E');
  HeapInsert(&HeapStructure, 'C');
  HeapInsert(&HeapStructure, 'A');
  HeapInsert(&HeapStructure, 'F');
  HeapInsert(&HeapStructure, 'F');
  HeapInsert(&HeapStructure, 'Z');
  HeapInsert(&HeapStructure, 'N');
  HeapInsert(&HeapStructure, 'M');


  HeapSort(&HeapStructure, HeapSortArray);

  printf("Finish Heap Structure\r");

}

