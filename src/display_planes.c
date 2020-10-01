/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** display_points
*/

#include <my.h>

void display_planes(radar_t *radar, plane_t *plane)
{
    if (!plane)
        return;
    if (plane->mask >> IN_RANGE & 1) {
        sfRectangleShape_setOutlineColor(plane->rect, sfGreen);
        plane->mask ^= 1 << IN_RANGE;
    } else
        sfRectangleShape_setOutlineColor(plane->rect, sfBlue);
    if (radar->mask >> AREA & 1 && plane->mask >> ALIVE & 1
        && !(plane->mask >> WAITING & 1))
        sfRenderWindow_drawRectangleShape(radar->window, plane->rect, NULL);
    if (radar->mask >> SPRITE & 1 && plane->mask >> ALIVE & 1
        && !(plane->mask >> WAITING & 1))
        sfRenderWindow_drawSprite(radar->window, plane->image->sprite, NULL);
    display_planes(radar, plane->next);
}
