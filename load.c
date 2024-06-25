/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:02:29 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/25 13:53:55 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_img(t_data *data)
{
	int		width;
	int		heigth;

	data->xpm[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/baobab.xpm", &width, &heigth);
	data->xpm[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/E_exit_open.xpm", &width, &heigth);
	data->xpm[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/0_floor.xpm", &width, &heigth);
	data->xpm[3] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/C_item.xpm", &width, &heigth);
	data->xpm[4] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/enemy.xpm", &width, &heigth);
	data->xpm[5] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/1_wall.xpm", &width, &heigth);
	data->xpm[6] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/way.xpm", &width, &heigth);
	data->xpm[7] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/game_over.xpm", &width, &heigth);
	(data->p_d)[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_down.xpm", &width, &heigth);
	(data->p_d)[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_down.xpm", &width, &heigth);
	ft_load_player(data);
}

void	ft_load_player(t_data *data)
{
	int		width;
	int		heigth;

	(data->p_d)[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_down.xpm", &width, &heigth);
	(data->p_l)[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_left.xpm", &width, &heigth);
	(data->p_l)[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_left.xpm", &width, &heigth);
	(data->p_l)[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_left.xpm", &width, &heigth);
	(data->p_r)[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_right.xpm", &width, &heigth);
	(data->p_r)[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_right.xpm", &width, &heigth);
	(data->p_r)[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_right.xpm", &width, &heigth);
	(data->p_u)[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_up.xpm", &width, &heigth);
	(data->p_u)[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_up.xpm", &width, &heigth);
	(data->p_u)[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./assets/2cv_up.xpm", &width, &heigth);
}
