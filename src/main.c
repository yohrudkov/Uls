#include "../inc/header.h"

static void error(char ch) {
    fprintf(stderr, "uls: illegal option -- %c\n", ch);
    fprintf(stderr, "usage: uls [-laR] [file ...]\n");
    exit(EXIT_FAILURE);
}

static int set_flags(int argc, char **argv, uint8_t *flags) {
    for (int i = 1; i < argc; i++) {
        if ((argv[i][0] == '-' && argv[i][1] == '\0')
            || strcmp(argv[i], "--") == 0
            || argv[i][0] != '-')
            return strcmp(argv[i], "--") == 0 ? i + 1 : i;
        for (int j = 1; argv[i][j]; j++) {
            if (argv[i][j] == 'l')
                SET_BIT(*flags, FLAG_L);
            else if (argv[i][j] == 'a')
                SET_BIT(*flags, FLAG_A);
            else if (argv[i][j] == 'R')
                SET_BIT(*flags, FLAG_R);
            else
                error(argv[i][j]);
        }
    }
    return argc;
}

static void create_list(t_list **list, char **argv, uint8_t flags) {
    for (int i = 0; argv[i]; i++)
        mx_push_front(list, mx_new_node(argv[i], flags));
}

int main(int argc, char **argv) {
    uint8_t flags;
    t_list *list = NULL;
    int begin = set_flags(argc, argv, &flags);
    int result = 0;

    if (argc == begin) {
        mx_push_front(&list, mx_new_node(".", flags));
        mx_uls(&list, flags, &result, true);
    }
    else {
        create_list(&list, &argv[begin], flags);
        mx_uls(&list, flags, &result, true);
    }
    // system("leaks -q uls");
    return result;
}
