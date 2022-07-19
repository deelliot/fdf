# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 10:02:36 by deelliot          #+#    #+#              #
#    Updated: 2022/07/19 15:32:35 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src
INCL_DIR = ./includes

SRCS = 1_main.c
SRCS += 2_initialise.c
SRCS += 3_store.c
SRCS += 4_colour.c
SRCS += 5_key_controls.c
SRCS += 6_key_functions.c
SRCS += 6_key_functions_2.c
SRCS += 7_plot_points.c
SRCS += 8_rotate.c
SRCS += 9_projection.c
SRCS += 10_draw.c
SRCS += 11_utilities.c
SRCS += 12_free_map.c

INCL = fdf.h

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
INCLS = $(addprefix $(INCL_DIR)/,$(INCL))

LINKS =  -L./libft -lft
LINKS +=  -L./minilibx -lmlx -framework OpenGL -framework Appkit
# LINKS += -L /usr/local/lib -lmlx -I /usr/local/include -framework \
# 	OpenGL -framework AppKit

INCLS = fdf.h

OBJS = $(SRC:%.c=%.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx
	@$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) -I $(INCL) $(LINKS)

%.o: $(SRC_DIR)/%.c
	$(CC) -g -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	make clean -C libft/
	make clean -C minilibx/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

run: re
	./fdf test

.PHONY: all fclean clean re

$(V).SILENT: