/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:00:16 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 13:32:49 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (map->map[map->i][map->j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->banana.img_ptr, x, y);
	if (map->map[map->i][map->j] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->exit.img_ptr, x, y);
}

void	win_init(t_map *map)
{
	int		x;
	int		y;

	map->i = -1;
	while (map->map[++(map->i)])
	{
		y = (32 * (map->i));
		map->j = -1;
		while (map->map[map->i][++(map->j)])
		{
			x = (32 * (map->j));
			put_imgs_init(map, x, y);
		}
	}
}

int	keypress(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		system("leaks so_long");
		exit(0);
	}
	if (keycode == 2)
		map->right = 0;
	if (keycode == 0)
		map->left = 0;
	if (keycode == 13)
		map->up = 0;
	if (keycode == 1)
		map->down = 0;
	return (0);
}

int	release(int keycode, t_map *map)
{
	if (keycode == 2)
		map->right = 1;
	if (keycode == 0)
		map->left = 1;
	if (keycode == 13)
		map->up = 1;
	if (keycode == 1)
		map->down = 1;
	return (0);
}
