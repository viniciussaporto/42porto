/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:27:49 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 17:15:29 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bigger_case(t_vars *vars)
{
	while ((vars->screen.max_x > WINDOW_WIDTH || \
		vars->screen.max_x > WINDOW_HEIGHT))
	{
		vars->screen.max_y /= 2;
		vars->screen.max_x /= 2;
		vars->offset_x = abs(vars->offset_x / 2);
		vars->offset_y = abs(vars->offset_y / 2);
		vars->size_grid /= 2;
		if (vars->size_grid < 1)
		{
			if (vars->screen.max_y > WINDOW_HEIGHT)
				vars->screen.max_y = WINDOW_HEIGHT;
			if (vars->screen.max_x > WINDOW_WIDTH)
				vars->screen.max_x = WINDOW_WIDTH;
			break ;
		}
	}
}

void	smaller_case(t_vars *vars)
{
	while ((vars->screen.max_x < WINDOW_WIDTH / 5 \
	|| vars->screen.max_x < WINDOW_HEIGHT / 5))
	{
		vars->screen.max_y *= 3;
		vars->screen.max_x *= 3;
		vars->offset_x = abs(vars->offset_x * 3);
		vars->offset_y = abs(vars->offset_y * 3);
		vars->size_grid *= 3;
	}
}

void	screen_size(t_vars *vars)
{
	int	diff_x;
	int	diff_y;

	diff_x = WINDOW_WIDTH - vars->screen.max_x;
	diff_y = WINDOW_HEIGHT - vars->screen.max_x;
	vars->screen.max_x = vars->screen.max_x - vars->screen.min_x;
	vars->screen.max_y = vars->screen.max_y - vars->screen.min_y;
	vars->offset_x = -vars->screen.min_x;
	vars->offset_y = -vars->screen.min_y;
	if (diff_x < 0 || diff_y < 0)
		bigger_case(vars);
	else
		smaller_case(vars);
	if (vars->map_option == 1)
	{
		vars->offset_x = WINDOW_WIDTH / 2 \
			- vars->screen.max_x / 2 + vars->offset_x;
		vars->offset_y = WINDOW_HEIGHT / 2 \
			- vars->screen.max_y / 2 + vars->offset_y;
		vars->screen.max_x = WINDOW_WIDTH;
		vars->screen.max_y = WINDOW_HEIGHT;
	}
}
