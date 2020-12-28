#ifndef MACROS_HEADER_H

#define FLAG_L           0
#define FLAG_A           1
#define FLAG_R           2

#define SET_BIT(BF, N)      BF |= (1 << N)
#define BIT_IS_SET(BF, N)   (BF >> N) & 0x1

#define MX_ISEXE(m)      (m & MX_IFMT) == MX_IFREG && (m & 0111)
#define MX_ISBLK(m)      (m & MX_IFMT) == MX_IFBLK
#define MX_ISCHR(m)      (m & MX_IFMT) == MX_IFCHR
#define MX_ISDIR(m)      (m & MX_IFMT) == MX_IFDIR
#define MX_ISFIFO(m)     (m & MX_IFMT) == MX_IFIFO
#define MX_ISREG(m)      (m & MX_IFMT) == MX_IFREG
#define MX_ISLNK(m)      (m & MX_IFMT) == MX_IFLNK
#define MX_ISSOCK(m)     (m & MX_IFMT) == MX_IFSOCK
#define MX_ISWHT(m)      (m & MX_IFMT) == MX_IFWHT

#define MX_IFMT          0170000
#define MX_IFIFO         0010000
#define MX_IFCHR         0020000
#define MX_IFDIR         0040000
#define MX_IFBLK         0060000
#define MX_IFREG         0100000
#define MX_IFLNK         0120000
#define MX_IFSOCK        0140000
#define MX_IFWHT         0160000

#define MX_IRWXU         0000700
#define MX_IRUSR         0000400
#define MX_IWUSR         0000200
#define MX_IXUSR         0000100

#define MX_IRWXG         0000070
#define MX_IRGRP         0000040
#define MX_IWGRP         0000020
#define MX_IXGRP         0000010

#define MX_IRWXO         0000007
#define MX_IROTH         0000004
#define MX_IWOTH         0000002
#define MX_IXOTH         0000001

#define MX_ISUID         0004000
#define MX_ISGID         0002000
#define MX_ISVTX         0001000

#define MX_MAJOR(x)        ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x)        ((int32_t)((x) & 0xffffff))

#endif
