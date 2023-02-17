/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:10:21 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/17 11:10:24 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r *= 10;
		r += str[i] - 48;
		i++;
	}
	return (r * s);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;
	
	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

static	int	ft_intlen(long number)
{
	int	l;
	int	is_negative;

	is_negative = 0;
	l = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		is_negative = 1;
		number = -number;
	}
	while (number != 0)
	{
		number /= 10;
		l++;
	}
	if (is_negative)
		return (l + 1);
	return (l);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	number;
	int		stop;

	stop = 0;
	number = n;
	len = ft_intlen(number);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (number < 0)
	{
		stop = 1;
		str[0] = '-';
		number = -number;
	}
	str[len--] = '\0';
	while (len >= stop)
	{
		str[len--] = (number % 10) + 48;
		number /= 10;
	}
	return (str);
}