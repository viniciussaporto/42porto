# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/06/01 16:17:31 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SRC = server.c \
	client.c \

LIB_LIBFT = ./libft/libft.a
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) -o $(SERVER) server.o $(LIB_LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) client.o $(LIB_LIBFT)

lib:
	make -C $(LIBFT)

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT)

re: fclean all
