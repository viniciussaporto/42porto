/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:20:07 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 18:00:54 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t len)
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
			return ((char *)(&s2[c - d]));
		if (s1[c] == s2[d])
			d++;
		else
			d = 0;
		if (s1[c] == '\0')
			break;
		c++;
	}
	return (NULL);
}

#include <string.h>
int	main()
{
	char	*s1 = "see FF your FF return FF now FF";
	char	*s2 = "FF";
	size_t	max = strlen(s1);
	char	*i1 = strnstr(s1, s2, max);
	char	*i2 = ft_strnstr(s1, s2, max);
	if (i1 == i2)
		printf()
}