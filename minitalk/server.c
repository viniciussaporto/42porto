/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:49:13 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/08 14:52:28 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_byte_struct	g_char_byte;

void	ft_putnbr(int n)
{
	char	c;
	
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	set_bit(int bit, int *i)
{
	if (*i == 1)
		g_char_byte.b1 = bit;
	if (*i == 2)
		g_char_byte.b2 = bit;
	if (*i == 3)
		g_char_byte.b3 = bit;
	if (*i == 4)
		g_char_byte.b4 = bit;
	if (*i == 5)
		g_char_byte.b5 = bit;
	if (*i == 6)
		g_char_byte.b6 = bit;
	if (*i == 7)
		g_char_byte.b7 = bit;
	if (*i == 8)
	{
		g_char_byte.b8 = bit;
		write(1, &*(unsigned char *)&g_char_byte, 1);
		*i = 0;
	}
}

void	handler(int sig)
{
	static int	i;

	if (!i)
		i = 1;
	if (sig == SIGUSR1)
	{
		set_bit(0, &i);
		i++;
	}
	if (sig == SIGUSR2)
	{
		set_bit(1, &i);
		i++;
	}
}

int	main(void)
{
	int	pid;
 
	struct sigaction	sa;

	reset_data();
	pid = getpid();
	printf("PID:%d\n", pid);
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}

// void	reset_data(void)
// {
// 	g_data.i = 0;
// 	g_data.x = 0;
// 	g_data.client_pid = 0;
// }

// void	handler(int sig, siginfo_t *info, void *ucontext)
// {
// 	(void)ucontext;
// 	sig -= SIGUSR1;
// 	if (g_data.client_pid != info->si_pid)
// 		reset_data();
// 	g_data.x = g_data.x << 1 | sig;
// 	g_data.i++;
// 	if (g_data.i == 8)
// 	{
// 		if (g_data.x == 0)
// 			kill(info->si_pid, SIGUSR2);
// 		write(1, &g_data.x, 1);
// 		reset_data();
// 	}
// 	g_data.client_pid = info->si_pid;
// }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	reset_data();
// 	ft_putstr("PID : ");
// 	ft_putnbr(getpid());
// 	ft_putstr("\n");
// 	sa.sa_sigaction = &handler;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaddset(&sa.sa_mask, SIGUSR1);
// 	sigaddset(&sa.sa_mask, SIGUSR2);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	while (1)
// 		sleep(1);
// }