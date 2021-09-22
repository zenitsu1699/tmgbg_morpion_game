/*
** EPITECH PROJECT, 2021
** err_gaming.c
** File description:
** err_gaming
*/

#include "./include/morpion.h"

int err_message(const char *string)
{
    if (string == NULL) return 1;
    else if (strlen(string) < 3) {
        printf("Is enough big.\n");
        return 1; }
    else if (strlen(string) > 3) {
        printf("Is too big.\n");
        return 1; }
    else {
        if (string[0] < 'a' || string[0] > 'c') {
            printf("Bad line.\n");
            return 1; }
        else if (string[1] != ' ') {
            printf("Print %c %c between line and column.\n", '"', '"');
            return 1; }
        else if (string[2] < '1' || string[2] > '3') {
            printf("Bad column.\n");
            return 1; }
    }
    return 0;
}

int err_mapping(char **map, char *msg)
{
    int cc1 = 0;
    int cc2 = 0;

    msg[0] = msg[0] - 49;
    cc1 = msg[0] - 48;
    cc2 = msg[2] - 48;
    cc2 = cc2 - 1;
    if (map[cc1][cc2] != ' ') {
        printf("This case is not empty.\n");
        return 2; }
    msg[0] = msg[0] + 49;
    return 0;
}

int all_err_gaming(char **map, char *msg)
{
    if (err_message(msg)) return 1;
    else if (err_mapping(map, msg)) return 2;
    return 0;
}