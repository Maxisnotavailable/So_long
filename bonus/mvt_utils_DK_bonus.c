/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils_DK_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:02:30 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:26:17 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	vrtl_mvt_put_dk(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_back1.img_ptr, map->pos.x, map->pos.y - 8);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_back2.img_ptr, map->pos.x, map->pos.y - 8);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_back3.img_ptr, map->pos.x, map->pos.y - 8);
	}
	else
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_front1.img_ptr, map->pos.x, map->pos.y + 8);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_front2.img_ptr, map->pos.x, map->pos.y + 8);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_front3.img_ptr, map->pos.x, map->pos.y + 8);
	}
}

void	hztl_mvt_put_dk(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_right1.img_ptr, map->pos.x + 8, map->pos.y);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_right2.img_ptr, map->pos.x + 8, map->pos.y);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_right3.img_ptr, map->pos.x + 8, map->pos.y);
	}
	else
	{
		if (map->mvt == 0 || map->mvt == 2)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_left1.img_ptr, map->pos.x - 8, map->pos.y);
		if (map->mvt == 1)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_left2.img_ptr, map->pos.x - 8, map->pos.y);
		if (map->mvt == 3)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->dk_left3.img_ptr, map->pos.x - 8, map->pos.y);
	}
}

int	sizing_map(t_map *map)
{
	map->whidth_map_pixel = 32 * map->size_line;
	map->height_map_pixel = 32 * map->nb_line + 64;
	if (map->whidth_map_pixel < 800 || map->whidth_map_pixel > 1980
		|| map->height_map_pixel > 960)
	{
		if (map->whidth_map_pixel < 800)
			write(2, "Error\nMap too small\n", 20);
		else
			write(2, "Error\nMap too large\n", 20);
		return (1);
	}
	return (0);
}
