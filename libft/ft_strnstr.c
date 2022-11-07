/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:07 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 15:28:26 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c;
	size_t	d;

	c = 0;
	if (s1[0] == '\0')
		return ((char *)s1);
	while (s1[c] != '\0')
	{
		d = 0;
		while (s1[c + d] == s2[d] && (c + d) < len)
		{
			if (s1[c + d] == '\0' && s2[d] == '\0')
				return ((char *)s1[c]);
			d++;
		}
		if (s2[d] == '\0')
			return ((char *)s1 + c);
		c++;
	}
	return (0);
}
