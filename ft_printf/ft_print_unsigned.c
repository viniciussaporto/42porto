/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:20:17 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 11:37:41 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 10)
		count += ft_print_char(num + '0');
	if (num >= 10)
	{
		count += ft_print_unsigned(num / 10);
		count += ft_print_unsigned(num % 10);
	}
	return (count);
}