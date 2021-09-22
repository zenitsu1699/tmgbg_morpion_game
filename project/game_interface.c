/*
** EPITECH PROJECT, 2021
** game_interface.c
** File description:
** game_interface
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

char *prompt(void)
{
    char *msg = NULL;
    size_t msgsize = 1000;
    int characters;
    int i = 0;

    msg = (char *)malloc(msgsize * sizeof(char));
    if (msg == NULL) return NULL;
    characters = getline(&msg, &msgsize, stdin);
    while (characters == -1) {
        printf("\n");
        exit(1);
    }
    for (i = 0; msg[i + 1] != '\0'; i++);
    msg[i] = '\0';
    return msg;
}

char *cmd_line()
{
    char *msg = NULL;

    while (err_message(msg) != 0) {
        free(msg);
        printf("Your turn : ");
        msg = prompt();
    }
    return msg;
}

int game_interface(char **map)
{
    char *msg = NULL;

    // while (42) {
        display_map(map);
        msg = cmd_line();
        printf("%s\n", msg);
        // update_map(map, msg);
    // }
    free(msg);
    return 0;
}