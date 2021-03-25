#ifndef LAB2_LIST_H
#define LAB2_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct _LIST_ELEMENT{
    double value;
    struct _LIST_ELEMENT *next;
}List_element;
typedef struct _LIST{
    struct _LIST_ELEMENT *head;
}List;
List *list_init(void);
int list_insert(List *list, double value, int index);
int list_remove(List *list, int index, double *ret);
int list_len(List* list);
int list_write(List *list);
int list_clear(List *list);
#endif //LAB2_LIST_H
