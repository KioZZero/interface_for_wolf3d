/*
** EPITECH PROJECT, 2024
** ING-Wolf3d
** File description:
** init_game.c
*/

#include "my.h"

static void handle_event_ex(menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->win);
    sfFloatRect start_bounds = sfSprite_getGlobalBounds(menu->start);
    sfFloatRect option_bounds = sfSprite_getGlobalBounds(menu->option);
    sfFloatRect quit_bounds = sfSprite_getGlobalBounds(menu->quit);

    if (sfFloatRect_contains(&start_bounds, mouse.x, mouse.y)){
        sfMusic_stop(menu->music);
        system("./.launch_game.sh");
    }
    if (sfFloatRect_contains(&option_bounds, mouse.x, mouse.y))
        menu->options->in = true;
    if (sfFloatRect_contains(&quit_bounds, mouse.x, mouse.y))
        sfRenderWindow_close(menu->win);
}

static void handle_events(menu_t *menu, sfEvent *event)
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

void display(menu_t *menu)
{
    sfRenderWindow_clear(menu->win, sfBlack);
    sfRenderWindow_drawSprite(menu->win, menu->background, NULL);
    sfRenderWindow_drawSprite(menu->win, menu->start, NULL);
    sfRenderWindow_drawSprite(menu->win, menu->option, NULL);
    sfRenderWindow_drawSprite(menu->win, menu->quit, NULL);
    sfRenderWindow_display(menu->win);
}

static void destroy_all_intro(intro_t *intro)
{
    if (!intro)
        return;
    if (intro->music)
        sfMusic_destroy(intro->music);
    if (intro->logo)
        sfSprite_destroy(intro->logo);
    if (intro->clock)
        sfClock_destroy(intro->clock);
    free(intro);
    intro = NULL;
}

static void destroy_all_options(options_t *options)
{
    if (!options)
        return;
    if (options->z_sp)
        sfSprite_destroy(options->z_sp);
    if (options->q_sp)
        sfSprite_destroy(options->q_sp);
    if (options->s_sp)
        sfSprite_destroy(options->s_sp);
    if (options->d_sp)
        sfSprite_destroy(options->d_sp);
    if (options->volume_sp)
        sfSprite_destroy(options->volume_sp);
    if (options->wsize_sp)
        sfSprite_destroy(options->wsize_sp);
    if (options->background_sp)
        sfSprite_destroy(options->background_sp);
    free(options);
    options = NULL;
}

static void destroy_all(menu_t *menu)
{
    if (!menu)
        return;
    if (menu->music)
        sfMusic_destroy(menu->music);
    if (menu->background)
        sfSprite_destroy(menu->background);
    if (menu->start)
        sfSprite_destroy(menu->start);
    if (menu->option)
        sfSprite_destroy(menu->option);
    if (menu->quit)
        sfSprite_destroy(menu->quit);
    if (menu->clock)
        sfClock_destroy(menu->clock);
    if (menu->win)
        sfRenderWindow_destroy(menu->win);
    destroy_all_intro(menu->intro);
    destroy_all_options(menu->options);
    free(menu);
}

void interface_display(void)
{
    menu_t *menu = init_menu_elmnts();
    sfEvent event;

    printf("init struct Menu_t and create sfEvent -> intro with music\n");
    play_intro(menu);
    printf("intro played\n\n");
    sfMusic_play(menu->music);
    printf("start music -> game\n\n");
    while (sfRenderWindow_isOpen(menu->win)) {
        if (menu->options->in == false){
        display(menu);
        handle_events(menu, &event);
    } else {
        display_options(menu);
        handle_events_options(menu, &event);
    }
    }
    printf("after game --> destroy\n");
    destroy_all(menu);
    printf("after destroy\n");
}
