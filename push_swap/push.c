/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:46:54 by vsa-port          #+#    #+#             */
/*   Updated: 2023/03/27 11:57:01 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_self_link(t_stack **stack)
{
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;
	
	if (*src)
	{
		temp = *src;
		if (ft_stack_size(*src) >= 2)
		{
			(*src)->next->prev = (*src)->prev;
			(*src)->prev->next = (*src)->next;
			*src = (*src)->next;
		}
		else
			*src = NULL;
		if (*dest)
		{
			temp->next = *dest;
			temp->prev = (*dest)->prev;
			(*dest)->prev->next = temp;
			(*dest)->prev = temp;
		}
		else
			ft_self_link(&temp);
		*dest = temp;
	}
}
/*the previou from node 2 of b should be put at the last of b
the next of the last node of b should be put at node 2 of b
the previous of node 1 of a should be put at node 1 of b
the next of the last node of a should be put at the node 1 of b
the previous of node 1 of b should be put at the last node of a
the next of node 1 of b should be put at the node 1 of a*/