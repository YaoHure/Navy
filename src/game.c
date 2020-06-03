/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** game.c
*/

#include "../include/my.h"

char **player1(map_t *map, link_t *link)
{
    coord_t coord;

    my_putstr("\nmy positions:\n");
    display_map(map->p1map);
    my_putstr("\nenemy's position:\n");
    display_map(map->enemy2);
    my_putstr("\nattack: ");
    map->input1 = input();
    if (check_entry(map->input1) == 84) {
        my_putstr("\nattack: ");
        map->input1 = input();
    }
    coord.x = map->input1[0] - 64;
    coord.y = map->input1[1] - 48;
    my_send(link, coord);
    edit_map(map->p2map, map->enemy2, map->input1);
    my_putstr("\nwaiting for enemy's attack...\n");
    my_receive();
    edit_map(map->p1map, map->enemy1, map->input1);
    return (map->p2map);
}

char **player2(map_t *map, link_t *link)
{
    coord_t coord;

    my_putstr("\nmy positions:\n");
    display_map(map->p2map);
    my_putstr("\nenemy's position:\n");
    display_map(map->enemy1);
    my_putstr("\nwaiting for enemy's attack...\n");
    my_receive();
    my_putstr("\nattack: ");
    map->input2 = input();
    if (check_entry(map->input2) == 84) {
        my_putstr("\nattack: ");
        map->input2 = input();
    }
    coord.x = map->input2[0] - 64;
    coord.y = map->input2[1] - 48;
    my_send(link, coord);
    edit_map(map->p1map, map->enemy1, map->input2);
    return (map->p1map);
}

int init_s1(map_t *map, char *str)
{
    int i;
    int verif = 0;
    char **coordp1 = into_double_array(coord_f(str));
    char **coordp2 = into_double_array(coord_f(str));
    if (check_coord(coordp1) == 0)
        verif++;
    if (check_len(coordp1) == 0)
        verif++;
    if (check_right_boat(coordp1) == 4) {
        verif++;
    } else
        return (84);
    if (check_size(coordp1) == 84)
        return (84);
    map->enemy1 = into_double_array(init_str());
    map->enemy2 = into_double_array(init_str());
    map->p1map = into_double_array(init_str());
    map->p2map = into_double_array(init_str());
    map->p1map = cut(coordp1, map->p1map);
    map->p2map = cut(coordp2, map->p2map);
    return (0);
}

int init_s2(map_t *map, char *str)
{
    int verif = 0;
    char **coordp1 = into_double_array(coord_f(str));
    char **coordp2 = into_double_array(coord_f(str));
    if (check_coord(coordp2) == 0)
        verif++;
    if (check_len(coordp2) == 0)
        verif++;
    if (check_right_boat(coordp2) == 4) {
        verif++;
    } else
        return (84);
    if (check_size(coordp1) == 84) {
        return (84);
    }
    map->enemy1 = into_double_array(init_str());
    map->enemy2 = into_double_array(init_str());
    map->p1map = into_double_array(init_str());
    map->p2map = into_double_array(init_str());
    map->p1map = cut(coordp1, map->p1map);
    map->p2map = cut(coordp2, map->p2map);
    return (0);
}

int game(int ac, char **av)
{
    link_t *link = malloc(sizeof(link_t));
    map_t *map = malloc(sizeof(map_t));
    if (ac == 2) {
        if (my_strcmp(coord_f(av[1]), "84") == 1 || init_s1(map, av[1]) == 84)
            return (84);
        connection_player_one(link);
    }
    if (ac == 3) {
        if (my_strcmp(coord_f(av[2]), "84") == 1 || my_str_is(av[1]) == 84 ||
                init_s2(map, av[2]) == 84)
            return (84);
        connection_player_two(my_getnbr(av[1]), link);
    }
    while (1) {
        if (ac == 2)
            player1(map, link);
        if (ac == 3)
            player2(map, link);
    }
    return (0);
}