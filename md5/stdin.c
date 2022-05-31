#include "ft_md.h"


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

char *read_stdin() {
    int n;
    int i = 30;
    unsigned char  buf[i + 1];
    char *r;
    r = NULL;

    ft_bzero(buf,i + 1);
    while ((n = read(STDIN_FILENO, buf, i)) > 0) {
        r = collapse(r, buf, n);
        ft_bzero(buf,i + 1);
    }
    printf("%s\n", r);
    free(r);
    return NULL;
}