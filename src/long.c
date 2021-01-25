#include "../inc/header.h"

static int add_space(t_list *argv, int index) {
    int count = 0;

    for (t_list *i = argv; i; i = i->next)
        if (count < mx_strlen(mx_st_point(i, index)))
            count = mx_strlen(mx_st_point(i, index));
    return count;
}

static void space(t_list *current, int max_len, int j, int until) {
    for (; max_len - mx_strlen(mx_st_point(current, j)) >= until; max_len--)
        printf(" ");
}

static void print_node_info(t_list *current, t_list *argv, bool dev) {
    int max_len = 0;

    for (int j = 1; j <= 9; j++) {
        if (!dev && j >= 6 && j <= 7)
            continue;
        max_len = add_space(argv, j);
        if (dev && j == 5) {
            mx_size_min_maj(current, &j, max_len);
            continue;
        }
        (j == 3 || j == 4) ? max_len += 1 : 0;
        if (j == 5 || j == 2)
            space(current, max_len, j, 1);
        printf("%s", mx_st_point(current, j));
        if (j == 5 || j == 2)
            printf(" ");
        else if (j != 5 && j != 2 && j != 9)
            space(current, max_len, j, 0);
    }
    printf("\n");
}

static void add_info(t_list **current, bool *dev) {
    struct stat st;

    if (lstat(mx_st_point(*current, 10), &st) == -1)
        return;
    mx_file_mode(current, st);
    ((t_ls *)(*current)->data)->num_links = mx_itoa(st.st_nlink);
    mx_user(current, st);
    mx_group(current, st);
    if (MX_ISCHR(st.st_mode) || MX_ISBLK(st.st_mode))
        mx_min_maj(current, st);
    else
        ((t_ls *)(*current)->data)->size = mx_itoa(st.st_size);
    if (MX_ISLNK(st.st_mode))
        mx_link(mx_st_point(*current, 10), &(((t_ls *)(*current)->data)->name));
    if (MX_ISBLK(st.st_mode) || MX_ISCHR(st.st_mode))
        *dev = true;
    mx_time(&(((t_ls *)(*current)->data)->time), st);
}

void mx_long_format(t_list **argv, bool flag) {
    t_list *i = NULL;
    bool dev = false;

    for (int count = 0; count < 2; count++)
        for (i = *argv; i; i = i->next) {
            if (flag && mx_st_type(i) == 2)
                break;
            count == 0 ? add_info(&i, &dev) : print_node_info(i, *argv, dev);
        }
    for (; *argv; *argv = (*argv)->next)
        if (flag && mx_st_type(*argv) == 2)
            break;
}
