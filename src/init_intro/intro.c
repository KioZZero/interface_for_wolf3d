/*
** EPITECH PROJECT, 2024
** interface
** File description:
** intro.c
*/

#include "my.h"

void intro_disp(menu_t *menu)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(menu->intro->clock));
    sfColor color = sfColor_fromRGBA(255, 255, 255, 0);

    if (time < 1.0f)
        color.a = (sfUint8)(255 * (time / 1.0f));
    else if (time < 3.0f)
        color.a = 255;
    else
        color.a = (sfUint8)(255 * ((4.0f - time) / 1.0f));
    sfSprite_setColor(menu->intro->logo, color);
    sfRenderWindow_clear(menu->win, sfBlack);
    sfRenderWindow_drawSprite(menu->win, menu->intro->logo, NULL);
    sfRenderWindow_display(menu->win);
}

static void handle_events(menu_t *menu, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(menu->win, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(menu->win);
    }
}

void play_intro(menu_t *menu)
{
    sfEvent event;

    sfMusic_play(menu->intro->music);
    sfClock_restart(menu->intro->clock);
    while (sfRenderWindow_isOpen(menu->win)) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(menu->intro->clock)) >=
            4.0f)
            break;
        handle_events(menu, &event);
        intro_disp(menu);
    }
}
