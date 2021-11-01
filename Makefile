CC  =	gcc -g3 -fsanitize=address
FLAGS   =   -Wall -Wextra -Werror
SRC =   pushswap.c sort_3.c sort_5.c sort_big.c \
	utils.c utils1.c utils2.c
NAME    =   push_swap 

all: $(NAME)
$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
clean:
	rm -rf *.o
fclean: clean
	@rm push_swap

re: fclean all
