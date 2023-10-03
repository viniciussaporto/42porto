/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:33 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 13:32:40 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deques(t_deque *deque_a, t_deque *deque_b, char *argv[])
{
	deque_a->head = 0;
	deque_a->tail = 0;
	deque_a->total_cnt = 0;
	deque_b->head = 0;
	deque_b->tail = 0;
	deque_b->total_cnt = 0;
	insert_argv_to_deque(deque_a, argv + 1);
}

void	push_deque_a_to_b(t_deque *deque_a, t_deque *deque_b)
{
	if (deque_a->total_cnt > 5)
	{
		move_based_pivot(deque_a, deque_b);
		while (deque_a->total_cnt > 3)
			push(deque_b, deque_a, 'b');
		if (!sort_check(deque_a->head))
			sort_under_5(deque_a, deque_b);
	}
	else
	{
		if (!sort_check(deque_a->head))
			sort_under_5(deque_a, deque_b);
	}
}

void	push_deque_b_to_a(t_deque *deque_a, t_deque *deque_b)
{
	if (!deque_b->head)
		return ;
	while (deque_b->total_cnt)
		push_optimal(deque_a, deque_b);
	while (deque_a->head->data != 0)
		reverse_rotate(deque_a, 'a');
}

int	main(int argc, char *argv[])
{
	t_deque		deque_a;
	t_deque		deque_b;
	t_element	*free_element;

	if (argc > 1)
	{
		init_deques(&deque_a, &deque_b, argv);
		push_deque_a_to_b(&deque_a, &deque_b);
		push_deque_b_to_a(&deque_a, &deque_b);
		while (deque_a.head)
		{
			free_element = deque_a.head;
			deque_a.head = deque_a.head->next;
			free(free_element);
		}
	}
	return (0);
}