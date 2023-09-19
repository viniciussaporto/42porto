/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:01 by vsa-port          #+#    #+#             */
/*   Updated: 2023/09/19 16:46:13 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "minitalk.h"
#include "libft/ft_printf/ft_printf.h"

static void	send_character(int pid, char c)
{
	int		bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (((c >> (7 - bit_count)) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_count++;
		usleep(50);
	}
}

static void	send_string(int pid, char *str)
{
	while (*str)
	{
		send_character(pid, *str);
		str++;
	}
	send_character(pid, '\0');
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	server_pid = atoi(argv[1]);
	message = argv[2];
	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	send_string(server_pid, message);
	return (0);
}
