/*
** EPITECH PROJECT, 2024
** interface
** File description:
** init_interface_elements.c
*/

#include "my.h"

sfRenderWindow *init_win(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "WOLF3D",
        sfClose, NULL);

    if (!window)
        exit(84);
    return window;
}

static sfSprite *init_background(sfRenderWindow *win)
{
    sfTexture* texture =
        sfTexture_createFromFile("Ressources/img/menu_wall.jpg", NULL);
    sfSprite* background = sfSprite_create();
    sfVector2u text_size = sfTexture_getSize(texture);
    sfVector2u w_size = sfRenderWindow_getSize(win);

    if (!texture || !background)
        exit(84);
    sfSprite_setScale(background,
        (sfVector2f) {(float)w_size.x / text_size.x,
            (float)w_size.x / text_size.y});
    sfSprite_setTexture(background, texture, sfTrue);
    return background;
}

sfSprite *init_sprite(sfRenderWindow *win, char *filepath)
{
    sfTexture* texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite* sprite = sfSprite_create();
    sfVector2u text_size = sfTexture_getSize(texture);
    sfVector2u w_size = sfRenderWindow_getSize(win);

    if (!texture || !sprite)
        exit(84);
    sfSprite_setScale(sprite,
        (sfVector2f) {(float)w_size.x / text_size.x / (HEIGHT / 180),
            (float)w_size.x / text_size.y / (HEIGHT / 50)});
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static sfMusic *init_music(float volume, char *filename)
{
    sfMusic* music = sfMusic_createFromFile(filename);

    if (!music)
        exit(84);
    sfMusic_setLoop(music, true);
    sfMusic_setVolume(music, volume);
    return music;
}

static void create_icon(menu_t *menu)
{
    sfImage *logoApp =
        sfImage_createFromFile("Ressources/img/appLogo.jpg");
    sfVector2u size = sfImage_getSize(logoApp);

    if (!logoApp)
        exit(84);
    sfRenderWindow_setIcon(menu->win, size.x, size.y,
        sfImage_getPixelsPtr(logoApp));
    sfImage_destroy(logoApp);
}

options_t *init_options(menu_t *menu)
{
    options_t *options = malloc(sizeof(options_t));

    if (!options || !menu->win)
        exit(84);
    memset(options, 0, sizeof(options_t));
    options->in = false;
    options->volume = 50.0;
    options->win_size = "1920x1080";
    options->background_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->wsize_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->z_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->q_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->s_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->d_sp = init_sprite(menu->win, "Ressources/img/logo.png");
    options->z = "z";
    options->q = "q";
    options->s = "s";
    options->d = "d";
    return options;
}

intro_t *init_intro(menu_t *menu)
{
    intro_t *intro = malloc(sizeof(intro_t));
    float lmt_x;
    float lmt_y;
    sfVector2u w_size = sfRenderWindow_getSize(menu->win);

    memset(intro, 0, sizeof(intro_t));
    create_icon(menu);
    intro->clock = sfClock_create();
    intro->logo = init_sprite(menu->win, "Ressources/img/logo.png");
    intro->music = init_music(100.0, "Ressources/Audio/ps_intro.ogg");
    intro->exit = 0;
    sfSprite_setScale(intro->logo, (sfVector2f) {0.45f, 0.45f});
    lmt_x = (w_size.x - sfSprite_getGlobalBounds(intro->logo).width) / 2;
    lmt_y = (w_size.y - sfSprite_getGlobalBounds(intro->logo).height) / 2;
    sfSprite_setPosition(intro->logo, (sfVector2f) {lmt_x, lmt_y});
    return intro;
}

menu_t *init_menu_elmnts(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2u w_size;
    float lmt;

    menu->win = init_win();
    w_size = sfRenderWindow_getSize(menu->win);
    menu->background = init_background(menu->win);
    menu->volume = 50.0;
    menu->clock = sfClock_create();
    menu->music = init_music(menu->volume, "Ressources/Audio/menu_music.ogg");
    menu->start = init_sprite(menu->win, "Ressources/img/start.png");
    menu->quit = init_sprite(menu->win, "Ressources/img/exit.png");
    menu->option = init_sprite(menu->win, "Ressources/img/options.png");
    lmt = (w_size.x - sfSprite_getGlobalBounds(menu->start).width) / 2;
    sfSprite_setPosition(menu->start, (sfVector2f) {lmt, w_size.y / 10 * 4.5});
    sfSprite_setPosition(menu->option, (sfVector2f) {lmt, w_size.y / 10 * 6});
    sfSprite_setPosition(menu->quit, (sfVector2f) {lmt, w_size.y / 10 * 7.5});
    menu->intro = init_intro(menu);
    menu->options = init_options(menu);
    return menu;
}
