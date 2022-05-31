#include "ft_md.h"

void print_md5(unsigned *d) {
    int j,k;
      WBunion u;
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%02x",u.b[k]);
    }
    printf("\n");
}

int mdd(char *msg) {
    unsigned *d = maker(msg, ft_strlen(msg));
    print_md5(d);
    unsigned *dd = maker("msg", ft_strlen("msg"));
    print_md5(dd);
    return 0;
    
}
int md5(t_md_opt *e) {
    if (e->arg == NULL)
        return 0;
    for (int i = 0; e->arg[i];i++) printf("%s\n", e->arg[i]);
    mdd("foo");
    return 1;
}