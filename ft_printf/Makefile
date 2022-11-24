# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 03:59:17 by vsa-port          #+#    #+#              #
#    Updated: 2022/11/24 04:15:29 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

INCLUDE	= ./include
SRC	= ./src

CFLAGS	= -Wall -Wextra -Werror -g -I./include
CC	= gcc
FLAGLIB	= -rcs
RM	= /bin/rm/ -f

LIBFT_DIR	= ./libft
LIBFT	= ./libft/libft.a

FT_PRINTF	= ft_printf_utils.c ft_putpointer.c puthex.c ft_printf.c
OBJECTS	= $(FT_PRINTF:.c=.o)

all:	$(NAME)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@echo "Starting compilation of: $(NAME)"
	@cp $(LIBFT) $(NAME)
	@ar $(FLAGLIB) $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Done!"
	
$(LIBFT): $(LIBFT_DIR)
	@echo "Compiling libft!"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "libft compiled!"

%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJECTS)
	@echo "clean done!"

fclean:	clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "fclean done!"

re: fclean all
	@echo "Rebuilding done!"

.PHONY: all re clean fclean