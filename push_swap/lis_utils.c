/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:43:55 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/05 19:00:59 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intset(int *arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*arr)[i] = value;
		i++;
	}
}

int	ft_find_max_i(int *arr, int size)
{
	int	i;
	int	max_i;
	int	temp;

	temp = arr[0];
	max_i = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int	ft_find_int(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}