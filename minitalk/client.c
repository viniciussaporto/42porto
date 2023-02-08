/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:35:01 by vsa-port          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/07 14:18:19 by vsa-port         ###   ########.fr       */
=======
/*   Updated: 2023/02/08 14:34:32 by vsa-port         ###   ########.fr       */
>>>>>>> 7240667 (new version minitalk)
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	check(size_t n, const char *nptr, int sign)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
<<<<<<< HEAD
		if (byte >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		j--;
=======
		n = *nptr - '0' + (n * 10);
		nptr++;
	}
	return (n * sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	n;
	int	sign;
	int	d;
	
	d = 0;
	sign = 1;
	n = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		d++;
		nptr++;
	}
	if (d > 1)
		return (n);
	n = check(n, nptr, sign);
	return (n);
}

void	send_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Unexpected error!\n", 18);
			exit (1);
		}
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Unextected error!\n", 18);
			exit(1);
		}
		usleep(150);
>>>>>>> 7240667 (new version minitalk)
	}
}

void	convert(int c, int pid)
{
	t_byte_struct	byte_char;
	
	*(unsigned char *)&byte_char = (unsigned char)c;
	send_signal(byte_char.b1, pid);
	send_signal(byte_char.b2, pid);
	send_signal(byte_char.b3, pid);
	send_signal(byte_char.b4, pid);
	send_signal(byte_char.b5, pid);
	send_signal(byte_char.b6, pid);
	send_signal(byte_char.b7, pid);
	send_signal(byte_char.b8, pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi((const char *)argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Invalid PID!\n", 13);
			return (0);
		}
		while (argv[2][i])
		{
			convert((int)argv[2][i], pid);
			i++;
		}
	}
	else
		write(1, "Usage: ./client [PID] [MESSAGE]\n", 32);
	return (0);
}
// void	send_byte(char byte, int pid)
// {
// 	int	j;
		
// 	j = 7;
// 	while (j >= 0)
// 	{
// 		if (byte >> j & 1)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(500);
// 		j--;
// 	}
// }

// void	send_message(char *str, int pid)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		send_byte(str[i], pid);
// 	send_byte(0, pid);
// }

// void	usage(void)
// {
// 	ft_putstr("./client [server-pid] [message]\n");
// 	exit(0);
// }

// void	handler2(int sig)
// {
// 	ft_putstr("Message received.");
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	char	*str;
	
// 	signal(SIGUSR2, handler2);
// 	if (argc != 3)
// 		usage();
// 	pid = ft_atoi(argv[1]);
// 	str = argv[2];
// 	send_message(str, pid);
// 	return (0);
// }