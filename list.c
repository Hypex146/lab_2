#include "list.h"

static List_element *list_element_init(double value){
    List_element *new_list_element = (List_element*)malloc(1 * sizeof(List_element));
    new_list_element->value = value;
    new_list_element->next = NULL;
    return new_list_element;
}


List *list_init(void){
    List *new_list = (List*)malloc(1 * sizeof(List));
    List_element *header = list_element_init(0);
    new_list->head = header;
    return new_list;
}


int list_insert(List *list, double value, int index){
    int i = 0;
    List_element *now = list->head;
    while (i < index && now->next){
        i++;
        now = now->next;
    }
    List_element *new_list_element = list_element_init(value);
    new_list_element->next = now->next;
    now->next = new_list_element;
    return 0;
}


int list_remove(List *list, int index, double *ret){
    if(list->head->next){
        int i = 0;
        List_element *now = list->head;
        while (i < index && now->next->next){
            i++;
            now = now->next;
        }
        List_element *for_del = now->next;
        now->next = now->next->next;
        *ret = for_del->value;
        free(for_del);
    }
    return 0;
}


int list_len(List* list){
    int count = 0;
    List_element *now = list->head;
    while (now->next){
        count++;
        now = now->next;
    }
    return count;
}


int list_write(List *list){
    printf("List:\n--->\n");
    if(list->head->next) {
        List_element *now = list->head->next;
        while (now){
            printf("%lf ", now->value);
            now = now->next;
        }
    }
    printf("\n--->\n");
    return 0;
}


int list_clear(List *list){
    List_element *now = list->head;
    List_element *tmp = NULL;
    while (now->next){
        tmp = now->next;
        free(now);
        now = tmp;
    }
    free(now);
    free(list);
    printf("Clear\n");
    return 0;
}
