/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:36:55 by vsa-port          #+#    #+#             */
/*   Updated: 2023/09/27 15:05:07 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_sawp.h"

void	swap(t_deque *deque, char c)
{
	int	tmp_data;

	tmp_data = deque->head->data;
	deque->head->data = deque->head->next->data;
	deque->head->next->data = tmp_data;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	each_swap(t_deque *deqie_a, t_deque *deque_b)
{
	swap(deque_a, 'c');
	swap(deque_b, 'c');
	ft_putstr_fd("ss\n", 1);
}
