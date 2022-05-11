#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#define TABLE_SIZE 100

typedef struct _hashTable
{
    /* == hash table member == */
    void **slot_pp;
    /* == hash table work func == */
    int (*insert)(struct _hashTable *ht, void *data_p);
    int (*remove)(struct _hashTable *ht, int key_val);
    void **(*get)(struct _hashTable *ht, int key_val);
    /* == hash table make key func == */
    int (*makeKey)(struct _hashTable *ht, int val);
    /* == hash table member struct func == */
    int (*keySrc)(void *arg_p);
    int (*delData)(void *arg_p);

} HashTable;

HashTable *HashTableInit(int (*getSrc_func)(void *arg_p), int (*delData_func)(void *arg_p));

#endif
