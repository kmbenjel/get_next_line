/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:24 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 09:08:03 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*alloc_for_unl(char *s)
{
	char	*unl;
	int		i;

	unl = NULL;
	i = 0;
	while (s[i] != '\n')
		i++;
	unl = malloc(i++);
	return (unl);
}

// Allocate for a string containing characters
// of the buffer until the first new line

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	dest = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		dest[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	dest[ft_strlen(s1) + i] = 0;
	free(s1);
	return (dest);
}

char	*until_nl(char *s)
{
	int		i;
	char	*unl;

	i = 0;
	unl = alloc_for_unl(s);
	while (s[i] != '\n')
		i++;
	unl[i++] = '\0';
	return (unl);
}

char	*after_nl(char *s)
{
	while (*s != '\n')
		s++;
	return (s + 1);
}
