/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** destroy_radar
*/

#include <my.h>

void destroy_radar(radar_t *radar)
{
    destroy_planes(radar->planes);
    destroy_clock_time(radar->timer);
    destroy_towers(radar->towers);
    destroy_image(radar->fond);
    destroy_fps(radar->fps);
    sfRenderWindow_destroy(radar->window);
    free(radar);
}
