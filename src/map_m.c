/*
** EPITECH PROJECT, 2019
** cprog
** File description:
** map_m
*/

#include "../include/my.h"

int check_size(char **coord)
{
    int first = coord[0][0] - '0';
    int second = coord[1][0] - '0';
    int third = coord[2][0] - '0';
    int fourth = coord[3][0] - '0';

    if (first < second && second < third && third < fourth) {
        return (0);
    } else {
        return (84);
    }
}

int check_coord(char **coord)
{
    int i;
    int verif = 0;

    for (i = 0; coord[i] != NULL; i++) {
        if (coord[i][2] == coord[i][5] || coord[i][3] == coord[i][6]) {
            verif++;
        } else {
            return (84);
        }
    }
    return (0);
}

int check_len(char **coord)
{
    int i;
    int verif = 0;

    for (i = 0; coord[i] != NULL; i++) {
        if ((coord[i][5] - 65) - (coord[i][2] - 65) == coord[i][0]-'0'-1 ||
            (coord[i][6] - '0') - (coord[i][3] - '0') == coord[i][0]-'0'-1) {
            verif++;
        } else {
            return (84);
        }
    }
    return (0);
}

int check_right_boat(char **coord)
{
    int i;
    int j;
    int count = 0;

    for (i = 0, j = 0; coord[i][j] != '\0';) {
        if (coord[i][j] != '\n' && coord[i][j] != '\0') {
            j++;
        }
        if (coord[i][j] == '\n') {
            count++;
            i++;
            j = 0;
        }
        if (coord[i] == NULL) {
            return (count);
        }
    }
    return (count);
}