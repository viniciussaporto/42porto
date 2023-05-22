# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:16:29 by vsa-port          #+#    #+#              #
#    Updated: 2023/05/22 11:38:58 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN) Successfully removed!$(NOCOL)
CMP = $(GREEN) Successfully compiled!$(NOCOL)

CC = cc

RM = /bin/rm -f

FLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

N_BNS = checker

LIBFT = libft.a

LBT_F = libft/
SRC_F = source/
BNS_F = source_bonus/

SRC =	call_op1.c \
		call_op2.c \
		deal_2to5.c \
		deal_6plus.c \
		err_check.c \
		execute_mov.c \
		fill_stack.c \
		lis_utils.c \
		lis.c \
		mov.c \
		other_utils.c \
		print_stack.c \
		push_swap.c \
		push.c \
		rotate.c \
		stack_utils.c \
		swap.c \

BNS =	checker.c \


LIBFT := $(addprefix $(LBT_F),$(LIBFT))
SRC := $(addprefix $(SRC_F),$(SRC))
BNS := $(addprefix $(BNS_F),$(BNS))

OBJ_S = $(SRC:.c=.o)
OBJ_B = $(BNS:.c=.o)

all: $(NAME) bonus

$(NAME): comp

libcomp:
		@make -C libft

comp: libcomp $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) -o $(NAME)
	echo "$(TCOL)$(N_BNS) $(CMP)"

bonus: libcomp $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) $(LIBFT) -o $(N_BNS)
	echo "$(TCOL)$(N_BNS) $(CMP)"

libclean:
	@make clean -C libft

clean:		libclean
	$(RM) $(OBJ_S)
	$(RM) $(OBJ_B)

libfclean:
	@make fclean -C libft

fclean:		libfclean clean
	if [ -f $(NAME) ]; then\
		rm -rf $(NAME);\
		echo "$(TCOL)$(NAME) $(RMD)";\
	fi
	if [ -f $(N_BNS) ]; then\
		rm -rf $(N_BNS);\
		echo "$(TCOL)$(N_BNS) $(RMD)";\
	fi

re: fclean all

.PHONY: $(NAME) all re clean fclean bonus

.SILENT:
