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
    printf("Start HashTable Program \r\n");

    Person *hyojin = Person_new((char *)"Park HyoJin", (char *)"010-1122-3456", 165);
    Person *jitae = Person_new((char *)"Kim JiTae", (char *)"010-2233-4567", 175);
    Person *seokha = Person_new((char *)"Kim SeokHa", (char *)"010-3344-5678", 172);
    Person *okhee = Person_new((char *)"Chae OkHee", (char *)"010-5566-7890", 161);
    Person *suyun = Person_new((char *)"Kim Suyun", (char *)"010-7788-9012", 174);

    HashTable *personBook = NULL;

    personBook = HashTableInit(Person_keyData, Person_del);

    personBook->insert(personBook, (void *)hyojin);
    personBook->insert(personBook, (void *)jitae);
    personBook->insert(personBook, (void *)seokha);
    personBook->insert(personBook, (void *)okhee);
    personBook->insert(personBook, (void *)suyun);

    Person *key_61 = *(Person **)personBook->get(personBook, 61);
    Person *key_72 = *(Person **)personBook->get(personBook, 72);

    printf("key_61: Name :%s , Number: %s, height: %d \r\n", key_61->name, key_61->phone, key_61->height);
    printf("key_72: Name :%s , Number: %s, height: %d \r\n", key_72->name, key_72->phone, key_72->height);

    personBook->remove(personBook, 72);
    key_72 = *(Person **)personBook->get(personBook, 72);

    printf("End HashTable Program \r\n");

    return 0;
}

