/*
** EPITECH PROJECT, 2021
** usage.c
** File description:
** usage
*/

#include "./include/morpion.h"

void instruction(void)
{
    printf("MORPION GAME\n\n");
    printf("DESCRIPTION\n");
    printf("    Choice your mark between %s\n", "o, u, x");
    printf("    Tap the coordonne of you pick\n");
    printf("    Enjoy your game\n");
}

int usage(int ac, char **av)
{
    if (ac != 2) {
        printf("Please tape %c%s%c for continued\n", '"',
              "./morpion -h || ./morpion --help", '"');
        return 1;
    }
    else {
        if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0) {
            instruction();
            return 0;
        }
    }
    return 0;
}