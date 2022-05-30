#include "ft_md.h"

int mdd(char *msg) {
    int j,k;
    t_md5 m = init();
    unsigned *d = maker(&m, msg, strlen(msg));
    WBunion u;
        printf("= 0x");
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%02x",u.b[k]);
    }
    printf("\n");
 
    return 0;
    
}
int md5(t_md_opt *e) {
    int j,k;
    mdd("The quick brown fox jumps over the lazy dog.");   
}