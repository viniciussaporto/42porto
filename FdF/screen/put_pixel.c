/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:55 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:59:11 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		*img;

	img = (int*)mlx->buff;
	if (x >= 0 && x < mlx->win_size.x && y >= 0 && y < mlx->win_size.y)
		img[x + mlx->win_size.x * y] = color;
}