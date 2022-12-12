/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:46:31 by vsa-port          #+#    #+#             */
/*   Updated: 2022/12/12 11:53:41 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#  include <stdarg.h>
#  include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_numbs(long num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hexa(unsigned long num, char c);
int	ft_print_address(unsigned long num);

#endif