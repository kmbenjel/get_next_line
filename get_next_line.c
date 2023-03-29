/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 03:39:53 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	new_line_in(char *b)
{
	while (*b)
	{
		if (*b == '\n')
			return (1);
		b++;
	}
	return (0);
}

int	no_new_line_in(char *b)
{
	if (new_line_in(b))
		return (0);
	return (1);
}

// In the two functions above, b stands for BUFFER, for convenience.

static char	*current_buffer(int fd, char *cb)
{
	int	i;

	i = read(fd, cb, BUFFER_SIZE);
	if (i <= 0)
		return (NULL);
	cb[i] = '\0';
	return (cb);
}

// READ_BS above stands for: Read the Current Buffer

static char	*joinline(int fd, char **line)
{
	char	*cb;
	char	*tail;

	tail = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	if (!cb)
		return (NULL);
	while (cb)
	{
		if (new_line_in(cb))
		{
			*line = ft_strjoin(*line, until_nl(cb));
			tail = ft_strjoin(after_nl(cb), NULL);
			return (tail);
		}
		else
		{
			*line = ft_strjoin(*line, cb);
			cb = current_buffer(fd, cb);
		}
	}
	free(cb);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	static int	pos;
	char		*line;

	line = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (pos > 0)
	{
		line = ft_strjoin(tail, line);
		free(tail);
	}
	tail = joinline(fd, &line);
	pos++;
	return (line);
}
