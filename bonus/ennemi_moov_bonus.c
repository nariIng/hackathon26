/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemi_moov_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:48:03 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:46:24 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_en_moov_left(t_data *data, int x, int y)
{
	if (ft_get_map(data->map, x - 1, y) == 'P')
		ft_game_over(data);
	else if (ft_get_map(data->map, x - 1, y) == '0')
	{
		ft_set_map(data->map, x - 1, y, 'R');
		ft_set_map(data->map, x, y, '0');
	}
	else
		data->en_moov++;
}

void	ft_en_moov_up(t_data *data, int x, int y)
{
	if (ft_get_map(data->map, x, y - 1) == 'P')
		ft_game_over(data);
	else if (ft_get_map(data->map, x, y - 1) == '0')
	{
		ft_set_map(data->map, x, y - 1, 'R');
		ft_set_map(data->map, x, y, '0');
	}
	else
		data->en_moov++;
}

int	ft_en_moov_right(t_data *data, int x, int y)
{
	if (ft_get_map(data->map, x + 1, y) == 'P')
		ft_game_over(data);
	else if (ft_get_map(data->map, x + 1, y) == '0')
	{
		ft_set_map(data->map, x + 1, y, 'R');
		ft_set_map(data->map, x, y, '0');
	}
	else
		data->en_moov++;
	return (1);
}

int	ft_en_moov_down(t_data *data, int x, int y)
{
	if (ft_get_map(data->map, x, y + 1) == 'P')
		ft_game_over(data);
	else if (ft_get_map(data->map, x, y + 1) == '0')
	{
		ft_set_map(data->map, x, y + 1, 'R');
		ft_set_map(data->map, x, y, '0');
	}
	else
		data->en_moov++;
	return (1);
}
