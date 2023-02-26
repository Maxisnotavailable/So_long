/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:22:27 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 14:44:12 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	initialize_hztl_mvt(t_map *map, int dir)
{
	if (map->map[map->pos_idx.y][map->pos_idx.x + dir] == '1')
		return (1);
	if (map->map[map->pos_idx.y][map->pos_idx.x + dir] == 'M'
		&& map->level == 0)
		quit(map);
	if (map->map[map->pos_idx.y][map->pos_idx.x + dir] == 'E'
		&& map->harvest != map->nb_item)
		return (1);
	else if (map->map[map->pos_idx.y][map->pos_idx.x + dir] == 'E'
		&& map->harvest == map->nb_item)
		quit(map);
	return (0);
}

int	initialize_vrtl_mvt(t_map *map, int dir)
{
	if (map->map[map->pos_idx.y + dir][map->pos_idx.x] == '1')
		return (1);
	if (map->map[map->pos_idx.y + dir][map->pos_idx.x] == 'M'
		&& map->level == 0)
		quit(map);
	if (map->map[map->pos_idx.y + dir][map->pos_idx.x] == 'E'
		&& map->harvest != map->nb_item)
		return (1);
	else if (map->map[map->pos_idx.y + dir][map->pos_idx.x] == 'E'
		&& map->harvest == map->nb_item)
		quit(map);
	return (0);
}

int	initialize_hztl_mvt_mob(t_map *map, int dir)
{
	if (dir == 1)
		map->dir_mob = 'r';
	else
		map->dir_mob = 'l';
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x + dir] == '1')
	{
		map->mvt_mob++;
		map->dir_mob = 'n';
		return (1);
	}
	if (map->map[map->pos_idx_mob.y][map->pos_idx_mob.x + dir] == 'E')
		return (1);
	return (0);
}

int	initialize_vrtl_mvt_mob(t_map *map, int dir)
{
	if (dir == 1)
		map->dir_mob = 'd';
	else
		map->dir_mob = 'u';
	if (map->map[map->pos_idx_mob.y + dir][map->pos_idx_mob.x] == '1')
	{
		map->mvt_mob++;
		map->dir_mob = 'n';
		return (1);
	}
	if (map->map[map->pos_idx_mob.y + dir][map->pos_idx_mob.x] == 'E')
		return (1);
	return (0);
}

void	replace_idx(t_map *map, int x)
{
	if (x == 0)
	{
		if (map->map[map->pos_idx.y][map->pos_idx.x] != 'R'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'L'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'U'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'D')
			map->map[map->pos_idx.y][map->pos_idx.x] = '0';
	}
	else
	{
		if (map->map[map->pos_idx.y][map->pos_idx.x] != 'R'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'L'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'U'
			&& map->map[map->pos_idx.y][map->pos_idx.x] != 'D')
			map->map[map->pos_idx.y][map->pos_idx.x] = 'P';
	}
}
