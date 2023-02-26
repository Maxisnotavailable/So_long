/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:48:37 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 15:29:58 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_elem_init(t_map *map)
{
	map->nb_wall = 0;
	map->nb_floor = 0;
	map->nb_item = 0;
	map->nb_bigbanana = 0;
	map->nb_exit = 0;
	map->nb_pos_idx = 0;
	map->nb_mob = 0;
	map->mvt = 0;
	map->mvt_mob = 0;
	map->level = 0;
	map->mob_life = 0;
	map->harvest = 0;
	map->right = 1;
	map->left = 1;
	map->up = 1;
	map->down = 1;
	map->nb_mvt = 0;
	map->i = -1;
	map->j = -1;
	map->detect.x = 0;
	map->detect.y = 0;
	map->detect_mob.x = 0;
	map->detect_mob.y = 0;
	map->dir_mob = 'n';
}

void	add_elem(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		map->nb_wall++;
	else if (map->map[i][j] == '0')
		map->nb_floor++;
	else if (map->map[i][j] == 'C')
		map->nb_item++;
	else if (map->map[i][j] == 'E')
		map->nb_exit++;
	else if (map->map[i][j] == 'P')
		map->nb_pos_idx++;
	else if (map->map[i][j] == 'M')
		map->nb_mob++;
	else if (map->map[i][j] == 'B')
	{
		map->nb_item++;
		map->nb_bigbanana++;
	}
}

int	error_elem(t_map *map)
{
	if (map->nb_item < 1)
		return (write(2, "Error\nCollectibles not found\n", 29), 1);
	else if (map->nb_exit < 1)
		return (write(2, "Error\nExit not found\n", 21), 1);
	else if (map->nb_pos_idx < 1)
		return (write(2, "Error\nStarting position not found\n", 34), 1);
	else if (map->nb_exit > 1)
		return (write(2, "Error\nToo many exits\n", 21), 1);
	else if (map->nb_pos_idx > 1)
		return (write(2, "Error\nToo many starting positions\n", 34), 1);
	else if (map->nb_bigbanana > 1)
		return (write(2, "Error\nToo many BigBanana\n", 25), 1);
	else if (map->nb_mob > 1)
		return (write(2, "Error\nToo many ennemy\n", 25), 1);
	else if (map->nb_mob < 1)
		return (write(2, "Error\nEnnemy missing\n", 21), 1);
	return (0);
}

int	count_line(char *map_line, size_t size_line, int fd)
{
	int	nb_line;

	nb_line = 0;
	while (map_line != NULL)
	{
		map_line = ft_strtrim(get_next_line(fd), "\n");
		if (map_line != NULL)
		{
			if (ft_strlen(map_line) != size_line)
			{
				free(map_line);
				return (write(2, "Error\nMap is not rectangular\n", 29), 0);
			}
		}
		free(map_line);
		nb_line++;
	}
	return (nb_line);
}

void	free_map(char **map, int nb_line)
{
	int	i;

	i = 0;
	while (i <= nb_line)
		free(map[i++]);
	free(map);
}
