/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:08 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 17:16:33 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* ft_realloc(char **str, int str_len(str_len), int *str_cap(str_cap))
 * *str - the string which we copy to new string
 * str_len current len of string
 * str_cap capacity of the string
 */
void	ft_realloc(char **str, size_t str_len, size_t *str_cap)
{
	char	*return_string;
	size_t	i;

	i = 0;
	if (str_len == 0)
		*str_cap = 128;
	else if (*str_cap <= 33554432)
		*str_cap *= 2;
	else
		*str_cap += 33554432;
	return_string = (char *)malloc(*str_cap);
	while (i < str_len && return_string != NULL)
	{
		return_string[i] = (*str)[i];
		i++;
	}
	free(*str);
	*str = return_string;
}
