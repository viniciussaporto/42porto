/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:00:06 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/16 13:01:47 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_fdf
{
	double	width;
	double	height;
	int		**z_matrix;
	double	zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	char	*line;
	double	lift;
	int		fd;
	int		i;
	double	max;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}				t_fdf;

typedef struct s_line
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}				t_line;

#endif