/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:42:11 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:08 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_variables(t_vars	*vars)
{
	vars->offset_x = 0;
	vars->offset_y = 0;
	vars -> theta = 0;
	vars->phi = 0;
	vars->qsi = 0;
	vars->flag = 4;
	vars->size_grid = 9;
	vars->angle_y = 0.523599;
	vars->angle_x = 0.523599;
	vars->angle_p = 0.7854;
	vars->z_modify = 1;
	vars->screen.max_x = 0;
	vars->screen.min_x = 0;
	vars->screen.max_y = 0;
	vars->screen.min_y = 0;
	vars->max_z = 0;
	vars->min_z = 0;
	vars->transform_number = 1;
}

void	choose_map(t_vars *vars)
{
	int	fd;

	fd = check_map(vars);
	ft_set_variables(vars);
	map_loading(vars, fd, 0);
	map_to_point(vars);
	screen_size(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = \
		mlx_new_image(vars->mlx, vars->screen.max_x, vars->screen.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->win = mlx_new_window(vars->mlx, \
		vars->screen.max_x, vars->screen.max_y, "FdF - vsa-port");
	mlx_hook(vars->win, 2, 1L << 0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_hook(vars->win, 4, 1L << 2, mouse_hook, vars);
	draw_img_grid(vars);
}

int	main(int ac, char **av)
{
	static t_vars	vars;

	(void) ac;
	vars.mlx = mlx_init();
	vars.map_number = 1;
	vars.max_maps = 0;
	vars.map_option = 1;
	while (av[vars.max_maps] != NULL)
		vars.max_maps++;
	vars.map_file = av;
	choose_map(&vars);
	mlx_loop(vars.mlx);
}
