/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils_mob_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:04:40 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 14:59:01 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	vrtl_mvt_put_floor_mob(t_map *map)
{
	if (map->pos_mob.y % 32 == 24)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y + 8);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y - 24);
	}
	else if (map->pos_mob.y % 32 == 16)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y + 16);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y - 16);
	}
	else if (map->pos_mob.y % 32 == 8)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y + 24);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y - 8);
	}
	else if (map->pos_mob.y % 32 == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y);
}

void	hztl_mvt_put_floor_mob(t_map *map)
{
	if (map->pos_mob.x % 32 == 24)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x + 8, map->pos_mob.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x - 24, map->pos_mob.y);
	}
	else if (map->pos_mob.x % 32 == 16)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x + 16, map->pos_mob.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x - 16, map->pos_mob.y);
	}
	else if (map->pos_mob.x % 32 == 8)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x + 24, map->pos_mob.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x - 8, map->pos_mob.y);
	}
	else if (map->pos_mob.x % 32 == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos_mob.x, map->pos_mob.y);
}

void	vrtl_mvt_put_mob(t_map *map, int x)
{
	if (x == 1)
		put_up_mob(map);
	else
		put_down_mob(map);
}

void	hztl_mvt_put_mob(t_map *map, int x)
{
	if (x == 1)
		put_right_mob(map);
	else
		put_left_mob(map);
}

void	update_idx_mob(t_map *map, int x)
{
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] != 'C'
		&& map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] != 'B')
		map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = '0';
	if (x == 1 || x == 2)
	{
		map->detect_mob.x = 0;
		if (x == 1)
			map->pos_idx_mob.x++;
		else
			map->pos_idx_mob.x--;
	}
	else
	{
		map->detect_mob.y = 0;
		if (x == 3)
			map->pos_idx_mob.y--;
		else
			map->pos_idx_mob.y++;
	}
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] != 'C'
		&& map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] != 'B')
		map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = 'M';
	map->dir_mob = 'n';
}
