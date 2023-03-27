/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:58:46 by vsa-port          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:32 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **mat)
{
	t_stack	*a;
	t_stack	*b;
	
	if (ft_error_handling(mat))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		a = ft_fill_stack(mat);
		b = NULL;
		if (ft_stack_size(a) == 2)
			ft_deal_2(&a, 'a');
		else if (ft_stack_size(a) == 3)
			ft_deal_3(&a, 'a');
		else if (ft_stack_size(a) > 3 && ft_stack_size(a) <= 5)
			ft_deal_4_5(&a, &b, 'a', 'b');
		else if (ft_stack_size > 5)
			ft_deal_6plus(&a, &b);
		ft_free_stack(a);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (*av)
			ft_push_swap(av);
		ft_free_mat(av);
	}
	else if (ac > 2)
		ft_push_swap(av + 1);
	return (0);
}