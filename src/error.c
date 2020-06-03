/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** error.c
*/

#include "../include/my.h"

int check_length(char **line)
{
    char nb = line[0][0];
    if (nb != '2' && nb != '3' && nb != '4' && nb != '5')
        return (84);
    return (0);
}

int check_entry(char *str)
{

    if (str == NULL)
        return (0);
    if (str[0] >= 'A' && str[0] <= 'H' && str[1] >= '1' && str[1] <= '8') {
        return (0);
    } else {
        my_putstr("wrong position");
        return (84);
    }
    return (0);
}
