#include "ft_md.h"

 int psf(char **argv, t_md_opt *l) {
    printf("%s\n", *argv);
    if (!argv)
        return -1;
    if (ft_strncmp(*argv, "md5", 3) == 0) {
        return 1;
    }
    l->pf = NULL;
    return -1;
}

static int getOpt(char c, int u, char *t, t_md_opt *y) {
     while (*t) {
        if (*t == c) {
            if (c == 'p') {
                if (y->p)
                    return 1;
                y->p = u;
            }
            else if (c == 'q') {
                if (y->q)
                    return 1;
                y->q = u;
            }
            else if (c == 'r')  {
                if (y->r)
                    return 0;
                y->r = 1;
            } else if (c == 's') {
                if (y->s)
                    return 1;
                y->s = u;
            }
            return 0;
        }
        t++;
    }
    return 1;
}

int getOutput(t_md_opt *l, char *h) {
    int i = opens(h);
    l->out = i;
    return i;
}

static int opt(char **argv, t_md_opt *l) {
    int u = 0;
   if ((psf(argv++, l)) < 0)
       return EXIT_FAILURE;
    while (*argv) {
        if (ft_strlen(*argv) == 0)
            return (EXIT_FAILURE);
        if (ft_strncmp(*argv, "-", 1) == 0) {
            if (ft_strlen(*argv) == 1) {          
             return (EXIT_FAILURE);
            }
            if (ft_strncmp(*argv, "--", 2) == 0) {
                l->arg = argv;
                return 0;
            } else if (ft_strncmp(*argv, "-t", 2) == 0) {
                argv++;
         
                if (l->t > 0)
                    return EXIT_FAILURE;
                if (!*argv)
                        return (EXIT_FAILURE);
        
                if (ft_strlen(*argv) == 0)
                    return (EXIT_FAILURE);
                getOutput(l, *argv);
                l->t = 1;
            } else if(ft_strlen(*argv) == 2) {
                u++;
                ++*argv;
                if (getOpt(**argv, u, "pqrs", l)) { 
                   return EXIT_FAILURE;
                }
            } else {
               return EXIT_FAILURE;
            }
        } else {
            l->arg = argv;
            return EXIT_SUCCESS;
        }
        argv++;
	}
	return EXIT_SUCCESS;
}


static t_md_opt getOptl() {
    t_md_opt l;
    l.p = 0;
    l.q = 0;
    l.out = 1;
    l.r = 0;
    l.t = 0;
    l.s = 0;
    l.nb = 0;
    return l;
}

int  main(int argc, char **argv)
{
    t_md_opt l = getOptl();

	if (argc > 1) {
		int y = opt(++argv, &l);
        if (!y) return (EXIT_FAILURE);
    }
	return (EXIT_FAILURE);
} 
