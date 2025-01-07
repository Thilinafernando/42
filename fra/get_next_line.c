/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:07:10 by fzuccaro          #+#    #+#             */
/*   Updated: 2024/12/13 15:51:57 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_putline(int fd, char **result, char *buffer)
{
	ssize_t		bt_read;
	char		*tmp;

	while (1)
	{
		bt_read = read(fd, buffer, BUFFER_SIZE);
		if (bt_read == -1)
		{
			free(*result);
			*result = NULL;
			return (NULL);
		}
		else if (bt_read == 0)
			break ;
		buffer[bt_read] = '\0';
		if (!*result)
			*result = ft_strdup("");
		tmp = *result;
		*result = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*result);
}

static char	*ft_getrest(char *line)
{
	ssize_t	i;
	char	*rest;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(rest);
		buffer = NULL;
		rest = NULL;
		return (NULL);
	}
	line = ft_putline(fd, &rest, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest = ft_getrest(line);
	return (line);
}

/*int	main()
{
	char	*line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			return(1);
		printf("%s", line);
		free(line);
	}
	close(fd);

}*/
