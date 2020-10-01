/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_radar
*/

#include <my.h>

radar_t *create_radar(char const *script)
{
    radar_t *radar = malloc(sizeof(radar_t));
    sfVector2f pos_timer = {1800, 0};

    radar->window = sfRenderWindow_create(MODE, "my_radar",
                                            sfResize | sfClose, NULL);
    radar->timer = create_clock_time(pos_timer);
    radar->qt = NULL;
    radar->planes = create_planes(script);
    radar->towers = create_towers(script);
    radar->mask = 6;
    radar->fond = create_image("resources/fond.jpg");
    radar->display = &display_radar;
    radar->speed = 1;
    radar->fps = create_fps();
    radar->pause_time = 0;
    radar->last_restart = 0;
    sfRenderWindow_setFramerateLimit(radar->window, 60);
    return (radar);
}
