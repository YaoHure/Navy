##
## EPITECH PROJECT, 2018
## Yaowanart Hure
## File description:
## Makefile
##

SRC	=	src/map_m.c			\
		src/connect.c		\
		src/count.c			\
		src/display_map.c	\
		src/error.c			\
		src/game.c			\
		src/handle.c		\
		src/input.c			\
		src/main.c			\
		src/usage.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CLIB	=	-L./lib/my -lmy

all:
	make -C ./lib/my/
	gcc $(SRC) -o navy $(CLIB) $(CFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f *~

fclean: clean
	make fclean -C ./lib/my/
	rm -f navy

re:	fclean all
	make re -C ./lib/my/
