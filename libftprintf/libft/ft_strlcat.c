/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:22:50 by enarindr          #+#    #+#             */
/*   Updated: 2024/02/19 15:22:52 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	while (*src && i + 1 < size)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (i < size)
		*dst = '\0';
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
