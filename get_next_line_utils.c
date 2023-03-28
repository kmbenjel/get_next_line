/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenjell <kbenjell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:59:24 by kbenjell          #+#    #+#             */
/*   Updated: 2023/03/02 00:08:59 by kbenjell         ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		*counts;
	int		sc;
	int		i;

	if (!s)
		return (0);
	i = -1;
	sc = ft_splits_count(s, c, 0, 0);
	counts = ft_splits_charcount(s, c, sc, 0);
	splits = malloc((sc + 1) * sizeof(char *));
	if (!splits)
		return (0);
	while (++i < sc)
	{
		splits[i] = malloc((counts[i] + 1) * sizeof(const char));
		if (!splits[i])
		{
			ft_free_previous(splits);
			return (0);
		}
	}
	ft_splits_filler(splits, counts, s, c);
	return (splits);
}
