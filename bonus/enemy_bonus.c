/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:23:52 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:46:20 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_e_moov(t_data *data)
{
	int		u;
	int		v;

	v = -1;
	while (++v < data->heigth / SCARE_SIZE)
	{
		u = -1;
		while (++u < data->width / SCARE_SIZE)
		{
			if (ft_get_map(data->map, u, v) == 'R' && data->sleep == 0
				&& data->over == 0 && data->finish == 0)
			{
				if (data->en_moov == 0)
					ft_en_moov_left(data, u, v);
				else if (data->en_moov == 1)
					ft_en_moov_up(data, u, v);
				else if (data->en_moov == 2)
					u += ft_en_moov_right(data, u, v);
				else if (data->en_moov == 3)
					v += ft_en_moov_down(data, u, v);
			}
		}
	}
	return (ft_e_moov_ext(data), 0);
}

void	ft_e_moov_ext(t_data *data)
{
	ft_draw(data);
	data->sleep++;
	if (data->sleep == 1500)
		data->sleep = 0;
	if (data->en_moov == 4)
		data->en_moov = 0;
}

void	ft_game_over(t_data *data)
{
	int		x;
	int		y;

	data->over = 1;
	data->finish = 0;
	x = ((data->width) / 2) - 275 / 2;
	y = ((data->heigth) / 2) - 183 / 2;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->xpm[7], x, y);
	ft_reset_map(data);
	data->finish = 0;
}
