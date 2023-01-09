/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fade.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:42:54 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 09:47:58 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	green_fade(int h)
{
	if (h > 70)
		return (0xE9EAF0);
	if (h > 62)
		return (0xC4C1BD);
	if (h > 50)
		return (0x4C591A);
	if (h > 10)
		return (0x4C591A);
	if (h > 1)
		return (0x4D5E36);
	if (h > 0)
		return (0xD8D19C);
	if (h > -5)
		return (0x444CC6);
	if (h > -10)
		return (0x2A2EAE);
	if (h > -30)
		return (0x3D497C);
	return (0x05093d);
}

unsigned int	white_on_black(int h)
{
	(void)h;
	return (0xFFFFFF);
}