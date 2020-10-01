/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** place_tower
*/

#include <my.h>

static tower_t *new_tower(tower_t *head, sfVector2f pos)
{
    tower_t *new = malloc(sizeof(tower_t));

    new->circle = NULL;
    new->pos = pos;
    new->radius = 0;
    new->image = create_image("resources/tower.png");
    pos.x -= 25;
    pos.y -= 25;
    sfSprite_setPosition(new->image->sprite, pos);
    new->next = head;
    head = new;
    return (head);
}

void place_tower(radar_t *radar, sfMouseButtonEvent mouse)
{
    static int placing = 0;
    static sfVector2f previous_pos;
    static tower_t *temp = NULL;
    sfVector2f pos = {mouse.x, mouse.y};

    if (!placing) {
        radar->towers = new_tower(radar->towers, pos);
        temp = radar->towers;
        previous_pos = pos;
    } else if (radar->towers == temp) {
        radar->towers->radius = distance(previous_pos, pos);
        radar->towers->circle = create_circle(previous_pos,
                                                radar->towers->radius, sfRed);
    }
    placing = (placing + 1) % 2;
}
