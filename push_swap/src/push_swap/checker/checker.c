/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:34:39 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/10 08:53:29 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_deque(t_deque *deque_a, t_deque *deque_b, char *argv[])
{
	deque_a->head = 0;
	deque_a->tail = 0;
	deque_a->total_cnt = 0;
	deque_b->head = 0;
	deque_b->tail = 0;
	deque_b->total_cnt = 0;
	insert_argv_to_deque(deque_a, argv + 1);
}

void	do_operation2(char *operation, t_deque *deque_a, t_deque *deque_b)
{
	if (!ft_strncmp(operation, "rra\n", 4))
		reverse_rotate(deque_a, 'd');
	else if (!ft_strncmp(operation, "rrb\n", 4))
		reverse_rotate(deque_b, 'd');
	else if (!ft_strncmp(operation, "rrr\n", 4))
		each_reverse_rotate(deque_a, deque_b);
	else if (!ft_strncmp(operation, "sa\n", 3))
		swap(deque_a, 'd');
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap(deque_b, 'd');
	else if (!ft_strncmp(operation, "ss\n", 3))
		each_swap(deque_a, deque_b);
	else
		exit_error();
}

void	do_operation(char *operation, t_deque *deque_a, t_deque *deque_b)
{
	if (!ft_strncmp(operation, "pa\n", 3))
		push(deque_a, deque_b, 'd');
	else if (!ft_strncmp(operation, "pb\n", 3))
		push(deque_b, deque_a, 'd');
	else if (!ft_strncmp(operation, "ra\n", 3))
		rotate(deque_a, 'd');
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotate(deque_b, 'd');
	else if (!ft_strncmp(operation, "rr\n", 3))
		each_rotate(deque_a, deque_b);
	else
		do_operation2(operation, deque_a, deque_b);
}

void	free_element(t_element *head)
{
	t_element	*free_element;

	while (head)
	{
		free_element = head;
		head = head->next;
		free(free_element);
	}
}

int	main(int argc, char *argv[])
{
	t_deque		deque_a;
	t_deque		deque_b;
	t_element	*head;
	char		*operation;
	
	if (argc > 1)
	{
		init_deque(&deque_a, &deque_b, argv);
		head = deque_a.head;
		while (1)
		{
			operation = get_next_line(0);
			if (!operation)
				break ;
			do_operation(operation, &deque_a, &deque_b)
			free(operation);
		}
		if (sort_check(head) && deque_b.total_cnt == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		free_element(deque_a.head);
	}
	return (0);
}