/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:38:53 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 13:26:01 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*		Parsing function that takes argument passed by the call
	to determine which value to print */
int	ft_check_specifier(char c, va_list args)

{
	int	byte_count;

	byte_count = 0;
	if (c == 'c')
		byte_count = ft_print_char(va_arg(args, int));
	else if (c == '%')
		byte_count = write(1, "%", 1);
	else if (c == 's')
		byte_count = ft_print_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		byte_count = ft_print_numbs(va_arg(args, int));
	else if (c == 'u')
		byte_count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'X' || c == 'x')
		byte_count = ft_print_hexa(va_arg(args, unsigned int), c);
	else if (c == 'p')
		byte_count = ft_print_address(va_arg(args, unsigned long));
	return (byte_count);
}

int	ft_printf(const char *format, ...)

{
	va_list		args;
	int			byte_count; //Counts characters/intergers/bytes to be passed
	int			i;
	// Starts variadic arguments list
	va_start(args, format);
	byte_count = 0;
	i = 0;
	/* This loop determines the type of the next argument for parsing */
	while (*(format + i) != '\0')
	{
		if (*(format + i) != '%')
			byte_count += write(1, (format + i), 1);
		else
		{
			i++;
			byte_count += ft_check_specifier(*(format + i), args);
		}
		i++;
	}
	va_end(args); // Closes list (per function rules)
	return (byte_count); // Return value provided by function calls in this function
}

/* int	main()

{

	ft_printf("%p", 683);
	return(0);
} */