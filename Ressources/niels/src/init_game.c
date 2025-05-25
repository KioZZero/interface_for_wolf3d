/*
** EPITECH PROJECT, 2024
** ING-Wolf3d
** File description:
** init_game.c
*/

#include "my.h"

// int worldMap[24][24]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

static int is_wall(int x, int y)
{
    return 0;
}

static void draw_floor_and_ceiling(sfRenderWindow *window)
{
    return;
}

static void handle_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

static sfRenderWindow *init_win(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "MyWorld", sfClose
        , NULL);

    if (!window)
        exit(84);
    return window;
}

sfSprite *init_background(void)
{
    sfTexture* texture = sfTexture_createFromFile("Ressources/Images/sky.bmp",
        NULL);
    sfSprite* background = sfSprite_create();

    if (!texture || !background)
        exit(0);
    sfSprite_setTexture(background, texture, sfTrue);
    return background;
}

sfCircleShape *init_player_point(player_t *player)
{
    sfCircleShape* point = sfCircleShape_create();

    sfCircleShape_setRadius(point, 3);
    sfCircleShape_setFillColor(point, sfRed);
    sfCircleShape_setPosition(point, (sfVector2f){400, 300});
    return point;
}

void game_display(void)
{
    sfRenderWindow *window = init_win();
    player_t *player = init_player();
    sfCircleShape *playerpoint = init_player_point(player);
    sfEvent event;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, &event);
        handle_player_input(playerpoint, clock);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawCircleShape(window, playerpoint, NULL);
        sfRenderWindow_display(window);
    }
    sfCircleShape_destroy(playerpoint);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
}
