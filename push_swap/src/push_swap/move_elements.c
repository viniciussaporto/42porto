/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:53:56 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/03 14:28:19 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_argv_to_deque(t_deque *deque_a, char *argv[])
{
	int			idx;
	char		**each_argv;
	t_element	*new_element;

	while (*argv)
	{
		idx = 0;
		each_argv = ft_split(*argv, ' ');
		if (!each_argv || !*each_argv)
			exit_error();
		while (each_argv[idx])
		{
			new_element = (t_element *)malloc(sizeof(t_element));
			new_element->data = push_swap_atoi(each_argv[idx]);
			element_add_back(deque_a, new_element);
			free(each_argv[idx++]);
			deque_a->total_cnt++;
		}
		free(each_argv);
		argv++;
	}
	if (sort_check(deque_a->head))
		exit(0);
	indexing_elements(deque_a->head, deque_a->total_cnt);
}

void	save_address(t_element *head, t_element **address)
{
	while (head)
	{
		*address++ = head;
		head = head->next;
	}
	*address = 0;
}

void	bubble_sort(t_element **array)
{
	int			idx;
	int			jdx;
	t_element	*tmp_element;
	
	idx = 0;
	while (array[idx])
	{
		jdx = idx + 1;
		while (array[jdx])
		{
			if (array[idx]->data > array[jdx]->data)
			{
				tmp_element = array[idx];
				array[idx] = array[jdx];
				array[jdx] = tmp_element;
			}
			jdx++;
		}
		idx++;
	}
}

void	indexing_elements(t_element *head, int total_cnt)
{
	int			idx;
	t_element	**address_array;
	
	idx = 0;
	address_array = (t_element **)malloc(sizeof(t_element *) * (total_cnt + 1));
	save_address(head, address_array);
	bubble_sort(address_array);
	while (address_array[idx])
	{
		address_array[idx]->data = idx;
		idx++;
	}
	free(address_array);
}

void	move_based_pivot(t_deque *deq_a, t_deque *deq_b)
{
	int	pivot_1;
	int	pivot_2;
	int	rotate_cnt;

	pivot_1 = (deq_a->total_cnt) / 3;
	pivot_2 = pivot_1 * 2;
	rotate_cnt = deq_a->total_cnt;
	while (rotate_cnt--)
	{
		if (deq_a->head->data < pivot_1)
			rotate(deq_a, 'a');
		else if (deq_a->head->data >= pivot_2)
		{
			push(deq_b, deq_a, 'b');
			rotate(deq_b, 'b');
		}
		else
			push(deq_b, deq_a, 'b');
	}
}