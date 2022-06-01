#include "ft_md.h"


t_md5 init() {
    t_md5 t;
    int i = 0;
    short rot0[] = { 7,12,17,22};
    short rot1[] = { 5, 9,14,20};
    short rot2[] = { 4,11,16,23};
    short rot3[] = { 6,10,15,21};

    t.r = (short *)malloc(sizeof(short) * 64);
    t.k = (unsigned *)malloc(sizeof(unsigned) * 64);
    for (;i<16;i++) t.r[i] = rot0[i%4];
    for (;i<32;i++) t.r[i] = rot1[i%4];
    for (;i<48;i++) t.r[i] = rot2[i%4];
    for (;i<64;i++) t.r[i] = rot3[i%4];
    for (i = 0; i < 64; i++) t.k[i] = floor(abs(sin(i + 1)) * 4294967296);
    t.h[0] = 0x67452301;
    t.h[1] = 0xEFCDAB89;
    t.h[2] = 0x98BADCFE;
    t.h[3] = 0x10325476;
    return t;
}

void deluxe(t_msg e) {
    t_md5 t = init();
    int grps, grp, q;
    int os = 0;
    unsigned char *msg2;
    unsigned abcd[4];
    int o = 0;
    int uu = 0;
    int k = 0;
    int ee = e.size + 1;
    
    while ((ee + k) % 512 != 448) k++;
    msg2 = malloc(ee + k);
    ft_memcpy(msg2, e.msg, e.size);
    msg2[e.size] = 0x80;
    while (uu++  < k)
        msg2[ee++] = 0;
    msg2[ee] = e.size;
    printf("%d,%d, %s\n", k, ee, msg2);
/*
    grps = 1 + (e.size + 8) / 64;
    msg2 = malloc( 64*grps);
    ft_memcpy(msg2, e.msg,e.size);
    msg2[e.size] = (unsigned char)0x80; 
    q = e.size + 1;
    while (q < 64*grps) {msg2[q] = 0; q++;}
    printf("k = %d\n", q);
    unsigned w = 8 * e.size;
    q -= 8;
    ft_memcpy(msg2 + q, &w, 4);
    printf("%d %d\n", q, grps);
    for (grp=0; grp<grps; grp++) {

    }
    */
    free(msg2);
    free(t.r);
    free(t.k);
}