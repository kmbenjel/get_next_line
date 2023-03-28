/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/28 01:59:42 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int new_line_in(char *b)
{
	while (*b)
		if (*b == '\n')
			return 1;
	return 0;
}

int no_new_line_in(char *b)
{
	if (new_line_in(b))
		return 0;
	return 1;
}

// In the two functions above, b stands for BUFFER, for convenience.

char	*current_buffer(int fd)
{
	char	*cb;
	int i;
	current = malloc(BUFFER_SIZE + 1);
	if (current)
	{
		read(fd, cb, BUFFER_SIZE);
		current(BUFFER_SIZE) = '\0';
		return (cb);
	}
	return (NULL);
}

// READ_BS above stands for: Read the Current Buffer

void joinline(int fd)
{
	char	*cb;
	char **sep;

	sep = NULL;
	cb = current_buffer(fd);
	while (no_new_line_in(cb))
	{
		line = ft_strjoin(line, cb);
		cb = current_buffer(fd);
	}
	if (new_line_in(cb))
	{
		sep = ft_split(cb, '\n');
		line = ft_strjoin(line, sep[0]);
		line = ft_strjoin(line, "\n");
		tail = sep[1];
		free(sep);
	}
}


char	*get_next_line(int fd)
{
	static char			*line;
	char *tail;


	return (line);
}
