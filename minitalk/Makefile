# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/06/01 18:19:25 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SRC = server.c \
	client.c \

LIBFT = libft/
LIBFTPRINTF = libft/ft_printf/

LIBFT_LIB = $(LIBFT)libft.a
LIBFTPRINTF_LIB = $(LIBFTPRINTF)libftprintf.a

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT) -L$(LIBFTPRINTF) -lft -lftprintf

all: $(NAME)

$(NAME): $(OBJS) libft libftprintf
	$(CC) $(CFLAGS) -o $(SERVER) server.o $(LDFLAGS)
	$(CC) $(CFLAGS) -o $(CLIENT) client.o $(LDFLAGS)

libft:
	make -C $(LIBFT)

libftprintf:
	make -C $(LIBFTPRINTF)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBFTPRINTF)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBFTPRINTF)

re: fclean all
