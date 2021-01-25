#include "../inc/header.h"

static char exstra_group(char **str) {
    ssize_t xattr = listxattr(*str, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(*str, ACL_TYPE_EXTENDED);
    char ch = xattr > 0 ? '@' : acl != NULL ? '+' : ' ';

    if (acl) {
        acl_free(acl);
        acl = NULL;
    }
    return ch;
}

static void access_group(char **str, struct stat st) {
    (*str)[1] = st.st_mode & MX_IRUSR ? 'r' : '-';
    (*str)[2] = st.st_mode & MX_IWUSR ? 'w' : '-';
    (*str)[3] = st.st_mode & MX_ISUID
        ? (st.st_mode & MX_ISUID ? 's' : 'S')
        : (st.st_mode & MX_ISUID ? 'x' : '-');
    (*str)[4] = st.st_mode & MX_IRGRP ? 'r' : '-';
    (*str)[5] = st.st_mode & MX_IWGRP ? 'w' : '-';
    (*str)[6] = st.st_mode & MX_ISGID
        ? (st.st_mode & MX_IXGRP ? 's' : 'S')
        : (st.st_mode & MX_IXGRP ? 'x' : '-');
    (*str)[7] = st.st_mode & MX_IROTH ? 'r' : '-';
    (*str)[8] = st.st_mode & MX_IWOTH ? 'w' : '-';
    (*str)[9] = st.st_mode & MX_ISVTX
        ? (st.st_mode & MX_IXOTH ? 't' : 'T')
        : (st.st_mode & MX_IXOTH ? 'x' : '-');
}

static void file_type(char **str, struct stat st) {
    (*str)[0] = MX_ISBLK(st.st_mode) ? 'b'
        : MX_ISCHR(st.st_mode) ? 'c'
        : MX_ISDIR(st.st_mode) ? 'd'
        : MX_ISFIFO(st.st_mode) ? 'p'
        : MX_ISSOCK(st.st_mode) ? 's'
        : MX_ISLNK(st.st_mode) ? 'l'
        : '-';
}

void mx_file_mode(t_list **argv, struct stat st) {
    ((t_ls *)(*argv)->data)->file_mode = mx_strnew(11);
    file_type(&((t_ls *)(*argv)->data)->file_mode, st);
    access_group(&((t_ls *)(*argv)->data)->file_mode, st);
    ((t_ls *)(*argv)->data)->file_mode[10] =
        exstra_group(&((t_ls *)(*argv)->data)->path);
}
