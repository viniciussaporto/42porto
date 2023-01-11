# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:27:38 by vsa-port          #+#    #+#              #
#    Updated: 2023/01/09 11:30:18 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a

LIBFT_PATH ?= .

LIBFT_LINK	:= -L $(LIBFT_PATH) -l ft
LIBFT_INC	:= -I $(LIBFT_PATH)/.

ifndef LIB_LINK
LIB_LINK	:=
LIB_INC	:=
endif

LIB_LINK	+= $(LIBFT_LINK)
LIB_INC	+= $(LIBFT_INC)