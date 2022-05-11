#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct _person
{
    char *name;
    char *phone;
    int height;

} Person;

Person *Person_new(char *name, char *phone, int height);
int Person_keyData(void *arg_p);
int Person_del(void *arg_p);

#endif
