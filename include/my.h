/*
** EPITECH PROJECT, 2018
** MY.H
** File description:
** Yaowanart
*/

#ifndef MY_H_
#define MY_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "struct.h"

data_t data;

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strline(char const *str);
int count_char_of_line(char *str);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat_mini(char *str, char *lig, char sep);
char *my_strcat(char *str1, char *str2);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_itoa(int nb);
int my_first_int_len(int res);
char **my_str_to_word_tab(char *str, char c);
char **wordtab(char **tab, char *str, char c, int nb);
char *my_strndup(char *str, int n);
int my_strncmp(char *s1, char *s2, int nb);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_clean_str(char *str);
int count_line(char *str);
int count_char_of_line(char *str);
char *coord_f(char *filepath);
char *input();
char **cut(char **coord, char **map);
char **into_double_array(char *str);
char *init_str();
char **edit_map(char **map1, char **map_real, char *input);
void print_map(char **map);
void display_map(char **map);
int my_strline(char const *str);
void connection_player_one(link_t *link);
void connection_player_two(pid_t pid, link_t *link);
void wait_ad(link_t *link);
void my_print_pid(link_t *link);
void connexion_ad(int sig, siginfo_t *info);
map_t *global_map(map_t *map);
coord_t my_receive(void);
void my_send(link_t *link, coord_t coord);
int check_entry(char *str);
void my_usage(void);
int game (int ac, char **av);
int check_arguments(int ac, char **av);
int	my_str_is(char *str);
char *alloc(int size);
int check_file(char *path);
int check_len(char **coord);
int check_coord(char **coord);
int init_s1(map_t *map, char *str);
int init_s2(map_t *map, char *str);
int check_size(char **coord);
int check_right_boat(char **coord);

#endif
