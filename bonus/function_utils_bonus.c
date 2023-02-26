/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:00:16 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 13:09:33 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	win_init(t_map *map)
{
	int		x;
	int		y;

	map->i = -1;
	while (map->map[++(map->i)])
	{
		y = (32 * (map->i)) + 64;
		map->j = -1;
		while (map->map[map->i][++(map->j)])
		{
			x = (32 * (map->j));
			put_imgs_init(map, x, y);
		}
	}
	put_nb_banana(map, 0, 0);
	put_order(map);
	put_bm(map);
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

void	quit(t_map *map)
{
	(void)map;
	exit(0);
}

int	close_window(int keycode, t_map *map)
{
	(void)keycode;
	(void)map;
	exit(0);
}
