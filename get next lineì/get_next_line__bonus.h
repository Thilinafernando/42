/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line__bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 01:06:14 by tkurukul          #+#    #+#             */
/*   Updated: 2024/12/20 01:06:14 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_strlen(const char *str, char c);
char		*ft_check_char(char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		fft_bzero(void *str, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*get_next_line(int fd);
char		*read_buff(int fd, char *buffer);
char		*make_line(char *buffer);
char		*save_prev(char *buffer);

#endif
