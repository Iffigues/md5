#include "ft_md.h"


int outer(char *t) {
    int fd = open(t, O_WRONLY | O_APPEND | O_CREAT, 0644);
    printf("hello %d\n", fd);
    return fd;
}

int opens(char *t) {
    int fd = open(t, O_RDONLY, 0);
    return fd;
}
static char *colle(char *r, unsigned char *b, int l) {
    char *p;
    int z = 0;
    int u = 0;
    int i = ft_strlen(r);
    int o = i + l;
    p = (char *)malloc((sizeof(char) * o) + 1);
    while (r[z]) {
        p[z] = r[z];
        z++;
    }
    while (u < l) {
        p[z++] = b[u++];
    }
    p[z] = 0;
    free(r);
    return p;
}

static char  *collapse(char *r, unsigned char *b, int l) {
    if (r == NULL) {
        int i = 0;
        r = (char *)malloc(((sizeof(char ) * l) + 1));
        while (i < l) {
            r[i] = b[i];
            i++;
        }
        r[i] = 0;
        return r;
    }
    return colle(r, b, l);
}
t_msg reads(int fd) {
    int i = 30;
    t_msg   y;
    int p = 0;
    y.msg = NULL;
    y.size = 0;
    int n;
    unsigned char  buf[i + 1];
    ft_bzero(buf,i + 1);
    while ((n = read(fd, buf, i)) > 0) {
        y.msg = collapse(y.msg, buf, n);
        y.size += n;
        ft_bzero(buf,i + 1);
    }
    return y;
}