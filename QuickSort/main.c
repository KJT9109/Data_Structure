/*
 * main.c
 *
 *  Created on: 2021. 11. 20
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "stdint.h"
#include "quickSort.h"

int array[] = {2,1,5,6,7,4,3,9,8,10};

int comp(int val1, int val2)
{
    int temp = 0;

    return temp = val1 < val2 ? val1 : val2;
}

int main(void)
{
    printf("Start Quick Sort \r\n");

    for (int i = 0; i <= (sizeof(array) / sizeof(int)) - 1; i++)
    {
	printf(" %d",array[i]);
    }
    printf("\r\n");

    quickSort(array, 0, (sizeof(array) / sizeof(int)) - 1, comp);

    printf("Finish Quick Sort \r\n");

    for (int i = 0; i <= (sizeof(array) / sizeof(int)) - 1; i++)
    {
	printf(" %d",array[i]);
    }
    printf("\r\n");

    return 0;
}




