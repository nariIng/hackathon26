/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:32:28 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:48:19 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_map(t_list *list, int x, int y, char c)
{
	t_list	*temp;
	int		i;
	char	*str;

	temp = list;
	i = 0;
	while (i < y)
	{
		temp = temp->next;
		i++;
	}
	str = temp->content;
	str[x] = c;
}

char	ft_get_map(t_list *list, int x, int y)
{
	t_list	*temp;
	int		i;
	char	*str;

	temp = list;
	i = 0;
	while (i < y)
	{
		temp = temp->next;
		i++;
	}
	str = temp->content;
	return (str[x]);
}

int	ft_find_path(t_data *data)
{
	int		x;
	int		y;

	ft_player_pos(data);
	x = data->player.x;
	y = data->player.y;
	ft_set_map(data->copy_map, x, y, 'F');
	ft_recursiv_set_map(data, 'F');
	if (ft_count_copy_p(data, 'C') != 0
		|| ft_count_copy_p(data, 'E') != 0)
	{
		ft_lstclear(&(data->copy_map), &free);
		free(data->copy_map);
		return (1);
	}
	ft_lstclear(&(data->copy_map), &free);
	free(data->copy_map);
	return (0);
}

void	ft_recursiv_set_map(t_data *data, char c)
{
	int		i;
	int		j;

	j = 0;
	while (j < data->heigth / SCARE_SIZE)
	{
		i = 0;
		while (i < data->width / SCARE_SIZE)
		{
			if (ft_get_map(data->copy_map, i, j) != '1'
				&& ft_get_map(data->copy_map, i, j) != c
				&& ft_near(data, i, j, c))
			{
				ft_set_map(data->copy_map, i, j, c);
				ft_recursiv_set_map(data, c);
			}
			i++;
		}
		j++;
	}
}
