/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:24 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/29 04:10:34 by kbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str)
{
	unsigned int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

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
	return (dest);
}

char	*until_nl(char *s)
{
	int		i;
	char	*unl;

	i = 0;
	unl = ft_strjoin(s, "");
	while (s[i] != '\n')
		i++;
	s[i + 1] = '\0';
	return (s);
}

char	*after_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	if (i < (int)ft_strlen(s) - 1)
		return (s + i);
	return (NULL);
}
