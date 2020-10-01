/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_nblen
*/

#include <my.h>

int my_nblen(int nb)
{
    int size = 0;

    if (!nb)
        return (1);
    if (nb < 0) {
        nb *= -1;
        size++;
    }
    for (; nb; nb /= 10, size++);
    return (size);
}
