/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:12:02 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/22 22:39:29 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int nb, const char format);
int		ft_printpercent(void);

void	ft_putstr(char *str);
void	ft_put_ptr(ptr_t nb);
int		ft_ptr_len(ptr_t nb);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int nb);
void	ft_put_hex(unsigned int nb, const char format);
int		ft_hex_len(unsigned	int nb);

#endif