/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:40:20 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/26 16:07:46 by vsa-port         ###   ########.fr       */
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
	if (vars->transform_number == 1)
	{
		mlx_string_put(vars->mlx, vars->win, s, y, \
		0xAFA9A9, "ISOMETRIC PROJECTION");
	}
	else if (vars->transform_number == 2)
	{
		mlx_string_put(vars->mlx, vars->win, s, y, \
		0xAFA9A9, "PARALLEL PROJECTION");
	}
	else if (vars->transform_number == 3)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "TOP VIEW");
	else if (vars->transform_number == 4)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "RIGHT VIEW");
	else if (vars->transform_number == 5)
		mlx_string_put(vars->mlx, vars->win, s, y, 0xAFA9A9, "BOTTOM VIEW");
	mlx_string_put(vars->mlx, vars->win, 100, 20, 0xAFA9A9, "COMMANDS");
	mlx_string_put(vars->mlx, vars->win, 100, 40, 0xAFA9A9, "^ UP");
}

void	ft_part_one(t_vars *vars)
{
	projection_type (vars);
	mlx_string_put(vars->mlx, vars->win, 100, 75, 0xAFA9A9, "< LEFT");
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0xAFA9A9, "> RIGHT");
	mlx_string_put(vars->mlx, vars->win, 100, 125, 0xAFA9A9, "\\/ DOWN");
	mlx_string_put(vars->mlx, vars->win, 100, 150, 0xAFA9A9, \
	"1 COLOR FORWARD");
	mlx_string_put(vars->mlx, vars->win, 100, 175, 0xAFA9A9, \
	"2 COLOR BACKWARD");
	mlx_string_put(vars->mlx, vars->win, 100, 200, 0xAFA9A9, \
	"Z/X Z inc/dec");
	mlx_string_put(vars->mlx, vars->win, 100, 225, 0xAFA9A9, \
	"SHIFT - Z FACTOR 1:1");
	mlx_string_put(vars->mlx, vars->win, 100, 250, 0xAFA9A9, \
	"CTRL - Z FACTOR 1:10");
	mlx_string_put(vars->mlx, vars->win, 100, 275, 0xAFA9A9, \
	"TAB - Z FACTOR 1:100");
	mlx_string_put(vars->mlx, vars->win, 100, 300, 0xAFA9A9, \
	"W/S - ROTATION X - PARALLEL");
	mlx_string_put(vars->mlx, vars->win, 100, 325, 0xAFA9A9, \
	"A/D - ROTATION Z");
	mlx_string_put(vars->mlx, vars->win, 100, 350, 0xAFA9A9, \
	"I/K - ROTATION X");
	mlx_string_put(vars->mlx, vars->win, 100, 375, 0xAFA9A9, \
	"J/L - ROTATION Y");
}

void	ft_menu(t_vars *vars)
{
	if (vars->map_option == 1)
	{
		ft_part_one(vars);
		mlx_string_put(vars->mlx, vars->win, 100, 400, 0xAFA9A9, \
		"7/8 - ROTATION PARALLEL Y");
		mlx_string_put(vars->mlx, vars->win, 100, \
			425, 0xAFA9A9, "RMD - GRID LOCATION");
		mlx_string_put(vars->mlx, vars->win, 100, \
			450, 0xAFA9A9, "Y/U - CHANGE PROJECTION");
		mlx_string_put(vars->mlx, vars->win, 100, 475, 0xAFA9A9, \
		"9/0 - MENU PAGE");
		mlx_string_put(vars->mlx, vars->win, 100, \
			500, 0xAFA9A9, "3/4 MODE CHANGE");
		mlx_string_put(vars->mlx, vars->win, 100, 525, 0xAFA9A9, \
		"M - CHANGE MAP");
		mlx_string_put(vars->mlx, vars->win, 100, \
			550, 0xAFA9A9, "R - RESET MAP");
		mlx_string_put(vars->mlx, vars->win, WINDOW_WIDTH - 125, \
			20, 0xAFA9A9, "MAP NAME");
		mlx_string_put(vars->mlx, vars->win, WINDOW_WIDTH - 125, \
			40, 0xAFA9A9, vars->map_file[vars->map_number]);
	}
}