##
## EPITECH PROJECT, 2019
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	./src

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS	=	-W -Wextra -Wall

SRC1	=	$(SRC)/main.c		\
			$(SRC)/hunter.c		\
			$(SRC)/game.c		\
			$(SRC)/display.c	\
			$(SRC)/clock.c		\
			$(SRC)/int_to_str.c	\
			$(SRC)/score.c		\
			$(SRC)/my_getnbr.c

NAME	=	my_hunter

CC	=	gcc

OBJ	=	$(SRC1:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFMLFLAGS)

CFLAGS	=	-W -Wall -Wextra $(CSFMLFLAGS) -I include -g

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

.PHONY: all clean fclean re

re: fclean all
