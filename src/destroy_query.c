/*
** EPITECH PROJECT, 2020
** quadtree
** File description:
** destroy_query
*/

#include <my.h>

void destroy_query(query_t *query)
{
    if (!query)
        return;
    destroy_query(query->next);
    free(query);
}
