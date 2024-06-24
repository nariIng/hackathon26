/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positiv_moov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:23:41 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 08:41:50 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moov_right(t_data *data)
{
	t_list	*map;
	char	*str;
	int		i;

	i = 0;
	map = data->map;
	while (i++ < data->player.y)
		map = map->next;
	str = map->content;
	data->dir = 1;
	(data->moov)++;
	if (data->moov == 3)
		data->moov = 0;
	ft_moov_right_ext(data, str);
	return (0);
}

int	ft_moov_right_ext(t_data *data, char *str)
{
	if (str[data->player.x + 1] != '1')
	{
		if (str[data->player.x + 1] == 'O')
			ft_finish(data);
		if (str[data->player.x + 1] == 'C')
			data->piece--;
		ft_player_pos(data);
		if (data->player.x == data->escape.x
			&& data->player.y == data->escape.y)
			str[data->player.x] = 'E';
		else
			str[data->player.x] = '0';
		str[data->player.x + 1] = 'P';
		data->player.x++;
		data->step++;
	}
	return (0);
}

int	ft_moov_up(t_data *data)
{
	t_list	*map;
	char	*str;
	int		i;

	i = 0;
	map = data->map;
	while (i++ < data->player.y - 1)
		map = map->next;
	str = map->content;
	data->dir = 0;
	(data->moov)++;
	if (data->moov == 3)
		data->moov = 0;
	ft_moov_up_ext(data, map, str);
	return (0);
}

int	ft_moov_up_ext(t_data *data, t_list *map, char *str)
{
	char	*temp;

	if (str[data->player.x] != '1')
	{
		if (str[data->player.x] == 'O')
			ft_finish(data);
		if (str[data->player.x] == 'C')
			data->piece--;
		map = map->next;
		temp = map->content;
		ft_player_pos(data);
		if (data->player.x == data->escape.x
			&& data->player.y == data->escape.y)
			temp[data->player.x] = 'E';
		else
			temp[data->player.x] = '0';
		str[data->player.x] = 'P';
		data->player.y--;
		data->step++;
	}
	return (0);
}
