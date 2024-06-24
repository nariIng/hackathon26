/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:17 by enarindr          #+#    #+#             */
/*   Updated: 2024/05/11 14:37:49 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *s)
{
	unsigned int	i;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*new;

	k = -1;
	if (!s1)
		s1 = ft_calloc(1, 1);
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	new = (char *)ft_calloc (sizeof(char), i + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++k])
		new[i + k] = s2[k];
	free (s1);
	free (s2);
	return (new);
}

char	*ft_strdup_gnl(char *s, int len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (len == -1)
	{
		while (s[i])
			i++;
		len = i;
	}
	while (s[i] && i <= len)
		i++;
	new = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!new)
		return (NULL);
	while (i--)
		new[i] = s[i];
	return (new);
}
