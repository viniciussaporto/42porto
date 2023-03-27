/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:51:56 by vsa-port          #+#    #+#             */
/*   Updated: 2023/03/27 16:51:56 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate( t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}