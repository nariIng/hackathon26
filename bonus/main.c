/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:23:41 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:47:42 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nil n'y a pas de jeux\n");
		return (0);
	}
	ft_map(&data, argv[1]);
	ft_start(&data);
	mlx_key_hook(data.win_ptr, ft_key, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_win, &data);
	mlx_loop_hook(data.mlx_ptr, ft_e_moov, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
