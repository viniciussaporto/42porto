/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:51:10 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 13:54:24 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new_str;
    size_t  i;
    size_t  j;

    if (!s || !(new_str = (char *)malloc(len + 1)))
        return (0);
    i = start;
    j = 0;
    while (i < ft_strlen(s) && j < len)
        new_str[j++] = s[i++];
    new_str[j] = '\0';
    return (new_str);
}