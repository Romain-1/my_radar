/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_circle
*/

#include <my.h>

sfCircleShape *create_circle(sfVector2f pos, float radius, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f origin_circle = {radius, radius};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOrigin(circle, origin_circle);
    return (circle);
}
