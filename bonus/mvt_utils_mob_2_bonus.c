/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils_mob_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:48:22 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 14:58:11 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_right_mob(t_map *map)
{
	if (map->mvt_mob == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_right1.img_ptr, map->pos_mob.x + 8, map->pos_mob.y);
	if (map->mvt_mob == 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_right2.img_ptr, map->pos_mob.x + 8, map->pos_mob.y);
	if (map->mvt_mob == 2)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_right3.img_ptr, map->pos_mob.x + 8, map->pos_mob.y);
	if (map->mvt_mob == 3)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_right4.img_ptr, map->pos_mob.x + 8, map->pos_mob.y);
}

void	put_left_mob(t_map *map)
{
	if (map->mvt_mob == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_left1.img_ptr, map->pos_mob.x - 8, map->pos_mob.y);
	if (map->mvt_mob == 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_left2.img_ptr, map->pos_mob.x - 8, map->pos_mob.y);
	if (map->mvt_mob == 2)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_left3.img_ptr, map->pos_mob.x - 8, map->pos_mob.y);
	if (map->mvt_mob == 3)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_left4.img_ptr, map->pos_mob.x - 8, map->pos_mob.y);
}

void	put_up_mob(t_map *map)
{
	if (map->mvt_mob == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_back1.img_ptr, map->pos_mob.x, map->pos_mob.y - 8);
	if (map->mvt_mob == 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_back2.img_ptr, map->pos_mob.x, map->pos_mob.y - 8);
	if (map->mvt_mob == 2)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_back3.img_ptr, map->pos_mob.x, map->pos_mob.y - 8);
	if (map->mvt_mob == 3)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_back4.img_ptr, map->pos_mob.x, map->pos_mob.y - 8);
}

void	put_down_mob(t_map *map)
{
	if (map->mvt_mob == 0)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_front1.img_ptr, map->pos_mob.x, map->pos_mob.y + 8);
	if (map->mvt_mob == 1)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_front2.img_ptr, map->pos_mob.x, map->pos_mob.y + 8);
	if (map->mvt_mob == 2)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_front3.img_ptr, map->pos_mob.x, map->pos_mob.y + 8);
	if (map->mvt_mob == 3)
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_front4.img_ptr, map->pos_mob.x, map->pos_mob.y + 8);
}
