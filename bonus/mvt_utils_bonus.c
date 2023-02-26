/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:16:04 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 14:44:02 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	vrtl_mvt_put_floor(t_map *map)
{
	if (map->pos.y % 32 == 24)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y + 8);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y - 24);
	}
	else if (map->pos.y % 32 == 16)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y + 16);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y - 16);
	}
	else if (map->pos.y % 32 == 8)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y + 24);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y - 8);
	}
	else if (map->pos.y % 32 == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y);
}

void	hztl_mvt_put_floor(t_map *map)
{
	if (map->pos.x % 32 == 24)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x + 8, map->pos.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x - 24, map->pos.y);
	}
	else if (map->pos.x % 32 == 16)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x + 16, map->pos.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x - 16, map->pos.y);
	}
	else if (map->pos.x % 32 == 8)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x + 24, map->pos.y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x - 8, map->pos.y);
	}
	else if (map->pos.x % 32 == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->floor.img_ptr,
			map->pos.x, map->pos.y);
}

void	vrtl_mvt_put_usr(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_back1.img_ptr, map->pos.x, map->pos.y - 16 - 8);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_back2.img_ptr, map->pos.x, map->pos.y - 16 - 8);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_back3.img_ptr, map->pos.x, map->pos.y - 16 - 8);
	}
	else
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_front1.img_ptr, map->pos.x, map->pos.y - 16 + 8);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_front2.img_ptr, map->pos.x, map->pos.y - 16 + 8);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_front3.img_ptr, map->pos.x, map->pos.y - 16 + 8);
	}
}

void	hztl_mvt_put_usr(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_right1.img_ptr, map->pos.x + 8, map->pos.y - 16);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_right2.img_ptr, map->pos.x + 8, map->pos.y - 16);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_right3.img_ptr, map->pos.x + 8, map->pos.y - 16);
	}
	else
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_left1.img_ptr, map->pos.x - 8, map->pos.y - 16);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_left2.img_ptr, map->pos.x - 8, map->pos.y - 16);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->usr_left3.img_ptr, map->pos.x - 8, map->pos.y - 16);
	}
}

void	update_idx(t_map *map, int x)
{
	replace_idx(map, 0);
	if (x == 1 || x == 2)
	{
		map->detect.x = 0;
		if (x == 1)
			map->pos_idx.x++;
		else
			map->pos_idx.x--;
	}
	else
	{
		map->detect.y = 0;
		if (x == 3)
			map->pos_idx.y--;
		else
			map->pos_idx.y++;
	}
	replace_idx(map, 1);
	map->nb_mvt++;
	ft_printf("%d\n", map->nb_mvt);
}
