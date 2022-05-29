#ifndef FT_MD_H
# define FT_MD_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include<stdio.h> 
# include<fcntl.h> 
# include<errno.h> 

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

int             opens(char *t);
int             reads(int fd);
size_t          ft_strlen(const char *s);
int             ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

