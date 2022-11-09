# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:41:01 by vsa-port          #+#    #+#              #
#    Updated: 2022/11/09 11:09:25 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a

CC      =   cc

CFLAGS  =   -Wall -Wextra -Werror

SRCS    =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_toupper.c \
		ft_tolower.c ft_strncmp.c ft_memcmp.c ft_strrchr.c ft_strnstr.c \
		ft_strdup.c ft_strjoin.c ft_substr.c ft_strlen.c ft_strlcpy.c \
		ft_strlcat.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strtrim.c \
		ft_split.c ft_strchr.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

OBJS    =   $(SRCS:.c=.o)

SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all:    $(NAME)

bonus:	$(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS)

$(NAME):    $(OBJS)
	ar rcs $(NAME) $^

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *.so
	rm -f *.out

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)
