/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:53:37 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 16:30:34 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_offset(int keysym, t_vars *vars)
{
	if (keysym == 65363)
		vars->offset_x += 50;
	else if (keysym == 65361)
		vars->offset_x -= 50;
	else if (keysym == 65364)
		vars->offset_y += 50;
	else if (keysym == 65362)
		vars->offset_y -= 50;
}

void	handle_angles(int keysym, t_vars *vars)
{
	if (keysym == 'w')
		vars->angle_y += 0.03;
	else if (keysym == 's')
		vars->angle_y -= 0.03;
	else if (keysym == '7')
		vars->angle_x += 0.03;
	else if (keysym == '8')
		vars->angle_x -= 0.03;
	else if (keysym == 'b')
		vars->angle_p += 0.03;
	else if (keysym == 'v')
		vars->angle_p -= 0.03;
}

void	handle_color(int keysym, t_vars *vars)
{
	if (keysym == 49 && vars->flag < 9)
		vars->flag++;
	else if (keysym == 50 && vars->flag > 0)
		vars->flag--;
	else if (keysym == '0')
		vars->map_option = 0;
	else if (keysym == '9')
		vars->map_option = 1;
}

void	handle_rotation(int keysym, t_vars *vars)
{
	if (keysym == 'i')
		vars->theta += 0.03;
	else if (keysym == 'k')
		vars->theta -= 0.03;
	else if (keysym == 'j')
		vars->phi += 0.03;
	else if (keysym == 'l')
		vars->phi -= 0.03;
	else if (keysym == 'a')
		vars->qsi += 0.03;
	else if (keysym == 'd')
		vars->qsi -= 0.03;
}
