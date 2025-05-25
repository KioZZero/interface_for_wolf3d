/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** player_settings.c
*/

#include "my.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        exit(84);
    player->angle = 0;
    player->x = 0;
    player->y = 0;
    return player;
}
