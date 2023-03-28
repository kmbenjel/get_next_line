/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:14 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/28 01:29:03 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_bs(int fd)
{
	char	*current;

	current = malloc(BUFFER_SIZE);
	if (current)
	{
	}
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char			*line;
	static unsigned int	position;

	position = 0;
	return (line);
}
