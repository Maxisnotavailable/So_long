/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:28:46 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:04:37 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_imgs2_init(t_map *map, int x, int y)
{
	if (map->map[map->i][map->j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->banana.img_ptr, x, y);
	if (map->map[map->i][map->j] == 'B')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->bigbanana.img_ptr, x, y);
	if (map->map[map->i][map->j] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->exit.img_ptr, x, y);
	if (map->map[map->i][map->j] == 'M')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->jag_front1.img_ptr, x, y);
		map->pos_mob.x = x;
		map->pos_mob.y = y;
	}
}

void	put_imgs_init(t_map *map, int x, int y)
{
	if (map->map[map->i][map->j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->wall.img_ptr, x, y);
	if (map->map[map->i][map->j] != '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor.img_ptr, x, y);
	if (map->map[map->i][map->j] == 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->usr_front1.img_ptr, x, y - 16);
		map->pos.x = x;
		map->pos.y = y;
	}
	put_imgs2_init(map, x, y);
}

void	put_order(t_map *map)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->title.img_ptr, (map->whidth_map_pixel / 2) - 128, 8);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 + 2, 8 + 2, 0xFFCC00,
		"PLEASE HELP ME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 - 2, 8 - 2, 0xFFCC00,
		"PLEASE HELP ME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 + 2, 8 - 2, 0xFFCC00,
		"PLEASE HELP ME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 - 2, 8 + 2, 0xFFCC00,
		"PLEASE HELP ME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32, 8, 0x663333,
		"PLEASE HELP ME");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 + 2, 32 + 2, 0xFFCC00,
		"TO GET MY BANANAS !!");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 - 2, 32 - 2, 0xFFCC00,
		"TO GET MY BANANAS !!");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 + 2, 32 - 2, 0xFFCC00,
		"TO GET MY BANANAS !!");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32 - 2, 32 + 2, 0xFFCC00,
		"TO GET MY BANANAS !!");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 32, 32, 0x663333,
		"TO GET MY BANANAS !!");
}

void	put_bm(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 196 + 2, 8 + 2, 0xFFCC00, "MOVES :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 196 - 2, 8 - 2, 0xFFCC00, "MOVES :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 196 + 2, 8 - 2, 0xFFCC00, "MOVES :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 196 - 2, 8 + 2, 0xFFCC00, "MOVES :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 196, 8, 0x663333, "MOVES :");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 176 + 2, 32 + 2, 0xFFCC00, "BANANAS :    /");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 176 - 2, 32 - 2, 0xFFCC00, "BANANAS :    /");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 176 + 2, 32 - 2, 0xFFCC00, "BANANAS :    /");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 176 - 2, 32 + 2, 0xFFCC00, "BANANAS :    /");
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 176, 32, 0x663333, "BANANAS :    /");
}

void	put_nb_banana(t_map *map, int x, int y)
{
	char	*tot;

	while (y < 64)
	{
		x = 0;
		while (x < map->whidth_map_pixel)
		{
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->floor.img_ptr, x, y);
				x += 32;
		}
		y += 32;
	}
	tot = ft_itoa(map->nb_item);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 324 + 2, 32 + 2, 0xFFCC00, tot);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 324 - 2, 32 - 2, 0xFFCC00, tot);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 324 + 2, 32 - 2, 0xFFCC00, tot);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 324 - 2, 32 + 2, 0xFFCC00, tot);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->whidth_map_pixel / 2)
		+ 324, 32, 0x663333, tot);
	free(tot);
}
