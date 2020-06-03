/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

char *my_strdup(char *str)
{
    char *dest =  NULL;
    if ((dest = malloc(sizeof(*str) * my_strlen(str) + 1)) == NULL) {
        return (NULL);
    }
    my_strcpy(dest, str);
    return (dest);
}
