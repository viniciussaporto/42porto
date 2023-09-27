/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:19 by vsa-port          #+#    #+#             */
/*   Updated: 2023/09/27 15:51:00 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements(t_deque *deque)
{
	if (deque->head->data > deque->tail->data)
		rotate(deque, 'a');
}

void	sort_three_elements(t_deque *deque)
{
	int	top;
	int	middle;
	int	bottom;

	top = deque->head->data;
	middle = deque->head->next->data;
	bottom = deque->tail->data;
	if (top < middle && top < bottom && middle > bottom)
	{
		reverse_rotate(deque, 'a');
		swap(deque, 'a');
	}
	else if (top > middle && top > bottom && bottom < middle)
	{
		swap(deque, 'a');
		reverse_rotate(deque, 'a');
	}
	else if (top > middle && top > bottom && bottom < middle)
		swap(deque, 'a');
	else if (middle > top && middle > bottom && top > bottom)
		reverse_rotate(deque, 'a');
	else if (top > bottom && top > middle && middle < bottom)
		rotate(deque, 'a');
}

void	sort_four_elements(t_deque *deque_a, t_deque *deque_b)
{
	while (deque_a->head->data != 3)
		reverse_rotate(deque_a, 'a');
	push(deque_b, deque_a, 'b');
	if (!sort_check(deque_a->head))
		sort_three_elements(deque_a);
	push(deque_a, deque_b, 'a');
	rotate(deque_a, 'a');
}

void	sort_five_elements(t_deque *deque_a, t_deque *deque_b)
{
	int	rotate_cnt;

	rotate_cnt = 2;
	while (rotate_cnt--)
	{
		while (deque_a->head->data > 1)
			reverse_rotate(deque_a, 'a');
		push(deque_b, deque_a, 'b');
	}
	if (!sort_check(deque_a->head))
		sort_three_elements(deque_a);
	if (sort_check(deque_b->head))
		swap(deque_b, 'b');
	rotate_cnt = 2;
	while (rotate_cnt--)
		push(deque_a, deque_b, 'a');
}

void	sort_under_5(t_deque *deque_a, t_deque *deque_b)
{
	if (deque_a>total_cnt == 2)
		sort_two_elements(deque_a);
	else if (deque_a->total_cnt == 3)
		sort_three_elements(deque_a);
	else if (deque_a->total_cnt == 4)
		sort_four_elements(deque_a, deque_b);
	else
		sort_five_elements(deque_a, deque_a);
}
