/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:38:42 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 10:22:57 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key(int key, t_data *data)
{
	if (data->piece == 0)
		ft_change_escape(data);
	if (key == ESC)
		ft_exit_key(data);
	if (data->finish == 0 && data->over == 0)
	{
		if (key == RIGHT)
			ft_moov_right(data);
		else if (key == LEFT)
			ft_moov_left(data);
		else if (key == UP)
			ft_moov_up(data);
		else if (key == DOWN)
			ft_moov_down(data);
		ft_draw(data);
	}
	return (0);
}

void	ft_change_escape(t_data *data)
{
	int	x;
	int	y;

	x = data->escape.x;
	y = data->escape.y;
	ft_set_map(data->map, x, y, 'O');
}

int	ft_count_p(t_data *data, char c)
{
	int		x;
	int		y;
	int		i;
	t_list	*map;
	char	*str;

	map = data->map;
	i = 0;
	y = 0;
	while (y < data->heigth / SCARE_SIZE)
	{
		str = map->content;
		x = 0;
		while (x < data->width / SCARE_SIZE)
		{
			if (str[x] == c)
				i++;
			x++;
		}
		if (map->next == NULL)
			break ;
		map = map->next;
		y++;
	}
	return (i);
}

int	ft_count_copy_p(t_data *data, char c)
{
	int		x;
	int		y;
	int		i;
	t_list	*map;
	char	*str;

	map = data->copy_map;
	i = 0;
	y = 0;
	while (y < data->heigth / SCARE_SIZE)
	{
		str = map->content;
		x = 0;
		while (x < data->width / SCARE_SIZE)
		{
			if (str[x] == c)
				i++;
			x++;
		}
		if (map->next == NULL)
			break ;
		map = map->next;
		y++;
	}
	return (i);
}
