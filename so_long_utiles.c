/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:35:24 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:00:31 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_stop(t_data *data, char *str)
{
	ft_lstclear(&data->map, free);
	free(data->map);
	free(data->xpm);
	free(data->p_d);
	free(data->p_l);
	free(data->p_r);
	free(data->p_u);
	ft_printf("Error\n%s\n", str);
	exit(1);
}

int	ft_finish(t_data *data)
{
	int		x;
	int		y;

	x = ((data->width) / 2) - 275 / 2;
	y = ((data->heigth) / 2) - 183 / 2;
	data->finish = 1;
	data->over = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->xpm[6], x, y);
	ft_reset_map(data);
	return (0);
}

void	ft_sleep(int i)
{
	usleep(i);
}
