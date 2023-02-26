/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:28:40 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:26:27 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include "../Libft/libft.h"
# include <fcntl.h>
# include <time.h>

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
	char	**map_tmp;
	int		nb_line;
	size_t	size_line;
	int		whidth_map_pixel;
	int		height_map_pixel;
	int		nb_wall;
	int		nb_floor;
	int		nb_item;
	int		nb_bigbanana;
	int		nb_exit;
	int		nb_pos_idx;
	int		nb_mob;
	int		level;
	int		mob_life;
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
	t_img	usr_front_jump1;
	t_img	usr_front_jump2;
	t_img	jag_front1;
	t_img	jag_front2;
	t_img	jag_front3;
	t_img	jag_front4;
	t_img	jag_back1;
	t_img	jag_back2;
	t_img	jag_back3;
	t_img	jag_back4;
	t_img	jag_right1;
	t_img	jag_right2;
	t_img	jag_right3;
	t_img	jag_right4;
	t_img	jag_left1;
	t_img	jag_left2;
	t_img	jag_left3;
	t_img	jag_left4;
	t_img	jagx_front;
	t_img	jagx_back;
	t_img	jagx_right;
	t_img	jagx_left;
	t_img	dk_front1;
	t_img	dk_front2;
	t_img	dk_front3;
	t_img	dk_back1;
	t_img	dk_back2;
	t_img	dk_back3;
	t_img	dk_right1;
	t_img	dk_right2;
	t_img	dk_right3;
	t_img	dk_left1;
	t_img	dk_left2;
	t_img	dk_left3;
	t_img	floor;
	t_img	wall;
	t_img	banana;
	t_img	banana2;
	t_img	bigbanana;
	t_img	bigbanana2;
	t_img	exit;
	t_img	title;
	t_point	pos;
	t_point	pos_mob;
	t_point	pos_idx;
	t_point	pos_idx_mob;
	int		mvt;
	int		mvt_mob;
	int		right;
	int		left;
	int		up;
	int		down;
	int		nb_mvt;
	int		i;
	int		j;
	char	dir_mob;
	t_point	detect;
	t_point	detect_mob;
}	t_map;

// .  check_map_bonus
int		check_map(char **argv, t_map *map);
int		check_map_shape(char **argv, t_map *map);
int		check_wall_ext(char **map, int size_line, int nb_line);
int		check_map_elem(t_map *map);
int		check_path(t_map *map, char **map_tmp);

// .  check_map_utils_bonus
int		check_param(int argc, char **argv, t_map *map);
char	**create_map_arr(char **argv, int nb_line);
int		flood_fill(char **map, t_point map_size, int row, int col);
void	find_idx(t_map *map, char **map_tmp);

// .  check_map_utils_2_bonus
void	map_elem_init(t_map *map);
void	add_elem(t_map *map, int i, int j);
int		error_elem(t_map *map);
int		count_line(char *map_line, size_t size_line, int fd);
void	free_map(char **map, int nb_line);

// .  imgs_init_bonus
void	user_imgs_init1(t_map *map);
void	user_imgs_init2(t_map *map);
void	dk_imgs_init1(t_map *map);
void	dk_imgs_init2(t_map *map);
void	imgs_init(t_map *map);

// .  jag_imgs_init_bonus
void	jag_front_imgs_init(t_map *map);
void	jag_back_imgs_init(t_map *map);
void	jag_right_imgs_init(t_map *map);
void	jag_left_imgs_init(t_map *map);
void	jagx_imgs_init(t_map *map);

// .  function_utils_bonus
void	win_init(t_map *map);
int		keypress(int keycode, t_map *map);
int		release(int keycode, t_map *map);
void	quit(t_map *map);
int		close_window(int keycode, t_map *map);

// .  mvt_bonus
void	mvt_right(t_map *map);
void	mvt_left(t_map *map);
void	mvt_up(t_map *map);
void	mvt_down(t_map *map);
void	continue_mvt(t_map *map, int x);

// .  mvt_mob_bonus
void	mvt_right_mob(t_map *map);
void	mvt_left_mob(t_map *map);
void	mvt_up_mob(t_map *map);
void	mvt_down_mob(t_map *map);
void	continue_mvt_mob(t_map *map, int x);

// .  mvt_utils_bonus
void	vrtl_mvt_put_floor(t_map *map);
void	hztl_mvt_put_floor(t_map *map);
void	vrtl_mvt_put_usr(t_map *map, int x);
void	hztl_mvt_put_usr(t_map *map, int x);
void	update_idx(t_map *map, int x);

// .  mvt_utils_2_bonus
int		initialize_hztl_mvt(t_map *map, int dir);
int		initialize_vrtl_mvt(t_map *map, int dir);
int		initialize_hztl_mvt_mob(t_map *map, int dir);
int		initialize_vrtl_mvt_mob(t_map *map, int dir);
void	replace_idx(t_map *map, int x);

// .  mvt_utils_mob_bonus
void	vrtl_mvt_put_floor_mob(t_map *map);
void	hztl_mvt_put_floor_mob(t_map *map);
void	vrtl_mvt_put_mob(t_map *map, int x);
void	hztl_mvt_put_mob(t_map *map, int x);
void	update_idx_mob(t_map *map, int x);

// .  mvt_utils_2_mob_bonus
void	put_right_mob(t_map *map);
void	put_left_mob(t_map *map);
void	put_up_mob(t_map *map);
void	put_down_mob(t_map *map);

// .  anim_bonus
void	put_bigbanana(t_map *map, int x, int y, long long frame);
void	put_banana(t_map *map, int x, int y, long long frame);
void	put_carpet(t_map *map, int x, int y, long long frame);
void	banana_anim(t_map *map, long long frame);
void	objects_imgs_init(t_map *map);

// .  put_init_bonus
void	put_imgs_init(t_map *map, int x, int y);
void	put_imgs2_init(t_map *map, int x, int y);
void	put_order(t_map *map);
void	put_bm(t_map *map);
void	put_nb_banana(t_map *map, int x, int y);

// .  print_evol_bonus
void	print_nb_mvt(t_map *map);
void	print_harvest(t_map *map);
void	mvt_mob(t_map *map, int dif_x, int dif_y, long long frame);
void	mvt_usr(t_map *map, long long frame);
int		update(t_map *map);

// .  mvt_utils_DK_bonus
void	vrtl_mvt_put_dk(t_map *map, int x);
void	hztl_mvt_put_dk(t_map *map, int x);
int		sizing_map(t_map *map);

#endif