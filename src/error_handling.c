/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** error_handling
*/

#include <my.h>

static int check_char(char *buffer)
{
    for (int i = 1; buffer[i] && buffer[i] != '\n'; i++) {
        if (!IS_NB(buffer[i]) && buffer[i] != '\t'
            && buffer[i] != ' ' && buffer[i] != '-') {
            write(2, "Error: wrong character: '", 25);
            write(2, &buffer[i], 1);
            write(2, "'.\n", 3);
            return (84);
        }
    }
    return (0);
}

static int check_buffer(char *buffer)
{
    int nb_args = 0;
    char type = buffer[0];

    if (!buffer[0] || !(buffer[0] == 'A' || buffer[0] == 'T')) {
        write(2, "Error: type of entity is not defined.\n", 38);
        return (84);
    }
    if (check_char(buffer))
        return (84);
    buffer = next_nb(buffer);
    for (; buffer[0]; nb_args++, buffer = next_nb(buffer));
    if ((nb_args != 3 && type == 'T') || (nb_args != 6 && type == 'A')) {
        write(2, "Error: wrong number of arguments.\n", 34);
        return (84);
    }
    return (0);
}

int error_handling(char const *script)
{
    FILE *fd = fopen(script, "r");
    size_t bufsize = 0;
    ssize_t nb_char = 1;
    char *buffer = NULL;

    if (!fd) {
        write(2, "Error: script not found.\n", 26);
        return (84);
    }
    while (nb_char > 0) {
        nb_char = getline(&buffer, &bufsize, fd);
        if (check_buffer(buffer)) {
            free(buffer);
            fclose(fd);
            return (84);
        }
    }
    free(buffer);
    fclose(fd);
    return (0);
}
