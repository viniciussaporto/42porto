/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_rotate_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:41 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 14:46:47 by vsa-port         ###   ########.fr       */
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
	int	rotate;

	range = deque_b->total_cnt / 2;
	if (idx <= range)
		return (idx * (-1));
	else
		return (deque_b->total_cnt - idx);
}

int	cal_dst_rotate(t_deque *deque_a, t_deque *deque_b, int idx)
{
	int	location;

	location = find_location
}