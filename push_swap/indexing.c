/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:46:09 by vsa-port          #+#    #+#             */
/*   Updated: 2023/06/21 16:35:25 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_swap(int small, int big)
{
	int	temp;

	temp = small;
	small = big;
	big = temp;
	return (big);
}

void	bubble_sort(t_stack **stack)
{
	t_stack *temp;
	int	i;
	int	count;
	int	num_temp;
	int	swap;

	i = 0;
	count = len_stack_index_assign(stack);
	temp = *stack;
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		i = 0;
		temp = *stack;
		while (i < count - 1)
		{
			if (temp->value > temp->next->value)
			{
				swap = 1;
				num_temp = temp->next->value;
				temp->next->value = bubble_swap(temp->value, temp->next->value);
				temp->value = num_temp;
			}
			i++;
			temp = temp->next;
		}
	}
}

int	len_stack_index_assign(t_stack **stack)
{
	t_stack *temp;
	int	counter;
	int	i;
	
	temp = *stack;
	i = 1;
	counter = 0;
	if (*stack != NULL)
	{
		counter = 1;
		while (temp->next != NULL)
		{
			temp->index = i;
			temp = temp->next;
			counter++;
			i++;
		}
		temp->index = i;
	}
	return (counter);
}

void	index_assignment(t_stack **stack_a, t_stack **stack_sorted)
{
	t_stack	*temp_a;
	t_stack	*temp_sorted;
	int	i;
	int	count;

	count = len_stack(stack_a);
	temp_a = *stack_a;
	temp_sorted = *stack_sorted;
	i = 0;
	while (i <= count && temp_sorted)
	{
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->value == temp_sorted->value \
			&& temp_a->index != temp_sorted->index)
			{
				i = 0;
				temp_a->index = temp_sorted->index;
			}
			temp_a = temp_a->next;
		}
		temp_sorted = temp_sorted->next;
		i++;
	}
}
