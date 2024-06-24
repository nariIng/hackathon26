/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:28:13 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 08:31:12 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_not_rectangle(t_list *map)
{
	size_t	i;
	t_list	*temp;

	temp = map;
	i = ft_strlen(map->content);
	while (1)
	{
		if (ft_strlen(temp->content) != i)
			return (1);
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (0);
}

int	ft_no_wall(t_list *map, int heigth)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = map;
	while (i < heigth / SCARE_SIZE)
	{
		if (i == 0 || i == heigth - 1)
		{
			if (ft_no_vertical_wall(temp))
				return (1);
		}
		else if (i != 0 || i != heigth - 1)
		{
			if (ft_no_horizontal_wall(temp))
				return (1);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_no_vertical_wall(t_list *map)
{
	int		i;
	char	*str;

	i = 0;
	str = map->content;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_no_horizontal_wall(t_list *map)
{
	char	*str;

	str = map->content;
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		return (1);
	return (0);
}
