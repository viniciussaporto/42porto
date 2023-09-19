# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:40:08 by vsa-port          #+#    #+#              #
#    Updated: 2023/09/19 17:47:40 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SRC = server.c \
	client.c \

LIBFTPRINTF = ./libft/ft_printf/

LIBFTPRINTF_LIB = $(LIBFTPRINTF)libftprintf.a

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = $(LIBFTPRINTF)libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) libftprintf
	@$(CC) $(CFLAGS) -o $(SERVER) server.o $(LDFLAGS)
	@$(CC) $(CFLAGS) -o $(CLIENT) client.o $(LDFLAGS)
	@echo "Successfully built server and client!"

server: $(NAME)
	@$(CC) $(CFLAGS) -o $(SERVER) server.o $(LDFLAGS)
	@echo "Successfully built server!"

client: $(NAME)
	@$(CC) $(CFLAGS) -o $(CLIENT) client.o $(LDFLAGS)
	@echo "Successfully built client!"

libftprintf:
	@$(MAKE) -C $(LIBFTPRINTF)
	@echo "Successfully built PRINTF!"

$(OBJS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJS)
	@$(MAKE) clean -C $(LIBFTPRINTF)
	@echo "CLEAN complete!"

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)
	@$(MAKE) fclean -C $(LIBFTPRINTF)
	@echo "FCLEAN complete!"

re: fclean all
