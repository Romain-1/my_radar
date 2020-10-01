/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** destroy_image
*/

#include <my.h>

void destroy_image(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    free(image);
}
