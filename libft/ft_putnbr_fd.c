/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:11:59 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 11:40:33 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if ((n > 2147483647) || (n < -2147483648))
        return;
    if (n == 0)
    {
        ft_putchar_fd('0', fd);
        return;
    }
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n *= -1;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}