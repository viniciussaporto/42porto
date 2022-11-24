/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:12:41 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/24 04:27:05 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_print_arg(const char *fmt, int i, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_print_arg(format, i, ap);
			i++;
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}

int	ft_print_arg(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == '%')
		return (ft_putchar(fmt[i + 1]));
	else if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (fmt [i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (putnbr_u(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
	{
		if (fmt[i + 1] == 'X')
			return (put_hex(va_arg(ap, unsigned int), "1234567890ABCDEF"));
		else
			return (put_hex(va_arg(ap, unsigned int), "1234567890abcdef"));
	}
	else if (fmt[i + 1] == 'p')
		return (ft_putstr("0x") + put_pointer(va_arg(ap, void *), "1234567890abcdef"));
	else
		return (0);
}