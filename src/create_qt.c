/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** create qt
*/

#include <my.h>

sfRectangleShape *create_rectangle(sfIntRect boundary, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = {boundary.left, boundary.top};
    sfVector2f origin = {boundary.width, boundary.height};
    sfVector2f size = {boundary.width * 2, boundary.height * 2};

    sfRectangleShape_setOrigin(rect, origin);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setOutlineColor(rect, color);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect, size);
    return (rect);
}

quadtree_t *create_qt(sfIntRect boundary)
{
    quadtree_t *qt = malloc(sizeof(quadtree_t));
    sfColor color = {120, 120, 120, 255};

    qt->rect = create_rectangle(boundary, color);
    qt->divided = 0;
    qt->capacity = POINTS_PER_QT;
    qt->nb_planes = 0;
    qt->boundary = boundary;
    qt->northwest = NULL;
    qt->northeast = NULL;
    qt->southwest = NULL;
    qt->southeast = NULL;
    return (qt);
}
