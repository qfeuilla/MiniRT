# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 18:51:09 by qfeuilla          #+#    #+#              #
#    Updated: 2019/11/30 14:25:50 by qfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
FLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -L mylibft -lft -O3 -Wall -Werror
INCLUDES = -I /usr/local/include
C = clang
LIBFT = mylibft
DIR_S = srcs
SOURCES =	parser/atof.c \
			parser/get_color.c \
			parser/get_each_digi.c \
			parser/get_vec3.c \
			parser/lst_last_obj.c \
			parser/man_er.c \
			parser/manage_alight.c \
			parser/manage_cam.c \
			parser/manage_cylinder.c \
			parser/manage_light.c \
			parser/manage_plane.c \
			parser/manage_screen.c \
			parser/manage_sphere.c \
			parser/manage_square.c \
			parser/manage_triangle.c \
			parser/parser.c \
			parser/parser_utils.c \
			parser/scene_last.c \
			render/color_stuff.c \
			render/compute_ray.c \
			render/destroyer.c \
			render/free_cy_sp.c \
			render/free_li_cam.c \
			render/free_tr_sq.c \
			render/get_color_utimate.c \
			render/hit_stuff.c \
			render/intersect_cy.c \
			render/intersect_pl.c \
			render/intersect_sp.c \
			render/intersect_sq.c \
			render/intersect_tr.c \
			render/main.c \
			render/obj_cmp.c \
			render/process_normal.c \
			render/rot_stuff.c \
			render/vector_functions1.c \
			render/vector_functions2.c \
			render/vector_functions3.c \
			render/vector_functions4.c \
			render/window.c \
			render/write_bmp.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): libft
	@cc $(INCLUDES) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f *.bmp
	@make fclean -C $(LIBFT)

re: fclean all