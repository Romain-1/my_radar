/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** destroy_clock_time
*/

#include <my.h>

void destroy_clock_time(clock_time_t *timer)
{
    sfClock_destroy(timer->clock);
    sfText_destroy(timer->text);
    sfFont_destroy(timer->font);
    free(timer);
}
