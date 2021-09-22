/*
** EPITECH PROJECT, 2021
** winner_case.c
** File description:
** winner_case
*/

#include "./include/morpion.h"

int winner_case_inside(char **map)
{
    if ((map[1][1] == map[0][1]) &&(map[1][1] == map[2][1])
        && (map[1][1] != ' '))
        return 1;
    else if ((map[1][1] == map[1][0]) &&(map[1][1] == map[1][2])
        && (map[1][1] != ' '))
        return 1;
    
    if ((map[1][1] == map[0][0]) &&(map[1][1] == map[2][2])
        && (map[1][1] != ' '))
        return 1;
    else if ((map[1][1] == map[2][0]) &&(map[1][1] == map[0][2])
        && (map[1][1] != ' '))
        return 1;
    return 0;
}

int winner_case_outside(char **map)
{
    if ((map[0][0] == map[0][1]) &&(map[0][0] == map[0][2])
        && (map[0][0] != ' '))
        return 1;
    else if ((map[0][0] == map[1][0]) &&(map[0][0] == map[2][0])
        && (map[0][0] != ' '))
        return 1;

    if ((map[2][2] == map[1][2]) &&(map[2][2] == map[0][2])
        && (map[2][2] != ' '))
        return 1;
    else if ((map[2][2] == map[2][1]) &&(map[2][2] == map[2][0])
        && (map[2][2] != ' '))
        return 1;
    return 0;
}

int winner_case(char **map)
{
    if (winner_case_inside(map)) {
        if (map[1][1] == TOOL_2) return 2;
        else if (map[1][1] == TOOL_1) return 1; }
    else if (winner_case_outside(map)) {
        if (map[0][0] == TOOL_2) return 2;
        else if (map[0][0] == TOOL_1) return 1;
        if (map[2][2] == TOOL_2) return 2;
        else if (map[2][2] == TOOL_1) return 1;
    }
    return 0;
}