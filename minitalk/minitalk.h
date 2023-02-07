/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:48 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/07 10:44:45 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	x;
	int		client_pid;
}	t_data;
void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	usage(void);
void	reset_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
#endif