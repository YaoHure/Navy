/*
** EPITECH PROJECT, 2019
** cprog
** File description:
** count
*/

#include "../include/my.h"

int my_strline(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

int count_line(char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            n++;
        i++;
    }
    return (n);
}

int count_char_of_line(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return (i);
}