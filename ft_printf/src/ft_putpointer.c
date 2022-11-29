/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:40:58 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/29 07:25:26 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*hex_to_str(unsigned long n, char *base)
{
	int	size;
	char	*hex;
	
	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	put_pointer(void *nb, char *base)
{
	int	len;
	char	*str;
	unsigned long		n;
	
	n = (unsigned long)nb;
	str = hex_to_str(n, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}