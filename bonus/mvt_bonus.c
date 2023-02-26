/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:13:43 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 13:22:36 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mvt_right(t_map *map)
{
	if (initialize_hztl_mvt(map, 1) == 1)
		return ;
	hztl_mvt_put_floor(map);
	if (map->level == 0)
		hztl_mvt_put_usr(map, 1);
	else
		hztl_mvt_put_dk(map, 1);
	if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'C'
		|| map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'B')
	{
		if (map->map[map->pos_idx.y][map->pos_idx.x + 1] == 'B')
			map->level = 1;
		map->map[map->pos_idx.y][map->pos_idx.x + 1] = '0';
		map->harvest++;
		print_harvest(map);
	}
	map->detect.x += 8;
	map->pos.x += 8;
	if (map->detect.x == 32)
		update_idx(map, 1);
	map->mvt++;
	if (map->mvt == 4)
		map->mvt = 0;
	print_nb_mvt(map);
}

void	mvt_left(t_map *map)
{
	if (initialize_hztl_mvt(map, -1) == 1)
		return ;
	hztl_mvt_put_floor(map);
	if (map->level == 0)
		hztl_mvt_put_usr(map, 2);
	else
		hztl_mvt_put_dk(map, 2);
	if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'C'
		|| map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'B')
	{
		if (map->map[map->pos_idx.y][map->pos_idx.x - 1] == 'B')
			map->level = 1;
		map->map[map->pos_idx.y][map->pos_idx.x - 1] = '0';
		map->harvest++;
		print_harvest(map);
	}
	map->detect.x -= 8;
	map->pos.x -= 8;
	if (map->detect.x == -32)
		update_idx(map, 2);
	map->mvt++;
	if (map->mvt == 4)
		map->mvt = 0;
	print_nb_mvt(map);
}

void	mvt_up(t_map *map)
{
	if (initialize_vrtl_mvt(map, -1) == 1)
		return ;
	vrtl_mvt_put_floor(map);
	if (map->level == 0)
		vrtl_mvt_put_usr(map, 1);
	else
		vrtl_mvt_put_dk(map, 1);
	if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'C'
		|| map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'B')
	{
		if (map->map[map->pos_idx.y - 1][map->pos_idx.x] == 'B')
			map->level = 1;
		map->map[map->pos_idx.y - 1][map->pos_idx.x] = '0';
		map->harvest++;
		print_harvest(map);
	}
	map->detect.y -= 8;
	map->pos.y -= 8;
	if (map->detect.y == -32)
		update_idx(map, 3);
	map->mvt++;
	if (map->mvt == 4)
		map->mvt = 0;
	print_nb_mvt(map);
}

void	mvt_down(t_map *map)
{
	if (initialize_vrtl_mvt(map, 1) == 1)
		return ;
	vrtl_mvt_put_floor(map);
	if (map->level == 0)
		vrtl_mvt_put_usr(map, 2);
	else
		vrtl_mvt_put_dk(map, 2);
	if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'C'
		|| map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'B')
	{
		if (map->map[map->pos_idx.y + 1][map->pos_idx.x] == 'B')
			map->level = 1;
		map->map[map->pos_idx.y + 1][map->pos_idx.x] = '0';
		map->harvest++;
		print_harvest(map);
	}
	map->detect.y += 8;
	map->pos.y += 8;
	if (map->detect.y == 32)
		update_idx(map, 4);
	map->mvt++;
	if (map->mvt == 4)
		map->mvt = 0;
	print_nb_mvt(map);
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
