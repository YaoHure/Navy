/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** usage.c
*/

#include "../include/my.h"

void my_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid:  only for the 2nd player.");
    my_putstr("  pid of the first player.\n");
    my_putstr("\tnavy_positions:  file representing");
    my_putstr(" the positions of the ships.\n");
}
