/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:33:16 by vsa-port          #+#    #+#             */
/*   Updated: 2023/10/02 16:37:04 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assert_duplicate(t_element *head, int data)
{
	t_element	*tmp_element;

	tmp_element = head;
	while (tmp_element)
	{
		if (tmp_element->data == data)
			exit_error();
		tmp_element = tmp_element->next;
	}
}

int	sort_check(t_element *element)
{
	element = element->next;
	while (element)
	{
		if (element->data < element->prev->data)
			return (0);
		element = element->next;
	}
	return (1);
}