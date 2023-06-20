/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:47:05 by vsa-port          #+#    #+#             */
/*   Updated: 2023/06/20 14:47:06 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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