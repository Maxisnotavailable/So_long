/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:28:23 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:27:30 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (check_param(argc, argv, &map) == 1)
		return (1);
	if (sizing_map(&map) == 1)
		return (1);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.whidth_map_pixel,
			map.height_map_pixel, "** BANANA.COM **");
	imgs_init(&map);
	win_init(&map);
	mlx_hook(map.win_ptr, 2, 0, keypress, &map);
	mlx_hook(map.win_ptr, 3, 0, release, &map);
	mlx_hook(map.win_ptr, 17, 0, close_window, &map);
	mlx_loop_hook(map.mlx_ptr, update, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
