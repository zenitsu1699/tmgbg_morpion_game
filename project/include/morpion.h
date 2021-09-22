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

#endif


#ifndef MORPION_H
#define MORPION_H

void instruction(void);
int usage(int ac, char **av);
void free_location(char **map);
void display_map(char **map);
char **new_location(int line, int column);

#endif /* !MORPION_H */
