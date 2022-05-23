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
    Person *simba = Person_new((char *)"Kim Simba", (char *)"010-2233-4567", 175);

    HashTable *personBook = NULL;

    personBook = HashTableInit(Person_keyData, Person_del);

    /* == Data Insert Test == */
    printf("\r\n");
    printf("Start Data Insert Test !!! \r\n");
    HashKey k_1 = personBook->insert(personBook, (void *)hyojin);
    printf("Insert data => Name :%s, Number :%s, height :%d\r\n", hyojin->name, hyojin->phone, hyojin->height);
    printf("k_1: value: %d, index: %d \r\n", k_1.value, k_1.index);
    HashKey k_2 = personBook->insert(personBook, (void *)jitae);
    printf("Insert data => Name :%s, Number :%s, height :%d\r\n", jitae->name, jitae->phone, jitae->height);
    printf("k_2: value: %d, index: %d \r\n", k_2.value, k_2.index);
    HashKey k_3 = personBook->insert(personBook, (void *)seokha);
    printf("Insert data => Name :%s, Number :%s, height :%d\r\n", seokha->name, seokha->phone, seokha->height);
    printf("k_3: value: %d, index: %d \r\n", k_3.value, k_3.index);
    HashKey k_4 = personBook->insert(personBook, (void *)okhee);
    printf("Insert data => Name :%s, Number :%s, height :%d\r\n", okhee->name, okhee->phone, okhee->height);
    printf("k_4: value: %d, index: %d \r\n", k_4.value, k_4.index);
    HashKey k_5 = personBook->insert(personBook, (void *)suyun);
    printf("Insert data => Name :%s, Number :%s, height :%d \r\n", suyun->name, suyun->phone, suyun->height);
    printf("k_5: value: %d, index: %d \r\n", k_5.value, k_5.index);

    /* == Data Get Test == */
    printf("\r\n");
    printf("Start Data Get Test !!! \r\n");
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

    /* == Data Change Test == */
    printf("\r\n");
    printf("Start Change !! \r\n");
    key_5->phone = "010-600-6000";
    printf("Change Number: %s\r\n", key_5->phone);
    key_5 = (Person *)personBook->get(personBook, k_5);
    key_5 ? printf("key_5: Name :%s , Number: %s, height: %d \r\n", key_5->name, key_5->phone, key_5->height) : printf("none \r\n");
    
    /* == Data remove Test == */
    printf("\r\n");
    printf("Start Remove !! \r\n");
    Person *remove_p = NULL;
    remove_p = (Person *)personBook->get(personBook, k_2);
    printf("k_2: value: %d, index: %d \r\n", k_2.value, k_2.index);
    remove_p ? printf("Remove : Name :%s , Number: %s, height: %d \r\n", remove_p->name, remove_p->phone, remove_p->height) : printf("none \r\n");
    personBook->remove(personBook, k_2);
    remove_p = (Person *)personBook->get(personBook, k_2);
    remove_p ? printf("remove_p: Name :%s , Number: %s, height: %d \r\n", remove_p->name, remove_p->phone, remove_p->height) : printf("none \r\n");
   
    /* == Data remove after insert Test == */
    printf("\r\n");
    printf("Start Re Insart !! \r\n");
    HashKey k_6 = personBook->insert(personBook, (void *)simba);
    printf("k_6: value: %d, index: %d \r\n", k_6.value, k_6.index);
    Person *key_6 = (Person *)personBook->get(personBook, k_6);
    key_6 ? printf("key_6: Name :%s , Number: %s, height: %d \r\n", key_6->name, key_6->phone, key_6->height) : printf("none \r\n");
    printf("End HashTable Program \r\n");

    return 0;
}

