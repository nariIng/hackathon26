/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:35:29 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 07:15:49 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_key(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_destroy_img(data);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_lstclear(&data->map, free);
	free(data->map);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_destroy_img(data);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_lstclear(&data->map, free);
	free(data->map);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	ft_destroy_img(t_data *data)
{
	int		i;

	i = 0;
	while ((data->xpm)[i])
	{
		mlx_destroy_image(data->mlx_ptr, data->xpm[i]);
		i++;
	}
	i = 0;
	while ((data->p_l)[i])
		mlx_destroy_image(data->mlx_ptr, (data->p_l)[i++]);
	i = 0;
	while ((data->p_d)[i])
		mlx_destroy_image(data->mlx_ptr, (data->p_d)[i++]);
	i = 0;
	while ((data->p_r)[i])
		mlx_destroy_image(data->mlx_ptr, (data->p_r)[i++]);
	i = 0;
	while ((data->p_u)[i])
		mlx_destroy_image(data->mlx_ptr, (data->p_u)[i++]);
	return (free(data->xpm), free(data->p_d), free(data->p_l),
		free(data->p_u), free(data->p_r), 0);
}
