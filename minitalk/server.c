/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:49:13 by vsa-port          #+#    #+#             */
/*   Updated: 2023/09/18 20:29:05 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "libft/ft_printf/ft_printf.h"

static void	signal_handler(int sig)
{
	static unsigned char	c = 0x00;
	static int				bit_count = 0;

	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		c |= (sig == SIGUSR1) << (7 - bit_count);
		bit_count++;
		if (bit_count == 8)
		{
			if (c == '\0')
				write(1, "\n", 1);
			else
				write(1, &c, 1);
			c = 0x00;
			bit_count = 0;
		}
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
