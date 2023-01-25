/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:40:20 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/25 13:46:59 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_type(t_vars *vars)
{
	int	s;
	int	y;

	s = WINDOW_WIDTH - 125;
	y = 100;
	mlx_string_put(vars->mlx, vars->win, s, 80, 0xAFA9A9, "PROJECTION TYPE");
	if (vars->tranform_number == 1)
	{
		mlx_string_put(vars->mlx, vars->win, s, y, \
		0xAFA9A9, "ISOMETRIC PROJECTION");
	}
	else if (vars->tranform_number == 2)
	{
		mlx_string_put(vars->mlx, vars->win, s, y, \
		0xAFA9A9, "PARALLEL PROJECTION");
	}
	else if (vars->tranform_number == 3)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "TOP VIEW");
	else if (vars->tranform_number == 4)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "RIGHT VIEW");
	else if (vars->tranform_number == 5)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "BOTTOM VIEW");
	mlx_string_put(vars->mlx, vars->win, 100, 20, 0xAFA9A9, "COMMANDS");
	mlx_string_put(vars->mlx, vars->win, 100, 40, 0xAFA9A9, "^ UP");
}

