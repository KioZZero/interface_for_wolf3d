/*
** EPITECH PROJECT, 2024
** interface
** File description:
** conditions.c
*/

#include "my.h"

void conditions(int ac, char **av)
{
    if (ac == 2 && strcmp("-h", av[1]) == 0){
        printf("USAGE\n    ./wolf3d [-h]\nDESCRIPTION\n    ");
        printf("This project consists of creating a clone\n");
        printf("    of the classic game Wolfenstein 3D. The \n");
        printf("    goal is to develop a 3D first-person \n");
        printf("    shooter using a simple rendering techniq");
        printf("ue,\n    raycasting.\n");
        exit(0);
    }
    if (ac != 1)
        exit(84);
    interface_display();
}
