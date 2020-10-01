/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** clean_planes
*/

#include <my.h>

static void destroy_node(plane_t *node)
{
    destroy_image(node->image);
    sfRectangleShape_destroy(node->rect);
    free(node);
}

void clean_planes(plane_t *planes)
{
    plane_t *node = NULL;

    for (plane_t *p = planes; p && p->next; p = p->next) {
        if (!(p->next->mask >> ALIVE & 1)) {
            node = p->next;
            p->next = p->next->next;
            destroy_node(node);
        }
    }
}
