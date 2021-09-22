/*
** EPITECH PROJECT, 2021
** game_interface.c
** File description:
** game_interface
*/

#include "./include/morpion.h"

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

char *cmd_line(char **map)
{
    char *msg = NULL;

    while (all_err_gaming(map, msg) != 0) {
        free(msg);
        printf("Your turn : ");
        msg = prompt();
    }
    return msg;
}

void update_map(data_map *mymap, char *msg, char tool)
{
    int cc1 = 0;
    int cc2 = 0;

    msg[0] = msg[0] - 49;
    cc1 = msg[0] - 48;
    cc2 = msg[2] - 48;
    cc2 = cc2 - 1;
    mymap->map[cc1][cc2] = tool;
    mymap->case_empty--;
    msg[0] = msg[0] + 49;
}

int game_interface(data_map *mymap, const char *string, char tool)
{
    char *msg = NULL;

    printf("%s must play now\n", string);
    msg = cmd_line(mymap->map);
    update_map(mymap, msg, tool);
    display_map(mymap->map);
    printf("The player has play at position (%c, %c)\n", msg[0], msg[2]);
    free(msg);
    return 0;
}