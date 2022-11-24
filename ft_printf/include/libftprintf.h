/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:54:48 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/24 03:58:21 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <../libft/libft.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	putnbr_u(unsigned int nb);
int	put_pointer(void *nb, char *base);
int	put_hex(unsigned int nb, char *base);
int	ft_printf(const char *format, ...);

#endif