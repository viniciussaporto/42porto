/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:28:07 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 09:32:29 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx.win_size.x = 1200;
	fdf->mlx.win_size.y = 800;
	fdf->flag.height_mod = 4;
	fdf->flag.zoom = 11;
	fdf->flag.angle_mod = 30;
	fdf->flag.pos.x = fdf->mlx.win_size.x / 2;
	fdf->flag.pos.y = fdf->mlx.win_size.y / 2;
	get_next_colorscheme(&fdf->disp);
}