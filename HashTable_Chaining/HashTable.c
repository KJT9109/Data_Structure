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
    HashKey hash_key = {0,};
    Storage *local_str_p = NULL;

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
        if (!(&(ht_p->data_strge_pp[hash_key.value]))) {
            ERR_OUT(EINVAL);
            hash_key.value = -EINVAL;
            return hash_key;
        } else if (!(ht_p->data_strge_pp[hash_key.value]->mem_slot_p)) {
            /* Insert Data */
            ht_p->data_strge_pp[hash_key.value]->mem_slot_p = data_p;
        } else {
            /* Check Next slot */
            local_str_p = ht_p->data_strge_pp[hash_key.value];
            while (local_str_p->next_p != NULL && local_str_p->mem_slot_p != NULL) {
                local_str_p = local_str_p->next_p;
                hash_key.index++;
            }
            if (local_str_p->mem_slot_p == NULL) {
                /* Delete Slot insert Data */
                local_str_p->mem_slot_p = data_p;
            } else {
                /* Insert new Slot */
                local_str_p->next_p = ht_p->strMalloc();
                if (local_str_p->next_p < 0) {
                    ERR_OUT(ENOMEM);
                    hash_key.value = -ENOMEM;
                    return  hash_key;
                } else {
                    hash_key.index++;
                    local_str_p = local_str_p->next_p;
                    local_str_p->mem_slot_p = data_p;
                }
            }
        }
    }

    return hash_key;
}

static int HashTableDel_Func(HashTable *ht_p, HashKey hash_key)
{
    TR_FUNC(TRACE);

    int err = 0;
    Storage *local_str_p = NULL;

    if (!(ht_p) || !(&(ht_p->data_strge_pp[hash_key.value]))) {
        ERR_SET_OUT(err, EINVAL);
        return err;
    }

    if (hash_key.index == 0 ) {
        /* == Delete data == */
        if ((ht_p->delData(ht_p->data_strge_pp[hash_key.value]->mem_slot_p)) < 0) {
            ERR_SET_OUT(err, EINVAL);
        } else {
            ht_p->data_strge_pp[hash_key.value]->mem_slot_p = NULL;
        }
    } else {
        /* == get Slot HashKey + index == */
        local_str_p = ht_p->data_strge_pp[hash_key.value];
        for (int i = 0; i < hash_key.index; i++) {
            local_str_p = local_str_p->next_p;
        }
        /* == Delete data == */
        if ((ht_p->delData(local_str_p->mem_slot_p)) < 0) {
            ERR_SET_OUT(err, EINVAL);
        } else {
            local_str_p->mem_slot_p = NULL;
        }
    }

    return err;
}

static void *HashTableGet_Func(HashTable *ht_p, HashKey hash_key)
{
    TR_FUNC(TRACE);

    Storage *local_str_p = NULL;

    if (!(ht_p) || hash_key.value < 0 || hash_key.value > TABLE_SIZE) {
        ERR_OUT(EINVAL);
        return NULL;
    }

    local_str_p = ht_p->data_strge_pp[hash_key.value];

    for (int i = 0; i < hash_key.index; i++) {
        if (local_str_p->next_p) {
            local_str_p = local_str_p->next_p;
        } else {
            ERR_OUT(ENOMEM);
            return NULL;
        }
    }

    return local_str_p->mem_slot_p;
}

static int HashKey_Func(HashTable *ht_p, int val)
{
    TR_FUNC(TRACE);

    return val % 100;
}

static Storage *HashTableStrMalloc_Func()
{
    TR_FUNC(TRACE);

    Storage *ret = (Storage *)calloc(1, sizeof(Storage));

    if (ret < 0 || ret == NULL) {
        ERR_OUT(ENOMEM);
    }

    return ret;
}

HashTable *HashTableInit(int (*getSrc_func)(void *arg_p), 
        int (*delData_func)(void *arg_p))
{
    TR_FUNC(TRACE);

    HashTable *ret = (HashTable *)malloc(sizeof(HashTable));
    ret->data_strge_pp = (Storage **)calloc(TABLE_SIZE, sizeof(Storage *));

    for (int i = 0; i < TABLE_SIZE; i++) {
        ret->data_strge_pp[i] = (Storage *)calloc(1, sizeof(Storage));
    }

    /* Hash Table Work Func */
    ret->insert = HashTableInsert_Func;
    ret->remove = HashTableDel_Func;
    ret->get = HashTableGet_Func;
    ret->strMalloc = HashTableStrMalloc_Func;
    /* hash table make key func */
    ret->makeKey = HashKey_Func;
    /* member Struct Func */
    ret->keySrc = getSrc_func;
    ret->delData = delData_func;

    return ret;
}



