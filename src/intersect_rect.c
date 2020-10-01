/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** intersect_rect
*/

#include <my.h>

int intersect_rect(sfIntRect rect1, sfIntRect rect2)
{
    int max_gauche = (rect1.left >= rect2.left) ? rect1.left : rect2.left;
    int min_droite = (rect1.left + rect1.width >= rect2.left + rect2.width) ?
        rect2.left + rect2.width : rect1.left + rect1.width;
    int max_bas = (rect1.top >= rect2.top) ? rect1.top : rect2.top;
    int min_haut = (rect1.top + rect1.height >= rect2.top + rect2.height) ?
        rect2.top + rect2.height : rect1.top + rect1.height;

    return (max_gauche < min_droite && max_bas < min_haut);
}
