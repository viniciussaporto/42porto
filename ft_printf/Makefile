# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 14:12:05 by vsa-port          #+#    #+#              #
#    Updated: 2022/11/29 07:26:28 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -rf

SRCS	= ft_printf.c \
	src/ft_printf_utils.c \
	src/ft_putpointer.c \
	src/puthex.c \

OBJS	= $(SRCS:.c=.o)

OBJSBONUS	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(MAKE) clean -C ./libft
	$(RM) $(NAME)

re: fclean all
