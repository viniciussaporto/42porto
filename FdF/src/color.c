/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:33:13 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 09:42:38 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static const	t_disp g_colorscheme[] =
{
	{
		.bg_color = 0x000000,
		.text_color = 0xFFFFFF,
		.usage_color = 0x00222222,
		.get_col = green_fade
	},
};

void	get_next_colorscheme(t_disp *disp)
{
	unsigned int	nb;
	
	nb = disp->colortheme + 1;
	if (nb >= sizeof(g_colorscheme) / sizeof(t_disp))
		nb = 0;
	disp->colortheme = nb;
	disp->bg_color = g_colorscheme[nb].bg_color;
	disp->text_color = g_colorscheme[nb].text_color;
	disp->usage_color = g_colorscheme[nb].usage_color;
	disp->get_col = g_colorscheme[nb].get_col;
}