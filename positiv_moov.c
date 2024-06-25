/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positiv_moov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:23:41 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/25 14:18:28 by enarindr         ###   ########.fr       */
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
	if (str[data->player.x + 1] != '0')
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
			str[data->player.x] = 'm';
		str[data->player.x + 1] = 'P';
		data->player.x++;
		data->step++;
	}
	if (str[data->player.x + 1] == 'D')
		system("xdg-open https://mada42.netlify.app/antsiranana.html");
	else if (str[data->player.x + 1] == 'T')
		system("xdg-open https://mada42.netlify.app");
	else if (str[data->player.x + 1] == 'M')
		system("xdg-open https://mada42.netlify.app/mahajanga.html");
	else if (str[data->player.x + 1] == 'I')
		system("xdg-open https://mada42.netlify.app/tamatave.html");
	else if (str[data->player.x + 1] == 't')
		system("xdg-open https://mada42.netlify.app/toliara.html");
	else if (str[data->player.x + 1] == 'F')
		system("xdg-open https://mada42.netlify.app/fianarantsoa.html");

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

	if (str[data->player.x] != '0')
	{
		if (str[data->player.x] == 'O')
			ft_finish(data);
		if (str[data->player.x] == 'C')
			data->piece--;
		map = map->next;
		temp = map->content;
		ft_player_pos(data);
		if (ft_get_map(data->tmp, data->player.x, data->player.y - 2) == 'D')
			system("xdg-open https://mada42.netlify.app/antsiranana.html");
		else if (str[data->player.x] == 'T')
			system("xdg-open https://mada42.netlify.app");
		else if (ft_get_map(data->tmp, data->player.x, data->player.y - 2) == 'M')
			system("xdg-open https://mada42.netlify.app/mahajanga.html");
		else if (str[data->player.x] == 'I')
			system("xdg-open https://mada42.netlify.app/tamatave.html");
		else if (str[data->player.x] == 't')
			system("xdg-open https://mada42.netlify.app/toliara.html");
		else if (str[data->player.x] == 'F')
			system("xdg-open https://mada42.netlify.app/fianarantsoa.html");
		if (data->player.x == data->escape.x
			&& data->player.y == data->escape.y)
			temp[data->player.x] = 'E';
		else
			temp[data->player.x] = 'm';
		str[data->player.x] = 'P';
		data->player.y--;
		data->step++;
	}
	return (0);
}
