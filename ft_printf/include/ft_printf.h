/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:54:48 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/29 07:24:25 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	putnbr_u(unsigned int nb);
int	put_pointer(void *nb, char *base);
int	put_hex(unsigned int nb, char *base);
int	ft_printf(const char *format, ...);

// static char	*hex_to_str(unsigned long n, char *base);
// static int	count_hex(unsigned long n);
// int	ft_print_arg(const char *fmt, int i, va_list ap);

#endif
