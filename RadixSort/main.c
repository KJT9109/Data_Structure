/*
 * main.c
 *
 *  Created on: 2021. 12. 06
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "stdint.h"
#include "radixSort.h"
#include "linkedList.h"

#define NOTATION 10

Data array[] = {107,884,173,153,255,222,766,715,649,262};


int main(void)
{
    printf("Start Radix Sort \r\n");

    for (int i = 0; i <= (sizeof(array) / sizeof(int)) - 1; i++)
    {
	printf(" %d",array[i]);
    }

    printf("\r\n");

    int array_len = sizeof(array) / sizeof(Data);

    radixSort(array, array_len, NOTATION);
#if 0  
    Node *head = linkedListInit();
    linkedListInsert(head, 1);
    linkedListInsert(head, 2);
    linkedListInsert(head, 3);
    linkedListInsert(head, 4);

   while (head->next != NULL)
   {
      printf("linkedList Data is : %d \r\n", head->data); 
      head = head->next;
   }
    printf("\r\n");
#endif

    printf("End Radix Sort\r\n");

    for (int i = 0; i <= (sizeof(array) / sizeof(int)) - 1; i++)
    {
	printf(" %d",array[i]);
    }

    printf("\r\n");
    return 0;
}

