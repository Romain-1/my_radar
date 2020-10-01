/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** next_nb
*/

#include <my.h>

char *next_nb(char *buffer)
{
    while (buffer[0] && !IS_NB(buffer[0]) && buffer[0] != '-')
        buffer = &buffer[1];
    while (buffer[0] && IS_NB(buffer[0]) || buffer[0] == '-')
        buffer = &buffer[1];
    return (buffer);
}
