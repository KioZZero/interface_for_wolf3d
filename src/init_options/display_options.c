/*
** EPITECH PROJECT, 2024
** interface
** File description:
** display_options.c
*/

#include "my.h"

static void handle_event_ex(menu_t *menu)
{
    // sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->win);
    // sfFloatRect start_bounds = sfSprite_getGlobalBounds(menu->start);
    // sfFloatRect option_bounds = sfSprite_getGlobalBounds(menu->option);
    // sfFloatRect quit_bounds = sfSprite_getGlobalBounds(menu->quit);
    return;
    printf("%d", menu->options->in);
}

void handle_events_options(menu_t *menu, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(menu->win, event)) {
        if (event->type == sfEvtClosed || (event->type == sfEvtKeyPressed &&
            event->key.code == sfKeyEscape && menu->options->in != 1))
            sfRenderWindow_close(menu->win);
        if (event->type == sfEvtMouseButtonPressed &&
            event->mouseButton.button == sfMouseLeft) {
            handle_event_ex(menu);
        }
    }
}

static void resize_and_draw(sfRenderWindow *win, sfSprite *sprite)
{
    sfSprite_setScale(sprite, (sfVector2f){500, 500});
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void display_options(menu_t *menu)
{
    sfSprite_setScale(menu->options->background_sp,
        (sfVector2f){WIDTH, HEIGHT});
    sfRenderWindow_drawSprite(menu->win, menu->options->background_sp, NULL);
    resize_and_draw(menu->win, menu->options->background_sp);
    resize_and_draw(menu->win, menu->options->wsize_sp);
    resize_and_draw(menu->win, menu->options->z_sp);
    resize_and_draw(menu->win, menu->options->q_sp);
    resize_and_draw(menu->win, menu->options->s_sp);
    resize_and_draw(menu->win, menu->options->d_sp);
}
