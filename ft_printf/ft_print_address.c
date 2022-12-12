/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:50 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 11:37:37 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(unsigned long num)
{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count += ft_print_hexa(num, 'x');
	return (count + 2);
}