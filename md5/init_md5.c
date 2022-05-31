#include "ft_md.h"
#include <math.h>

unsigned f0( unsigned abcd[] ){
    return ( abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);}
 
unsigned f1( unsigned abcd[] ){
    return ( abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);}
 
unsigned f2( unsigned abcd[] ){
    return  abcd[1] ^ abcd[2] ^ abcd[3];}
 
unsigned f3( unsigned abcd[] ){
    return abcd[2] ^ (abcd[1] |~ abcd[3]);}

 unsigned *calcKs( unsigned *k)
{
    double s, pwr;
    int i;
 
    pwr = pow( 2, 32);
    for (i=0; i<64; i++) {
        s = fabs(sin(1+i));
        k[i] = (unsigned)( s * pwr );
    }
    return k;
}

unsigned rol( unsigned v, short amt )
{
    unsigned  msk1 = (1<<amt) -1;
    return ((v>>(32-amt)) & msk1) | ((v<<amt) & ~msk1);
}
 

t_md5 init() {
    t_md5 l;
    l.k=NULL;

     l.ff[0] = &f0;
     l.ff[1] = &f1;
     l.ff[2] = &f2;
     l.ff[3] = &f3;
     l.h0[0] =  0x67452301;
     l.h0[1] = 0xEFCDAB89;
     l.h0[2] = 0x98BADCFE;
     l.h0[3] = 0x10325476;
    l.M[0] = 1 ;
    l.M[1] = 5;
    l.M[2] = 3;
    l.M[3] = 7;
    l.O[0] = 0;
    l.O[1] = 1;
    l.O[2] = 5;
    l.O[3] = 0;
    l.rot0[0] = 7;
    l.rot0[1]= 12;
    l.rot0[2]=17;
    l.rot0[3] =22;

    l.rot1[0] = 5;
    l.rot1[1]= 9;
    l.rot1[2]=14;
    l.rot1[3] =20;

      l.rot2[0] = 4;
    l.rot2[1]= 11;
    l.rot2[2]=16;
    l.rot2[3] =203;
  l.rot3[0] =6;
    l.rot3[1]= 10;
    l.rot3[2]=15;
    l.rot3[3] =21;
    l.rots[0] = l.rot0;
    l.rots[1] = l.rot1;
    l.rots[2] = l.rot2;
    l.rots[3] = l.rot3;
    return l;
}


unsigned *maker( const char *msg, int mlen) {
 static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    static DgstFctn ff[] = { &f0, &f1, &f2, &f3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rot0[] = { 7,12,17,22};
    static short rot1[] = { 5, 9,14,20};
    static short rot2[] = { 4,11,16,23};
    static short rot3[] = { 6,10,15,21};
    static short *rots[] = {rot0, rot1, rot2, rot3 };
    static unsigned kspace[64];
    static unsigned *k;
 
    static Digest h;
    Digest abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;
    short *rotn;
    union {
        unsigned w[16];
        char     b[64];
    }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;
 
    if (k==NULL) k= calcKs(kspace);
 
    for (q=0; q<4; q++) h[q] = h0[q];   // initialize
 
    {
        grps  = 1 + (mlen+8)/64;
        msg2 = malloc( 64*grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80;  
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
            WBunion u;
            u.w = 8*mlen;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }
 
    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) abcd[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotn = rots[p];
            m = M[p]; o= O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);
 
                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++)
            h[p] += abcd[p];
        os += 64;
    }
 
    if( msg2 )
        free( msg2 );
 
    return h;
} 