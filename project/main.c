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
    // char **map = NULL;
    data_map *mymap;

    if (usage(ac, av)) return 84;
    mymap = new_location(LINE, COL);
    two_player_game(mymap);
    free_location(mymap);
    return 0;
}