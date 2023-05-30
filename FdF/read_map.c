/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:00:31 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 16:25:16 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_max_and_min(int nb, t_vars *vars)
{
	if (!vars->max_z || nb > vars->max_z)
		vars->max_z = nb;
	if (!vars->min_z || nb < vars->min_z)
		vars->min_z = nb;
}

int	*split_array(t_vars *vars, char *line)
{
	int		*t;
	int		size;
	int		i;
	char	**temp;

	size = 0;
	i = 0;
	temp = ft_split(line, ' ');
	while (temp[size])
		size++;
	vars->nb_cols = size;
	t = malloc(sizeof(int) * size);
	while (i < size)
	{
		t[i] = ft_atoi(temp[i]);
		ft_max_and_min(t[i], vars);
		free(temp[i]);
		i++;
	}
	free(temp);
	return (t);
}

void	map_loading(t_vars *vars, int fd, int index)
{
	char	*line;

	line = get_next_line(fd);
	vars->nb_lines++;
	if (line)
		map_loading(vars, fd, index + 1);
	else
		vars->map = malloc(sizeof(int *) * vars->nb_lines);
	if (line)
		vars->map[index] = split_array(vars, line);
	else
		vars->map[index] = (int *)line;
	free(line);
}
