# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/02/17 16:32:38 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SRC = server.c \
	client.c \
	wrapper.c
LIBFT = ./libft/libft.a
OBJS = $(SRC:.c=.o)

CC = cc -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(OBJS)
			$(CC) 