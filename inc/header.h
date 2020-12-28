#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wchar.h>
#include <uuid/uuid.h>
#include <sys/uio.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <malloc/malloc.h>
#include "macros_header.h"
#include "../libmx/inc/libmx.h"

typedef struct s_ls {
    int f_d;
    char *file_mode;
    char *num_links;
    char *owner;
    char *group;
    char *size;
    char *min;
    char *maj;
    char *time;
    char *name;
    char *path; 
}              t_ls;

void mx_open_dir(t_list **argv, uint8_t flags, int *result, bool flag);
void mx_uls(t_list **argv, uint8_t flags, int *result, bool flag);
void mx_uls(t_list **argv, uint8_t flags, int *result, bool flag);
void mx_size_min_maj(t_list *current, int *j, int max_len);
void mx_min_maj(t_list **argv, struct stat stbuf);
void mx_file_mode(t_list **argv, struct stat st);
void mx_sort_file_dir(t_list **argv, bool flag);
void mx_short_format(t_list **argv, bool flag);
void mx_long_format(t_list **argv, bool flag);
void mx_group(t_list **argv, struct stat st);
void mx_sort_name(t_list **argv, bool flag);
void mx_user(t_list **argv, struct stat st);
void mx_time(char **str, struct stat st);
void mx_link(char *path, char **name);
void mx_del_node(void *data);
t_ls *mx_new_node(char *name, uint8_t flags);
char *mx_st_point(t_list *list, int index);
int mx_st_type(t_list *list);

#endif
