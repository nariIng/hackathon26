/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 06:42:27 by enarindr          #+#    #+#             */
/*   Updated: 2024/02/25 06:42:37 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = (char *)malloc (ft_strlen((char *)s) + 1);
	if (!s || !new)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, (char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
