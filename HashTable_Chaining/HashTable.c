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
#include "debug.h"

#define TRACE 0

static HashKey HashTableInsert_Func(HashTable *ht_p, void *data_p)
{
    TR_FUNC(TRACE);

    int key_src;
    HashKey hash_key;

    if (!(ht_p) || !(data_p)) {
        ERR_OUT(ENOMEM);
        hash_key.value = -ENOMEM;
        return hash_key;
    }
    /* get resource for make hash key */
    if ((key_src = ht_p->keySrc(data_p)) < 0) {
        ERR_OUT(EINVAL);
        hash_key.value = -EINVAL;
        return hash_key;
        /* get Hash Key */
    } else if ((hash_key.value = ht_p->makeKey(ht_p, key_src)) < 0) {
        ERR_OUT(EINVAL);
        hash_key.value = -EINVAL;
        return hash_key;
    } else {
        if (!(&(ht_p->data_strge_p[hash_key.value]))) {
            ERR_OUT(EINVAL);
            hash_key.value = -EINVAL;
            return hash_key;
        } else if (!(ht_p->data_strge_p[hash_key.value].mem_slot_p)) {
            /* Insert Data */
            ht_p->data_strge_p[hash_key.value].mem_slot_p = data_p;
        } else {
            /* TODO: need to Chaining code */
        }
    }

    return hash_key;
}

static int HashTableDel_Func(HashTable *ht_p, HashKey hash_key_p)
{
    TR_FUNC(TRACE);

    int err = 0;

    if (!(ht_p) || !(&(ht_p->data_strge_p[hash_key_p.value]))) {
        ERR_SET_OUT(err, EINVAL);
        return err;
    }

    if ((ht_p->delData(ht_p->data_strge_p[hash_key_p.value].mem_slot_p)) < 0) {
        ERR_SET_OUT(err, EINVAL);
    } else {
        /* TODO: Need to Chaing code */
        ht_p->data_strge_p[hash_key_p.value].mem_slot_p = NULL;
    }

    return err;
}

static void **HashTableGet_Func(HashTable *ht_p, HashKey hash_key)
{
    TR_FUNC(TRACE);

    int err = 0;
    void **ret = NULL;

    if (!(ht_p) || hash_key.value < 0 || hash_key.value > TABLE_SIZE) {
        ERR_SET_OUT(err, EINVAL);
        return NULL;
    }

    if (!(ret = &(ht_p->data_strge_p[hash_key.value].mem_slot_p)) 
                || !(ht_p->data_strge_p[hash_key.value].mem_slot_p)) {
        ERR_SET_OUT(err, EINVAL);
    }

    return ret;
}

static int HashKey_Func(HashTable *ht_p, int val)
{
    TR_FUNC(TRACE);

    return val % 100;
}

HashTable *HashTableInit(int (*getSrc_func)(void *arg_p), 
        int (*delData_func)(void *arg_p))
{
    TR_FUNC(TRACE);

    HashTable *ret = (HashTable *)malloc(sizeof(HashTable));
    ret->data_strge_p = (Storage *)calloc(TABLE_SIZE, sizeof(Storage));

    /* Hash Table Work Func */
    ret->insert = HashTableInsert_Func;
    ret->remove = HashTableDel_Func;
    ret->get = HashTableGet_Func;
    ret->makeKey = HashKey_Func;
    /* member Struct Func */
    ret->keySrc = getSrc_func;
    ret->delData = delData_func;

    return ret;
}

