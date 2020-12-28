#include "header.h"

void mx_user(t_list **argv, struct stat st) {
    struct passwd *pas = NULL;

    if ((pas = getpwuid(st.st_uid)) == NULL)
        return ;
    ((t_ls *)(*argv)->data)->owner = mx_strdup(pas->pw_name);
}

void mx_group(t_list **argv, struct stat st) {
    struct group *gr = NULL;

    if ((gr = getgrgid(st.st_gid)) != NULL)
        ((t_ls *)(*argv)->data)->group = mx_strdup(gr->gr_name);
    else
        ((t_ls *)(*argv)->data)->group = mx_itoa(st.st_gid);
}

static void copy_time(char **str, struct stat st, bool flag) {
    char *date = ctime(&st.st_mtime);
    int k = 0;

    *str = mx_strnew(mx_strlen(date));
    for (int i = 4; i < mx_strlen(date) - 1; i++)
        if ((flag && (i < 11 || i > 18))
            || (!flag && (i < 16))) {
            (*str)[k] = date[i];
            k++;
        }
}

void mx_time(char **str, struct stat st) {
    time_t last = st.st_mtime;
    time_t now = time(NULL);

    if ((now - last) > 15768000)
        copy_time(str, st, true);
    else
        copy_time(str, st, false);
}

