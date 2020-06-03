/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** my_clean_str.c
*/

#include "../../include/my.h"

char *my_clean_str(char *str)
{
    char *dest = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int space = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (int j = 0; str[i];) {
        if (str[i] != ' ' && str[i] != '\t') {
            dest[j] = str[i];
            j++;
        }
        else
            space++;
        i++;
        if (space != 0 && str[i] != ' ' && str[i] != '\t' && str[i]) {
            dest[j] = ' ';
            j++;
            space = 0;
        }
    }
    return (dest);
}
