#include "../inc/header.h"

void mx_del_node(void *data) {
    mx_strdel(&((t_ls *)data)->file_mode);
    mx_strdel(&((t_ls *)data)->num_links);
    mx_strdel(&((t_ls *)data)->owner);
    mx_strdel(&((t_ls *)data)->group);
    mx_strdel(&((t_ls *)data)->size);
    mx_strdel(&((t_ls *)data)->min);
    mx_strdel(&((t_ls *)data)->maj);
    mx_strdel(&((t_ls *)data)->time);
    mx_strdel(&((t_ls *)data)->name);
    mx_strdel(&((t_ls *)data)->path);
}

static int link_type(char *name) {
    DIR *dir;

    if ((dir = opendir(name)) == NULL)
        return 1;
    closedir(dir);
    return 2;
}

static int mx_set_type_flag(char *name, uint8_t flags) {
    struct stat st;

    if (lstat(name, &st) == -1)
        return 0;
    if (MX_ISDIR(st.st_mode))
        return 2;
    else if (MX_ISLNK(st.st_mode) && !(BIT_IS_SET(flags, FLAG_L)))
        return link_type(name);
    else
        return 1;
}

t_ls *mx_new_node(char *name, uint8_t flags) {
    t_ls *node = (t_ls *)malloc(sizeof(t_ls));

    node->f_d = mx_set_type_flag(name, flags);
    node->file_mode = NULL;
    node->num_links = NULL;
    node->owner = NULL;
    node->group = NULL;
    node->size = NULL;
    node->min = NULL;
    node->maj = NULL;
    node->time = NULL;
    node->name = mx_strdup(name);
    node->path = mx_strdup(name);
    return node;
}
