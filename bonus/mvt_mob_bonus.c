/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_mob_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:52:09 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 14:33:25 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mvt_right_mob(t_map *map)
{
	if (initialize_hztl_mvt_mob(map, 1) == 1)
		return ;
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x + 1] == 'P')
	{
		if (map->level == 0)
			quit(map);
		else
		{
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = '0';
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x + 1] = 'R';
			map->mob_life = 1;
			return ;
		}
	}
	hztl_mvt_put_floor_mob(map);
	hztl_mvt_put_mob(map, 1);
	map->detect_mob.x += 8;
	map->pos_mob.x += 8;
	if (map->detect_mob.x == 32)
		update_idx_mob(map, 1);
	map->mvt_mob++;
	if (map->mvt_mob >= 4)
		map->mvt_mob = 0;
}

void	mvt_left_mob(t_map *map)
{
	if (initialize_hztl_mvt_mob(map, -1) == 1)
		return ;
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x - 1] == 'P')
	{
		if (map->level == 0)
			quit(map);
		else
		{
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = '0';
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x - 1] = 'L';
			map->mob_life = 1;
			return ;
		}
	}
	hztl_mvt_put_floor_mob(map);
	hztl_mvt_put_mob(map, 2);
	map->detect_mob.x -= 8;
	map->pos_mob.x -= 8;
	if (map->detect_mob.x == -32)
		update_idx_mob(map, 2);
	map->mvt_mob++;
	if (map->mvt_mob >= 4)
		map->mvt_mob = 0;
}

void	mvt_up_mob(t_map *map)
{
	if (initialize_vrtl_mvt_mob(map, -1) == 1)
		return ;
	if (map->map[map->pos_idx_mob.y - 1][map->pos_idx_mob.x] == 'P')
	{
		if (map->level == 0)
			quit(map);
		else
		{
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = '0';
			map->map[map->pos_idx_mob.y - 1][map->pos_idx_mob.x] = 'U';
			map->mob_life = 1;
			return ;
		}
	}
	vrtl_mvt_put_floor_mob(map);
	vrtl_mvt_put_mob(map, 1);
	map->detect_mob.y -= 8;
	map->pos_mob.y -= 8;
	if (map->detect_mob.y == -32)
		update_idx_mob(map, 3);
	map->mvt_mob++;
	if (map->mvt_mob >= 4)
		map->mvt_mob = 0;
}

void	mvt_down_mob(t_map *map)
{
	if (initialize_vrtl_mvt_mob(map, 1) == 1)
		return ;
	if (map->map[map->pos_idx_mob.y + 1][map->pos_idx_mob.x] == 'P')
	{
		if (map->level == 0)
			quit(map);
		else
		{
			map->map[map->pos_idx_mob.y][map->pos_idx_mob.x] = '0';
			map->map[map->pos_idx_mob.y + 1][map->pos_idx_mob.x] = 'D';
			map->mob_life = 1;
			return ;
		}
	}
	vrtl_mvt_put_floor_mob(map);
	vrtl_mvt_put_mob(map, 2);
	map->detect_mob.y += 8;
	map->pos_mob.y += 8;
	if (map->detect_mob.y == 32)
		update_idx_mob(map, 4);
	map->mvt_mob++;
	if (map->mvt_mob >= 4)
		map->mvt_mob = 0;
}

void	continue_mvt_mob(t_map *map, int x)
{
	if (x == 1)
	{
		if (map->detect_mob.x > 0)
			mvt_right_mob(map);
		else
			mvt_left_mob(map);
	}
	else
	{
		if (map->detect_mob.y > 0)
			mvt_down_mob(map);
		else
			mvt_up_mob(map);
	}
}
