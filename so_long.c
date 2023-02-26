/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:28:23 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 19:58:42 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	exit(0);
}

int	update(t_map *map)
{
	static long long	frame;

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
	frame++;
	if (frame > 9223372036854775806)
		frame = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (check_param(argc, argv, &map) == 1)
		return (1);
	map.whidth_map_pixel = 32 * map.size_line;
	map.height_map_pixel = 32 * map.nb_line;
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.whidth_map_pixel,
			map.height_map_pixel, "** BANANA.COM **");
	imgs_init(&map);
	win_init(&map);
	mlx_hook(map.win_ptr, 2, 0, keypress, &map);
	mlx_hook(map.win_ptr, 3, 0, release, &map);
	mlx_hook(map.win_ptr, 17, 0, close_window, NULL);
	mlx_loop_hook(map.mlx_ptr, update, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
