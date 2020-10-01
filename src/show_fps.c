/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** show_fps
*/

#include <my.h>

static char *fps_to_str(float fps)
{
    int int_fps = fps;
    int len = my_nblen(int_fps);
    char *str = malloc(sizeof(char) * (len + 4 + 1));

    if (!int_fps)
        str[0] = '0';
    for (int i = 0; int_fps > 0; int_fps /= 10, i++)
        str[len - i - 1] = int_fps % 10 + '0';
    str[len] = ' ';
    str[len + 1] = 'f';
    str[len + 2] = 'p';
    str[len + 3] = 's';
    str[len + 4] = 0;
    return (str);
}

void show_fps(radar_t *radar)
{
    static time_t previous_time = 0;
    time_t t = sfClock_getElapsedTime(radar->timer->clock).microseconds;
    float fps = 0;
    char *str = NULL;

    fps = (float)(t - previous_time) / 1000000.0;
    previous_time = t;
    str = fps_to_str(1.0 / fps);
    sfText_setString(radar->fps->text, str);
    sfRenderWindow_drawText(radar->window, radar->fps->text, NULL);
    free(str);
}
