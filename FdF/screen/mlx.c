/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:14 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:58:16 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mlx_keycode.h"
#include "fdf.h"

void	add_mlx_hook(t_fdf *fdf)
{
	mlx_key_hook(fdf->mlx.window, key_hook, fdf);
	mlx_hook(fdf->mlx.window, KEYPRESS, 0, move_hook, fdf);
	mlx_hook(fdf->mlx.window, DESTROYNOTIFY, 0, fdf_exit, fdf);
}

int		display_mlx_win(t_fdf *fdf)
{
	fdf->mlx.mlx = mlx_init();
	if (fdf->mlx.mlx != NULL)
	{
		fdf->mlx.window = mlx_new_window(fdf->mlx.mlx, fdf->mlx.win_size.x,
										fdf->mlx.win_size.y, "FdF");
		if (fdf->mlx.window != NULL)
		{
			fdf->mlx.image = mlx_new_image(fdf->mlx.mlx,
				fdf->mlx.win_size.x, fdf->mlx.win_size.y);
			if (fdf->mlx.image != NULL)
			{
				fdf->mlx.buff = mlx_get_data_addr(fdf->mlx.image,
					&fdf->mlx.bpp, &fdf->mlx.buf_wid, &fdf->mlx.endian);
				mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window,
					fdf->mlx.image, 0, 0);
				add_mlx_hook(fdf);
				draw_win(fdf);
				mlx_loop(fdf->mlx.mlx);
				return (0);
			}
		}
	}
	return (1);
}