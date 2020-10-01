/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** display_time
*/

#include <my.h>

static char *time_to_str(size_t seconds, size_t minutes, char temp[])
{
    temp[0] = minutes / 10 + '0';
    temp[1] = minutes % 10 + '0';
    temp[3] = seconds / 10 + '0';
    temp[4] = seconds % 10 + '0';
}

void display_time(radar_t *radar)
{
    char temp[6] = {0, 0, ':', 0, 0};
    time_t t = sfClock_getElapsedTime(radar->timer->clock).microseconds
        - radar->pause_time;
    size_t seconds = t / 1000000;
    size_t minutes = seconds / 60;

    seconds -= minutes * 60;
    time_to_str(seconds, minutes, temp);
    sfText_setString(radar->timer->text, temp);
    sfRenderWindow_drawText(radar->window, radar->timer->text, NULL);
}
