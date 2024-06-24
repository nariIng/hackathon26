/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:54:25 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:46:28 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_error(t_data *data)
{
	if (ft_not_name(data->file))
		ft_stop(data, "Le nom doit se terminer par un .ber");
	if (data->heigth < 3 || data->width < 3)
		ft_stop(data, "Il n'y a pas d'espace pour balader");
	if (ft_not_rectangle(data->map))
		ft_stop(data, "c'est pas un rectangle");
	if (ft_no_wall(data->map, data->heigth))
		ft_stop(data, "Votre mur n'est pas fermer");
	if (ft_no_game(data))
		ft_stop(data, "Impossible de jouer avec ca");
}

int	ft_not_name(char *file)
{
	char			*name;
	char			*comp;
	size_t			len;
	unsigned int	start;

	name = file;
	if (name[0] == '.')
		return (1);
	len = ft_strlen(name);
	start = len - 4;
	comp = ft_substr(name, start, len);
	if (ft_strcmp(comp, ".ber") != 0)
		return (free(comp), 1);
	return (free(comp), 0);
}

int	ft_no_game(t_data *data)
{
	t_data	*temp;

	temp = data;
	if (ft_count_p(temp, 'P') != 1)
		return (1);
	if (ft_count_p(temp, 'E') != 1)
		return (1);
	if (ft_count_p(temp, 'C') < 1)
		return (1);
	ft_creat_map_copy(data);
	if (ft_find_path(temp))
		return (1);
	if (ft_else_char(temp))
		return (1);
	return (0);
}

int	ft_else_char(t_data *data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < data->heigth / SCARE_SIZE)
	{
		x = 0;
		while (x < data->width / SCARE_SIZE)
		{
			c = ft_get_map(data->map, x, y);
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_near(t_data *data, int x, int y, char c)
{
	if (ft_get_map(data->copy_map, x + 1, y) == c)
		return (1);
	else if (ft_get_map(data->copy_map, x, y + 1) == c)
		return (1);
	else if (ft_get_map(data->copy_map, x - 1, y) == c)
		return (1);
	else if (ft_get_map(data->copy_map, x, y - 1) == c)
		return (1);
	return (0);
}
