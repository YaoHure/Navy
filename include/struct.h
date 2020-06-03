/*
** EPITECH PROJECT, 2018
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

typedef struct data {
    int pid;
    int pos;
    int wait;
}data_t;

typedef struct pid {
    int pid_one;
    int pid_two;
}link_t;

typedef struct coord {
    int x;
    int y;
}coord_t;

typedef struct map_moi {
    char *input1;
    char *input2;
    char **enemy1;
    char **enemy2;
    char **p1map;
    char **p2map;
    int lose;
} map_t;
