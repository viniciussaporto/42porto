/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:01 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/17 16:10:48 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	msg_received(int sig, siginfo_t *info, void *context);
static void	prepare_msg(char *pid_string, char *message);
static void	send_char(int pid, t_byte byte);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Usage is ./lcient <server_pid> <\"a text\">\n", 1);
		return (EXIT_FAILURE);
	}
	ft_signal(SIGUSR1, msg_received);
	prepare_msg(argv[1], argv[2]);
	return (EXIT_SUCCESS);
}

static void	msg_received(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;
	ft_putnbr_fd(info->si_pid, 1);
	ft_putstr_fd("Server PID: data received.\n", 1);
}

static void	prepare_msg(char *pid_string, char *message)
{
	int	pid;

	pid = ft_atoi(pid_string);
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, *message);
}

static void	send_char(int pid, t_byte byte)
{
	t_byte	index;

	index = 1 << 7;
	while (index)
	{
		if (byte & index)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		index >>= 1;
		usleep(SLEEP_TIME);
	}
}