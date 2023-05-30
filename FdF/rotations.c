/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 17:13:15 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	init_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point	rotation_x(t_point a, t_vars *vars)
{
	float	temp_z;
	float	temp_y;

	temp_z = a.z;
	temp_y = a.y;
	a.y = temp_y * cos(vars->theta) + temp_z * sin(vars->theta);
	a.z = -temp_y * sin(vars->theta) + temp_z * cos(vars->theta);
	return (a);
}

t_point	rotation_y(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_z;

	temp_x = a.x;
	temp_z = a.z;
	a.x = temp_x * cos(vars->phi) + temp_z * sin(vars->phi);
	a.z = -temp_x * sin(vars->phi) + temp_z * cos(vars->phi);
	return (a);
}

t_point	rotation_z(t_point a, t_vars *vars)
{
	float	temp_x;
	float	temp_y;

	temp_x = a.x;
	temp_y = a.y;
	a.x = temp_x * cos(vars->qsi) - temp_y * sin(vars->qsi);
	a.y = temp_x * sin(vars->qsi) + temp_y * cos(vars->qsi);
	return (a);
}
