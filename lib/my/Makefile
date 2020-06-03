##
## EPITECH PROJECT, 2018
## Huré Yaowanart
## File description:
## Makefile
##

SRC	=	my_strlen.c 			\
		my_putstr.c 			\
		my_putchar.c			\
		my_strcmp.c				\
		my_strcpy.c				\
		my_swap.c				\
		my_put_nbr.c			\
		my_getnbr.c				\
		my_strcat.c				\
		my_str_to_word_tab.c	\
		my_strncmp.c			\
		my_strdup.c				\
		my_strndup.c			\
		my_strcat_mini.c		\
		my_clean_str.c			\
		my_str_isnum.c

OBJ	= $(SRC:.c=.o)

NAME	= libmy.a

all:	$(OBJ)
		ar rc $(NAME) *.o
		rm -f $(OBJ) *~
clean:
		rm -f $(OBJ) *~

fclean:	clean
		rm -f $(NAME)

re:		fclean all
