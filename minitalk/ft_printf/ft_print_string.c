/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:16:46 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 13:49:31 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str) // Standart print string
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*(str + count))
	{
		write(1, (str + count), 1);
		count++;
	}
	return (count);
}