NAME=ft_md5
SRC=main.c open.c md5.c init_md5.c
OBJ= $(SRC:.c=.o)
CC= gcc -g -fsanitize=address
INCLUDE= -I ./
all:$(NAME)
$(NAME):$(OBJ)
	@make -C libft/ 
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME) libft/libft.a -lm
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	rm -f *.o
	@make clean -C  libft/
fclean:clean
	rm -f $(NAME)
	make fclean -C libft/
re:fclean all
.PHONY:all clean fclean re
