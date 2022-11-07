/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:47:41 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/04 15:16:44 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char        *blank;

    if (!s || !f)
        return (NULL);
    if (!(blank = ft_strnew(ft_strlen(s))))
        return (NULL);
    i = 0;
    if (s && f)
    {
        while (s[i] != '\0')
        {
            blank[i] = (*f)(i, s[i]);
            i++;
        }
    }
    blank[i]= '\0';
    return (blank);
}