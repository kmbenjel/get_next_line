/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 00:23:05 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	new_line_in(char *b)
{
	while (*b)
		if (*b == '\n')
			return (1);
	return (0);
}

int	no_new_line_in(char *b)
{
	if (new_line_in(b))
		return (0);
	return (1);
}

// In the two functions above, b stands for BUFFER, for convenience.

static char	*current_buffer(int fd)
{
	char	*cb;
	int		i;

	i = 0;
	cb = malloc(BUFFER_SIZE + 1);
	if (cb)
	{
		i = read(fd, cb, BUFFER_SIZE);
		if (i <= 0)
			return (NULL);
		cb[BUFFER_SIZE] = '\0';
		return (cb);
	}
	return (NULL);
}

// READ_BS above stands for: Read the Current Buffer

static char	*joinline(int fd, char *tail)
{
	char	*cb;
	char	*line;

	line = NULL;
	cb = current_buffer(fd);
	while (no_new_line_in(cb))
	{
		line = ft_strjoin(line, cb);
		cb = current_buffer(fd);
	}
	if (new_line_in(cb))
	{
		line = ft_strjoin(line, until_nl(cb));
		tail = after_nl(cb);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tail;

	return (line);
}
