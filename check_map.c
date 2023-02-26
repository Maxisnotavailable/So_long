/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:46:22 by molla             #+#    #+#             */
/*   Updated: 2023/02/22 18:23:43 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **argv, t_map *map)
{
	char	**map_tmp;

	map->nb_line = check_map_shape(argv, map);
	if (map->nb_line == 1)
		return (1);
	map->map = create_map_arr(argv, map->nb_line);
	if (!map->map)
		return (1);
	if (check_wall_ext(map->map, map->size_line, map->nb_line) == 1)
		return (free_map(map->map, map->nb_line), 1);
	map_elem_init(map);
	if (check_map_elem(map) == 1)
		return (free_map(map->map, map->nb_line), 1);
	map_tmp = create_map_arr(argv, map->nb_line);
	if (!map_tmp)
		return (1);
	if (check_path(map, map_tmp) == 1)
		return (free_map(map_tmp, map->nb_line), 1);
	free_map(map_tmp, map->nb_line);
	return (0);
}

int	check_map_shape(char **argv, t_map *map)
{
	char	*map_line;
	int		nb_line;
	int		fd;

	nb_line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nMap does not exist\n", 25), 1);
	map_line = ft_strtrim(get_next_line(fd), "\n");
	if (map_line == NULL)
		return (write(2, "Error\nMap is empty\n", 19), 1);
	if (*map_line == '\0')
		return (write(2, "Error\nFirst line is empty\n", 26), 1);
	map->size_line = ft_strlen(map_line);
	free(map_line);
	nb_line = count_line(map_line, map->size_line, fd);
	if (nb_line == 1)
		return (write(2, "Error\nMap is not rectangular\n", 29), 1);
	if (nb_line == 0)
		return (1);
	if (close(fd) == -1)
		return (write(2, "Closed failed\n", 14), 1);
	return (nb_line);
}

int	check_wall_ext(char **map, int size_line, int nb_line)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		if (i == 0 || i == nb_line - 1)
		{
			while (map[i][++j])
			{
				if (map[i][j] != '1')
					return (write(2, "Error\nWalls don't close map\n", 28), 1);
			}
		}
		else
		{
			while (map[i][++j])
			{
				if ((j == 0 || j == (int)size_line - 1) && map[i][j] != '1')
					return (write(2, "Error\nWalls don't close map\n", 28), 1);
			}
		}
	}
	return (0);
}

int	check_map_elem(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0'
				|| map->map[i][j] == 'C' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'P')
				add_elem(map, i, j);
			else
				return (write(2, "Error\nImpossible element in map\n", 32), 1);
		}
	}
	if (error_elem(map) == 1)
		return (1);
	return (0);
}

int	check_path(t_map *map, char **map_tmp)
{
	t_point	map_size;
	int		i;
	int		j;

	map_size.x = map->size_line;
	map_size.y = map->nb_line;
	i = -1;
	while (map_tmp[++i])
	{
		j = -1;
		while (map_tmp[i][++j])
		{
			if (map_tmp[i][j] == 'P')
			{
				map->pos_idx.x = j;
				map->pos_idx.y = i;
			}
		}
	}
	j = flood_fill(map_tmp, map_size, map->pos_idx.y, map->pos_idx.x);
	if (j != map->nb_item)
		return (write(2, "Error\nImpossible path\n", 22), 1);
	return (0);
}
