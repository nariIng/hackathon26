/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:17 by enarindr          #+#    #+#             */
/*   Updated: 2024/02/22 10:58:18 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*new;
	char			*str;

	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * i);
	if (!new)
		return (NULL);
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}
