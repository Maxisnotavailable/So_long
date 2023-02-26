/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:28:40 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 19:59:04 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "Libft/libft.h"
# include <fcntl.h>

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_img {
	char	*img_path;
	int		img_width;
	int		img_height;
	void	*img_ptr;
}	t_img;

typedef struct s_map {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		nb_line;
	size_t	size_line;
	int		whidth_map_pixel;
	int		height_map_pixel;
	int		nb_wall;
	int		nb_floor;
	int		nb_item;
	int		nb_exit;
	int		nb_pos_idx;
	int		harvest;
	t_img	usr_front1;
	t_img	usr_front2;
	t_img	usr_front3;
	t_img	usr_back1;
	t_img	usr_back2;
	t_img	usr_back3;
	t_img	usr_right1;
	t_img	usr_right2;
	t_img	usr_right3;
	t_img	usr_left1;
	t_img	usr_left2;
	t_img	usr_left3;
	t_img	floor;
	t_img	wall;
	t_img	banana;
	t_img	banana2;
	t_img	exit;
	t_point	pos;
	t_point	pos_idx;
	int		mvt;
	int		right;
	int		left;
	int		up;
	int		down;
	int		nb_mvt;
	int		i;
	int		j;
	t_point	detect;
}	t_map;

int		check_map(char **argv, t_map *map);
int		check_map_shape(char **argv, t_map *map);
int		check_wall_ext(char **map, int size_line, int nb_line);
int		check_map_elem(t_map *map);
int		check_path(t_map *map, char **map_tmp);

int		check_param(int argc, char **argv, t_map *map);
char	**create_map_arr(char **argv, int nb_line);
int		flood_fill(char **map, t_point map_size, int row, int col);

void	map_elem_init(t_map *map);
void	add_elem(t_map *map, int i, int j);
int		error_elem(t_map *map);
int		count_line(char *map_line, size_t size_line, int fd);
void	free_map(char **map, int nb_line);

void	user_imgs_init1(t_map *map);
void	user_imgs_init2(t_map *map);
void	imgs_init(t_map *map);

void	win_init(t_map *map);
int		keypress(int keycode, t_map *map);
int		release(int keycode, t_map *map);

int		mvt_right(t_map *map);
int		mvt_left(t_map *map);
int		mvt_up(t_map *map);
int		mvt_down(t_map *map);
void	continue_mvt(t_map *map, int x);

void	vrtl_mvt_put_floor(t_map *map);
void	hztl_mvt_put_floor(t_map *map);
void	vrtl_mvt_put_usr(t_map *map, int x);
void	hztl_mvt_put_usr(t_map *map, int x);
void	update_idx(t_map *map, int x);

#endif