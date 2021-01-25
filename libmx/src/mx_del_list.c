#include "../inc/libmx.h"

void mx_del_list(t_list **list, void (*f)(void *)) {
    if (!list || !*list)
        return;
    for (t_list *i = *list; i; ) {
        t_list *j = i->next;

        if (*f)
            (*f)(i->data);
        free(i->data);
        i->data = NULL;
        i->next = NULL;
        free(i);
        i = NULL;
        i = j;
    }
    *list = NULL;
}
