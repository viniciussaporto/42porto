/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:56:41 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/04 11:22:10 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char *new_str;
    int i;
    int j;

    if (!s1 || !s2 || !(new_str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (0);
    i = 0;
    while (s1[i] != '\0')
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    return (new_str);
}