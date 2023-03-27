/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:34:58 by vsa-port          #+#    #+#             */
/*   Updated: 2023/03/27 17:34:58 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	size;

	size = ft_stack_size(stack);
	while (size > 0)
	{
		ft_printf("%d\n", stack->n);
		stack = stack->next;
		size--;
	}
}

void	ft_rev_print_stack(t_stack *stack)
{
	int	size;

	size = ft_stack_size(stack);
	if (stack)
		stack = stack->prev;
	while (size > 0)
	{
		ft_printf("%d\n", stack->n);
		stack = stack->prev;
		size--;
	}
}