/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:05:13 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:46:41 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_map(t_data *data)
{
	void	**xpm;
	void	**p_d;
	void	**p_l;
	void	**p_r;
	void	**p_u;

	data->width = ft_map_width(data->map) * SCARE_SIZE;
	data->heigth = ft_map_heigth(data->map) * SCARE_SIZE;
	xpm = (void **)ft_calloc(sizeof(void *), 9);
	p_d = (void **)ft_calloc(sizeof(void *), 4);
	p_l = (void **)ft_calloc(sizeof(void *), 4);
	p_r = (void **)ft_calloc(sizeof(void *), 4);
	p_u = (void **)ft_calloc(sizeof(void *), 4);
	data->xpm = xpm;
	data->p_d = p_d;
	data->p_l = p_l;
	data->p_r = p_r;
	data->p_u = p_u;
}

void	ft_init_enemi(t_data *data)
{
	int		x;
	int		y;

	x = data->escape.x;
	y = data->escape.y;
	if (ft_get_map(data->map, x + 1, y) == '0')
		ft_set_map(data->map, x + 1, y, 'R');
	if (ft_get_map(data->map, x - 1, y) == '0')
		ft_set_map(data->map, x - 1, y, 'R');
	if (ft_get_map(data->map, x, y + 1) == '0')
		ft_set_map(data->map, x, y + 1, 'R');
	if (ft_get_map(data->map, x, y - 1) == '0')
		ft_set_map(data->map, x, y - 1, 'R');
}

void	ft_start(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window
		(data->mlx_ptr, data->width, data->heigth, "varavaran-kely");
	data->step = 0;
	data->moov = 0;
	data->sleep = 0;
	data->dir = 2;
	data->en_moov = 0;
	data->finish = 0;
	data->over = 0;
	data->piece = ft_count_p(data, 'C');
	data->enemy = ft_count_p(data, 'R');
	ft_player_pos(data);
	ft_escape_pos(data);
	ft_load_img(data);
	ft_init_enemi(data);
	ft_draw(data);
}
