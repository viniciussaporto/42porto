/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:52:26 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/20 15:27:24 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	
	if(!(x < 0 || y < 0 || x >= vars->screen.max_x || y >= vars->screen.max_y))
	{
		dst = vars->img.addr + (y * vars->img.line_length + \
		x * (vars->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

dsa-mora