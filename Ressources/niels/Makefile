##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## Makefile
##

SRC =	./src/main.c \
		./src/init_game.c \
		./src/maze_gen.c \
		./src/player_related/player_movement.c \
		./src/player_related/player_settings.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Iinclude -g3

FLAGCSFML +=	-lcsfml-graphics -lcsfml-window -lcsfml-system

FLAGCSFML +=	-lcsfml-audio -lcsfml-network -lm

NAME = wolf3d

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(FLAGCSFML) $(CFLAGS)

clean:
	$(RM) $(NAME) $(OBJ)

fclean:	clean

re:	fclean all
