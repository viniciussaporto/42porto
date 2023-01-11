/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:08:24 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/14 13:16:02 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long num, char c)
{
	int	count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef"; // Sets base for lowercase formats
	if (c == 'X')
		base = "0123456789ABCDEF"; // Sets base for uppercase formats
	if (num < 16)
		count += ft_print_char(*(base + num)); // If less than 16 it prints it directly
	if (num >= 16) // Otherwise divides and modules to get the base
	{
		count += ft_print_hexa(num / 16, c);
		count += ft_print_hexa(num % 16, c);
	}
	return (count);
}