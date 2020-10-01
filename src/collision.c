/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** collision
*/

#include <my.h>

static void intersection(plane_t *p1, plane_t *p2)
{
    sfIntRect rect1 = {p1->pos.x - RADIUS.x / 2, p1->pos.y - RADIUS.y / 2,
                        RADIUS.x, RADIUS.y};
    sfIntRect rect2 = {p2->pos.x - RADIUS.x / 2, p2->pos.y - RADIUS.y / 2,
                        RADIUS.x, RADIUS.y};

    if (p1 != p2 && intersect_rect(rect1, rect2)) {
        p1->mask ^= 1 << ALIVE;
        p2->mask ^= 1 << ALIVE;
    }
}

void collision(radar_t *radar)
{
    sfIntRect rect = {0, 0, RADIUS.x * 2, RADIUS.y * 2};
    query_t *query_p = NULL;

    for (plane_t *p = radar->planes; p; p = p->next) {
        rect.left = p->pos.x - RADIUS.x * 2;
        rect.top = p->pos.y - RADIUS.y * 2;
        if (!(p->mask >> ALIVE & 1) || p->mask >> IN_RANGE & 1
            || p->mask >> WAITING & 1)
            continue;
        query_p = query(radar->qt, rect, NULL);
        for (query_t *other = query_p; other; other = other->next)
            intersection(p, other->p);
        destroy_query(query_p);
    }
}
