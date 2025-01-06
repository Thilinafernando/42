/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:03:21 by tkurukul          #+#    #+#             */
/*   Updated: 2024/12/20 01:03:21 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*read_line;

	if (fd < 0 || (read(fd, 0, 0) < 0 )|| BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_buff(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	read_line = make_line(buffer[fd]);
	buffer = save_prev(buffer[fd]);
	return (read_line);
}

char	*read_buff(int fd, char *buffer)
{
	char	*tmp;
	int		buf_count;
	int		check;

	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	check = 0;
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (check == 0)
	{
		buf_count = read(fd, tmp, BUFFER_SIZE);
		if (buf_count < 0)
		{
			free(tmp);
			return (NULL);
		}
		if (buf_count == 0)
			break;
		tmp[buf_count] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_check_char(tmp, '\n'))
			check = 1;
	}
	free(tmp);
	return (buffer);
}

char	*make_line(char *buffer)
{
	char	*nline;
	int		size;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer, '\n');
	nline = ft_calloc((size + 1), sizeof(char) );
	if (nline == NULL)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		nline[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		nline[i] = '\n';
	nline[i + 1] = '\0';
	return (nline);
}

char	*save_prev(char *buffer)
{
	char	*tmp;
	int		start;
	int		i;
	int		remainder;

	if (!buffer)
		return (NULL);
	start = 0;
	while (buffer[start] != '\n' && buffer[start])
		start++;
	if (buffer[start] == '\0')
		return (NULL);
	remainder = (ft_strlen(buffer, '\0')) - start;
	tmp = ft_calloc((remainder + 1) , sizeof(char));
	if(tmp == NULL)
		return (NULL);
	i = 0;
	while (buffer[start + 1])
	{
		tmp[i] = buffer[start + 1];
		start++;
		i++;
	}
	tmp[i] = '\0';
	free(buffer);
	return (tmp);
}
