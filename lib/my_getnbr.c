/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr
*/

#include <my.h>

static int my_atoi(char const *s, int *nb)
{
    for (int i = 0; IS_NB(s[i]); i++) {
        *nb *= 10;
        *nb += ATN(s[i]);
    }
}

int my_getnbr(char const *s)
{
    int i = 0;
    int nb = 0;

    if (!s)
        return (0);
    for (; !IS_NB(s[i]); i++);
    my_atoi(&s[i], &nb);
    return ((i && s[i - 1] == '-') ? (-nb) : (nb));
}
