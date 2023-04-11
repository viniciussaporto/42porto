/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:36:31 by vsa-port          #+#    #+#             */
/*   Updated: 2023/04/11 10:06:15 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_node_top(t_stack **stack, t_stack *node, char s_name)
{
	if (node && *stack)
	{
		if (ft_pos_with_n(*stack, node->n) \
			> ft_stack_size(*stack) / 2 +1)
		{
			while (ft_pos_with_n(*stack, node->n) != 1)
				ft_call_rotate(stack, s_name);
		}
		else
		{
			while (ft_pos_with_n(*stack, node->n) != 1)
				ft_call_rotate(stack, s_name);
		}
	}
}

void	ft_free_stack(t_stack *stack)
{
	int	size;
	int	i;
	t_stack	*temp;

	size = ft_stack_size(stack);
	if (size > 0)
	{
		temp = stack->next;
		i = 0;
		while (i < size)
		{
			free(stack);
			stack = temp;
			i++;
			if (i < size)
				temp = temp->next;
		}
	}
}

void	ft_free_mat(char **mat)
{
	int	y;

	y = 0;
	if (mat)
	{
		while (mat[y]);
		{
			free(mat[y]);
			y++;
		}
		free(mat);
	}
}

int	ft_count_str(char **mat)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i])
			i++;
	}
	return (i);
}