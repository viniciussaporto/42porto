/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:48:14 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:08:04 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_keycode.h"
#include "fdf.h"

static void	move(t_fdf *fdf, int keycode)
{
	if (keycode == SP_KEY)
		fdf->flag.disp_helper = !fdf->flag.disp_helper;
	if (keycode == P_KEY)
		fdf->flag.proj = !fdf->flag.proj;
	if (keycode == C_KEY)
		get_next_colorscheme(&fdf->disp);
	if (keycode == PUP_KEY)
		fdf->flag.height_mod++;
	if (keycode == PDOWN_KEY)
		fdf->flag.height_mod--;
	if (keycode == NKPL_KEY)
		fdf->flag.zoom += 2;
	if (keycode == NKMN_KEY)
		fdf->flag.zoom -= 2;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		fdf_exit(fdf);
	move(fdf, keycode);
	draw_win(fdf);
	return (0);
}

int			move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		fdf->flag.pos.y -= 20;
	if (keycode == DOWN_KEY || keycode == S_KEY)
		fdf->flag.pos.y += 20;
	if (keycode == LEFT_KEY || keycode == A_KEY)
		fdf->flag.pos.x -= 20;
	if (keycode == RIGHT_KEY || keycode == D_KEY)
		fdf->flag.pos.x += 20;
	if (keycode == CM_KEY || keycode == Q_KEY)
		fdf->flag.angle_mod += 3;
	if (keycode == PT_KEY || keycode == E_KEY)
		fdf->flag.angle_mod -= 3;
	draw_win(fdf);
	return (0);
}