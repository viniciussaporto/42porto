/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:48 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/17 16:26:42 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H

# define SLEEP_TIME 300

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef void	t_handler(int, siginfo_t*, void*);

void	ft_kill(pid_t pid, int signum);
t_handler	*ft_signal(int signum, t_handler *handler);

#endif
