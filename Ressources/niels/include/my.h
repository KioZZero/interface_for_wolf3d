/*
** EPITECH PROJECT, 2024
** undefined
** File description:
** Untitled-1
*/

#ifndef WOLF3D_H_
    #define WOLF3D_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <dirent.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #define PI 3.14159265359
    #define PI_OVER_2 PI / 2
    #define WIDTH 50
    #define HEIGHT 50
typedef struct player_s {
    float angle;
    int x;
    int y;
} player_t;
void game_display(void);
player_t *init_player(void);
void handle_player_input(sfCircleShape *playerpoint, sfClock *clock);
#endif /* WOLF3D_H_ */
