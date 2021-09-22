/*
** EPITECH PROJECT, 2021
** morpion.h
** File description:
** morpion
*/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 3
#define COL 3

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

#define TOOL_1 'o'
#define TOOL_2 'x'

typedef struct morpion_map {
    char **map;
    int case_empty;
} data_map;


#endif


#ifndef MORPION_H
#define MORPION_H

void instruction(void);
int usage(int ac, char **av);
void free_location(data_map *mymap);
void display_map(char **map);
data_map *new_location(int line, int column);
int game_interface(data_map *mymap, const char *string, char tool);
char *cmd_line(char **map);
char *prompt(void);
int err_message(const char *string);
void update_map(data_map *mymap, char *msg, char tool);
int all_err_gaming(char **map, char *msg);
int err_mapping(char **map, char *msg);

int two_player_game(data_map *mymap);
int winner_case(char **map);
int winner_case_outside(char **map);
int winner_case_inside(char **map);

#endif /* !MORPION_H */
