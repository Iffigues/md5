#ifndef FT_MD5_H
# define FT_MD5_H
#include <stdio.h>
#include <string.h>

#include <stdint.h>

# define RL(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
typedef union uwb {
    unsigned w;
    unsigned char b[4];
} WBunion;
 
typedef unsigned Digest[4];
typedef unsigned (*DgstFctn)(unsigned a[]);

typedef struct  s_md5 {
    short *r;
    unsigned *k;
    uint32_t h[4];
}  t_md5;
#endif

