/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:14:41 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 16:56:27 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;
	int		l;

	l = 0;
	ps = (char *)s;
	while (s[l])
		l++;
	while (l >= 0)
	{
		if (ps[l] == (char)c)
			return (&ps[l]);
		l--;
	}
	return (0);
}
