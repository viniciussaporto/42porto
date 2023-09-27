/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:17:47 by vsa-port          #+#    #+#             */
/*   Updated: 2023/09/27 15:08:51 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../src/libft/libft.h"
# include "get_next_line.h"

typedef struct s_element
{
	int					data;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_deque
{
	int					total_cnt;
	struct s_element	*head;
	struct s_element	*tail;
}	t_deque;

typedef struct s_optimal
{
	int	idx;
	int	src_rotate;
	int	dst_rotate;
	int	total_rotate;
}	t_optimal;

// cal_rotate_cnt.c
int			cal_src_rotate(int idx, t_deque *deque_b);
int			cal_dst_rotate(t_deque *deque_a, t_deque *deque_b, int idx);
int			cal_total_rotate(int src_rotate, int dst_rotate);
int			find_location(t_deque *deque_a, t_deque *deque_b, int idx);

// find_optimal_element.c
void		cnt_to_zero(int a_rotate, int b_rotate, \
				t_deque *deq_a, t_deque *deq_b);
void		sort_optimal(int a_rotate, int b_rotate, \
				t_deque *deq_a, t_deque *deq_b);
void		init_optimal(t_optimal *init, t_deque *deq_a, t_deque *deq_b);
void		push_optimal(t_deque *deq_a, t_deque *deq_b);

// move_elements.c
void		insert_argv_to_deque(t_deque *deque_a, char *argv[]);
void		save_address(t_element *head, t_element **address);
void		bubble_sort(t_element **array);
void		indexing_elements(t_element *head, int total_cnt);
void		move_based_pivot(t_deque *deq_a, t_deque *deq_b);

// push_swap.c
void		init_deques(t_deque *deque_a, t_deque *deque_b, char *argv[]);
void		push_deque_a_to_b(t_deque *deque_a, t_deque *deque_b);
void		push_deque_b_to_a(t_deque *deque_a, t_deque *deque_b);
int			main(int argc, char *argv[]);

// push, rotate, swap
void		push(t_deque *deq_dst, t_deque *deq_src, char c);
void		rotate(t_deque *deque, char c);
void		each_rotate(t_deque *deque_a, t_deque *deque_b);
void		reverse_rotate(t_deque *deque, char c);
void		each_reverse_rotate(t_deque *deque_a, t_deque *deque_b);
void		swap(t_deque *deque, char c);
void		each_swap(t_deque *deque_a, t_deque *deque_b);

// utils
int			push_swap_atoi(const char *str);
void		exit_error(void);
void		element_add_back(t_deque *deque, t_element *element);
t_element	*last_element(t_element *head);

// rule_check
void		assert_duplicate(t_element *head, int data);
int			sort_check(t_element *element);

// sort_under_5
void		sort_two_elements(t_deque *deque);
void		sort_three_elements(t_deque *deque);
void		sort_four_elements(t_deque *deque_a, t_deque *deque_b);
void		sort_five_elements(t_deque *deque_a, t_deque *deque_b);
void		sort_under_5(t_deque *deque_a, t_deque *deque_b);

#endif
