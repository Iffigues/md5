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
    printf("%s strlen= %ld\n", msg ,ft_strlen(msg));
    return maker(msg, ft_strlen(msg));   
}

void printer(t_md_opt *e, char *t, char *y,  int i) {
       if (i) printf("MD5 ");
       unsigned *d = mdd(t);
       if (!e->q && !e->r) {
        if (e->p)
         printf("(\"%s\") = ", t);
        else 
         printf("(%s) = ", y);
    }
    print_md5(d);
     if (!e->q && e->r) {
        if (e->p)
         printf(" = (\"%s\")", t);
        else 
         printf(" = (%s)", y);
    }
    printf("\n");
}

int vovo(t_md_opt *e) {
    char *t = reads(STDIN_FILENO);
    t[ft_strlen(t) - 1] = 0;
    if (e->p)
        printer(e, t, t, 0);
    else 
    printer(e, t, "stdin", 0);
    if (t) free(t);
    return 0;
}



int vava(t_md_opt *e) {
    char *t = NULL;
    char *p = NULL;
    unsigned *d;
    int i;

    if (e->s) 
        t = *e->arg++;
    if (e->p)
        p = reads(STDIN_FILENO);
    if (p) {
        p[ft_strlen(p) - 1] = 0; 
        printer(e, p, p, 0);
        free(p);
    }
    if (t)
        printer(e, t, t, 1);
   
    while (*e->arg) {
        i = opens(*e->arg);
        if (i < 0)
            return 1;
        p = reads(i);
        printer(e, p, *e->arg, 1);
        *e->arg++;
        free(p);
    }
    return 0;
}

int md5(t_md_opt *e) {

    if (e->arg == NULL)
       return vovo(e);
    return vava(e);
}