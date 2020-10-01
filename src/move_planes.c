/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** move_point
*/

#include <my.h>

static void fix_pos(plane_t *p)
{
    while (p->pos.x > WIDTH)
        p->pos.x -= WIDTH;
    while (p->pos.y > HEIGHT)
        p->pos.y -= HEIGHT;
    while (p->pos.x < 0)
        p->pos.x += WIDTH;
    while (p->pos.y < 0)
        p->pos.y += HEIGHT;
}

static sfVector2f calc_pos_sprite(plane_t *p)
{
    sfVector2f pos = {0, 0};

    pos.x = p->pos.x - RADIUS.x / 2.0 * cosf(p->angle * M_PI / 180.0) * 1.5;
    pos.y = p->pos.y - RADIUS.y / 2.0 * sinf(p->angle * M_PI / 180.0) * 1.5;
    return (pos);
}

void move_planes(plane_t **head, radar_t *radar)
{
    time_t t = sfClock_getElapsedTime(radar->timer->clock).microseconds
        - radar->pause_time;
    float seconds = t / 1000000.0;
    sfVector2f pos_sprite = {0, 0};

    for (plane_t *p = *head; p; p = p->next) {
        if (seconds + radar->last_restart / 1000000.0 > p->delay
            && p->mask >> WAITING & 1)
            p->mask ^= 1 << WAITING;
        if (!(p->mask >> ALIVE & 1) || p->mask >> WAITING & 1)
            continue;
        p->pos.x = p->start.x + p->vector.x * (seconds - p->delay) * p->coeff;
        p->pos.y = p->start.y + p->vector.y * (seconds - p->delay) * p->coeff;
        fix_pos(p);
        pos_sprite = calc_pos_sprite(p);
        sfRectangleShape_setPosition(p->rect, p->pos);
        sfSprite_setPosition(p->image->sprite, pos_sprite);
        if ((seconds - p->delay) * p->coeff > 1)
            p->mask ^= 1 << ALIVE;
    }
}
