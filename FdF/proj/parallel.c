/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:40:43 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:40:46 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_vec2	parallel_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	double	zoom;

	x -= fdf->map.size.x / 4;
	y -= fdf->map.size.y / 2;
	zoom = fdf->flag.zoom < 0 ? 1 / (double)-(fdf->flag.zoom) : fdf->flag.zoom;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height_mod / 15;
	rtn.x = y + cos(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.y = -z + sin(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.x += fdf->flag.pos.x;
	rtn.y += fdf->flag.pos.y;
	return (rtn);
}
