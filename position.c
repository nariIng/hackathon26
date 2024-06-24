/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:14:55 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 08:15:45 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_escape_pos(t_data *data)
{
	t_list	*map;
	char	*str;
	int		x;
	int		y;

	map = data->map;
	y = 0;
	while (y < data->heigth / SCARE_SIZE)
	{
		str = map->content;
		x = 0;
		if (ft_escape_pos_ext(data, str, x, y))
			break ;
		if (map->next == NULL)
			break ;
		map = map->next;
		y++;
	}
	return (1);
}

int	ft_escape_pos_ext(t_data *data, char *str, int x, int y)
{
	while (x < data->width / SCARE_SIZE)
	{
		if (str[x] == 'E')
		{
			data->escape.x = x;
			data->escape.y = y;
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_player_pos(t_data *data)
{
	t_list	*map;
	char	*str;
	int		x;
	int		y;

	map = data->map;
	y = 0;
	while (y < data->heigth / SCARE_SIZE)
	{
		str = map->content;
		x = 0;
		if (ft_player_pos_ext(data, str, x, y))
			break ;
		if (map->next == NULL)
			break ;
		map = map->next;
		y++;
	}
	return (1);
}

int	ft_player_pos_ext(t_data *data, char *str, int x, int y)
{
	while (x < data->width / SCARE_SIZE)
	{
		if (str[x] == 'P')
		{
			data->player.x = x;
			data->player.y = y;
			return (1);
		}
		x++;
	}
	return (0);
}
