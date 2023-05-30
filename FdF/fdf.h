/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:44:17 by vsa-port          #+#    #+#             */
/*   Updated: 2023/05/30 18:46:25 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "X11/X.h"
# include "X11/keysymdef.h"
# include <stdlib.h>

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define MLX_ERROR 1
# define ESCAPE 65307

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct s_screen {
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
}				t_screen;

typedef struct	s_edge_case_args
{
	t_vars	*vars;
	t_point a;
	t_point b;
	float	range;
	float	range_z;
	float	x;
}				t_edge_case_args;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			**map;
	int			nb_lines;
	int			nb_cols;
	float		size_grid;
	int			offset_x;
	int			offset_y;
	float		angle_x;
	float		angle_y;
	float		angle;
	int			last_x;
	int			middle_point_x;
	int			middle_point_y;
	int			max_z;
	int			min_z;
	int			color;
	int			flag;
	float		theta;
	float		phi;
	float		qsi;
	t_data		img;
	t_point		**point_map;
	int			new_max;
	float		z_modify;
	char		**map_file;
	t_screen	screen;
	int			map_number;
	int			transform_number;
	int			map_option;
	int			max_maps;
	int			off_set_change;
	float		rgb_p;
	float		range_z;
	float		slope;
	int			direction;
	float		angle_p;
}				t_vars;

char	*get_next_line(int fd);
void	map_loading(t_vars *vars, int fd, int index);
void	ft_max_and_min(int nb, t_vars *vars);
void	ft_set_variables(t_vars *vars);
t_point	init_point(int x, int y, int z);
t_point	rotation_z(t_point a, t_vars *vars);
t_point	rotation_y(t_point a, t_vars *vars);
t_point	rotation_x(t_point a, t_vars *vars);
t_point	isometric_projection(t_point a, t_vars *vars);
t_point	top_view(t_point a, t_vars *vars);
t_point	right_view(t_point a, t_vars *vars);
t_point	front_view(t_point a, t_vars *vars);
t_point	parallel_projection(t_point a, t_vars *vars);
t_point	transformations(t_vars *vars, t_point a);
void	map_to_point(t_vars *vars);
void	draw_img_grid(t_vars *vars);
int		percent_to_color(float percent, int flag);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	choose_map(t_vars *vars);
int		ft_close(void *o);
void	clean_img(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		handle_keypress(int keysym, t_vars *vars);
void	ft_menu(t_vars *vars);
void	screen_size(t_vars *vars);
void	handle_offset(int keysym, t_vars *vars);
void	handle_angles(int keysym, t_vars *vars);
void	handle_reset(t_vars *vars);
void	handle_color(int keysym, t_vars *vars);
void	handle_rotation(int keysym, t_vars *vars);
void	handle_z(int keysym, t_vars *vars);
void	handle_projection(int keysym, t_vars *vars);
void	free_map(t_vars *vars);
int		change_map(t_vars *vars, int i);
void	free_map(t_vars *vars);
int		check_map(t_vars *vars);
int		counter(char *line);
int		strcmp_fdf(char *a);

#endif