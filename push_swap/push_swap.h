/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:59:12 by vsa-port          #+#    #+#             */
/*   Updated: 2023/04/11 11:16:19 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

# ifndef PRINT_PERM
#  define PRINT_PERM 1
# endif

typedef struct s_stack
{
	int	n;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
//used to fill stack
t_stack *ft_fill_stack(char **mat);
//error handling
int	ft_error_handling(char **mat);
//utilities
int	ft_stack_size(t_stack *stack);
int	ft_order_check(t_stack *stack);
int	ft_n_at_pos(t_stack *stack, int pos);
int	ft_pos_with_n(t_stack *stack, int n);
t_stack *ft_find_smallest(t_stack *stack);
//print
void	ft_print_stack(t_stack *stack);
void	ft_rev_print_stack(t_stack *stack);
//more utilities
void	ft_put_node_on_top(t_stack **stack, t_stack *node, char s_name);
void	ft_free_stack(t_stack *stack);
void	ft_free_mat(char **mat);
int	ft_count_str(char **mat);
//operations call
void	ft_call_swap(t_stack **stack, char s_name);
void	ft_call_push(t_stack **dest, t_stack **src, char dest_name);
void	ft_call_rotate(t_stack **stack, char s_name);
void	ft_call_rev_rotate(t_stack **stack, char s_name);
void	ft_call_rr(t_stack **stack1, t_stack **stack2);
void ft_call_rrr(t_stack **stack1, t_stack **stack2);
//operations
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
//2 to 5
void	ft_deal_2(t_stack **stack, char s_name);
void	ft_deal_3(t_stack **stack, char s_name);
void	ft_deal_4_5(t_stack **s1, t_stack **s2, char s1_name, char s2_name);
//6 or more cases
void	ft_deal_6plus(t_stack **s1, t_stack **s2);
void	ft_exec_move(t_stack **s1, t_stack **s2, int mov_a, int mov_b);
//list
void	ft_lis(t_stack **s1, t_stack **s2);
void	ft_intset(int **arr, int value, int size);
int	ft_find_max_i(int *arr, int size);
int	ft_find_int(int *arr, int size, int value);
//movement between stacks
int	*ft_mov_a(t_stack *s1, t_stack *s2, int size);
int	*ft_mov_b(int size);
#endif