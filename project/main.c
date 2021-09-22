/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "./include/morpion.h"

int morpion_game(void)
{
    return 0;
}

int main(int ac, char **av)
{
    char **map = NULL;

    if (usage(ac, av)) return 84;
    map = new_location(LINE, COL);
    game_interface(map);
    free_location(map);
    return 0;
}