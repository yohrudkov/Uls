#ifndef LIBMX_H
#define LIBMX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <malloc/malloc.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
} t_list;

void mx_del_list(t_list **list, void (*f)(void *));
void mx_push_front(t_list **list, void *data);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
int mx_list_size(t_list *list);
int mx_strlen(const char *s);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_strdup(const char *s1);
char *mx_strnew(const int size);
char *mx_itoa(long int number);
char *mx_hex(int num);

#endif
