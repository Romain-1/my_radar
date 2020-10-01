/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** insert qt
*/

#include <my.h>

int in_node(sfIntRect boundary, sfVector2f p)
{
    return ((int)p.x <= boundary.left + boundary.width
            && (int)p.x >= boundary.left - boundary.width
            && (int)p.y <= boundary.top + boundary.height
            && (int)p.y >= boundary.top - boundary.height);
}

int insert_qt(quadtree_t *qt, plane_t *p)
{
    if (!in_node(qt->boundary, p->pos))
        return (0);
    if (qt->nb_planes < qt->capacity) {
        qt->planes[qt->nb_planes] = p;
        qt->nb_planes++;
        return (1);
    } else {
        if (!qt->divided)
            subdivide_qt(qt);
        if (insert_qt(qt->northeast, p))
            return (1);
        if (insert_qt(qt->northwest, p))
            return (1);
        if (insert_qt(qt->southeast, p))
            return (1);
        if (insert_qt(qt->southwest, p))
            return (1);
    }
    return (0);
}
