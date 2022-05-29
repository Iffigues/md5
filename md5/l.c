#include "ft_md.h"

int opens(char *t) {
    int fd = open(t, O_RDONLY, 0);
    return fd;
}

int reads(int fd) {
    int i = 128;
    char  buf[128];
    while (read(fd, buf, i) != EOF) {
        printf("%s",buf);
    }
    return 1;
}
