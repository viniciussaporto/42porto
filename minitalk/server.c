/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:49:13 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/17 16:19:01 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	print_pid(void);
static void	print_message(int sig, siginfo_t *info, void *context);

int main (void)
{
	print_pid();
	ft_signal(SIGUSR1, print_message);
	ft_signal(SIGUSR2, print_message);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

static void	print_pid(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(getpid(), 1);
	ft_putstr_fd(".\n", 1);
}

static void	print_message(int sig, siginfo_t *info, void *context)
{
	static size_t	byte;
	static t_byte	decoded_char;
	
	(void) context;
	if (sig == SIGUSR1)
		sig = 1;
	else if (sig == SIGUSR2)
		sig = 0;
	if (byte == 0 && decoded_char == 0)
		byte = 8;
	byte--;
	decoded_char += (sig & 1) << byte;
	if (byte == 0)
	{
		if (!decoded_char)
		{
			ft_putchar_fd('\n', 1);
			ft_kill(info->si_pid, SIGUSR1);
		}
		ft_putchar_fd(decoded_char, 1);
		byte = 8;
		decoded_char = 0;
	}
}