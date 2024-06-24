/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:41:23 by enarindr          #+#    #+#             */
/*   Updated: 2024/06/02 09:10:44 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libftprintf/libftprintf.h"
# include "./gnl/get_next_line_bonus.h"
# include "key.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}		t_img;

typedef struct s_player
{
	int		x;
	int		y;
}		t_player;

typedef struct s_escape
{
	int		x;
	int		y;
}		t_escape;

typedef struct s_data
{
	/*------windows------*/
	int			step;
	int			piece;
	int			width;
	int			heigth;
	int			moov;
	int			dir;
	int			sleep;
	int			enemy;
	int			en_moov;
	int			finish;
	int			over;
	char		*file;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*texture;
	void		**xpm;
	void		**p_d;
	void		**p_l;
	void		**p_r;
	void		**p_u;
	t_img		img;
	t_player	player;
	t_escape	escape;
	t_list		*map;
	t_list		*copy_map;
}		t_data;

int		close_win(t_data *data);
int		ft_key(int key, t_data *data);

int		ft_moov_right(t_data *data);
int		ft_moov_right_ext(t_data *data, char *str);
int		ft_moov_left(t_data *data);
int		ft_moov_left_ext(t_data *data, char *str);
int		ft_moov_up(t_data *data);
int		ft_moov_up_ext(t_data *data, t_list *map, char *str);
int		ft_moov_down(t_data *data);
int		ft_moov_down_ext(t_data *data, t_list *map, char *str);
int		ft_e_moov(t_data *data);
void	ft_e_moov_ext(t_data *data);

void	ft_en_moov_left(t_data *data, int x, int y);
void	ft_en_moov_up(t_data *data, int x, int y);
int		ft_en_moov_right(t_data *data, int x, int y);
int		ft_en_moov_down(t_data *data, int x, int y);

int		ft_map_width(t_list *map);
int		ft_map_heigth(t_list *map);
int		ft_not_rectangle(t_list *map);
int		ft_no_wall(t_list *map, int heigth);
int		ft_no_vertical_wall(t_list *map);
int		ft_no_horizontal_wall(t_list *map);
int		ft_not_name(char *file);
int		ft_no_game(t_data *data);
int		ft_else_char(t_data *data);
int		ft_creat_map_copy(t_data *data);
int		ft_find_path(t_data *data);
int		ft_player_pos(t_data *data);
int		ft_player_pos_ext(t_data *data, char *str, int x, int y);
int		ft_escape_pos(t_data *data);
int		ft_escape_pos_ext(t_data *data, char *str, int x, int y);
int		ft_draw(t_data *data);
void	ft_draw_ext(t_data *data);
int		ft_reset_map(t_data *data);
int		ft_count_p(t_data *data, char c);
int		ft_count_copy_p(t_data *data, char c);
int		ft_near(t_data *data, int x, int y, char c);

void	ft_recursiv_set_map(t_data *data, char c);

int		ft_add_img(t_data *data, char c, int y, int x);
int		ft_add_img_ext(t_data *data);
int		ft_destroy_img(t_data *data);
int		ft_exit_key(t_data *data);

int		ft_finish(t_data *data);

char	ft_get_map(t_list *list, int x, int y);
void	ft_init_map(t_data *data);
void	ft_start(t_data *data);
void	ft_map(t_data *data, char *file);
void	ft_clean_map(t_list *map);
void	ft_check_map_error(t_data *data);
void	ft_del_endline(char *str);
void	ft_load_img(t_data *data);
void	ft_load_player(t_data *data);
void	ft_change_escape(t_data *data);
void	ft_set_map(t_list *list, int x, int y, char c);
void	ft_game_over(t_data *data);
void	ft_stop(t_data *data, char *str);

void	ft_sleep(int i);

#endif