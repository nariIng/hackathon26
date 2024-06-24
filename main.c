/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:23:41 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/24 15:03:50 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	ft_map(&data, "map2.ber");
	ft_start(&data);
	mlx_key_hook(data.win_ptr, ft_key, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_win, &data);
	// mlx_loop_hook(data.mlx_ptr, ft_e_moov, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
