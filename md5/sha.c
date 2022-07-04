#include "ft_md.h"


static t_sha init() {
    t_sha t;
    t.h[0] = 0x6a09e667;
    t.h[1] = 0xbb67ae85;
    t.h[2] = 0x3c6ef372;
    t.h[3] = 0xa54ff53a;
    t.h[4] = 0x510e527f;
    t.h[5] = 0x9b05688c;
    t.h[6] = 0x1f83d9ab;
    t.h[7] = 0x5be0cd19;
    uint32_t k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };
    t.k = k;
    return t;
}

uint32_t *sha( const char *msg, int size) {
    t_sha t = init();
    unsigned w;
    int q;

   uint32_t f;
   int g;

    union {
        unsigned w[16];
        char     b[64];
    }mm;

    unsigned char *msg2;
    int o = 0;
    int uu = size + 1;
    int ee = size * 8 + 1;    
    while ((ee) % 512 != 448) ee++;
    ee /= 8;
    ee = ee + 8;
printf("dd %d\n", uu);
    msg2 = malloc(ee);
    ft_memcpy(msg2, msg, size);
    msg2[size] = 0x80;
printf("dd %d\n", uu);
    while (uu < ee) 
        msg2[uu++] = 0;
    printf("ddm %d\n", uu);
    w = size * 8;
    uu = uu - 8;
    printf("ds %d\n", uu);
    ft_memcpy(msg2 + uu, &w, 4);
    printf("ldd %d\n", msg2[uu]);
}
