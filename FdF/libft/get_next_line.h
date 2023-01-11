/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:11:34 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/09 17:11:36 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	int				fd;
	char			rb_ar[BUFFER_SIZE];
	char			*str;
	ssize_t			rb_size;
	size_t			rb_pos;
	size_t			str_cap;
	size_t			str_len;
	struct s_file	*next;
}				t_file;

char	*get_next_line(int fd);
void	ft_realloc(char **str, size_t str_len, size_t *str_cap);

#endif