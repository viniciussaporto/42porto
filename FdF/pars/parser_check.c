/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:15:29 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:30:50 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static char	*check_point(char *str)
{
	if (*str = '-' || *str == '+')
		++str;
	while (*str != ' ' && *str != ',' && *str)
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		++str;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' || *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str)
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			++str;
		}
	}
	return (str);
}

int	check_line(t_fdf *fdf, char *line)
{
	int	x;

	x = 0;
	while(*line)
	{
		while (*line == ' ')
			++line;
		if(!(line = check_point(line)))
			return (0);
		while (*line == ' ')
			++line;
		++x;
	}
	if (fdf->map.size.x != 0 && x != fdf->map.size.x)
		return (0);
	fdf->map.size.x = x;
	return (1);
}