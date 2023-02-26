/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:51:45 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 19:58:24 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	user_imgs_init1(t_map *map)
{
	map->usr_front1.img_path = "./imgs/usr/usr_front1.xpm";
	map->usr_front1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_front1.img_path, &map->usr_front1.img_width,
			&map->usr_front1.img_height);
	map->usr_front2.img_path = "./imgs/usr/usr_front2.xpm";
	map->usr_front2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_front2.img_path, &map->usr_front2.img_width,
			&map->usr_front2.img_height);
	map->usr_front3.img_path = "./imgs/usr/usr_front3.xpm";
	map->usr_front3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_front3.img_path, &map->usr_front3.img_width,
			&map->usr_front3.img_height);
	map->usr_back1.img_path = "./imgs/usr/usr_back1.xpm";
	map->usr_back1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_back1.img_path, &map->usr_back1.img_width,
			&map->usr_back1.img_height);
	map->usr_back2.img_path = "./imgs/usr/usr_back2.xpm";
	map->usr_back2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_back2.img_path, &map->usr_back2.img_width,
			&map->usr_back2.img_height);
	map->usr_back3.img_path = "./imgs/usr/usr_back3.xpm";
	map->usr_back3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_back3.img_path, &map->usr_back3.img_width,
			&map->usr_back3.img_height);
}

void	user_imgs_init2(t_map *map)
{
	map->usr_right1.img_path = "./imgs/usr/usr_right1.xpm";
	map->usr_right1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_right1.img_path, &map->usr_right1.img_width,
			&map->usr_right1.img_height);
	map->usr_right2.img_path = "./imgs/usr/usr_right2.xpm";
	map->usr_right2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_right2.img_path, &map->usr_right2.img_width,
			&map->usr_right2.img_height);
	map->usr_right3.img_path = "./imgs/usr/usr_right3.xpm";
	map->usr_right3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_right3.img_path, &map->usr_right3.img_width,
			&map->usr_right3.img_height);
	map->usr_left1.img_path = "./imgs/usr/usr_left1.xpm";
	map->usr_left1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_left1.img_path, &map->usr_left1.img_width,
			&map->usr_left1.img_height);
	map->usr_left2.img_path = "./imgs/usr/usr_left2.xpm";
	map->usr_left2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_left2.img_path, &map->usr_left2.img_width,
			&map->usr_left2.img_height);
	map->usr_left3.img_path = "./imgs/usr/usr_left3.xpm";
	map->usr_left3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->usr_left3.img_path, &map->usr_left3.img_width,
			&map->usr_left3.img_height);
}

void	imgs_init(t_map *map)
{
	user_imgs_init1(map);
	user_imgs_init2(map);
	map->floor.img_path = "./imgs/grass.xpm";
	map->floor.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->floor.img_path, &map->floor.img_width, &map->floor.img_height);
	map->wall.img_path = "./imgs/wall_ext.xpm";
	map->wall.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->wall.img_path,
			&map->wall.img_width, &map->wall.img_height);
	map->banana.img_path = "./imgs/banana1.xpm";
	map->banana.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->banana.img_path, &map->banana.img_width,
			&map->banana.img_height);
	map->banana2.img_path = "./imgs/banana2.xpm";
	map->banana2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->banana2.img_path, &map->banana2.img_width,
			&map->banana2.img_height);
	map->exit.img_path = "./imgs/exit.xpm";
	map->exit.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->exit.img_path,
			&map->exit.img_width, &map->exit.img_height);
}
