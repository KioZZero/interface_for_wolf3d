##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	./src/main.c \
		./src/init_intro/intro.c \
		./src/init_options/display_options.c \
		./src/initialization_interface/init_interface.c \
		./src/initialization_interface/init_interface_elements.c \
		./src/conditions.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude -Wall -Wextra -Werror

FLAGCSFML =	-lcsfml-graphics -lcsfml-window -lcsfml-system

FLAGCSFML +=	-lcsfml-audio -lcsfml-network -lm

NAME	=	interface

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(FLAGCSFML) $(CFLAGS)

clean:
	$(RM) $(NAME) $(OBJ)

fclean:	clean

re:	fclean all
