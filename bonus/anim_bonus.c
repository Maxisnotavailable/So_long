/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:35:17 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 12:45:26 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_bigbanana(t_map *map, int x, int y, long long frame)
{
	if (map->map[map->i][map->j] == 'B' && frame % 4000 == 1)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor.img_ptr, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->bigbanana.img_ptr, x, y);
	}
	else if (map->map[map->i][map->j] == 'B' && frame % 2000 == 1)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor.img_ptr, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->bigbanana2.img_ptr, x, y);
	}
}

void	put_banana(t_map *map, int x, int y, long long frame)
{
	if (map->map[map->i][map->j] == 'C' && frame % 4000 == 1)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor.img_ptr, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->banana.img_ptr, x, y);
	}
	else if (map->map[map->i][map->j] == 'C' && frame % 2000 == 1)
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->floor.img_ptr, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->banana2.img_ptr, x, y);
	}
	put_bigbanana(map, x, y, frame);
}

void	put_carpet(t_map *map, int x, int y, long long frame)
{
	if (frame % 500 == 1)
	{
		if (map->map[map->i][map->j] == 'R')
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->jagx_right.img_ptr, x - 32, y);
		else if (map->map[map->i][map->j] == 'L')
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->jagx_left.img_ptr, x + 32, y);
		else if (map->map[map->i][map->j] == 'U')
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->jagx_back.img_ptr, x, y);
		else if (map->map[map->i][map->j] == 'D')
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->jagx_front.img_ptr, x, y);
	}
}

void	banana_anim(t_map *map, long long frame)
{
	int	x;
	int	y;

	x = 0;
	y = 64;
	map->i = -1;
	while (map->map[++(map->i)])
	{
		map->j = -1;
		x = 0;
		while (map->map[map->i][++(map->j)])
		{
			put_banana(map, x, y, frame);
			put_carpet(map, x, y, frame);
			x = x + 32;
		}
		y = y + 32;
	}
}

void	objects_imgs_init(t_map *map)
{
	map->banana.img_path = "./imgs/banana1.xpm";
	map->banana.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->banana.img_path, &map->banana.img_width,
			&map->banana.img_height);
	map->banana2.img_path = "./imgs/banana2.xpm";
	map->banana2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->banana2.img_path, &map->banana2.img_width,
			&map->banana2.img_height);
	map->bigbanana.img_path = "./imgs/bigbananat1.xpm";
	map->bigbanana.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->bigbanana.img_path, &map->bigbanana.img_width,
			&map->bigbanana.img_height);
	map->bigbanana2.img_path = "./imgs/bigbananat2.xpm";
	map->bigbanana2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->bigbanana2.img_path, &map->bigbanana2.img_width,
			&map->bigbanana2.img_height);
	map->exit.img_path = "./imgs/hammock.xpm";
	map->exit.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->exit.img_path,
			&map->exit.img_width, &map->exit.img_height);
}
