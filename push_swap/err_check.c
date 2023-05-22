/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:36:15 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/11 16:18:53 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_limit_check(char *str)
{
	long long	res;
	int	sign;
	int	i;
	int	dig_n;

	dig_n = 0;
	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && dig_n <= 11)
	{
		res = res * 10 + str[i] - '0';
		i++;
		dig_n++;
	}
	if (dig_n > 10 || res * sign > INT_MAX || res * sign < INT_MIN)
		return (1);
	return (0);
}

int	ft_int_type_check(char *str)
{
	int	i;
	int	check;

	check = 0;
	if (((str[0] == '-' || str[0] == '+')
			&& ft_strlen(str) > 1) || ft_isdigit(str[0]))
	{
		i = 1;
		while (str[i] && check == 0)
		{
			if (!ft_isdigit(str[i]))
				check = 1;
			i++;
		}
	}
	else
		check = 1;
	return (check);
}

int	ft_error_deal(char **mat)
{
	int	check;
	int	size;
	int	j;
	int	k;

	size = ft_count_str(mat);
	check = 0;
	j = 0;
	while (j < size && !check)
	{
		k = j + 1;
		while (k < size && !check)
		{
			if (ft_atoi(mat[j]) == ft_atoi(mat[k]))
				check++;
			k++;
		}
		check += ft_int_type_check(mat[j]);
		check += ft_int_limit_check(mat[j]);
		j++;
	}
	return (check);
}