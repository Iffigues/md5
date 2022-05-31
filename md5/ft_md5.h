#ifndef FT_MD5_H
# define FT_MD5_H

typedef union uwb {
    unsigned w;
    unsigned char b[4];
} WBunion;
 
typedef unsigned Digest[4];
typedef unsigned (*DgstFctn)(unsigned a[]);

typedef struct  s_md5 {
    Digest h0;
    DgstFctn ff[4];
    short M[4];
    short O[4];
    short rot0[4];
    short rot1[4];
    short rot2[4];
    short rot3[4];
    short *rots[4];
    unsigned kspace[64];
    unsigned *k;
    Digest h;
}  t_md5;

typedef unsigned (*DgstFctn)(unsigned a[]);


t_md5   init();
unsigned *maker(const char *msg, int mlen);
unsigned f0( unsigned abcd[] );
unsigned f1( unsigned abcd[] );
unsigned f2( unsigned abcd[] );
unsigned f3( unsigned abcd[] );
unsigned *calcKs( unsigned *k);
unsigned rol( unsigned v, short amt );
#endif

