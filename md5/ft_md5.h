#ifndef FT_MD5_H
# define FT_MD5_H

typedef union uwb {
    unsigned w;
    unsigned char b[4];
} WBunion;
 
typedef unsigned Digest[4];
typedef unsigned (*DgstFctn)(unsigned a[]);

typedef struct  s_md5 {
    short *r;
    unsigned *k;
    unsigned h[4];
}  t_md5;
unsigned *maker( const char *msg, int mlen);
#endif

