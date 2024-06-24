/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:41:11 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:47:56 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_map(t_data *data, char *file)
{
	int		fd;
	char	*str;
	t_list	*map;

	data->file = file;
	fd = open(data->file, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nC'est pas la bonne carte\n");
		exit(0);
	}
	map = NULL;
	str = get_next_line(fd);
	while (str)
	{
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(str)));
		free(str);
		str = get_next_line(fd);
	}
	data->map = map;
	close(fd);
	ft_clean_map(data->map);
	ft_init_map(data);
	ft_check_map_error(data);
}

void	ft_clean_map(t_list *map)
{
	t_list	*temp;
	char	*str;

	temp = map;
	while (1)
	{
		str = temp->content;
		ft_del_endline(str);
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

int	ft_map_width(t_list *map)
{
	return (ft_strlen(map->content));
}

int	ft_map_heigth(t_list *map)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = map;
	while (1)
	{
		i++;
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (i);
}
