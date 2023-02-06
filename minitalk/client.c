/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:01 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/06 17:13:50 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char byte, int pid)
{
	int	j;
		
	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
	send_byte(0, pid);
}

void	usage(void)
{
	ft_putstr("./client [server-pid] [message]\n");
	exit(0);
}

void	handler2(int sig)
{
	ft_putstr("Message received.");
}

int	main(int argc, char **argv)
{
	int	pid;
	char	*str;
	
	signal(SIGUSR2, handler2);
	if (argc != 3)
		usage();
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_message(str, pid);
	return (0);
}