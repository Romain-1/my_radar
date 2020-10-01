/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** create_rect
*/

#include <my.h>

sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f origin = {size.x / 2.0, size.y / 2.0};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOrigin(rect, origin);
    sfRectangleShape_setOutlineColor(rect, sfBlue);
    sfRectangleShape_setOutlineThickness(rect, 1);
    return (rect);
}
