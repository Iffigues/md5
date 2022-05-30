#include "ft_md.h"
#include <math.h>
void ccpy(unsigned  *e, unsigned *c, int v) {
    int y = 0;

    while (y < v) {
        e[y] = c[y];
        y++;
    }
}

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
     Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    ccpy(l.h0, h0,4);
    short M[] = { 1, 5, 3, 7 };
    ft_memcpy(l.M, M, 4);
    short O[] = { 0, 1, 5, 0 };
    ft_memcpy(l.O, O, 4);
    short rot0[] = { 7,12,17,22};
    ft_memcpy(l.rot0, rot0, 4);
    short rot1[] = { 5, 9,14,20};
    ft_memcpy(l.rot1, rot1, 4);
    short rot2[] = { 4,11,16,23};
    ft_memcpy(l.rot2, rot2, 4);
    short rot3[] = { 6,10,15,21};
    ft_memcpy(l.rot3, rot3, 4);
    short *rots[] = {rot0, rot1, rot2, rot3 };
    l.rots[0] = rot0;
    l.rots[1] = rot1;
    l.rots[2] = rot2;
    l.rots[3] = rot3;
    return l;
}


unsigned *maker(t_md5 *l,  const char *msg, int mlen) {
    unsigned abcd[4];
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
    if (l->k==NULL) l->k= calcKs(l->kspace);
    for (q=0; q<4; q++)
        l->h[q] = l->h0[q]; 
    {
        grps  = 1 + (mlen+8)/64;
        msg2 = malloc( 64*grps);
        ft_memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80;  
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
            WBunion u;
            u.w = 8*mlen;
            q -= 8;
            ft_memcpy(msg2+q, &u.w, 4 );
        }
    }
    for (grp=0; grp<grps; grp++)
    {
        ft_memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) abcd[q] = l->h[q];
        for (p = 0; p<4; p++) {
            fctn = l->ff[p];
            rotn = l->rots[p];
            printf("%hn\n", l->rots[p]);
            m = l->M[p]; o= l->O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                abcd[0]+ fctn(abcd) + l->k[q+16*p] + mm.w[g];
                printf("rotn = %d  %d\n", abcd[0]+ fctn(abcd) + l->k[q+16*p] + mm.w[g], rotn[q%4]);
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + l->k[q+16*p] + mm.w[g], rotn[q%4]);
                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++)
            l->h[p] += abcd[p];
        os += 64;
    }
 
        if( msg2 )
         free( msg2 );
 
        return l->h;
} 