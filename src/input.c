/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** input.c
*/

#include "../include/my.h"

char *coord_f(char *filepath)
{
    char *error;
    int fd = open(filepath, O_RDONLY);
    char BUFF[5000];
    int i = my_strline(BUFF);
    int rd = read(fd, BUFF, 42);
    char *map = BUFF;

    i++;
    if (rd == -1 || fd == -1 || rd == 0) {
        error = "84";
        return (error);
    }
    if (rd != EOF) {
        while (map[i] != '\0') {
            i++;
        }
    }
    return (map);
}

char *input(void)
{
    char *line = malloc(sizeof(char *) * 100 + 1);
    int ret;

    while ((ret = read(0, line, 101)) != -1)
    {
        line[ret] = ' ';
        return (line);
    }
    return (line);
}

char **cut(char **coord, char **map)
{
    int first_x = 0;
    int last_x = 0;
    int first_y = 0;
    int last_y = 0;
    for (int i = 0; coord[i]; i++) {
        char c = coord[i][0];
        first_x = coord[i][2] - 65;
        first_y = coord[i][3] - '0' - 1;
        map[first_y][first_x] = c;
        last_x = coord[i][5] - 65;
        last_y = coord[i][6] - '0' - 1;
        map[last_y][last_x] = c;
        for (; first_x < last_x; first_x++) {
            map[first_y][first_x] = c;
        }
        for (; first_y < last_y; first_y++) {
            map[first_y][first_x] = c;
        }
    }
    return (map);
}