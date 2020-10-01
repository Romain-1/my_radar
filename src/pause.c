/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** pause
*/

#include <my.h>

void pause_radar(radar_t *radar)
{
    static time_t previous_t = 0;
    time_t t = 0;

    if (!(radar->mask >> PAUSE & 1))
        previous_t = sfClock_getElapsedTime(radar->timer->clock).microseconds;
    else {
        t = sfClock_getElapsedTime(radar->timer->clock).microseconds;
        radar->pause_time += t - previous_t;
    }
    radar->mask ^= 1 << PAUSE;
}
