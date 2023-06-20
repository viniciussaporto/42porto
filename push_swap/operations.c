/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:05:41 by vsa-port          #+#    #+#             */
/*   Updated: 2023/06/20 14:30:56 by vsa-port         ###   ########.fr       */
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

void	rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
	t_stack	*temp;
	
	temp = *stack;
	first = *stack;
	second = first->next;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp;
	last->next = first;
	first->next = NULL;
	*stack = second;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
	t_stack	*temp;
	
	temp = *stack;
	first = *stack;
	second = first->next;
	while (temp->next != NULL)
		temp = temp->next;
	last = temp;
	last->next = first;
	first->next = NULL;
	*stack = second;
	write(1, "rb\n", 3);
}

void	reverse_rotate_a(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;
	int		counter;
	int		i;
	
	counter = 1;
	i = 1;
	temp = *stack;
	first = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	last = temp;
	last->next = first;
	temp = *stack;
	while (i < (counter - 1))
	{
		temp = temp->next;
		i++;
	}
	before_last = temp;
	before_last->next = NULL;
	*stack = last;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;
	int		counter;
	int		i;

	counter = 1;
	i = 1;
	temp = *stack;
	first = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		counter++;
	}
	last = temp;
	last->next = first;
	temp = *stack;
	while (i < (counter - 1))
	{
		temp = temp->next;
		i++;
	}
	before_last = temp;
	before_last->next = NULL;
	*stack = last;
	write(1, "rrb\n", 4);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	*stack_a = second;
	first->next = *stack_b;
	*stack_b = first;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	*stack_a = second;
	first->next = *stack_b;
	*stack_b = first;
	write(1, "pb\n", 3);
}