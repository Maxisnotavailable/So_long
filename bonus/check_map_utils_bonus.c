/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:49:39 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 12:33:59 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		g_collectible = 0;
int		g_exit = 0;

int	check_param(int argc, char **argv, t_map *map)
{
	int		i;

	if (argc != 2)
		return (write(2, "Error\nInvalid number of arguments\n", 34), 1);
	i = ft_strlen(argv[1]);
	if (!ft_strnstr(argv[1], ".ber", i)
		|| ft_strncmp(ft_strnstr(argv[1], ".ber", i), ".ber", 5) != 0)
		return (write(2, "Error\nThe map must be in *.ber format\n", 38), 1);
	if (check_map(argv, map) == 1)
		return (1);
	return (0);
}

char	**create_map_arr(char **argv, int nb_line)
{
	int		j;
	int		fd;
	int		size_line;
	char	**map;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nMap does not exist\n", 25), NULL);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (write(2, "Error\nMalloc failed\n", 19), NULL);
	map[j] = ft_strtrim(get_next_line(fd), "\n");
	size_line = ft_strlen(map[j]);
	while (map[j++])
		map[j] = ft_strtrim(get_next_line(fd), "\n");
	if (close(fd) == -1)
		return (write(2, "Closed failed\n", 14), NULL);
	return (map);
}

int	flood_fill(char **map, t_point map_size, int row, int col)
{
	if (row < 0 || row > map_size.y || col < 0 || col > map_size.x)
		return (g_collectible);
	if (map[row][col] == 'C' || map[row][col] == 'B')
		g_collectible++;
	if (map[row][col] == 'E')
	{
		if (g_exit == 1)
			g_exit = 1;
		else
			g_exit++;
	}
	if (map[row][col] == '+' || (map[row][col] != 'P' && map[row][col] != '0'
		&& map[row][col] != 'C' && map[row][col] != 'B'))
		return (g_collectible);
	map[row][col] = '+';
	flood_fill(map, map_size, row - 1, col);
	flood_fill(map, map_size, row + 1, col);
	flood_fill(map, map_size, row, col - 1);
	flood_fill(map, map_size, row, col + 1);
	if (g_exit != 1)
		return (-1);
	return (g_collectible);
}

void	find_idx(t_map *map, char **map_tmp)
{
	if (map_tmp[map->i][map->j] == 'P')
	{
		map->pos_idx.x = map->j;
		map->pos_idx.y = map->i;
	}
	if (map_tmp[map->i][map->j] == 'M')
	{
		map->pos_idx_mob.x = map->j;
		map->pos_idx_mob.y = map->i;
	}
}
