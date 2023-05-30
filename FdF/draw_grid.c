/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:54:57 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 18:46:35 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	transformations(t_vars *vars, t_point a)
{
	a = rotation_x(a, vars);
	a = rotation_y(a, vars);
	a = rotation_z(a, vars);
	ft_max_and_min(a.z, vars);
	if (vars->transform_number == 1)
		a = isometric_projection(a, vars);
	if (vars->transform_number == 2)
		a = parallel_projection(a, vars);
	if (vars->transform_number == 3)
		a = top_view(a, vars);
	if (vars->transform_number == 4)
		a = right_view(a, vars);
	if (vars->transform_number == 5)
		a = front_view(a, vars);
	return (a);
}

void	edge_case(t_edge_case_args *args)
{
	int	y;
	int	flag;

	flag = 0;
	y = args->a.y;
	while (fabs(args->b.y - y) > 0.5)
	{
		args->vars->rgb_p = args->vars->rgb_p + args->range / (args->vars->size_grid);
		my_mlx_pixel_put(args->vars, args->x, y, percent_to_color(args->vars->rgb_p, args->vars->flag));
		y += ((args->b.y - args->a.y) / (fabs(args->b.y - args->a.y)));
		flag++;
	}
	return ;
}

void initializer(t_vars* vars, t_point a, t_point b)
{
    t_edge_case_args edge_case_args;
    edge_case_args.vars = vars;
    edge_case_args.a = a;
    edge_case_args.b = b;
    edge_case_args.range = vars->range;
    edge_case_args.range_z = vars->range_z;
    edge_case_args.x = vars->x;

    if (fabs(b.x - a.x) <= 0.5 && fabs(b.y - a.y) > 0.5)
        edge_case(&edge_case_args);

    vars->slope = (b.y - a.y) / (b.x - a.x);
    vars->direction = (b.x - a.x) / (fabs(b.x - a.x));
}

void	two_points(t_vars *vars, t_point a, t_point b)
{
	float	x;
	float	y;

	a = transformations(vars, a);
	b = transformations(vars, b);
	x = a.x;
	initializer(vars, a, b, x);
	while (fabs(b.x - x) > 0.5)
	{
		y = vars->slope * (x - a.x) + a.y;
		vars->rgb_p = vars->rgb_p + vars->range_z / ((vars->size_grid));
		my_mlx_pixel_put(vars, x, y, percent_to_color(vars->rgb_p, vars->flag));
		if ((fabs(y - (vars->slope * ((x + vars->direction) - a.x) + a.y))) > 1)
		{
			while ((int)(y - (vars->slope * \
				((x + vars->direction) - a.x) + a.y)))
			{
				y += ((b.y - a.y) / (fabs(b.y - a.y)));
				my_mlx_pixel_put(vars, x, y, \
				percent_to_color(vars->rgb_p, vars->flag));
			}
		}
		x += vars->direction;
	}
}

void	draw_img_grid(t_vars *vars)
{
	int	x;
	int	y;
	int	y_new;

	y = -1;
	while (++y < vars->nb_lines - 1)
	{
		x = 0;
		while (x < vars->nb_cols)
		{
			y_new = vars->nb_lines - 2 - y;
			if (x < vars->nb_cols - 1)
				two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new][x + 1]);
			if (y < vars->nb_lines -2)
				two_points(vars, (vars->point_map)[y_new][x], \
				(vars->point_map)[y_new - 1][x]);
			x++;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_menu(vars);
}
