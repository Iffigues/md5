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
    for (i = 0; i < 64; i++) 
	    t.k[i] = floor(fabs(sin(i + 1)) * 4294967296);
    t.h[0] = 0x67452301;
    t.h[1] = 0xEFCDAB89;
    t.h[2] = 0x98BADCFE;
    t.h[3] = 0x10325476;
    return t;
}


uint32_t leftRotate (unsigned v, short amt ) {
    unsigned  msk1 = (1<<amt) -1;
    return ((v>>(32-amt)) & msk1) | ((v<<amt) & ~msk1);
}


int leftR(int n, unsigned int d)
{
    //return ((n) << (d)) | ((n) >> (32 - (d)));
   return (n << d)|(n >> (INT_BITS - d));
}

uint32_t *deluxe( const char *msg, int size) {
     t_md5 t = init();
    unsigned w;
    int q;
    int oo  = 0;

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
    msg2 = malloc(ee);
    ft_memcpy(msg2, msg, size);
    msg2[size] = 0x80;
    while (uu < ee) 
        msg2[uu++] = 0;
    w = size * 8;
    uu = uu - 8;
    printf("%d\n", uu);
    ft_memcpy(msg2 + uu, &w, 4);

    for (int i = 0; i < ee / 64; i++) {
        ft_memcpy(mm.b, msg2+oo, 64);
        uint32_t a = t.h[0];
    	uint32_t b = t.h[1];
    	uint32_t c = t.h[2];
    	uint32_t d = t.h[3];
        for (int y = 0; y < 64; y++ ) {
	    	if (y <= 15) {
		    	f = (b & c) | ((~b) & d);		
			    g = y;	
		    } else if (y <= 31) {
		    	f = (d & b) | ((~d) & c);
			    g = (5 * y + 1 ) % 16;
    		} else if (y <= 47) {
			    f = b ^ c ^ d;
			    g = (3 * y + 5) % 16;
		    } else if (y <= 63) {
			    f = c ^ (b | (~d));
			    g = (7 * y) % 16; 
		    }
	    	uint32_t tmp = d;
		    d = c;
		    c = b;
		    b = leftRotate((a + f + t.k[y] + mm.w[g]), t.r[y]) + b;
		    a = tmp;
	    }
	
        oo = oo + 64;
	    t.h[0] = t.h[0] + a;
	    t.h[1] = t.h[1] + b;
	    t.h[2] = t.h[2] + c;
	    t.h[3] = t.h[3]	+ d;
    }
    free(msg2);
    free(t.r);
    free(t.k);
    return t.h;
}
