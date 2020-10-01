/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** main
*/

#include <my.h>

static void check_key(radar_t *radar, sfEvent event)
{
    switch (event.key.code) {
    case sfKeyQ:
        radar->mask ^= 1 << QTREE;
        break;
    case sfKeyS:
        radar->mask ^= 1 << SPRITE;
        break;
    case sfKeyL:
        radar->mask ^= 1 << AREA;
        break;
    case sfKeySpace:
        pause_radar(radar);
        break;
    }
}

static void window_event(radar_t *radar)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(radar->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(radar->window);
            break;
        case sfEvtKeyPressed:
            check_key(radar, event);
            break;
        case sfEvtMouseButtonPressed:
            modify_towers(radar, event);
            break;
        default:
            break;
        }
    }
}

void my_radar(char const *script)
{
    radar_t *radar = create_radar(script);

    while (sfRenderWindow_isOpen(radar->window)) {
        window_event(radar);
        if (radar->mask >> PAUSE & 1)
            continue;
        radar->qt = recreate_qt(radar->planes);
        move_planes(&radar->planes, radar);
        in_control_area(radar->towers, radar->planes, radar->qt);
        collision(radar);
        clean_planes(radar->planes);
        radar->display(radar);
        destroy_qt(radar->qt);
        if (radar->planes && !radar->planes->next
            && !(radar->planes->mask >> ALIVE & 1))
            sfRenderWindow_close(radar->window);
    }
    destroy_radar(radar);
}
