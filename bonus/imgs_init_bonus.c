/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:51:45 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 13:08:20 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	dk_imgs_init1(t_map *map)
{
	map->dk_front1.img_path = "./imgs/dk/dk_front1.xpm";
	map->dk_front1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_front1.img_path, &map->dk_front1.img_width,
			&map->dk_front1.img_height);
	map->dk_front2.img_path = "./imgs/dk/dk_front2.xpm";
	map->dk_front2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_front2.img_path, &map->dk_front2.img_width,
			&map->dk_front2.img_height);
	map->dk_front3.img_path = "./imgs/dk/dk_front3.xpm";
	map->dk_front3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_front3.img_path, &map->dk_front3.img_width,
			&map->dk_front3.img_height);
	map->dk_back1.img_path = "./imgs/dk/dk_back1.xpm";
	map->dk_back1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_back1.img_path, &map->dk_back1.img_width,
			&map->dk_back1.img_height);
	map->dk_back2.img_path = "./imgs/dk/dk_back2.xpm";
	map->dk_back2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_back2.img_path, &map->dk_back2.img_width,
			&map->dk_back2.img_height);
	map->dk_back3.img_path = "./imgs/dk/dk_back3.xpm";
	map->dk_back3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_back3.img_path, &map->dk_back3.img_width,
			&map->dk_back3.img_height);
}

void	dk_imgs_init2(t_map *map)
{
	map->dk_right1.img_path = "./imgs/dk/dk_right1.xpm";
	map->dk_right1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_right1.img_path, &map->dk_right1.img_width,
			&map->dk_right1.img_height);
	map->dk_right2.img_path = "./imgs/dk/dk_right2.xpm";
	map->dk_right2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_right2.img_path, &map->dk_right2.img_width,
			&map->dk_right2.img_height);
	map->dk_right3.img_path = "./imgs/dk/dk_right3.xpm";
	map->dk_right3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_right3.img_path, &map->dk_right3.img_width,
			&map->dk_right3.img_height);
	map->dk_left1.img_path = "./imgs/dk/dk_left1.xpm";
	map->dk_left1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_left1.img_path, &map->dk_left1.img_width,
			&map->dk_left1.img_height);
	map->dk_left2.img_path = "./imgs/dk/dk_left2.xpm";
	map->dk_left2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_left2.img_path, &map->dk_left2.img_width,
			&map->dk_left2.img_height);
	map->dk_left3.img_path = "./imgs/dk/dk_left3.xpm";
	map->dk_left3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->dk_left3.img_path, &map->dk_left3.img_width,
			&map->usr_left3.img_height);
}

void	imgs_init(t_map *map)
{
	user_imgs_init1(map);
	user_imgs_init2(map);
	dk_imgs_init1(map);
	dk_imgs_init2(map);
	jag_front_imgs_init(map);
	jag_back_imgs_init(map);
	jag_right_imgs_init(map);
	jag_left_imgs_init(map);
	jagx_imgs_init(map);
	objects_imgs_init(map);
	map->floor.img_path = "./imgs/grass.xpm";
	map->floor.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->floor.img_path, &map->floor.img_width, &map->floor.img_height);
	map->wall.img_path = "./imgs/wall.xpm";
	map->wall.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, map->wall.img_path,
			&map->wall.img_width, &map->wall.img_height);
	map->title.img_path = "./imgs/BANANA.COM.xpm";
	map->title.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->title.img_path, &map->title.img_width, &map->title.img_height);
}
