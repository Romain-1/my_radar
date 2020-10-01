/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** my.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#ifndef POINTS_PER_QT
#define POINTS_PER_QT (4)
#endif
#define IS_NB(c) ((c <= '9' && c >= '0') ? (1) : (0))
#define ATN(c) (c - '0')

typedef struct pause_menu {
    char str_pause[3];
    time_t pause;
} pause_menu_t;

typedef struct image {
    sfSprite *sprite;
    sfTexture *texture;
} image_t;

typedef struct plane {
    char mask;
    image_t *image;
    sfRectangleShape *rect;
    sfVector2f vector;
    sfVector2f start;
    float delay;
    float coeff;
    float angle;
    float speed;
    sfVector2f pos;
    struct plane *next;
} plane_t;

typedef struct query {
    plane_t *p;
    struct query *next;
} query_t;

typedef struct tower {
    float radius;
    sfVector2f pos;
    image_t *image;
    sfCircleShape *circle;
    struct tower *next;
} tower_t;

typedef struct quadtree {
    char divided;
    size_t capacity;
    size_t nb_planes;
    sfIntRect boundary;
    sfRectangleShape *rect;
    plane_t *planes[4];
    struct quadtree *northwest;
    struct quadtree *northeast;
    struct quadtree *southwest;
    struct quadtree *southeast;
} quadtree_t;

typedef struct clock_time {
    sfClock *clock;
    sfText *text;
    sfFont *font;
} clock_time_t;

typedef struct fps {
    sfText *text;
    sfFont *font;
} fps_t;

typedef struct radar {
    float speed;
    fps_t *fps;
    time_t pause_time;
    time_t last_restart;
    sfRenderWindow *window;
    plane_t *planes;
    tower_t *towers;
    quadtree_t *qt;
    image_t *fond;
    clock_time_t *timer;
    int mask;
    void (*display)(struct radar *);
} radar_t;

static const int WIDTH = 1920;
static const int HEIGHT = 1080;
static const int BPX = 32;
static const sfVector2f RADIUS = {20.0, 20.0};
static const sfIntRect BOUNDARY = {WIDTH / 2, HEIGHT / 2,
                                    WIDTH / 2, HEIGHT / 2};
static const sfVideoMode MODE = {WIDTH, HEIGHT, BPX};
static const char FILE_HELP[] = "help";

enum mask_radar {QTREE, SPRITE, AREA, PAUSE};
enum mask_plane {WAITING, ALIVE, IN_RANGE};

void display_qt(radar_t *, quadtree_t *);
quadtree_t *create_qt(sfIntRect);
int insert_qt(quadtree_t *, plane_t *);
void subdivide_qt(quadtree_t *);
plane_t *create_planes(char const *);
void move_planes(plane_t **, radar_t *);
int nb_points(quadtree_t *);
void display_planes(radar_t *, plane_t *);
void collision(radar_t *);
quadtree_t *recreate_qt(plane_t *);
int in_node(sfIntRect, sfVector2f);
query_t *query(quadtree_t *, sfIntRect, query_t *);
int intersect_rect(sfIntRect, sfIntRect);
void destroy_qt(quadtree_t *);
void destroy_query(query_t *);
void destroy_planes(plane_t *);
image_t *create_image(char const *);
void destroy_image(image_t *);
sfRectangleShape *create_rect(sfVector2f, sfVector2f);
void display_time(radar_t *);
void destroy_clock_time(clock_time_t *);
clock_time_t *create_clock_time(sfVector2f);
void destroy_radar(radar_t *);
void display_radar(radar_t *);
radar_t *create_radar(char const *);
void destroy_towers(tower_t *);
tower_t *create_towers(char const *);
void display_towers(radar_t *, tower_t *);
void in_control_area(tower_t *, plane_t *, quadtree_t *);
void clean_planes(plane_t *);
void my_radar(char const *);
int my_getnbr(char const *);
sfCircleShape *create_circle(sfVector2f, float, sfColor);
char *next_nb(char *);
float distance(sfVector2f, sfVector2f);
int my_strlen(char const *);
void my_putstr(char const *);
int my_strcmp(char const *, char const *);
void help(void);
int error_handling(char const *);
void show_fps(radar_t *);
int my_nblen(int);
fps_t *create_fps(void);
void destroy_fps(fps_t *);
void pause_radar(radar_t *);
float coeff(plane_t *);
void place_tower(radar_t *, sfMouseButtonEvent);
void modify_towers(radar_t *, sfEvent);
