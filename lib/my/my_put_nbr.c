/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include "./../../include/my.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr((nb / 10) * - 1);
        my_putchar(((nb % 10) * - 1) + '0');
    }
    else if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
}
