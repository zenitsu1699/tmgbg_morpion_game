/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include "./include/morpion.h"

char **new_location(int line, int column)
{
    char **noob = NULL;

    noob = malloc(sizeof(char *) * (line + 1));
    for (int k = 0; k < line; k++) {
        noob[k] = malloc(sizeof(char) * (column + 1));
        for (int l = 0; l < column; l++)
            noob[k][l] = ' ';
        noob[k][column] = '\0';
    }
    noob[line] = NULL;
    return noob;
}

void display_map(char **map)
{
    int o = 97;

    printf(" 1 2 3\n");
    // printf("_ _ _\n");
    for (int k = 0; k < LINE; k++) {
        for (int l = 0; l < COL; l++)
            printf(" _");
        printf("\n");
        for (int l = 0; l < COL; l++) {
            printf("|");
            printf("%c", map[k][l]); }
        printf("| (%c)\n", o);
        o++; }
}

void free_location(char **map)
{
    for (int k = 0; k < LINE; k++)
        free(map[k]);
    free(map);
    map = NULL;
}