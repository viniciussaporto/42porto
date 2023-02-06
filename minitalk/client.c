/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:01 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/06 14:39:44 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	send_bit(int pid, char *str, size_t len)
{
	int	shift;
	size_t	i;
	
	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	char	*str;
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nPlease send an argument\n");
}