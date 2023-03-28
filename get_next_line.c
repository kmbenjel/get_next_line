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

char	*current_buffer(int fd)
{
	char	*cb;

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

char	*join_safe_buffers(int fd)
{
	char	*sb;

	while ()
		return (cb);
}

char	*split_newlined_buffer(void)
{
}

char	*get_next_line(int fd)
{
	static char			*line;
	char				*current_buffer;
	static unsigned int	position;

	position = 0;
	while (no_new_line_in(current_buffer(int fd)))
	{
		line = ft_strjoin(line, current_buffer);
	}
	return (line);
}
