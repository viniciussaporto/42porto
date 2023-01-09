/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:13:11 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 13:47:30 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_numbs(long num) // Standard atoi with long int
{
	int	count;
	char *base;

	count = 0;
	base = "0123456789";
	if (num < 0)
	{
		num *= -1;
		count += ft_print_char('-');
	}
	if (num < 10)
		count += ft_print_char(*(base + num));
	if (num >= 10)
	{
		count += ft_print_numbs(num / 10);
		count += ft_print_numbs(num % 10);
	}
	return (count);
}