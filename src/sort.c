#include "header.h"

static void swap(t_list **j) {
    void *swap = NULL;

    swap = (*j)->data;
    (*j)->data = (*j)->next->data;
    (*j)->next->data = swap;
}

static int name(void *str1, void *str2) {
    return strcmp(((t_ls *)str1)->name, ((t_ls *)str2)->name);
}

void mx_sort_name(t_list **argv, bool flag) {
    for (int i = 0; i < mx_list_size(*argv); i++)
        for (t_list *j = *argv; j->next; j = j->next)
            if ((flag
                && name(j->data, j->next->data) > 0
                && mx_st_type(j) == mx_st_type(j->next))
                    || (!flag && name(j->data, j->next->data) > 0))
                swap(&j);
}

static int file_dir(void *num1, void *num2) {
    if (((t_ls *)num1)->f_d > ((t_ls *)num2)->f_d)
        return 1;
    return 0;
}

void mx_sort_file_dir(t_list **argv, bool flag) {
    for (int i = 0; i < mx_list_size(*argv); i++)
        for (t_list *j = *argv; j->next; j = j->next)
            if (flag && file_dir(j->data, j->next->data) > 0)
                swap(&j);
}
