/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** handle.c
*/

#include "../include/my.h"

void handle(int sig)
{
    if (sig == SIGUSR1)
        data.pos++;
    if (sig == SIGUSR2)
        data.pos++;
}

void my_send(link_t *link, coord_t coord)
{
    struct sigaction act;
    int stop = (coord.y * 8 + coord.x) - 1;

    act.sa_sigaction = (void *) handle;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    data.pos = 0;
    for (int i = 0; i < 65; i++) {
        if (stop >= i)
            kill(link->pid_two, SIGUSR1);
        else
            kill(link->pid_two, SIGUSR2);
        usleep(10000);
    }
}

coord_t my_receive(void)
{
    coord_t coord;
    struct sigaction act;

    act.sa_sigaction = (void *)handle;
    act.sa_flags = SA_SIGINFO;
    for (int j = 0; j < 65; j++) {
        signal(SIGUSR1, handle);
        signal(SIGUSR2, handle);
        pause();
    }
    coord.x = data.pos % 8;
    coord.y = data.pos / 8;
    return (coord);
}
