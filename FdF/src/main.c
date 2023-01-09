/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:21:13 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 09:25:43 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "fdf.h"

int	main(const int ac, const char **av)
{
	t_fdf	fdf;
	int	rtn;
	
	rtn = 1;
	if (ac == 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		if(parser(&fdf, av[1]))
		{
			init_fdf(&fdf);
			if (display_mlx_win(&fdf) == 0)
				rtn = 0;
		}
		else
		{
			free_map(&fdf.map);
			ft_printf("Error\n");
		}
	}
	else
		ft_printf("Usage: %s map.fdf\n", av[0]);
	return (rtn);
}