/*
 * HashTable.c
 *
 *  Created on: 2022. 05. 08.
 *      Author: Jitae
 */

#include "HashTable.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

static int HashTableInsert_Func(HashTable *ht, void *data_p)
{
    TR_FUNC(1);

    int key_resource = ht->keyData(data_p);
    printf(" key val: %d \r\n", key_resource);

    return 0;
}

static int HashTableDel_Func(HashTable *ht, void *data_p)
{
    TR_FUNC(1);

    return 0;
}

static int HashTableSearch_Func(HashTable *ht, HashKey *key_val_p)
{
    TR_FUNC(1);

    return 0;
}

HashTable *HashTableInit(int (*data_func)(void *arg_p))
{
    HashTable *ret = (HashTable *)malloc(sizeof(HashTable));

    ret->slot_pp = NULL;
    ret->keyData = data_func;
    ret->insert = HashTableInsert_Func;
    ret->remove = HashTableDel_Func;
    ret->search = HashTableSearch_Func;

    return ret;
}



