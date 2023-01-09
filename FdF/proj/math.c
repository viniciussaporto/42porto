/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:40:16 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 10:40:18 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	deg_to_rad(int degree)
{
	return (degree * 3.14159265F / 180.0F);
}

double	fpart(double x)
{
	return (x > 0 ? x - (int)x : x - (int)x - 1);
}