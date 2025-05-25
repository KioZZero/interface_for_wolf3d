/*
** EPITECH PROJECT, 2024
** undefined
** File description:
** Untitled-1
*/

#ifndef MY_H_
    #define MY_H_
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
    #define WIDTH 800
    #define HEIGHT 600
    #define TITLE_SIZE 10

typedef struct intro_s {
    sfImage *logo_app;
    sfMusic *music;
    sfSprite *logo;
    sfClock *clock;
    int exit;
} intro_t;

typedef struct options_s {
    bool in;
    sfSprite *background_sp;
    sfSprite *volume_sp;
    sfSprite *wsize_sp;
    sfSprite *z_sp;
    sfSprite *q_sp;
    sfSprite *s_sp;
    sfSprite *d_sp;
    char *win_size;
    float volume;
    char *z;
    char *q;
    char *s;
    char *d;
} options_t;

typedef struct menu_s {
    sfRenderWindow *win;
    sfMusic *music;
    sfSprite *background;
    sfSprite *start;
    sfClock *clock;
    sfSprite *option;
    sfSprite *quit;
    float volume;
    intro_t *intro;
    options_t *options;
} menu_t;

sfSprite *init_sprite(sfRenderWindow *win, char *filepath);
void conditions(int ac, char **av);
void interface_display(void);
void play_intro(menu_t *menu);
sfRenderWindow *init_win(void);
menu_t *init_menu_elmnts(void);
void display_options(menu_t *menu);
void handle_events_options(menu_t *menu, sfEvent *event);
#endif /* MY_H_ */
