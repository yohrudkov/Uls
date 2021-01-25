#include "../inc/header.h"

static void recursion(t_list *tmp, uint8_t flags, int *result) {
    mx_sort_file_dir(&tmp, true);
    for (t_list *i = tmp; i; i = i->next) {
        if (mx_st_type(i) == 2
            && strcmp(mx_st_point(i, 9), ".") != 0
            && strcmp(mx_st_point(i, 9), "..") != 0) {
            printf("\n");
            t_list *tmp = NULL;
            t_list *begin = NULL;

            mx_push_front(&tmp, mx_new_node(mx_st_point(i, 10), flags));
            begin = tmp;
            mx_open_dir(&tmp, flags, result, true);
            mx_del_list(&begin, mx_del_node);
        }
    }
}

static void output(t_list **argv, uint8_t flags, bool flag) {
    if (BIT_IS_SET(flags, FLAG_L))
        mx_long_format(argv, flag);
    else
        mx_short_format(argv, flag);
}

static void skip_error(t_list **argv) {
    for (; *argv && mx_st_type(*argv) == 0; *argv = (*argv)->next)
        fprintf(stderr, "uls: %s: No such file or directory\n",
                mx_st_point(*argv, 9));
}

void mx_uls(t_list **argv, uint8_t flags, int *result, bool flag) {
    if (!argv || !*argv)
        return;
    t_list *tmp = *argv;

    if (flag)
        mx_sort_file_dir(argv, flag);
    mx_sort_name(argv, flag);
    skip_error(argv);
    if (*argv) {
        output(argv, flags, flag);
        if (*argv && mx_st_type(tmp) != 2)
            printf("%s", !(BIT_IS_SET(flags, FLAG_L)) ? "\n\n" : "\n");
        mx_open_dir(argv, flags, result, flag);
        if (!flag && BIT_IS_SET(flags, FLAG_R))
            recursion(tmp, flags, result);
    }
    mx_del_list(&tmp, mx_del_node);
}
