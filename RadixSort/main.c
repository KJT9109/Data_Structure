/*
 * main.c
 *
 *  Created on: 2021. 12. 06
 *      Author: Jitae Kim
 */

#include "stdio.h"
#include "stdint.h"
#include "radixSort.h"

#define NOTATION 10

Data array[] = {107,884,173,153,255,222,766,715,649,262};


int main(void)
{
    printf("Start Radix Sort \r\n");

    for (int i = 0; i <= (sizeof(array) / sizeof(int)) - 1; i++)
    {
	printf(" %d",array[i]);
    }

    radixSort(array, NOTATION);

    printf("\r\n");

    return 0;
}

