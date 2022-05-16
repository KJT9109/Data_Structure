#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#define TABLE_SIZE 100

/* TODO: Change Hash Key */ 
typedef struct _hashKey
{
    int value;
    int index;

} HashKey;

typedef struct _storage
{
    void *mem_slot_p;
    struct _storage *next_p;
} Storage;

typedef struct _hashTable
{
    /* == hash table member == */
    Storage **data_strge_pp;
    /* == hash table work func == */
    HashKey (*insert)(struct _hashTable *ht, void *data_p);
    Storage *(*strMalloc)();
    int (*remove)(struct _hashTable *ht, HashKey key_val);
    void **(*get)(struct _hashTable *ht, HashKey key_val);
    /* == hash table make key func == */
    int (*makeKey)(struct _hashTable *ht, int val);
    /* == hash table member struct func == */
    int (*keySrc)(void *arg_p);
    int (*delData)(void *arg_p);

} HashTable;

HashTable *HashTableInit(int (*getSrc_func)(void *arg_p), int (*delData_func)(void *arg_p));

#endif
