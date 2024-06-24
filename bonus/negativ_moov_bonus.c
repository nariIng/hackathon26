/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negativ_moov_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:40:17 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:48:05 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_moov_left(t_data *data)
{
	t_list	*map;
	char	*str;
	int		i;

	i = 0;
	map = data->map;
	while (i++ < data->player.y)
		map = map->next;
	str = map->content;
	data->dir = 3;
	(data->moov)++;
	if (data->moov == 3)
		data->moov = 0;
	ft_moov_left_ext(data, str);
	return (0);
}

int	ft_moov_left_ext(t_data *data, char *str)
{
	if (str[data->player.x - 1] != '1')
	{
		if (str[data->player.x - 1] == 'O')
			ft_finish(data);
		if (str[data->player.x - 1] == 'C')
			data->piece--;
		ft_player_pos(data);
		if (data->player.x == data->escape.x
			&& data->player.y == data->escape.y)
			str[data->player.x] = 'E';
		else
			str[data->player.x] = '0';
		str[data->player.x - 1] = 'P';
		data->player.x--;
		data->step++;
	}
	return (0);
}

int	ft_moov_down(t_data *data)
{
	t_list	*map;
	t_list	*temp;
	char	*str;
	int		i;

	i = 0;
	map = data->map;
	while (i++ < data->player.y)
		map = map->next;
	temp = map;
	temp = temp->next;
	str = temp->content;
	data->dir = 2;
	(data->moov)++;
	if (data->moov == 3)
		data->moov = 0;
	ft_moov_down_ext(data, map, str);
	return (0);
}

int	ft_moov_down_ext(t_data *data, t_list *map, char *str)
{
	char	*tmp;

	if (str[data->player.x] != '1')
	{
		if (str[data->player.x] == 'O')
			ft_finish(data);
		if (str[data->player.x] == 'C')
			data->piece--;
		tmp = map->content;
		ft_player_pos(data);
		if (data->player.x == data->escape.x
			&& data->player.y == data->escape.y)
			tmp[data->player.x] = 'E';
		else
			tmp[data->player.x] = '0';
		str[data->player.x] = 'P';
		data->player.y++;
		data->step++;
	}
	return (0);
}
