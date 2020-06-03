/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** my_strcat.c
*/

#include "../../include/my.h"

char *my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *res = malloc(sizeof(char) * (len1 + len2 + 1));

    res[len1 + len2 + 1] = 0;
    if (!res)
        return (0);
    for (; len2 >= 0; --len2)
        res[len1 + len2] = str2[len2];
    --len1;
    for (; len1 >= 0; --len1)
        res[len1] = str1[len1];
    return (res);
}
