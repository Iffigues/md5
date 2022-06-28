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

void deluxe( const char *msg, int size) {
    t_md5 t = init();
    unsigned w;
    int q;
    printf("%s %d\n", msg, size);

    unsigned char *msg2;
    unsigned abcd[4];
    int o = 0;
    int uu = size + 1;
    int ee = size * 8 + 1;
    
    while ((ee) % 512 != 448) ee++;
    ee /= 8;
    ee = ee + 8;
    msg2 = malloc(ee);
    printf("s = %d\n", ee);
    ft_memcpy(msg2, msg, size);
    msg2[size] = 0x80;
    while (uu < ee) 
        msg2[uu++] = 0;
    printf("%d\n", uu);
    w = size * 8;
    q = size + 1;
    msg2[ee] = size;
    printf("%s\n", msg2);

    free(msg2);
    free(t.r);
    free(t.k);
}