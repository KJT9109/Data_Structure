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

static int HashTableInsert_Func(HashTable *ht, void *data_p)
{
    TR_FUNC(TRACE);

    int err = 0;
    int key_src;
    int hash_key;

    if (!(ht) || !(data_p)) {
        ERR_SET_OUT(err, ENOMEM);
        return -err;
    }
    /* get resource for make hash key */
    if ((key_src = ht->keySrc(data_p)) < 0) {
        ERR_SET_OUT(err, EINVAL);
        return -err;
        /* get Hash Key */
    } else if ((hash_key = ht->makeKey(ht, key_src)) < 0) {
        ERR_SET_OUT(err, EINVAL);
        return -err;
    } else {
        if (!(&(ht->data_strge_p[hash_key]))) {
            ERR_SET_OUT(err, EINVAL);
            return -err;
        } else if (!(ht->data_strge_p[hash_key].mem_slot_p)) {
            /* Insert Data */
            ht->data_strge_p[hash_key].mem_slot_p = data_p;
        } else {
            /* TODO: need to Chaining code */
        }
    }

    return hash_key;
}

static int HashTableDel_Func(HashTable *ht, int hash_key)
{
    TR_FUNC(TRACE);

    int err = 0;

    if (!(ht) || !(&(ht->data_strge_p[hash_key]))) {
        ERR_SET_OUT(err, EINVAL);
        return err;
    }

    if ((ht->delData(ht->data_strge_p[hash_key].mem_slot_p)) < 0) {
        ERR_SET_OUT(err, EINVAL);
    } else {
        /* TODO: Need to Chaing code */
        ht->data_strge_p[hash_key].mem_slot_p = NULL;
    }

    return err;
}

static void **HashTableGet_Func(HashTable *ht, int key_val)
{
    TR_FUNC(TRACE);

    int err = 0;
    void **ret = NULL;

    if (!(ht) || key_val < 0 || key_val > TABLE_SIZE) {
        ERR_SET_OUT(err, EINVAL);
        return NULL;
    }

    if (!(ret = &(ht->data_strge_p[key_val].mem_slot_p)) 
                || !(ht->data_strge_p[key_val].mem_slot_p)) {
        ERR_SET_OUT(err, EINVAL);
    }

    return ret;
}

static int HashKey_Func(HashTable *ht, int val)
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

