# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:37:32 by bordenoy          #+#    #+#              #
#    Updated: 2019/03/22 15:47:56 by bordenoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I 

SRC=	ft_memalloc.c ft_maxunsignedsize.c ft_russianpeasant.c ft_pow.c	\
		ft_lstaddend.c ft_lstbeetwin.c  ft_jds.c ft_isbisextile.c		\
		ft_maonthn.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c	\
		ft_lstdelone.c ft_memdup.c ft_lstnew.c ft_memmove.c				\
		ft_strsplit.c ft_strlcat.c ft_itoa.c ft_strnstr.c ft_strrchr.c	\
		ft_memcmp.c ft_memchr.c ft_putnbr_fd.c ft_putnbr.c				\
		ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl.c 	\
		ft_putstr.c ft_putchar.c ft_strtrim.c ft_strjoin.c ft_strsub.c	\
		ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c	\
		ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c	\
		ft_strncmp.c ft_tolower.c ft_toupper.c ft_isprint.c				\
		ft_isascii.c ft_countdeci.c	ft_puiss.c 			\
		ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strcmp.c ft_strchr.c	\
		ft_strstr.c ft_strncat.c ft_strcat.c ft_memset.c ft_bzero.c		\
		ft_memcpy.c ft_memccpy.c ft_atoi.c ft_strlen.c ft_memalloc.c	\
		ft_strdup.c ft_strcpy.c ft_strncpy.c ft_addtomul.c				\
		get_next_line.c

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
		$(CC) -c $(SRC) 
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean

