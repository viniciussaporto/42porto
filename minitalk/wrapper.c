/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:10:21 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/17 16:23:27 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_handler	*ft_signal(int signum, t_handler *handler)
{
	struct sigaction	action;
	struct sigaction	old_action;
	
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(signum, &action, &old_action) < 0)
		ft_putstr_fd("Signal error.\n", 1);
	return (old_action.sa_sigaction);
}

void	ft_kill(pid_t, int signum)
{
	int rc;
	
	rc = kill(pid, signum);
	if (rc < 0)
		ft_putstr_fd("Kill error.\n", 1);
}