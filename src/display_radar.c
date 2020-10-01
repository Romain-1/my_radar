/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** display_radar
*/

#include <my.h>

void display_radar(radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    sfRenderWindow_drawSprite(radar->window, radar->fond->sprite, NULL);
    display_qt(radar, radar->qt);
    display_towers(radar, radar->towers);
    display_planes(radar, radar->planes);
    display_time(radar);
    show_fps(radar);
    sfRenderWindow_display(radar->window);
}
