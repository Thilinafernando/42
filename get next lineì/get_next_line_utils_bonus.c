/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:05:01 by tkurukul          #+#    #+#             */
/*   Updated: 2024/12/20 01:05:01 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_check_char(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	if (c == '\0')
		return (str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	int				i;
	int				j;
	unsigned int	total;

	i = 0;
	j = 0;
	total = ft_strlen(s1, '\0') + ft_strlen(s2, '\0');
	str = (char *)malloc((total + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	fft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (nmemb == 0 && size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	str = (char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	fft_bzero(str, nmemb * size);
	return ((void *)str);
}
