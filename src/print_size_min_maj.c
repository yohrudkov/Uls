#include "../inc/header.h"

static bool dev_or_not(t_list *current) {
    if (mx_st_point(current, 1)[0] == 'c'
        || mx_st_point(current, 1)[0] == 'b')
        return true;
    return false;
}

static void min_maj(t_list *current, int max_len) {
    int i = 0;

    i = mx_strlen(mx_st_point(current, 6));
    for (; i < 3; i++)
        printf(" ");
    printf("%s", mx_st_point(current, 6));
    printf(", ");
    i = max_len <= 8
        ? 2 - mx_strlen(mx_st_point(current, 5))
        : max_len - mx_strlen(mx_st_point(current, 7)) - 5;
    for (; i > 0; i--)
        printf(" ");
    printf("%s", mx_st_point(current, 7));
}

void mx_size_min_maj(t_list *current, int *j, int max_len) {
    if (dev_or_not(current))
        min_maj(current, max_len);
    else {
        int i = max_len <= 8
            ? 8 - mx_strlen(mx_st_point(current, 5))
            : max_len - mx_strlen(mx_st_point(current, 5));
        for (; i > 0; i--)
            printf(" ");
        printf("%s", mx_st_point(current, 5));
    }
    printf(" ");
    *j += 2;
}
