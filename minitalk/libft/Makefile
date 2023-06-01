# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 19:03:30 by vsa-port          #+#    #+#              #
#    Updated: 2023/06/01 16:30:15 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft.h

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Successfully created $(NAME)"

$(LIBFTPRINTF):
	@make -C ./ft_printf
	@echo "Successfully built ft_printf"

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJS)
	@make clean -C ./ft_printf
	@echo "Successfully cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf
	@echo "Successfully removed $(NAME)"

re: fclean all
