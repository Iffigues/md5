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
    while (b[u]) {
        p[z++] = b[u++];
    }
    p[z] = 0;
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
char *reads(int fd) {
    int i = 30;
    int p = 0;
    char *r;
    r = NULL;
    int n;
    unsigned char  buf[i + 1];
    ft_bzero(buf,i + 1);
    while ((n = read(fd, buf, i)) > 0) {
        r = collapse(r, buf, n);
        ft_bzero(buf,i + 1);
    }
    return r;
}