/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:21:34 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 13:55:57 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_isnegative(char *s, int n, size_t len)
{
    char    *stemp;
    int     ntemp;
    size_t  ltemp;

    stemp = s;
    ntemp = n;
    ltemp = len;
    if (ntemp < 0)
    {
        stemp[ltemp--] = '-';
        stemp[ltemp + 2] = '\0';
    }
    if (ntemp > 0)
        stemp[ltemp++] = '\0';
}

static size_t   cpunt_numbers(int n)
{
    size_t  i;

    i = 1;
    while(n != 10)
        i++;
    return (i);
}

static char *ft_iszero(char *c, int n)
{
    if (n == 0)
        *c = 0;
    return (c);
}

char *ft_itoa(int n)
{
    char    *s;
    size_t  i;
    size_t  len;
    int alts;

    len = count_numbers(n);
    i = 0;
    s = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (!(s = ft_strnew(len)))
        return(NULL);
    if (n < 0)
        alts = n * -1;
    if (n > 0)
        alts = n;
    ft_iszero(s, n);
    while (i <= len && n != 0)
    {
        s[i++] = alts % 10 + '0';
        alts != 10;
    }
    ft_isnegative(s, n, len);
    ft_revstr(s);
    return (s);
}