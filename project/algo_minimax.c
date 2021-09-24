/*
** EPITECH PROJECT, 2021
** algo_minimax.c
** File description:
** algo_minimax
*/

#include "./include/morpion.h"


typedef struct scores {
    int score;
    struct scores *next;
} scores, *the_scores;

typedef struct moves {
    int move;
    struct moves *next;
} moves, *the_moves;


char *morpion_grille(void)
{
    char *grid = NULL;

    grid = malloc(sizeof(char) * (9 + 1));
    for (int i = 0; i < 9; i++)
        grid[i] = i + 48;
    grid[9] = '\0';
    return grid;
}

char *aimove(int move)
{
    char *aimove = NULL;
    return aimove;
}

int win(char *grid)
{
    char *testrow = NULL;
    char rowvalue[3];
    char winsituation[8][3] = {
        { '0', '1', '2' },
        { '3', '4', '5' },
        { '6', '7', '8' },

        { '0', '3', '6' },
        { '1', '4', '7' },
        { '2', '5', '8' },

        { '0', '4', '8' },
        { '6', '4', '2' }
    };

    for (int i = 0; i < 8; i++) {
        testrow = winsituation[i];
        for (int j = 0; j < 3; j++)
            rowvalue[j] = grid[testrow[j] - 48];
        if ((rowvalue[0] == rowvalue[1]) && (rowvalue[0] == rowvalue[2])
            && (rowvalue[0] == 'x'))
            return 1;
        if ((rowvalue[0] == rowvalue[1]) && (rowvalue[0] == rowvalue[2])
            && (rowvalue[0] == 'o'))
            return 2;
    }
    return 0;
}

void display_mapping(char *grid)
{
    int o = 0;

    printf("\n\n i i i\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c", grid[o]);
            o++; }
        printf(" (%c)\n", o + 97);
    }
}

char *available_grille(char *grid)
{
    char *available = NULL;
    int count = 0;

    for (int i = 0; i < 9; i++)
        if (grid[i] != 'o' && grid[i] != 'x')
            count++;
    if (count == 0) return NULL;
    available = malloc(sizeof(char) * (count + 1));
    count = 0;
    for (int i = 0; i < 9; i++)
        if (grid[i] != 'o' && grid[i] != 'x') {
            available[count] = grid[i];
            count++; }
    available[count] = '\0';
    return available;
}

void push_scores(the_scores myscore, int new_score)
{
    scores *tmp = malloc(sizeof(*tmp));
    the_scores temp = NULL;

    if (tmp == NULL) return ;
    tmp->score = new_score;
    tmp->next = NULL;
    printf("new_score == %d\n", new_score);
    if (myscore == NULL) {
        myscore = tmp;
        return ;
    }
    else if (myscore->next == NULL) {
        myscore->next = tmp;
        return ;
    }
    else {
        for (temp = myscore; temp->next != NULL; temp = temp->next);
        temp->next = tmp;
        return ;
    }
}

void push_moves(the_moves mymove, int new_move)
{
    moves *tmp = malloc(sizeof(*tmp));
    the_moves temp = NULL;

    if (tmp == NULL) return ;
    tmp->move = new_move;
    tmp->next = NULL;
    printf("new_move == %d\n", new_move);
    if (mymove == NULL) {
        mymove = tmp;
        return ;
    }
    else if (mymove->next == NULL) {
        mymove->next = tmp;
        return ;
    }
    else {
        for (temp = mymove; temp->next != NULL; temp = temp->next);
        temp->next = tmp;
        return ;
    }
}

void free_location_score(the_scores myscore)
{
    the_scores tmp = NULL;
    the_scores temp = NULL;

    if (myscore == NULL) return ;
    else if (myscore->next == NULL) {
        free(myscore);
        myscore = NULL;
    }
    else {
        for (temp = myscore; temp->next->next != NULL; temp = temp->next);
        tmp = temp->next;
        temp->next = NULL;
        free(tmp);
        tmp = NULL;
    }
    if (myscore == NULL) return ;
    free_location_score(myscore);
}

void free_one_location_move(the_moves mymove)
{
    the_moves tmp = NULL;
    the_moves temp = NULL;

    for (temp = mymove; temp->next->next != NULL; temp = temp->next);
    tmp = temp->next;
    temp->next = NULL;
    free(tmp);
    tmp = NULL;
}

void free_location_move(the_moves mymove)
{
    the_moves tmp = NULL;
    the_moves temp = NULL;

    if (mymove == NULL) return ;
    else if (mymove->next == NULL) {
        free(mymove);
        mymove = NULL;
    }
    else {
        for (temp = mymove; temp->next->next != NULL; temp = temp->next);
        tmp = temp->next;
        temp->next = NULL;
        free(tmp);
        tmp = NULL;
    }
    if (mymove == NULL) return ;
    free_location_move(mymove);
}

int get_hight_score(the_scores myscore)
{
    int hight_score = 0;

    for (the_scores tmp = myscore; tmp != NULL; tmp = tmp->next)
        if (tmp->score >= hight_score)
            hight_score = tmp->score;
    return hight_score;
}

int get_low_score(the_scores myscore)
{
    int hight_score = 0;

    for (the_scores tmp = myscore; tmp != NULL; tmp = tmp->next)
        if (tmp->score <= hight_score)
            hight_score = tmp->score;
    return hight_score;
}

int get_position_hight_score(the_scores myscore, int hight_score)
{
    int index = 0;

    for (the_scores tmp = myscore; tmp != NULL; tmp = tmp->next) {
        if (tmp->score == hight_score) break;
        index++; }
    return index;
}

int get_move_position(the_moves mymove, int position)
{
    int move = 0;
    int l = 0;

    for (the_moves tmp = mymove; tmp != NULL; tmp = tmp->next, l++) {
        if (l == position) {
        move = tmp->move;
        break; }
    }
    return move;
}


int minimax(char *newgrid, char player)
{
    static int ko = 0;
    // display_mapping(newgrid);
    // printf("example...%d\n", ko);
    // exit(0);
    char *available = available_grille(newgrid);
    the_moves mymove = NULL;
    the_scores myscore = NULL;
    int move = 0;
    int hight_score = 0;
    int lowscore = 0;
    int index = 0;
    int aimove = 0;

    // Vérifier la situation du jeu ...
    if (available == NULL) return 0;
    else if (win(newgrid) == 1) return 1;
    else if (win(newgrid) == 2) return 2;
    ko++;

    for (int k = 0; available[k] != '\0'; k++) {
        move = available[k] - 48;
        newgrid[move] = player;
        if (player == 'x')
            push_scores(myscore, minimax(newgrid, 'o'));
        else push_scores(myscore, minimax(newgrid, 'x'));
        newgrid[move] = move + 48;
        push_moves(mymove, move);
        for (the_moves tmp = mymove; tmp != NULL; tmp = tmp->next)
            printf("%d -> ", mymove->move);
        printf("\n");
        for (the_scores tmp = myscore; tmp != NULL; tmp = tmp->next)
            printf("%d -> ", myscore->score);
        printf("\n");
        return aimove;
    }
    free(available);
    if (player == 'x') {
        hight_score = get_hight_score(myscore);
        index = get_position_hight_score(myscore, hight_score);
        aimove = get_move_position(mymove, index);
        // printf("index == %d\n", index);
        return aimove; }
    else {
        lowscore = get_low_score(myscore);
        index = get_position_hight_score(myscore, lowscore);
        aimove = get_move_position(mymove, index);
        // printf("index == %d\n", index);
        return aimove; }
    free_location_move(mymove);newgrid[move] = move + 48;
    free_location_score(myscore);
    return 0;
}


int plyer_vs_ai(char *grid)
{
    int play = 1;
    int turn = 1;
    char ai;
    char *available = NULL;
    int choice = 0;

    while (play != 0) {
        available = available_grille(grid);
        if ((win(grid) == 1) || (win(grid) == 2)
            || (available == NULL))
            play = 0;
        else {
            if (turn == 1) {
                ai = TOOL_2;
                turn = 0; }
            else {
                ai = TOOL_1;
                turn = 1; }
            choice = minimax(grid, ai);
            grid[choice] = ai;
            display_mapping(grid);
        }
    }
    return 0;
}

int ai_vs_ai(char *grid)
{
    int play = 1;
    int turn = 1;
    char ai;
    char *available = NULL;
    int choice = 0;
    int stop = 0;

    while (play != 0) {
        available = available_grille(grid);
        if ((win(grid) == 1) || (win(grid) == 2)
            || (available == NULL))
            play = 0;
        else {
            if (turn == 1) {
                ai = TOOL_2;
                turn = 0; }
            else {
                ai = TOOL_1;
                turn = 1; }
            display_mapping(grid);
            printf("before ....\n");
            choice = minimax(grid, ai);
            printf("choice %d\n", choice);
            grid[choice] = ai;
            display_mapping(grid);
            printf("after ...\n");
        }
        free(available);
        available = NULL;
        if (stop == 2) return 0;
            stop++;
    }
    return 0;
}

int main(int ac, char **av)
{
    char *grid = morpion_grille();
    
    ai_vs_ai(grid);
    free(grid);
    return 0;
}