/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:38:42 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/25 14:45:47 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_data *data)
{
	if (data->piece == 0)
		ft_change_escape(data);
	if (key == ESC)
		ft_exit_key(data);
	data->sary = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/map2.xpm", &data->width, &data->heigth);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sary, 0, 0);
	if (data->finish == 0 && data->over == 0)
	{
		if (key == RIGHT || key == RIGHT_)
			ft_moov_right(data);
		else if (key == LEFT || key == LEFT_)
			ft_moov_left(data);
		else if (key == UP || key == UP_)
			ft_moov_up(data);
		else if (key == DOWN || key == DOWN_)
			ft_moov_down(data);
		// ft_printf("%d\n", data->step);
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
