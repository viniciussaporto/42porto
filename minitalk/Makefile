# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/02/06 15:00:04 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF) -L$(PRINTF) -lftprintf

PRINTF = ft_printf

all:
	make -s -C $(PRINTF)
	gcc $(FLAGS) server.c -o $(SERVER)
	gcc $(FLAGS) client.c -o $(CLIENT)

clean:
	make clean -s -C $(PRINTF)

fclean: clean
	make fclean -s -C $(PRINTF)
	rm -f $(SERVER) $(CLIENT)
	
re: fclean all