/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:20:25 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/05 18:03:07 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_mov_b(int size)
{
	int	i;
	int	*mov_b;

	mov_b = malloc(sizeof(int) * size);
	if (size > 0)
	{
		i = 0;
		while (i < (size / 2))
		{
			mov_b[size - i - 1] = (i + 1) * - 1;
			i++;
		}
		i = 0;
		while (i < (size / 2) + 1)
		{
			mov_b[i] = i;
			i++;
		}
	}
	return (mov_b);
}

int	ft_fill_mov_a(t_stack *s1, int s2_n)
{
	t_stack	*temp;
	int	size;
	int	value;
	int	i;
	
	size = ft_stack_size(s1);
	if (ft_pos_with_n(s1, ft_find_smallest(s1)->n) > size / 2 + 1)
		value = ft_pos_with_n(s1, ft_find_smallest(s1)->n) - 1 - size;
	else
		value = ft_pos_with_n(s1, ft_find_smallest(s1)->n) - 1;
	temp = s1;
	i = 0;
	while (i++ < size)
	{
		if (s2_n > temp->prev->n && s2_n < temp->n)
		{
			if (ft_pos_with_n(s1, temp->n) > 2 + 1)
				value = ft_pos_with_n(s1, temp->n) - 1 - size;
			else
				value = ft_pos_with_n(s1, temp->n) - 1;
		}
		temp = temp->next;
	}
	return (value);
}

int	*ft_mov_a(t_stack *s1, t_stack *s2, int size)
{
	int	*mov_a;
	int	i;

	mov_a = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		mov_a[i] = ft_fill_mov_a(s1, s2->n);
		i++;
		s2 = s2->next;
	}
	return (mov_a);
}