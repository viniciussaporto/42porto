/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:08:50 by vsa-port          #+#    #+#             */
/*   Updated: 2023/03/27 17:08:50 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack && (*stack) != (*stack)->next)
	{
		if ((*stack)->next == (*stack)->prev)
			(*stack) = (*stack)->next;
		else
		{
			temp = (*stack)->prev;
			(*stack)->prev = (*stack)->next;
			(*stack)->next = (*stack)->next->next;
			(*stack)->next->prev = (*stack);
			temp->next = (*stack)->prev;
			temp->next->prev = temp;
			temp->next->next = (*stack);
			(*stack) = temp->next;
		}
	}
}

/*if only 2 nodes
the 2 turns into first

else
temp goes to 4th (last)
the prev from 1 goes to 2
next from 1 go to 3 (the one after 2)
prev from 3 goes to 1
next goes from 4(last) to 2
prev goes from 2 to 4
next goes from 2 to 1
stack goest to 2 (the new first)

in the possibility of more than 2 nodes
[... -> 4 -> 1 -> 2 -> 3 -> 4 -> ...]

the next of (node) 4 should be in 2
the next of (node) 2 should be in 4
the next of (node) 2 should be in 1
the next of (node) 1 should be in 2
the next of (node) 1 should be in 3
the next of (node) 3 should be in 2

in the case of 2 nodes

[... -> 2 -> 1 -> 2 -> ...]
the first goes to the second
*/