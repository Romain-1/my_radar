/*
** EPITECH PROJECT, 2020
** quadtree
** File description:
** destroy_qt
*/

#include <my.h>

void destroy_qt(quadtree_t *qt)
{
    if (!qt)
        return;
    sfRectangleShape_destroy(qt->rect);
    destroy_qt(qt->northwest);
    destroy_qt(qt->northeast);
    destroy_qt(qt->southwest);
    destroy_qt(qt->southeast);
    free(qt);
}
