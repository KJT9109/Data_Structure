#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "errno.h"

#define TR_FUNC(_value_)  \
    if(_value_)            \
    printf("FILENAME:%s, FUNCNAME: %s, LINENUM: %d \r\n" \
	    , __FILE__, __FUNCTION__, __LINE__)

#define ERR_OUT(err) printf((char *)(__FILE__ ":%d = %s(%d)\n"), __LINE__, strerror((err)), (err))
#define ERR_SET_OUT(err, val) \
    do { \
        (err) = (val); \
        ERR_OUT(err);  \
    } while(0);

#define TABLE_SIZE 100

typedef struct _hashKey
{
    int key;
    int password;

} HashKey;

typedef struct _hashTable
{
    /* == hash table member == */
    void **slot_pp;

    int (*keyData)(void *arg_p);
    int (*insert)(struct _hashTable *ht, void *data_p);
    int (*remove)(struct _hashTable *ht, void *data_p);
    int (*search)(struct _hashTable *ht, HashKey *key_val_p);

    int (*makeKey)(struct _hashTable *ht, int val);

} HashTable;

HashTable *HashTableInit(int (*data_func)(void *arg_p));

#endif
