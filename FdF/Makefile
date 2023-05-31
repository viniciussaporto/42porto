# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 15:56:43 by vsa-port          #+#    #+#              #
#    Updated: 2023/05/31 16:29:43 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
	  get_next_line.c \
	  read_map.c \
	  draw_grid.c \
	  color.c \
	  map_to_point.c \
	  keys.c \
	  keys2.c \
	  keys3.c \
	  mouse.c \
	  transformations.c \
	  menu.c \
	  screen.c \
	  rotations.c \
	  check_map.c \
	  check_map2.c

OBJS	= ${SRCS:.c=.o}

LIB_MINILIBX = -Lminilibx -lmlx -lXext -lX11 -lm -lz 
LIB_LIBFT	= libft/libft.a

MINILIBX = minilibx/
LIBFT = libft/

all: $(NAME) lib

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MINILIBX) $(LIB_LIBFT) -o $(NAME)

lib:
	make -C $(MINILIBX)
	make -C $(LIBFT)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	make clean -C ${MINILIBX}
	make fclean -C ${LIBFT}

re: fclean all