/*
** EPITECH PROJECT, 2020
** quadtree
** File description:
** destroy_pt
*/

#include <my.h>

void destroy_planes(plane_t *pt)
{
    if (!pt)
        return;
    destroy_planes(pt->next);
    destroy_image(pt->image);
    sfRectangleShape_destroy(pt->rect);
    free(pt);
}
