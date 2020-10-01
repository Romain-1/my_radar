/*
** EPITECH PROJECT, 2019
** my_libc
** File description:
** my_putstr
*/

#include <my.h>

void my_putstr(char const *str)
{
    if (!str)
        return;
    write(1, str, my_strlen(str));
}
