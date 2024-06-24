/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:06:48 by enarindr          #+#    #+#             */
/*   Updated: 2024/02/25 10:06:50 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char const *str, char c)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int	ft_str(char **tab, int j, int i)
{
	int	u;

	u = 0;
	tab[j] = (char *)malloc (sizeof(char) * i);
	if (!tab[j])
	{
		while (u < j)
			free(tab[u++]);
		free(tab);
		return (1);
	}
	return (0);
}

static int	ft_string(char **tab, char const *s, char c)
{
	int	j;
	int	i;

	j = 0;
	while (*s)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			i++;
			s++;
		}
		if (i)
		{
			if (ft_str(tab, j, i + 1))
				return (1);
			ft_strlcpy(tab[j], s - i, (i + 1));
		}
		j++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**tab;

	len = 0;
	if (!s)
		return (NULL);
	len = ft_count_str(s, c);
	tab = (char **)malloc (sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = NULL;
	if (ft_string(tab, s, c))
		return (NULL);
	return (tab);
}
