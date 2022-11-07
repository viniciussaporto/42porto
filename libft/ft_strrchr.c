/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:14:41 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/03 13:20:04 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;
	const char	*init;

	init = s;
	i = ft_strlen(s);
	s = (s + 1);
	while (*s != *init && c != *s)
		s--;
	if (c == *s)
		return ((char *)s);
	return (0);
}
