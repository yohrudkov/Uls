#include "../inc/header.h"

static int add_total(char *full_path) {
    struct stat st;

    if (lstat(full_path, &st) == -1)
        return 0;
    return st.st_blocks;
}

static void add_path(char *path, struct dirent *dp, char **full_path) {
    char *tmp = NULL;

    if (strcmp(path, "/") != 0)
        *full_path = mx_strjoin(path, "/");
    tmp = *full_path;
    if (strcmp(path, "/") != 0)
        *full_path = mx_strjoin(*full_path, dp->d_name);
    else
        *full_path = mx_strjoin(path, dp->d_name);
    mx_strdel(&tmp);
}

static int push_to_list(DIR *dir, uint8_t flags, t_list **list, char *path) {
    struct dirent *dp;
    int total = 0;

    while ((dp = readdir(dir)) != NULL) {
        if (!(BIT_IS_SET(flags, FLAG_A)) && dp->d_name[0] == '.')
            continue;
        char *full_path = NULL;

        add_path(path, dp, &full_path);
        mx_push_front(list, mx_new_node(full_path, flags));
        mx_strdel(&((t_ls *)(*list)->data)->name);
        ((t_ls *)(*list)->data)->name = mx_strdup(dp->d_name);
        total += add_total(full_path);
        mx_strdel(&full_path);
    }
    return total;
}

static void run_dir(DIR **dir, uint8_t flags, int *result, char *path) {
    t_list *list = NULL;
    int total = 0;

    total = push_to_list(*dir, flags, &list, path);
    if (list && BIT_IS_SET(flags, FLAG_L))
        printf("total %d\n", total);
    closedir(*dir);
    mx_uls(&list, flags, result, false);
}

void mx_open_dir(t_list **argv, uint8_t flags, int *result, bool flag) {
    for (; *argv; *argv = (*argv)->next) {
        DIR *dir;
        char *path = mx_st_point(*argv, 10);

        if (flag)
            printf("%s:\n", path);
        if ((dir = opendir(path)) == NULL) {
            fprintf(stderr, "uls: %s: Permission denied\n",
                    mx_st_point(*argv, 9));
            *result = 1;
            continue;
        }
        run_dir(&dir, flags, result, path);
        if ((*argv)->next)
            printf("\n");
    }
}
