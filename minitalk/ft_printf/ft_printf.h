/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:46:31 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:54 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#  include <stdarg.h>
#  include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_numbs(long num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hexa(unsigned long num, char c);
int	ft_print_address(unsigned long num);

// minitalk

# include <signal.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

int	ft_strlen(const char *str);
int	ft_atoi(const char *str);

#endif