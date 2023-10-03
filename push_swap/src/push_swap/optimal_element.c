/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:37:00 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 13:50:11 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cnt_to_zero(int a_rotate, int b_rotate, t_deque *deq_a, t_deque *deq_b)
{
	while (a_rotate > 0)
	{
		reverse_rotate(deq_a, 'a');
		a_rotate++;
	}
	while (a_rotate < 0)
	{
		rotate(deq_a, 'a');
		a_rotate++;
	}
	while (b_rotate > 0)
	{
		reverse_rotate(deq_b, 'b');
		b_rotate--;
	}
	while (b_rotate < 0)
	{
		rotate(deq_b, 'b');
		b_rotate++;
	}
}

void	sort_optimal(int a_rotate, int b_rotate, t_deque *deq_a, t_deque *deq_b)
{
	while (a_rotate * b_rotate > 0)
	{
		if (a_rotate > 0 && b_rotate > 0)
		{
			each_reverse_rotate(deq_a, deq_b);
			a_rotate--;
			b_rotate--;
		}
		else
		{
			each_rotate(deq_a, deq_b);
			a_rotate++;
			b_rotate++;
		}
	}
	cnt_to_zero(a_rotate, b_rotate, deq_a, deq_b);
	push(deq_a, deq_b, 'a');
}

void	init_optimal(t_optimal *init, t_deque *deq_a, t_deque *deq_b)
{
	init->idx = 0;
	init->src_rotate = cal_src_rotate(0, deq_b);
	init->dst_rotate = cal_dst_rotate(deq_a, deq_b, 0);
	init->total_rotate = cal_total_rotate(init->src_rotate, init->dst_rotate);
}

void	push_optimal(t_deque *deq_a, t_deque *deq_b)
{
	int			idx;
	int			dst_rotate;
	int			src_rotate;
	int			total_rotate;
	t_optimal	optimal;

	idx = 1;
	init_optimal(&optimal, deq_a, deq_b);
	while (idx < deq_b->total_cnt)
	{
		dst_rotate = cal_dst_rotate(deq_a, deq_b, idx);
		src_rotate = cal_src_rotate(idx, deq_b);
		total_rotate = cal_total_rotate(src_rotate, dst_rotate);
		if (total_rotate < optimal.total_rotate)
		{
			optimal.idx = idx;
			optimal.dst_rotate = dst_rotate;
			optimal.src_rotate = src_rotate;
			optimal.total_rotate = total_rotate;
		}
		idx++;
	}
	sort_optimal(optimal.dst_rotate, optimal.src_rotate, deq_a, deq_b);
}
