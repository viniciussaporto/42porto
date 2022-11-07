/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:00:50 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 14:45:47 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	*ptr;
	
	ptr = (unsigned char *)b;
	i = 0;
	while (i < len && ptr[i] != '\0')
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
/*
int main ()
{
	char s[] =  "fodasscaralhofodassecaralhofodassecaralhofodassefodassecaralhofodassecaralhofodassefodassecaralhofodassecaralhofodasse";

	ft_memset(s, 43, 45);
	printf("%s\n", s);
}*/