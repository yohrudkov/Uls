#include "libmx.h"

static int hex(int num) {
    int count = 0;

    for (int i = num; i != 0; i /= 16)
        count++;
    return count;
}

static char hex_if(int i) {
    if (i % 16 == 10)
        return 'a';
    else if (i % 16 == 11)
        return 'b';
    else if (i % 16 == 12)
        return 'c';
    else if (i % 16 == 13)
        return 'd';
    else if (i % 16 == 14)
        return 'e';
    else if (i % 16 == 15)
        return 'f';
    else
        return i % 16 + '0';
}

char *mx_hex(int num) {
    int j = 0;
    char *s = mx_strnew(hex(num));

    for (int i = num; i != 0; i /= 16) {
        s[j] = hex_if(i);
        j++;
    }
    mx_str_reverse(s);
    return s;
}
