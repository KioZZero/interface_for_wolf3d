/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** player_movement.c
*/

#include "my.h"

static void player_input_ex_mvt
(sfVector2f direction, sfVector2f *movement, float moveSpeed, float delta)
{
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        movement->x += direction.x * moveSpeed * delta;
        movement->y += direction.y * moveSpeed * delta;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        movement->x -= direction.x * moveSpeed * delta;
        movement->y -= direction.y * moveSpeed * delta;
    }
}

static void player_input_ex_rot
(sfCircleShape *playerpoint, float rotateSpeed, float delta)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) && sfKeyboard_isKeyPressed(sfKeyW)
    || sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyS))
        sfCircleShape_rotate(playerpoint, -rotateSpeed * delta);
    else if (sfKeyboard_isKeyPressed(sfKeyA) && sfKeyboard_isKeyPressed(sfKeyS)
    || sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyW))
        sfCircleShape_rotate(playerpoint, rotateSpeed * delta);
}

void handle_player_input(sfCircleShape *playerpoint, sfClock *clock)
{
    float moveSpeed = 200.0f;
    float rotateSpeed = 100.0f;
    sfTime dt = sfClock_restart(clock);
    float delta = sfTime_asSeconds(dt);
    float angle = sfCircleShape_getRotation(playerpoint);
    float radians = angle * 3.14159265f / 180.0f;
    sfVector2f direction = {cos(radians), sin(radians)};
    sfVector2f movement = {0, 0};

    player_input_ex_rot(playerpoint, rotateSpeed, delta);
    player_input_ex_mvt(direction, &movement, moveSpeed, delta);
    sfCircleShape_move(playerpoint, movement);
}
