/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 06:45:59 by kbenjell         ###   ########.fr       */
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

// In the function above, b stands for BUFFER, for convenience.

static char	*current_buffer(int fd, char *cb, int *rc)
{
	*rc = read(fd, cb, BUFFER_SIZE);
	if (*rc < 0)
		return (NULL);
	cb[*rc] = '\0';
	return (cb);
}

// READ_BS above stands for: Read the Current Buffer

static char	*joinline(int fd, char **line, int *rc)
{
	char	*cb;
	char	*unl;
	char	*tail;

	//tail = NULL;
	//unl = NULL;
	cb = malloc(BUFFER_SIZE + 1);
	if (!cb)
		return (NULL);
	cb = current_buffer(fd, cb, rc);
	while (*rc)
	{
		cb = current_buffer(fd, cb, rc);
		if (new_line_in(cb))
		{
			unl = until_nl(cb);
			*line = ft_strjoin(*line, unl);
			tail = ft_strjoin(after_nl(cb), NULL);
			free(unl);
			break ;
		}
		else
			*line = ft_strjoin(*line, cb);
	}
	free(cb);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	int			rc;
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

// rc is for Read Count
