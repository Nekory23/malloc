##
## EPITECH PROJECT, 2021
## Malloc
## File description:
## makefile
##

NAME	=	libmy_malloc.so

SRC		=	src/functions.c		\
			src/malloc.c		\
			src/free.c			\
			src/realloc.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS=	-I./include/

CFLAGS	=	-Wall -Werror -Wextra -g -fpic

all		:	$(OBJ)
			gcc $(CFLAGS) -shared -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re