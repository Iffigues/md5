#include "ft_md.h"


int outer(char *t) {
    int fd = open(t, O_WRONLY | O_APPEND | O_CREAT, 0644);
    return fd;
}

int opens(char *t) {
    int fd = open(t, O_RDONLY, 0);
    return fd;
}
static char *colle(char *r, unsigned char *b, int yy, int l) {
    char *p;
    int z = 0;
    int u = 0;
    int o = yy + l;
    
    p = (char *)malloc((sizeof(char) * o));
    while (z < yy) p[z] = r[z++];
    while (u < l) p[z++] = b[u++];
    free(r);
    return p;
}

static char  *collapse(char *r, unsigned char *b, int yy, int l) {
    if (r == NULL) {
        int i = 0;
        r = (char *)malloc(((sizeof(char ) * l)));
        while (i < l)
            r[i] = b[i++];
        return r;
    }
    return colle(r, b, yy, l);
}

t_msg reads(int fd) {
    int i = 500;
    t_msg   y;
    int p = 0;
    y.msg = NULL;
    y.size = 0;
    int n;
    unsigned char  buf[i + 1];
    ft_bzero(buf,i + 1);
    while ((n = read(fd, buf, i)) > 0) {
        y.msg = collapse(y.msg, buf, y.size, n);
        y.size = y.size + n;
        ft_bzero(buf,i + 1);
    }
    return y;
}