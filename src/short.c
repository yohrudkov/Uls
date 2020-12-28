#include "header.h"

static int find_max_len(t_list **argv, bool flag) {
    int len = 0;

    for (t_list *i = *argv; i; i = i->next) {
        if (flag && mx_st_type(i) == 2)
            break;
        if (len < mx_strlen(mx_st_point(i, 9)))
            len = mx_strlen(mx_st_point(i, 9));
    }
    if (len % 8 == 0)
        len += 1;
    for (; len % 8 != 0; len++);
    return len;
}

static int terminal_width(int len) {
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if (len == 0)
        len = 1;
    return w.ws_col / len;
}

void mx_short_format(t_list **argv, bool flag) {
    int len = find_max_len(argv, flag);
    int slesh = terminal_width(len);

    for (; *argv; *argv = (*argv)->next) {
        if (flag && mx_st_type(*argv) == 2)
            break;
        if (slesh == 0) {
            printf("\n");
            slesh = terminal_width(len);
        }
        printf("%s", ((t_ls *)(*argv)->data)->name);
        if (slesh - 1 != 0
            && (*argv)->next != NULL
            && !(flag && mx_st_type((*argv)->next) == 2))
            for (int i = 0; i < len - mx_strlen(mx_st_point(*argv, 9)); i++)
                printf(" ");
        slesh--;
    }
    if (!*argv)
        printf("\n");
}
