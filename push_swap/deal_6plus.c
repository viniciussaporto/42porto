/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_6plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:55:45 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/11 16:17:20 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minmax(int a, int b)
{
	int	max;

	if (a >= 0 && b >= 0)
	{
		if (a >= b)
			max = a;
		else
			max = b;
	}
	if (a < 0 && b < 0)
	{
		if (a <= b)
			max = a;
		else
			max = b;
	}
	return (max);
}

int	ft_find_move_value(int a, int b)
{
	int	moves;

	moves = 0;
	if (a >= 0 && b >= 0)
		moves = ft_minmax(a, b);
	else if (a < 0 && b < 0)
		moves = (ft_minmax(a, b) * -1);
	else if (a >= 0 && b < 0)
		moves = (b * -1) + a;
	else if (a < 0 && b >= 0)
		moves = (a * -1) + b;
	return (moves);

}

int	ft_best_move(int size, int *mov_a, int *mov_b)
{
	int	move;
	int	move_i;
	int	i;

	move = ft_find_move_value(mov_a[0], mov_b[0]);
	move_i = 0;
	i = 1;
	while (i < size)
	{
		if (move >= ft_find_move_value(mov_a[0], mov_b[0]))
		{
			move = ft_find_move_value(mov_a[i], mov_b[i]);
			move_i = i;
		}
		i++;
	}
	return (move_i);
}

void	ft_mov(t_stack **s1, t_stack **s2)
{
	int	*mov_a;
	int	*mov_b;
	int	s2_size;
	int	i;

	s2_size = ft_stack_size(*s2);
	mov_a = ft_mov_a(*s1, *s2, s2_size);
	mov_b = ft_mov_b(s2_size);
	i = ft_best_move(s2_size, mov_a, mov_b);
	ft_exec_move(s1, s2, mov_a[i], mov_b[i]);
	free(mov_a);
	free(mov_b);
}

void	ft_deal_6plus(t_stack **s1, t_stack **s2)
{
	int	s2_size;

	ft_lis(s1, s2);
	s2_size = ft_stack_size(*s2);
	while (s2_size--)
	{
		ft_mov(s1, s2);
		ft_call_push(s1, s2, 'a');
	}
	ft_put_node_on_top(s1, ft_find_smallest(*s1), 'a');
}