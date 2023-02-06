# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 11:23:03 by vsa-port          #+#    #+#              #
#    Updated: 2023/02/06 14:57:38 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_print_address.c \
	ft_print_char.c \
	ft_print_hexa.c \
	ft_print_numbs.c \
	ft_print_string.c \
	ft_print_unsigned.c \
	utils.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)
	@echo "make all built!"

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@rm -f *.a
	@echo "clean done!"

fclean: clean
	@$(RM) $(NAME)
	@echo "fclean done!"

re: fclean all
	@echo "rebuild done!"