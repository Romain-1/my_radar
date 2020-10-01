/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** destroy_towers
*/

#include <my.h>

void destroy_towers(tower_t *tower)
{
    if (!tower)
        return;
    destroy_towers(tower->next);
    sfCircleShape_destroy(tower->circle);
    destroy_image(tower->image);
    free(tower);
}
