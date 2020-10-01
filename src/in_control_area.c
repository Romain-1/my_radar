/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** in_control_area
*/

#include <my.h>

static int intersect_cir(sfIntRect rect, sfVector2f pos, float radius)
{
    sfVector2f p1 = {rect.left, rect.top};
    sfVector2f p2 = {rect.left + rect.width, rect.top};
    sfVector2f p3 = {rect.left + rect.width, rect.top + rect.height};
    sfVector2f p4 = {rect.left, rect.top + rect.height};

    return (distance(p1, pos) < radius
            && distance(p2, pos) < radius
            && distance(p3, pos) < radius
            && distance(p4, pos) < radius);
}

void in_control_area(tower_t *towers, plane_t *planes, quadtree_t *qt)
{
    sfIntRect rect_t = {0, 0, 0, 0};
    sfIntRect rect_p = {0, 0, RADIUS.x, RADIUS.y};
    query_t *query_p = NULL;

    for (tower_t *actual = towers; actual; actual = actual->next) {
        rect_t.left = actual->pos.x - actual->radius;
        rect_t.top = actual->pos.y - actual->radius;
        rect_t.width = actual->radius * 2;
        rect_t.height = rect_t.width;
        query_p = query(qt, rect_t, NULL);
        for (query_t *in_query = query_p; in_query; in_query = in_query->next) {
            rect_p.left = in_query->p->pos.x - RADIUS.x / 2;
            rect_p.top = in_query->p->pos.y - RADIUS.y / 2;
            if (intersect_cir(rect_p, actual->pos, actual->radius))
                in_query->p->mask ^= 1 << IN_RANGE;
        }
        destroy_query(query_p);
    }
}
