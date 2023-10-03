/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_rotate_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:41 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 15:18:50 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_location(t_deque *deque_a, t_deque *deque_b, int idx)
{
	int			cnt;
	int			data;
	t_element	*element;
	t_element	*head;
	
	head = deque_a->head;
	element = deque_b->head;
	cnt = 1;
	while (idx--)
		element = element->next;
	data = element->data;
	while (head != deque_a->tail)
	{
		if (((head->data > head->next->data) && ((data > head->data \
		&& data > head->next->data) || \
		(data < head->data && data < head->next->data))) || \
		((!(head->data > head->next->data)) && \
		(data > head->data && data < head->next->data)))
			return (cnt);
		head = head->next;
		cnt++;
	}
	return (0);
}

int	cal_src_rotate(int idx, t_deque *deque_b)
{
	int	range;

	range = deque_b->total_cnt / 2;
	if (idx <= range)
		return (idx * (-1));
	else
		return (deque_b->total_cnt - idx);
}

int	cal_dst_rotate(t_deque *deque_a, t_deque *deque_b, int idx)
{
	int	location;

	location = find_location(deque_a, deque_b, idx);
	if (!location)
		return (0);
	else
	{
		if (location < deque_a->total_cnt / 2)
			return (location *= -1);
		else
			return (deque_a->total_cnt - location);
	}
}

int	cal_total_rotate(int src_rotate, int dst_rotate)
{
	if (src_rotate * dst_rotate > 0)
	{
		if (src_rotate < 0)
		{
			src_rotate *= -1;
			dst_rotate *= -1;
		}
		if (src_rotate > dst_rotate)
			return (src_rotate);
		else
			return (dst_rotate);
	}
	else
	{
		if (src_rotate - dst_rotate > 0)
			return (src_rotate - dst_rotate);
		else
			return (dst_rotate - src_rotate);
	}
}
