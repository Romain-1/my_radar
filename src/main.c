/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** main
*/

#include <my.h>

int main(int ac, char *av[], char *ae[])
{
    if (ac < 2) {
        write(2, "./my_radar: bad arguments: 0 given but 1 is required ", 53);
        write(2, "\nretry with -h\n", 16);
        return (84);
    }
    if (!my_strcmp(av[1], "-h"))
        help();
    else if (error_handling(av[1]) || !ae[0])
        return (84);
    else
        my_radar(av[1]);
    return (0);
}
