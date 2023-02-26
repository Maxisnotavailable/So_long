/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jag_imgs_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:39:19 by molla             #+#    #+#             */
/*   Updated: 2023/02/26 13:11:08 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	jag_front_imgs_init(t_map *map)
{
	map->jag_front1.img_path = "./imgs/jag/jag_front1.xpm";
	map->jag_front1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_front1.img_path, &map->jag_front1.img_width,
			&map->jag_front1.img_height);
	map->jag_front2.img_path = "./imgs/jag/jag_front2.xpm";
	map->jag_front2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_front2.img_path, &map->jag_front2.img_width,
			&map->jag_front2.img_height);
	map->jag_front3.img_path = "./imgs/jag/jag_front3.xpm";
	map->jag_front3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_front3.img_path, &map->jag_front3.img_width,
			&map->jag_front3.img_height);
	map->jag_front4.img_path = "./imgs/jag/jag_front4.xpm";
	map->jag_front4.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_front4.img_path, &map->jag_front4.img_width,
			&map->jag_front4.img_height);
}

void	jag_back_imgs_init(t_map *map)
{
	map->jag_back1.img_path = "./imgs/jag/jag_back1.xpm";
	map->jag_back1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_back1.img_path, &map->jag_back1.img_width,
			&map->jag_back1.img_height);
	map->jag_back2.img_path = "./imgs/jag/jag_back2.xpm";
	map->jag_back2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_back2.img_path, &map->jag_back2.img_width,
			&map->jag_back2.img_height);
	map->jag_back3.img_path = "./imgs/jag/jag_back3.xpm";
	map->jag_back3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_back3.img_path, &map->jag_back3.img_width,
			&map->jag_back3.img_height);
	map->jag_back4.img_path = "./imgs/jag/jag_back4.xpm";
	map->jag_back4.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_back4.img_path, &map->jag_back4.img_width,
			&map->jag_back4.img_height);
}

void	jag_right_imgs_init(t_map *map)
{
	map->jag_right1.img_path = "./imgs/jag/jag_right1.xpm";
	map->jag_right1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_right1.img_path, &map->jag_right1.img_width,
			&map->jag_right1.img_height);
	map->jag_right2.img_path = "./imgs/jag/jag_right2.xpm";
	map->jag_right2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_right2.img_path, &map->jag_right2.img_width,
			&map->jag_right2.img_height);
	map->jag_right3.img_path = "./imgs/jag/jag_right3.xpm";
	map->jag_right3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_right3.img_path, &map->jag_right3.img_width,
			&map->jag_right3.img_height);
	map->jag_right4.img_path = "./imgs/jag/jag_right4.xpm";
	map->jag_right4.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_right4.img_path, &map->jag_right4.img_width,
			&map->jag_right4.img_height);
}

void	jag_left_imgs_init(t_map *map)
{
	map->jag_left1.img_path = "./imgs/jag/jag_left1.xpm";
	map->jag_left1.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_left1.img_path, &map->jag_left1.img_width,
			&map->jag_left1.img_height);
	map->jag_left2.img_path = "./imgs/jag/jag_left2.xpm";
	map->jag_left2.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_left2.img_path, &map->jag_left2.img_width,
			&map->jag_left2.img_height);
	map->jag_left3.img_path = "./imgs/jag/jag_left3.xpm";
	map->jag_left3.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_left3.img_path, &map->jag_left3.img_width,
			&map->jag_left3.img_height);
	map->jag_left4.img_path = "./imgs/jag/jag_left4.xpm";
	map->jag_left4.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jag_left4.img_path, &map->jag_left4.img_width,
			&map->jag_left4.img_height);
}

void	jagx_imgs_init(t_map *map)
{
	map->jagx_front.img_path = "./imgs/jag/jagx_front.xpm";
	map->jagx_front.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jagx_front.img_path, &map->jagx_front.img_width,
			&map->jagx_front.img_height);
	map->jagx_back.img_path = "./imgs/jag/jagx_back.xpm";
	map->jagx_back.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jagx_back.img_path, &map->jagx_back.img_width,
			&map->jagx_back.img_height);
	map->jagx_right.img_path = "./imgs/jag/jagx_right.xpm";
	map->jagx_right.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jagx_right.img_path, &map->jagx_right.img_width,
			&map->jagx_right.img_height);
	map->jagx_left.img_path = "./imgs/jag/jagx_left.xpm";
	map->jagx_left.img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->jagx_left.img_path, &map->jagx_left.img_width,
			&map->jagx_left.img_height);
}
