##
## EPITECH PROJECT, 2019
## quadtree
## File description:
## Makefile
##

LIB	=	lib/my_getnbr.c		\
		lib/next_nb.c		\
		lib/distance.c		\
		lib/my_putstr.c		\
		lib/my_strlen.c		\
		lib/my_strcmp.c		\
		lib/my_nblen.c		\

SRC	=	src/main.c			\
		src/my_radar.c			\
		src/query.c			\
		src/create_qt.c			\
		src/recreate_qt.c		\
		src/display_planes.c		\
		src/display_qt.c		\
		src/insert_qt.c			\
		src/subdivide_qt.c		\
		src/create_planes.c		\
		src/move_planes.c		\
		src/destroy_qt.c		\
		src/destroy_query.c		\
		src/destroy_planes.c		\
		src/create_image.c		\
		src/destroy_image.c		\
		src/create_rect.c		\
		src/display_time.c		\
		src/create_clock_time.c		\
		src/destroy_clock_time.c	\
		src/destroy_radar.c		\
		src/create_radar.c		\
		src/display_radar.c		\
		src/collision.c			\
		src/create_towers.c		\
		src/destroy_towers.c		\
		src/display_towers.c		\
		src/in_control_area.c		\
		src/clean_planes.c		\
		src/create_circle.c		\
		src/intersect_rect.c		\
		src/help.c			\
		src/error_handling.c		\
		src/show_fps.c			\
		src/destroy_fps.c		\
		src/create_fps.c		\
		src/pause.c			\
		src/place_tower.c		\
		src/modify_towers.c		\

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	my_radar

CFLAGS	=	-I./include -g

CPPLAGS	=	-l csfml-window -l csfml-graphics -l csfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all
