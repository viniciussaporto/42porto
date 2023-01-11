/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:50 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 13:28:04 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(unsigned long num) //Unsigned because memory address is passed as hexadecimal
{
	int	count;

	count = 0;
	if (!num)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2); //Prints memory address sufix, always starts with "0x"
	count += ft_print_hexa(num, 'x'); // Prints address itself as hexadecimal number
	return (count + 2);// Returns count + 2 because of suffix
}