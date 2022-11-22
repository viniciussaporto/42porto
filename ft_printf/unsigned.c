/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:14:24 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/22 22:42:14 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_num_len(unsigned	int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_num_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (nb);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}