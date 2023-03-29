/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 04:54:38 by kbenjell         ###   ########.fr       */
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

static char	*current_buffer(int fd, char *cb, int *rc)
{
	*rc = read(fd, cb, BUFFER_SIZE);
	if (*rc < 0)
	{
		free(cb);
		return (NULL);
	}
	cb[*rc] = '\0';
	return (cb);
}

// READ_BS above stands for: Read the Current Buffer

static char	*joinline(int fd, char **line, int *rc)
{
	char	*cb;
	char	*unl;
	char	*tail;

	tail = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	unl = NULL;
	if (!cb)
		return (NULL);
	while (cb)
	{
		cb = current_buffer(fd, cb, rc);
		if (new_line_in(cb))
		{
			unl = until_nl(cb);
			*line = ft_strjoin(*line, unl);
			tail = ft_strjoin(after_nl(cb), NULL);
			break ;
		}
		else
		{
			*line = ft_strjoin(*line, cb);
		}
		if (*rc == 0)
			break ;
	}
	free(cb);
	free(unl);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	static int	rc;
	static int	pos;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (pos > 0)
	{
		line = ft_strjoin(tail, NULL);
		free(tail);
	}
	tail = joinline(fd, &line, &rc);
	pos++;
	return (line);
}
