/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:13:43 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 19:17:41 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mvt_right(t_map *map)
{
	if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == '1')
		return (0);
	if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'E'
		&& map->harvest != map->nb_item)
		return (0);
	else if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'E'
		&& map->harvest == map->nb_item)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	hztl_mvt_put_floor(map);
	hztl_mvt_put_usr(map, 1);
	if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'C')
	{
		map->map[map->pos_idx.y][map->pos_idx.x + 1] = '0';
		map->harvest++;
	}
	map->detect.x += 8;
	map->pos.x += 8;
	if (map->detect.x == 32)
		update_idx(map, 1);
	return (0);
}

int	mvt_left(t_map *map)
{
	if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == '1')
		return (0);
	if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'E'
		&& map->harvest != map->nb_item)
		return (0);
	else if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'E'
		&& map->harvest == map->nb_item)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	hztl_mvt_put_floor(map);
	hztl_mvt_put_usr(map, 2);
	if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'C')
	{
		map->map[map->pos_idx.y][map->pos_idx.x - 1] = '0';
		map->harvest++;
	}
	map->detect.x -= 8;
	map->pos.x -= 8;
	if (map->detect.x == -32)
		update_idx(map, 2);
	return (0);
}

int	mvt_up(t_map *map)
{
	if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == '1')
		return (0);
	if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'E'
		&& map->harvest != map->nb_item)
		return (0);
	else if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'E'
		&& map->harvest == map->nb_item)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	vrtl_mvt_put_floor(map);
	vrtl_mvt_put_usr(map, 1);
	if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'C')
	{
		map->map[map->pos_idx.y - 1][map->pos_idx.x] = '0';
		map->harvest++;
	}
	map->detect.y -= 8;
	map->pos.y -= 8;
	if (map->detect.y == -32)
		update_idx(map, 3);
	return (0);
}

int	mvt_down(t_map *map)
{
	if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == '1')
		return (0);
	if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'E'
		&& map->harvest != map->nb_item)
		return (0);
	else if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'E'
		&& map->harvest == map->nb_item)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	vrtl_mvt_put_floor(map);
	vrtl_mvt_put_usr(map, 2);
	if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'C')
	{
		map->map[map->pos_idx.y + 1][map->pos_idx.x] = '0';
		map->harvest++;
	}
	map->detect.y += 8;
	map->pos.y += 8;
	if (map->detect.y == 32)
		update_idx(map, 4);
	return (0);
}

void	continue_mvt(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->detect.x > 0)
			mvt_right(map);
		else
			mvt_left(map);
	}
	else
	{
		if (map->detect.y > 0)
			mvt_down(map);
		else
			mvt_up(map);
	}
}
