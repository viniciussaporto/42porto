# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:02:50 by vsa-port          #+#    #+#              #
#    Updated: 2023/01/17 14:56:19 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra -g -nostartfiles
MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lz -lm
#-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
LIBFT	=	./libft/libft.a
PRINTF	=	./ft_printf/libftprintf.a

LNK  = -L /libft -lft -L /ft_printf -lftprintf \
#libft.a libftprintf.a \

SRC = main.c \
	draw.c \
	init_data.c \
	key_and_mouse_controls.c \

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(MAKE) --no-print-directory -C ./libft
	@cp ./libft/libft.a .
	@echo "LIBFT DONE!💻📚"
	@$(MAKE) --no-print-directory -C ./ft_printf
	@cp ./ft_printf/libftprintf.a .
	@echo "FT_PRINTF DONE!💻🖨"
	@$(MAKE) --no-print-directory -C ./mlx_linux
	@echo "MiniLibX DONE!💻🕹"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME)
	@echo "FdF READY!💻📈"

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
	rm -rf $(NAME)
	echo "OBJECTS DELETED!"

fclean:
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf
	rm -rf $(NAME)
	echo "$(NAME) DELETED!"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

# NAME = fdf

# SRC = main.c \
# 	draw.c \
# 	init_data.c \
# 	key_and_mouse_controls.c \

# OBJDIR = ./obj/
# OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
# D_FILES = $(addprefix $(OBJDIR),$(SRC:.c=.d))
# CC ?= gcc -Wall -Werror -Wextra
# DEBUG = -g
# OPTIMIZATION = -O2
# LIB += -lmlx
# LIB += -lft
# LIB += -lXext #X11 miscellaneous extensions library
# LIB += -lX11 #Core X11 protocol client library
# LIB += -lm #standard C library of basic mathematical functions
# LIB += -lz #libz - compression/decompression library
# LIBPATH += -L./libraries/mlx_linux
# LIBPATH += -L./libraries/libft
# LIBINC += -I./libraries/mlx_linux/
# LIBINC += -I./libraries/libft/

# all : $(NAME)

# $(NAME): obj $(OBJ)
# 	make -C ./libraries/libft/
# 	make -C ./libraries/mlx_linux/
# 	$(CC) $(OBJ) $(LIBPATH) $(LIB) $(LIBINC)  -o $(NAME)

# obj:
# 	mkdir -p $(OBJDIR)

# $(OBJ): $(OBJDIR)%.o : %.c fdf.h
# 	$(CC) $(DEBUG) $(OPTIMIZATION) $(LIBINC) -c $< -o $@ -MMD

# include $(wildcard $(D_FILES))

# bonus: all

# norm:
# 	norminette $(SRC)

# # rule for the cleaning
# clean:
# 	make clean -C ./libraries/libft
# 	make clean -C ./libraries/mlx_linux
# 	rm -rf $(OBJDIR)

# fclean:
# 	make fclean -C ./libraries/libft
# 	make clean -C ./libraries/mlx_linux
# 	rm -rf $(OBJDIR)
# 	rm -f $(NAME)

# # rule for rebuild a project
# re: fclean all

# # directory exceptions
# .PHONY: all clean fclean norm re bonus