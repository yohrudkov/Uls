#include "header.h"

char *mx_st_point(t_list *list, int index) {
    char *str = NULL;

    str = ((char **)((t_ls *)list->data))[index];
    return str;
}

int mx_st_type(t_list *list) {
    return ((t_ls *)list->data)->f_d;
}
