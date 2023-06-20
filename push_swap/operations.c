/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:05:41 by vsa-port          #+#    #+#             */
/*   Updated: 2023/06/12 14:12:31 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	
	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
	write(1, "sb\n", 3);
}

