/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:58:49 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/16 22:02:31 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//join strings and frees memory allocated during buffer expansion
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
//delete "buffer line" created for the possibility of existing another fd line
char	*ft_next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	//find strlen of the first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	//if line ends with null, returns null
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// length of file - length of 1st line + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	//equals line to buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}
//line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int	i;

	i = 0;
	//if no line exists return null
	if (!buffer[i])
		return (NULL);
	//takes index to end of line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	//malloc to end of line
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	//equals line to buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	//when end of line is null of \n replace the end of line for \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int	byte_read;

	//malloc in case red is null
	if (!res)
		res = ft_calloc(1, 1);
	//malloc for buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		//while not end of line read this
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		// 0 at the end of line for memory leak
		buffer[byte_read] = 0;
		//join strings and free memory in buffer
		res = ft_free(res, buffer);
		//ends program in case \n is found
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	//handles invalid entries
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}