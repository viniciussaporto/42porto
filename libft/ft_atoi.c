/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:46:26 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/08 18:16:21 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	skiper(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' '
			|| str[i] == '\n'
			|| str[i] == '\f'
			|| str[i] == '\r'
			|| str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				res;

	res = 0;
	n = 1;
	i = skiper(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * n);
}