/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 1)
        my_usage();
    else
        return (game(ac, av));
}
