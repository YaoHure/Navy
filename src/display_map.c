/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** display_map.c
*/

#include "../include/my.h"

char **into_double_array(char *str)
{
    int k = 0;
    int j = 0;
    char **map = malloc(sizeof(char *) * count_line(str) + 1);

    for (int i = 0 ; i < count_line(str) ; i++) {
        map[i] = malloc(sizeof(char) * count_char_of_line(str));
        for (j = 0; j < count_char_of_line(str) ; j++)
            map[i][j] = str[k++];
        map[i][j] = '\n';
        j++;
        k++;
    }
    map[count_line(str)] = NULL;
    return (map);
}

char *init_str(void)
{
    int nb_line = 0;
    int line = 9;
    int col = 8;
    int i = 0;
    int j;
    char *map = malloc(sizeof(char *) * (line * col + 1));

    while (nb_line < col) {
        for (j = 0; j < col; j++) {
            map[i] = '.';
            i++;
        }
        map[i] = '\n';
        i++;
        j = 0;
        nb_line++;
    }
    i++;
    map[i] = '\0';
    return (map);
}

char **edit_map(char **map1, char **map_real, char *input)
{
    int x = input[0] - 65;
    int y = input[1] - '0' - 1;

    if (map1[y][x] == '.' || map1[y][x] == 'o') {
        map_real[y][x] = 'o';
        my_putchar(input[0]);
        my_putchar(input[1]);
        my_putstr(": missed\n");
        return (map_real);
    }
    if (map1[y][x] != '.' || map1[y][x] == 'x') {
        map_real[y][x] = 'x';
        my_putchar(input[0]);
        my_putchar(input[1]);
        my_putstr(": hit\n");
        return (map_real);
    }
    return (map_real);
}

void print_map(char **map)
{
    for (int i = 0 ; map[i]; i++) {
        my_putstr(map[i]);
    }
}

void display_map(char **map)
{
    char number = '1';
    int end = 8;
    int i = 0;
    int j = 0;
    int k = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (i = 0; map[i];i++, number++) {
        my_putchar(number);
        my_putchar('|');
        for (j = 0, k = 0; map[i][j];j++) {
            my_putchar(map[i][j]);
            if (k < end) {
                my_putchar(' ');
                k++;
            }
        }
    }
}
