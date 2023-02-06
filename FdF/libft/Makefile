# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 19:03:30 by vsa-port          #+#    #+#              #
#    Updated: 2023/01/27 11:23:57 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  ft_atoi.c \
		ft_isdigit.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_striteri.c \
		ft_bzero.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_tolower.c \
		ft_strmapi.c \
		ft_split.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_putendl_fd.c

BNS	= ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 

OBJS	= ${SRCS:.c=.o}
OBNS	= ${BNS:.c=.o}
INCS	= libft.h
NAME	= libft.a
LIBC	= ar rcs
CC		= clang
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME} ${OBNS}
	${LIBC} ${NAME} ${OBNS}

clean:
	${RM} ${OBJS} ${OBNS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re

# NAME = libft.a

# CC = cc

# CFLAGS = -Wall -Wextra -Werror -c

# INCLUDE	= libft.h

# SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
#     ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
# 	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
# 	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
# 	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
# 	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
# 	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# 	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
# 	get_next_line.c ft_abs_d.c ft_max_double.c \
# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@ar -rcs $(NAME) $(OBJS)

# $(OBJS): $(SRCS)
# 	@$(CC) $(CFLAGS) $(SRCS)

# bonus: $(NAME)
# 	@ar -rcs $(NAME)

# clean:
# 	@rm -f *.o

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
# 	$(CC)  -nostartfiles -shared -o libft.so $(OBJS)