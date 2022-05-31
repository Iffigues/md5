#include "ft_md.h"

void print_md5(unsigned *d) {
    int j,k;
      WBunion u;
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%02x",u.b[k]);
    }
}

unsigned  *mdd(t_msg t) {
    printf("e");
    return maker(t.msg, t.size);   
}

void printer(t_md_opt *e, t_msg t, char *y,  int i) {
       if (i) printf("MD5 ");
       unsigned *d = mdd(t);
       if (!e->q && !e->r) {
        if (e->p)
         printf("(\"%s\") = ", t.msg);
        else 
         printf("(%s) = ", y);
    }
    print_md5(d);
     if (!e->q && e->r) {
        if (e->p)
         printf(" = (\"%s\")", t.msg);
        else 
         printf(" = (%s)", y);
    }
    printf("\n");
}

int vovo(t_md_opt *e) {
    t_msg t = reads(STDIN_FILENO);
    t.msg[ft_strlen(t.msg) - 1] = 0;
    if (e->p)
        printer(e, t, t.msg, 0);
    else 
    printer(e, t, "stdin", 0);
    if (t.msg) free(t.msg);
    return 0;
}



int vava(t_md_opt *e) {
     t_msg t;
     t_msg p;
    unsigned *d;
    int i;
    p.msg = NULL;
    t.msg = NULL;

    if (e->s) {
        t.msg = *e->arg++;
        t.size = ft_strlen(t.msg);
    }
    if (e->p)
        p = reads(STDIN_FILENO);
    if (p.msg) {
        printf("s-%d\n", p.size);
        p.msg[ft_strlen(p.msg) - 1] = 0; 
        printer(e, p, p.msg, 0);
        free(p.msg);
    }
    if (t.msg)
        printer(e, t, t.msg, 1);
   
    while (*e->arg) {
        i = opens(*e->arg);
        if (i < 0)
            return 1;
        p = reads(i);
        printer(e, p, *e->arg, 1);
        e->arg++;
        free(p.msg);
    }
    return 0;
}

int md5(t_md_opt *e) {
 printf("e\n");
    if (e->arg == NULL)
       return vovo(e);
    return vava(e);
}