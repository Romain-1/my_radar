/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** destroy_fps
*/

#include <my.h>

void destroy_fps(fps_t *fps)
{
    sfText_destroy(fps->text);
    sfFont_destroy(fps->font);
    free(fps);
}
