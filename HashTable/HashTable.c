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

#define TRACE 0

static int HashTableInsert_Func(HashTable *ht, void *data_p)
{
    TR_FUNC(TRACE);
    int key_resource;
    int hash_key;
     /* get resource for make hash key */
    if ((key_resource = ht->keyData(data_p)) < 0) {
	return -1;
	/* get Hash Key */
    } else if ((hash_key = ht->makeKey(ht, key_resource)) < 0) {
	return -2;
    } else {
	if (!(ht->slot_pp)) {
	    return -3;
	    /* Insert Work */
	} else if (!(ht->slot_pp[hash_key])) {
	    ht->slot_pp[hash_key] = data_p;
	}
    }

    return 0;
}

static int HashTableDel_Func(HashTable *ht, void *data_p)
{
    TR_FUNC(TRACE);

    return 0;
}

static int HashTableSearch_Func(HashTable *ht, HashKey *key_val_p)
{
    TR_FUNC(TRACE);

    return 0;
}

static int HashKey_Func(HashTable *ht, int val)
{
    TR_FUNC(TRACE);

    return val % 100;
}

HashTable *HashTableInit(int (*data_func)(void *arg_p))
{
    TR_FUNC(TRACE);

    HashTable *ret = (HashTable *)malloc(sizeof(HashTable));
    ret->slot_pp = (void **)malloc(sizeof(int) * TABLE_SIZE);
    memset(ret->slot_pp, 0, sizeof(int) * TABLE_SIZE);

    ret->keyData = data_func;
    ret->insert = HashTableInsert_Func;
    ret->remove = HashTableDel_Func;
    ret->search = HashTableSearch_Func;
    ret->makeKey = HashKey_Func;

    return ret;
}



