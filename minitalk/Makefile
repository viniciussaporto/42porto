# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/02/07 10:24:06 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror -g

CC = gcc

c_src = utils.c

c_obj=$(c_src:.c=.o)

cb_obj=$(cb_src:.c=.o)

cb_src = utils_bonus.c

server = server

client = client

server_bonus = server_bonus

client_bonus = client_bonus

all: $(server) $(client)

bonus:$(server_bonus) $(client_bonus)

$(server_bonus):$(cb_obj) minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c $(cb_obj) -o $(server_bonus)

$(client_bonus):$(cb_obj) minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c $(cb_obj) -o $(client_bonus)

$(server):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) server.c $(c_obj) -o $(server)

$(client):$(c_obj) minitalk.h
	$(CC) $(CFLAGS) client.c $(c_obj) -o $(client)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(c_obj) $(cb_obj)

fclean: clean
	rm -rf $(client) $(server) $(client_bonus) $(server_bonus)

re: fclean all