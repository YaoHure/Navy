/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** connect.c
*/

#include "../include/my.h"

void connexion_ad(int sig, siginfo_t *info)
{
    int i = sig;

    if (i == sig)
        data.pid = info->si_pid;
}

void my_print_pid(link_t *link)
{
    link->pid_one = getpid();
    my_putstr("my pid: ");
    my_put_nbr(link->pid_one);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
}

void wait_ad(link_t *link)
{
    struct sigaction act;

    act.sa_sigaction = (void *) connexion_ad;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    pause();
    link->pid_two = data.pid;
}

void connection_player_one(link_t *link)
{
    my_print_pid(link);
    wait_ad(link);
    my_putchar('\n');
    my_putstr("enemy connected\n");
}

void connection_player_two(pid_t pid, link_t *link)
{
    link->pid_two = pid;
    link->pid_one = getpid();
    my_putstr("my pid: ");
    my_put_nbr(link->pid_one);
    my_putchar('\n');
    kill(link->pid_two, SIGUSR1);
    my_putstr("successfully connected\n");
}
