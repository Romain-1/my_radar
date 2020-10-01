/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** distance
*/

#include <my.h>

float distance(sfVector2f p1, sfVector2f p2)
{
    return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}
