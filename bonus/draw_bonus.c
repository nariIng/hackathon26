/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:19:05 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:46:14 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_draw(t_data *data)
{
	if (data->over == 1)
		ft_game_over(data);
	else if (data->finish == 1)
		ft_finish(data);
	else if (data->over != 1 && data->finish != 1)
		ft_draw_ext(data);
	return (0);
}

void	ft_draw_ext(t_data *data)
{
	t_list	*map;
	char	*str;
	int		i;
	int		j;

	map = data->map;
	i = 0;
	while (i < data->heigth / SCARE_SIZE)
	{
		str = map->content;
		j = 0;
		while (j < data->width / SCARE_SIZE)
		{
			ft_add_img(data, str[j], i * SCARE_SIZE, j * SCARE_SIZE);
			j++;
		}
		if (map->next == NULL)
			break ;
		map = map->next;
		i++;
	}
	ft_put_text(data);
}

void	ft_put_text(t_data *data)
{
	char	*step;
	char	*piece;

	step = ft_itoa(data->step);
	piece = ft_itoa(data->piece);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		SCARE_SIZE / 2, SCARE_SIZE / 2, WITE, step);
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		data->width - SCARE_SIZE / 2, SCARE_SIZE / 2, RED, piece);
	free(step);
	free(piece);
}

int	ft_add_img(t_data *data, char c, int y, int x)
{
	if (c == 'E')
		data->texture = data->xpm[0];
	else if (c == 'O')
		data->texture = data->xpm[1];
	else if (c == '0')
		data->texture = data->xpm[2];
	else if (c == 'C')
		data->texture = data->xpm[3];
	else if (c == 'R')
		data->texture = data->xpm[4];
	else if (c == '1')
		data->texture = data->xpm[5];
	else if (c == 'P')
		ft_add_img_ext(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->texture, x, y);
	return (0);
}

int	ft_add_img_ext(t_data *data)
{
	if (data->dir == 0)
		data->texture = (data->p_u)[data->moov];
	else if (data->dir == 1)
		data->texture = (data->p_r)[data->moov];
	else if (data->dir == 2)
		data->texture = (data->p_d)[data->moov];
	else if (data->dir == 3)
		data->texture = (data->p_l)[data->moov];
	return (0);
}
