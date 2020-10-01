/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** display_towers
*/

#include <my.h>

void display_towers(radar_t *radar, tower_t *tower)
{
    if (!tower)
        return;
    if (radar->mask >> AREA & 1 && tower->circle)
        sfRenderWindow_drawCircleShape(radar->window, tower->circle, NULL);
    if (radar->mask >> SPRITE & 1)
        sfRenderWindow_drawSprite(radar->window, tower->image->sprite, NULL);
    display_towers(radar, tower->next);
}
