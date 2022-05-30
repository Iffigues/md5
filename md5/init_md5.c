#include "ft_md.h"

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
 

t_md5 init() {
    t_md5 l;
     DgstFctn ff[] =  { &f0, &f1, &f2, &f3 };
     ft_memcpy(l.ff, ff, 4);
    unsigned Digest[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    ccpy(l.DigestHo, Digest,4);
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
    printf("%d\n", l.rot3[1]);
    short *rots[] = {rot0, rot1, rot2, rot3 };
    ft_memcpy(l.rots, rots, 4);
}