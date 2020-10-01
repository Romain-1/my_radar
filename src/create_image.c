/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create image
*/

#include <my.h>

image_t *create_image(char const *str)
{
    image_t *image = malloc(sizeof(image_t));

    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return (image);
}
