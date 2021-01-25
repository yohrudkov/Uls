#include "../inc/header.h"

void mx_link(char *path, char **name) {
    char buf[PATH_MAX + 1];
    char *tmp = NULL;
    int len = 0;

    len = readlink(path, buf, PATH_MAX);
    if (len == -1)
        return;
    buf[len] = '\0';
    tmp = *name;
    *name = mx_strjoin(*name, " -> ");
    mx_strdel(&tmp);
    tmp = *name;
    *name = mx_strjoin(*name, buf);
    mx_strdel(&tmp);
}

static char *add_the_null(char *src) {
    char *str = mx_strnew(10);
    char *buf = NULL;

    str[0] = '0';
    str[1] = 'x';
    for (int i = 2; i < 10 - mx_strlen(src); i++)
        str[i] = '0';
    buf = str;
    str = mx_strjoin(str, src);
    mx_strdel(&buf);
    mx_strdel(&src);
    return str;
}

void mx_min_maj(t_list **argv, struct stat stbuf) {
    int min_maj = MX_MAJOR(stbuf.st_rdev);

    ((t_ls *)(*argv)->data)->min = min_maj > 256
        ? add_the_null(mx_hex(min_maj))
        : mx_itoa(min_maj);
    min_maj = MX_MINOR(stbuf.st_rdev);
    ((t_ls *)(*argv)->data)->maj = min_maj > 256
        ? add_the_null(mx_hex(min_maj))
        : mx_itoa(min_maj);
}
