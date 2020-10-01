/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** subdivide_qt
*/

#include <my.h>

static void divide_south(quadtree_t *qt)
{
    sfIntRect se = {qt->boundary.left + qt->boundary.width / 2.0,
                    qt->boundary.top + qt->boundary.height / 2.0,
                    qt->boundary.width / 2.0,
                    qt->boundary.height / 2.0};
    sfIntRect sw = {qt->boundary.left - qt->boundary.width / 2.0,
                    qt->boundary.top + qt->boundary.height / 2.0,
                    qt->boundary.width / 2.0,
                    qt->boundary.height / 2.0};

    qt->southwest = create_qt(sw);
    qt->southeast = create_qt(se);
}

static void divide_north(quadtree_t *qt)
{
    sfIntRect ne = {qt->boundary.left + qt->boundary.width / 2.0,
                    qt->boundary.top - qt->boundary.height / 2.0,
                    qt->boundary.width / 2.0,
                    qt->boundary.height / 2.0};
    sfIntRect nw = {qt->boundary.left - qt->boundary.width / 2.0,
                    qt->boundary.top - qt->boundary.height / 2.0,
                    qt->boundary.width / 2.0,
                    qt->boundary.height / 2.0};

    qt->northwest = create_qt(nw);
    qt->northeast = create_qt(ne);
}

void subdivide_qt(quadtree_t *qt)
{
    divide_south(qt);
    divide_north(qt);
    qt->divided = 1;
}
