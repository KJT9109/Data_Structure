/*
 * Person.c
 *
 *  Created on: 2022. 05. 08.
 *      Author: Jitae
 */

#include "Person.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "debug.h"

Person *Person_new(char *name, char *phone, int height)
{
    Person *ret = (Person *)malloc(sizeof(Person));
    char *input_name = (char *)malloc(strlen(name));
    char *input_phone = (char *)malloc(strlen(phone));

    strcpy(input_name, name);
    strcpy(input_phone, phone);

    ret->name = input_name;
    ret->phone = input_phone;
    ret->height = height;

    return ret;
}

int Person_keyData(void *arg_p)
{
    Person *pers = (Person *)arg_p;

    return pers->height;
}

int Person_del(void *arg_p)
{
    int err = 0;

    Person *pers = (Person *)arg_p;
    if (!pers) {
        ERR_SET_OUT(err, ENOMEM);
    } else {
        /* person name member free */
        if (!pers->name) {
            ERR_SET_OUT(err, EINVAL);
        } else {
            free(pers->name);
        }
        /* person phone member free */
        if (!pers->phone) {
            ERR_SET_OUT(err, EINVAL);
        } else {
            free(pers->phone);
        }
        /* person struct free */
        free(pers);
    }

    return -err;
}

