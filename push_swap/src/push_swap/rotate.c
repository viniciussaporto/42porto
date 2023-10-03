/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:37:25 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 12:59:40 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_deque *deque, char c)
{
	t_element	*prev_head;
	t_element	*prev_tail;

	if (deque->total_cnt == 1)
		return;
	prev_head = deque->head;
	prev_tail = deque->tail;
	deque->tail = prev_tail->prev;
	prev_head->prev = prev_tail;
	deque->head = prev_tail;
	deque->head->next = prev_head;
	deque->head->prev = 0;
	deque->tail->next = 0;
	deque->head->next = prev_head;
	if (c == 'a')
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	each_rotate(t_deque *deque_a, t_deque *deque_b)
{
	rotate(deque_a, 'c');
	rotate(deque_b, 'c');
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}

void	rotate(t_deque *deque, char c)
{
	t_element	*prev_head;
	t_element	*prev_tail;

	if (deque->total_cnt == 1)
		return;
	prev_head = deque->head;
	prev_tail = deque->tail;
	deque->head = deque->head->next;
	if (deque->head)
		deque->head->prev = 0;
	deque->tail = prev_head;
	if (deque->tail)
	{
		deque->tail->prev = prev_tail;
		prev_tail->next = deque->tail;
	}
	deque->tail->next = 0;
	if (c == 'a')
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (c == 'b')
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	each_reverse_rotate(t_deque *deque_a, t_deque *deque_b)
{
	reverse_rotate(deque_a, 'c');
	reverse_rotate(deque_b, 'c');
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
