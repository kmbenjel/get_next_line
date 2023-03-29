/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 09:28:03 by kbenjell         ###   ########.fr       */
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

// In the function above, b stands for BUFFER, for convenience

static char	*current_buffer(int fd, int *rc, char *cb)
{
	*rc = read(fd, cb, BUFFER_SIZE);
	if (*rc <= 0)
		return (NULL);
	cb[*rc] = '\0';
	return (cb);
}

// all over the code, cb is for: Current Buffer

static char	*joinline(int fd, char **line, int *rc)
{
	char	*cb;
	char	*unl;
	char	*tail;

	tail = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	cb = current_buffer(fd, rc, cb);
	while (*rc > 0 && !new_line_in(cb))
	{
		*line = ft_strjoin(*line, cb);
		cb = current_buffer(fd, rc, cb);
	}
	if (new_line_in(cb))
	{
		unl = until_nl(cb);
		*line = ft_strjoin(*line, unl);
		free(unl);
		tail = until_nl(after_nl(cb));
	}
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	int			rc;
	char		*line;

	line = malloc(1);
	line[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tail)
		line = ft_strjoin(tail, NULL);
	tail = joinline(fd, &line, &rc);
	return (line);
}

// rc is for Read Count
