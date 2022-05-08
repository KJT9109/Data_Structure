/*
 * main.c
 *
 *  Created on: 2022. 05. 08.
 *      Author: Jitae
 */


#include "HashTable.h"
#include "Person.h"
#include "string.h"
#include "stdio.h"


int main(void)
{
    HashTable *test = NULL;

    test = HashTableInit(Person_keyData);
    Person *hyojin = Person_new((char *)"Park HyoJin", (char *)"01012345678", 172);
    Person *jitae = Person_new((char *)"Kim JiTae", (char *)"01012345678", 173);

    test->insert(test, (void *)hyojin);
    test->insert(test, (void *)jitae);

    return 0;
}

