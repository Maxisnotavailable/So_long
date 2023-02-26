/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_evol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:46:18 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:16:00 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_nb_mvt(t_map *map)
{
	char	*nb;

	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->floor.img_ptr, (map->whidth_map_pixel / 2) + 272, 0);
	nb = ft_itoa(map->nb_mvt);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 274 + 2, 8 + 2, 0xFFCC00, nb);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 274 - 2, 8 - 2, 0xFFCC00, nb);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 274 + 2, 8 - 2, 0xFFCC00, nb);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 274 - 2, 8 + 2, 0xFFCC00, nb);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 274, 8, 0x663333, nb);
	free(nb);
}

void	print_harvest(t_map *map)
{
	char	*harvest;

	harvest = ft_itoa(map->harvest);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->floor.img_ptr, (map->whidth_map_pixel / 2) + 272, 32);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 276 + 2, 32 + 2, 0xFFCC00, harvest);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 276 - 2, 32 - 2, 0xFFCC00, harvest);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 276 + 2, 32 - 2, 0xFFCC00, harvest);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 276 - 2, 32 + 2, 0xFFCC00, harvest);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 276, 32, 0x663333, harvest);
	free(harvest);
}

void	mvt_mob(t_map *map, int dif_x, int dif_y, long long frame)
{
	if (frame % 650 == 1 && map->dir_mob == 'n' && dif_x < 0
		&& map->mob_life == 0)
		mvt_right_mob(map);
	if (frame % 650 == 1 && map->dir_mob == 'n' && dif_x > 0
		&& map->mob_life == 0)
		mvt_left_mob(map);
	if (frame % 650 == 1 && map->dir_mob == 'n' && dif_y > 0
		&& map->mob_life == 0)
		mvt_up_mob(map);
	if (frame % 650 == 1 && map->dir_mob == 'n' && dif_y < 0
		&& map->mob_life == 0)
		mvt_down_mob(map);
	if (frame % 650 == 1 && (map->dir_mob == 'r' || map->dir_mob == 'l')
		&& map->mob_life == 0)
		continue_mvt_mob(map, 1);
	else if (frame % 650 == 1 && (map->dir_mob == 'u' || map->dir_mob == 'd')
		&& map->mob_life == 0)
		continue_mvt_mob(map, 2);
}

void	mvt_usr(t_map *map, long long frame)
{
	if (map->right == 1 && map->left == 1 && map->detect.x != 0
		&& frame % 500 == 1)
		continue_mvt(map, 1);
	if (map->up == 1 && map->down == 1 && map->detect.y != 0
		&& frame % 500 == 1)
		continue_mvt(map, 2);
	if (map->right == 0 && frame % 500 == 1 && map->pos.y % 32 == 0)
		mvt_right(map);
	else if (map->left == 0 && frame % 500 == 1 && map->pos.y % 32 == 0)
		mvt_left(map);
	if (map->up == 0 && frame % 500 == 1 && map->pos.x % 32 == 0)
		mvt_up(map);
	else if (map->down == 0 && frame % 500 == 1 && map->pos.x % 32 == 0)
		mvt_down(map);
}

int	update(t_map *map)
{
	static long long	frame;
	int					dif_x;
	int					dif_y;

	dif_x = map->pos_idx_mob.x - map->pos_idx.x;
	dif_y = map->pos_idx_mob.y - map->pos_idx.y;
	banana_anim(map, frame);
	mvt_mob(map, dif_x, dif_y, frame);
	mvt_usr(map, frame);
	frame++;
	if (frame > 9223372036854775806)
		frame = 0;
	return (0);
}
