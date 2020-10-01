/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_towers
*/

#include <my.h>

static tower_t *add_tower(tower_t *head, char *buffer)
{
    tower_t *new = malloc(sizeof(tower_t));
    sfVector2f pos_sprite = {-25, -25};

    new->image = create_image("resources/tower.png");
    new->pos.x = my_getnbr(buffer);
    buffer = next_nb(buffer);
    new->pos.y = my_getnbr(buffer);
    buffer = next_nb(buffer);
    new->radius = my_getnbr(buffer) * WIDTH / 100.0;
    new->circle = create_circle(new->pos, new->radius, sfRed);
    pos_sprite.x += new->pos.x;
    pos_sprite.y += new->pos.y;
    sfSprite_setPosition(new->image->sprite, pos_sprite);
    new->next = head;
    head = new;
    return (head);
}

tower_t *create_towers(char const *script)
{
    tower_t *towers = NULL;
    FILE *fd = fopen(script, "r");
    size_t bufsize = 0;
    ssize_t nb_char = 0;
    char *buffer = NULL;

    if (!fd)
        return (NULL);
    do {
        nb_char = getline(&buffer, &bufsize, fd);
        if (nb_char > 0 && buffer[0] == 'T') {
            towers = add_tower(towers, &buffer[2]);
        }
    } while (nb_char > 0);
    fclose(fd);
    free(buffer);
    return (towers);
}
