/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** display_qt
*/

#include <my.h>

void display_qt(radar_t *radar, quadtree_t *qt)
{
    if (!qt || !(radar->mask >> QTREE & 1))
        return;
    sfRenderWindow_drawRectangleShape(radar->window, qt->rect, NULL);
    display_qt(radar, qt->northwest);
    display_qt(radar, qt->northeast);
    display_qt(radar, qt->southwest);
    display_qt(radar, qt->southeast);
}
