/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** modify_towers
*/

#include <my.h>

static int test(sfIntRect rect, sfMouseButtonEvent p)
{
    return (p.x > rect.left && p.x < rect.left + rect.width
            && p.y > rect.top && p.y < rect.top + rect.height);
}

static void destroy_node(tower_t *node)
{
    sfCircleShape_destroy(node->circle);
    destroy_image(node->image);
    free(node);
}

static tower_t *delete_a_tower(tower_t *tower, sfMouseButtonEvent pos)
{
    sfIntRect rect = {tower->pos.x - 25, tower->pos.y - 25, 50, 50};
    tower_t *node = tower;

    if (test(rect, pos)) {
        tower = tower->next;
        destroy_node(node);
        return (tower);
    }
    for (tower_t *t = tower; t && t->next; t = t->next) {
        node = t->next;
        rect.left = node->pos.x - 25;
        rect.top = node->pos.y - 25;
        if (test(rect, pos)) {
            t->next = t->next->next;
            destroy_node(node);
        }
    }
    return (tower);
}

void modify_towers(radar_t *radar, sfEvent event)
{
    switch (event.mouseButton.button) {
    case sfMouseLeft:
        place_tower(radar, event.mouseButton);
        break;
    case sfMouseRight:
        if (radar->towers)
            radar->towers = delete_a_tower(radar->towers, event.mouseButton);
        break;
    default:
        break;
    }

}
