/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:58:26 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/22 11:03:15 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_swap(t_stack **stack, char s_name)
{
	ft_swap(stack);
	if (PRINT_PERM == 1)
		ft_printf("s%c\n", s_name);
}

void	ft_call_push(t_stack **dest, t_stack **src, char dest_name)
{
	ft_push(dest, src);
	if (PRINT_PERM == 1)
		ft_printf("p%c\n", dest_name);
}