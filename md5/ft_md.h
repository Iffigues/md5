#ifndef FT_MD_H
# define FT_MD_H
# include "ft_md5.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include<stdio.h> 
# include<fcntl.h> 
# include<errno.h> 
#include <math.h>
#define INT_BITS 32

typedef struct  s_msg {
    char        *msg;
    int         size;
}               t_msg;

typedef struct  s_md_opt
{
    int         out;
    char        **arg;
    int         nb;
    int         (*pf)(struct s_md_opt *d);
	int         p;
    int         q;
    int         r;
    int         s;
    int         t;
}               t_md_opt;
int             outer(char *t);
int             opens(char *t);
t_msg            reads(int fd);
size_t          ft_strlen(const char *s);
int             ft_strncmp(const char *s1, const char *s2, size_t n);
int             md5(t_md_opt *e);
uint32_t *deluxe(const char *msg, int mlen);

#endif

