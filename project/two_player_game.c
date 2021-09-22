/*
** EPITECH PROJECT, 2021
** two_player_game.c
** File description:
** two_player_game
*/

#include "./include/morpion.h"

int two_player_game(data_map *mymap)
{
    display_map(mymap->map);
    while (42) {
        if (mymap->case_empty == 0) break;
        game_interface(mymap, "Player1", TOOL_1);
        if (mymap->case_empty == 0) break;
        game_interface(mymap, "Player2", TOOL_2);
    }
    if (mymap->case_empty == 0)
    printf("Nobody won't this game\n");
    return 0;
}