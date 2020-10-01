/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** recreate_qt
*/

#include <my.h>

quadtree_t *recreate_qt(plane_t *planes)
{
    quadtree_t *qt = create_qt(BOUNDARY);

    for (plane_t *actual = planes; actual; actual = actual->next)
        insert_qt(qt, actual);
    return (qt);
}
