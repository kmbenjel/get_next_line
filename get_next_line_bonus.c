/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/30 00:34:42 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

// In the function above, b stands for BUFFER, for convenience

static char	*current_buffer(int fd, int *rc, char *cb)
{
	*rc = read(fd, cb, BUFFER_SIZE);
	if (*rc < 0)
		return (free(cb), NULL);
	cb[*rc] = '\0';
	return (cb);
}

// all over the code, cb is for: Current Buffer

static char	*joinline(int fd, char **line, int *rc)
{
	char	*cb;
	char	*tail;

	tail = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	if (!cb)
		return (NULL);
	cb = current_buffer(fd, rc, cb);
	if (!cb)
		return (NULL);
	*line = ft_strjoin(*line, cb, 1);
	while (*rc > 0 && !new_line_in(cb))
	{
		cb = current_buffer(fd, rc, cb);
		*line = ft_strjoin(*line, cb, 1);
	}
	if (new_line_in(*line))
	{
		tail = after_nl(*line);
		*line = until_nl(*line);
	}
	free(cb);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail[10240];
	int			rc;
	char		*line;

	line = ft_strjoin("", "", 0);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line);
		return (NULL);
	}
	if (tail[fd])
	{
		line = ft_strjoin(tail[fd], line, 2);
		tail[fd] = NULL;
	}
	tail[fd] = joinline(fd, &line, &rc);
	if (line[0] == '\0' || rc < 0)
		return (free(line), free(tail[fd]), tail[fd] = NULL, NULL);
	return (line);
}

// rc is for Read Count
