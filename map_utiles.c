/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:36:02 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 08:38:40 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_reset_map(t_data *data)
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
			if (c == 'Q')
				ft_set_map(data->map, x, y, '0');
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_creat_map_copy(t_data *data)
{
	t_list	*map_copy;
	t_list	*temp;

	map_copy = NULL;
	temp = data->map;
	while (1)
	{
		ft_lstadd_back(&map_copy, ft_lstnew(ft_strdup(temp->content)));
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	data->copy_map = map_copy;
	return (0);
}

void	ft_del_endline(char *str)
{
	char	*temp;

	temp = str;
	temp += ft_strlen(str) - 1;
	if (*temp == '\n')
		*temp = '\0';
}
