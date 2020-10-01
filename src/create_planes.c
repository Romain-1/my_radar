/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_planes
*/

#include <my.h>

static sfVector2f calc_vector(sfVector2f a, char *buffer)
{
    sfVector2f v = {0, 0};
    sfVector2f b = {0, 0};

    b.x = my_getnbr(buffer);
    buffer = next_nb(buffer);
    b.y = my_getnbr(buffer);
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return (v);
}

static void angle(plane_t *new)
{
    float angle = atanf(new->vector.x / new->vector.y) * 180.0 / M_PI;
    float end = new->pos.y + new->vector.y;

    if (new->pos.y <= end)
        angle = 180.0 - angle;
    else
        angle *= -1.0;
    sfRectangleShape_setRotation(new->rect, -45);
    sfSprite_setRotation(new->image->sprite, -45);
    sfRectangleShape_rotate(new->rect, angle);
    sfSprite_rotate(new->image->sprite, angle);
    new->angle = angle;
}

float coeff(plane_t *plane)
{
    return (plane->speed / sqrt(pow((plane->pos.x + plane->vector.x)
                                    - plane->pos.x, 2) +
                                pow((plane->pos.y + plane->vector.y)
                                    - plane->pos.y, 2)));
}

static plane_t *add_plane(plane_t *head, char *buffer)
{
    plane_t *plane = malloc(sizeof(plane_t));

    plane->mask = 0b011;
    plane->image = create_image("resources/plane.png");
    plane->pos.x = my_getnbr(buffer);
    buffer = next_nb(buffer);
    plane->pos.y = my_getnbr(buffer);
    plane->start = plane->pos;
    buffer = next_nb(buffer);
    plane->vector = calc_vector(plane->start, buffer);
    buffer = next_nb(next_nb(buffer));
    plane->rect = create_rect(plane->pos, RADIUS);
    plane->speed = my_getnbr(buffer);
    buffer = next_nb(buffer);
    plane->coeff = coeff(plane);
    plane->delay = my_getnbr(buffer);
    angle(plane);
    plane->next = head;
    head = plane;
    return (head);
}

plane_t *create_planes(char const *script)
{
    plane_t *planes = NULL;
    FILE *fd = fopen(script, "r");
    size_t bufsize = 0;
    ssize_t nb_char = 0;
    char *buffer = NULL;

    do {
        nb_char = getline(&buffer, &bufsize, fd);
        if (nb_char > 0 && buffer[0] == 'A') {
            planes = add_plane(planes, &buffer[1]);
        }
    } while (nb_char > 0);
    fclose(fd);
    free(buffer);
    return (planes);
}

