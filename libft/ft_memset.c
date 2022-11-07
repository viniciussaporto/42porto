/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:00:50 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 16:54:17 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	temp;
	size_t			i;

	p = (unsigned char *)b;
	temp = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		p[i] = temp;
		i++;
	}
	return (p);
}
/*
#include <stdio.h>
int main ()
{
	char s[] =  "fodasscaralhofodassecaralhofodassecaralhofodassefodassecaralhofodassecaralhofodassefodassecaralhofodassecaralhofodasse";

	ft_memset(s, 43, 45);
	printf("%s\n", s);
}*/