# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 22:20:35 by vsa-port          #+#    #+#              #
#    Updated: 2022/11/22 22:31:55 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm -f
AR	=	ar rcs
LIBFT	=	libft

SRCS	=	ft_printf.c ishex.c isptr.c unisgned.c utils.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "ft_printf compiled!"

clean:
	@$(RM) -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "ft_printf cleaned!"
	
fclean:	clean
	@$(RM) -f $(NAME)
	@$(RM) -f $(LIBFT)/libft.a
	@echo "ft_printf and libft executables cleaned!"

re:	fclean all
	@echo "Everything rebuilt!"

.PHONY:	all clean fclean re norm