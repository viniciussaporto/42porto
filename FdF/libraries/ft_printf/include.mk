# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:16:50 by vsa-port          #+#    #+#              #
#    Updated: 2023/01/09 11:30:07 by vsa-port         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPF = libftprint.a

LIBPF_PATH ?= .

LIBPF_LINK	:= -L $(LIBPF_PATH) -l ftprintf
LIBPF_INC	:= -I $(LIBPF_PATH)/.

ifndef LIBPF_LINK
LIB_LINK	:=
LIBPF_INC	:=
endif

LIB_LINK	+= $(LIBPF_LINK)
LIB_INC	+= $(LIBPF_INC)