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

    Person *hyojin = Person_new((char *)"Park HyoJin", (char *)"010-1122-3456", 175);
    Person *jitae = Person_new((char *)"Kim JiTae", (char *)"010-2233-4567", 175);
    Person *seokha = Person_new((char *)"Kim SeokHa", (char *)"010-3344-5678", 175);
    Person *okhee = Person_new((char *)"Chae OkHee", (char *)"010-5566-7890", 175);
    Person *suyun = Person_new((char *)"Kim Suyun", (char *)"010-7788-9012", 175);

    HashTable *personBook = NULL;

    personBook = HashTableInit(Person_keyData, Person_del);

    HashKey k_1 = personBook->insert(personBook, (void *)hyojin);
    HashKey k_2 = personBook->insert(personBook, (void *)jitae);
    HashKey k_3 = personBook->insert(personBook, (void *)seokha);
    HashKey k_4 = personBook->insert(personBook, (void *)okhee);
    HashKey k_5 = personBook->insert(personBook, (void *)suyun);

    Person *key_1 = (Person *)personBook->get(personBook, k_1);
    key_1 ? printf("key_1: Name :%s , Number: %s, height: %d \r\n", key_1->name, key_1->phone, key_1->height) : printf("none \r\n");
    Person *key_2 = (Person *)personBook->get(personBook, k_2);
    key_2 ? printf("key_2: Name :%s , Number: %s, height: %d \r\n", key_2->name, key_2->phone, key_2->height) : printf("none \r\n");
    Person *key_3 = (Person *)personBook->get(personBook, k_3);
    key_3 ? printf("key_3: Name :%s , Number: %s, height: %d \r\n", key_3->name, key_3->phone, key_3->height) : printf("none \r\n");
    Person *key_4 = (Person *)personBook->get(personBook, k_4);
    key_4 ? printf("key_4: Name :%s , Number: %s, height: %d \r\n", key_4->name, key_4->phone, key_4->height) : printf("none \r\n");
    Person *key_5 = (Person *)personBook->get(personBook, k_5);
    key_5 ? printf("key_5: Name :%s , Number: %s, height: %d \r\n", key_5->name, key_5->phone, key_5->height) : printf("none \r\n");

    key_5->phone = "010-600-6000";

    key_5 = (Person *)personBook->get(personBook, k_5);
    key_5 ? printf("key_5: Name :%s , Number: %s, height: %d \r\n", key_5->name, key_5->phone, key_5->height) : printf("none \r\n");

    printf("End HashTable Program \r\n");

    return 0;
}

