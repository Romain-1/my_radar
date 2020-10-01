/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** query
*/

#include <my.h>

static query_t *add_plane_to_query(query_t *query_p, plane_t *p)
{
    query_t *new = NULL;

    new = malloc(sizeof(query_t));
    new->p = p;
    new->next = query_p;
    query_p = new;
    return (query_p);
}

static int condition(plane_t *plane, sfIntRect range, sfIntRect rect)
{
    return (intersect_rect(range, rect) && plane->mask >> ALIVE & 1
            && !(plane->mask >> IN_RANGE & 1)
            && !(plane->mask >> WAITING & 1));
}

query_t *query(quadtree_t *qt, sfIntRect range, query_t *query_p)
{
    sfIntRect rect = {0, 0, RADIUS.x, RADIUS.y};
    sfIntRect temp = {qt->boundary.left - qt->boundary.width,
                        qt->boundary.top - qt->boundary.height,
                        qt->boundary.width * 2, qt->boundary.height * 2};

    if (!intersect_rect(range, temp))
        return (query_p);
    for (int i = 0; i < qt->nb_planes; i++) {
        rect.left = qt->planes[i]->pos.x - RADIUS.x;
        rect.top = qt->planes[i]->pos.y - RADIUS.y;
        if (condition(qt->planes[i], range, rect))
            query_p = add_plane_to_query(query_p, qt->planes[i]);
    }
    if (qt->divided) {
        query_p = query(qt->northwest, range, query_p);
        query_p = query(qt->northeast, range, query_p);
        query_p = query(qt->southwest, range, query_p);
        query_p = query(qt->southeast, range, query_p);
    }
    return (query_p);
}
