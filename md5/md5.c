#include "ft_md.h"

void print_md5(unsigned *d) {
    int j,k;
      WBunion u;
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%02x",u.b[k]);
    }
}

unsigned  *mdd(char *msg) {
    return maker(msg, ft_strlen(msg));   
}

int vovo(t_md_opt *e) {
    unsigned *d;
    char *t = reads(STDIN_FILENO);
    t[ft_strlen(t) - 1] = 0; 
    d = mdd(t);
    if (!e->q && !e->r) {
        if (e->p)
         printf("(\"%s\") = ", t);
        else 
         printf("(stdin) = ");
    }
    print_md5(d);
     if (!e->q && e->r) {
        if (e->p)
         printf(" = (\"%s\")", t);
        else 
         printf(" = (stdin)");
    }
    printf("\n");
    if (t) free(t);
    return 0;
}

int vava(t_md_opt *e) {
    char *t = NULL;
    char *p = NULL;
    unsigned *d;

    if (e->s) 
        t = *e->arg++;

    if (e->p)
        p = reads(STDIN_FILENO);
    if (p) {
        p[ft_strlen(p) - 1] = 0; 
        d = mdd(p);
        print_md5(d);
        free(p);
    }
  
    if (t) {
        d = mdd(t);
        print_md5(d);
    }
   
    while (*e->arg) {
        e->arg++;
    }
    return 0;
}

int md5(t_md_opt *e) {
    if (e->arg == NULL)
       return vovo(e);
    return vava(e);
}