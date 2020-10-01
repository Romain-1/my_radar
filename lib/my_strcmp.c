/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i]; i++)
        if (s1[i] == 0)
            return (0);
    return ((s1[i] - s2[i] > 0) ? (1) : (-1));
}
