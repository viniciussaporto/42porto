/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:35:35 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/29 07:25:33 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_putnbr(int nb)
{
	char	*str;
	int	len;
	
	str = ft_itoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	putnbr_u(unsigned int nb)
{
	char	*str;
	int	len;

	str = ft_utoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}