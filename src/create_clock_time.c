/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_clock_time
*/

#include <my.h>

clock_time_t *create_clock_time(sfVector2f pos)
{
    clock_time_t *timer = malloc(sizeof(clock_time_t));

    timer->clock = sfClock_create();
    timer->text = sfText_create();
    timer->font = sfFont_createFromFile("resources/DS-DIGI.TTF");
    sfText_setPosition(timer->text, pos);
    sfText_setFont(timer->text, timer->font);
    sfText_setCharacterSize(timer->text, 50);
    return (timer);
}
