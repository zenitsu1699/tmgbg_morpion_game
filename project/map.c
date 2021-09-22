/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include "./include/morpion.h"

data_map *new_location(int line, int column)
{
    data_map *noob_map = NULL;
    char **noob = NULL;
    int cases = 0;

    noob_map = malloc(sizeof(data_map));
    noob = malloc(sizeof(char *) * (line + 1));
    for (int k = 0; k < line; k++) {
        noob[k] = malloc(sizeof(char) * (column + 1));
        for (int l = 0; l < column; l++) {
            noob[k][l] = ' ';
            cases++; }
        noob[k][column] = '\0';
    }
    noob[line] = NULL;
    noob_map->map = noob;
    noob_map->case_empty = cases;
    return noob_map;
}

void display_map(char **map)
{
    int o = 97;

    printf(" 1 2 3\n");
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

void free_location(data_map *mymap)
{
    for (int k = 0; k < LINE; k++)
        free(mymap->map[k]);
    free(mymap->map);
    free(mymap);
    mymap = NULL;
}