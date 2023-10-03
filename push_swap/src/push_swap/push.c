/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:00:06 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 13:22:15 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_deque *deq_dst, t_deque *deq_src, char c)
{
	t_element	*prev_dst_head;
	t_element	*prev_src_head;
	
	if (deq_src->total_cnt == 0)
		return ;
	prev_dst_head = deq_dst->head;
	prev_src_head = deq_src->head;
	deq_src->head = prev_src_head->next;
	if (deq_src->head)
		deq_src->head->prev = 0;
	deq_dst->head = prev_src_head;
	deq_dst->head->next = prev_dst_head;
	if (prev_dst_head)
		prev_dst_head->prev = deq_dst->head;
	else
	{
		deq_dst->head->next = 0;
		deq_dst->tail = deq_dst->head;
	}
	deq_dst->total_cnt++;
	deq_src->total_cnt--;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}