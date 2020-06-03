/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** my_str_isnum.c
*/

#include "../../include/my.h"


int	my_str_is(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            i = i + 1;
        } else
            return (84);
    }
    return (0);
}
