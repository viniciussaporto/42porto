/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:17:33 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/09 10:21:41 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c;
	size_t	d;

	c = 0;
	d = 0;
	if (s2[c] == '\0')
		return ((char *)s1);
	if (len == 0)
		return (NULL);
	while (c <= len)
	{
		if (s2[d] == '\0')
			return ((char *)(&s1[c - d]));
		if (s1[c] == s2[d])
			d++;
		else
			d = 0;
		if (s1[c] == '\0')
			break ;
		c++;
	}
	return (NULL);
}
