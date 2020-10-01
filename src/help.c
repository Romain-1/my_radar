/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** help
*/

#include <my.h>

void help(void)
{
    FILE *fd = fopen(FILE_HELP, "r");
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t nb_char = 0;

    do {
        nb_char = getline(&buffer, &bufsize, fd);
        if (nb_char > 0)
            my_putstr(buffer);
    } while (nb_char > 0);
    fclose(fd);
    free(buffer);
}
