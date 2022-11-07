/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:05:54 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 17:30:40 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;
	size_t	result;

	i = 0;
	if (!dest && !size)
		return (0);
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen < size)
		result = destlen + srclen;
	else
	{
		result = srclen + size;
		return (result);
	}
	while (src[i] != '\0' && destlen < (size - 1))
	{
		dest[destlen] = src[i];
		i++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (result);
}
