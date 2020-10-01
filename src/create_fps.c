/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_fps
*/

#include <my.h>

fps_t *create_fps(void)
{
    fps_t *fps = malloc(sizeof(fps_t));
    sfVector2f pos = {1800, 80};

    if (!fps)
        return (NULL);
    fps->text = sfText_create();
    fps->font = sfFont_createFromFile("resources/DS-DIGI.TTF");
    sfText_setFont(fps->text, fps->font);
    sfText_setPosition(fps->text, pos);
    return (fps);
}
