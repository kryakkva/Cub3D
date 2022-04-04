/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:19 by apaege            #+#    #+#             */
/*   Updated: 2022/03/30 22:38:58 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_set_dir(t_scene *scene, char map)
{
	if (map == 'S')
	{
		scene->dir.x = 1;
		scene->dir.y = 0;
	}
	else if (map == 'N')
	{
		scene->dir.x = -1;
		scene->dir.y = 0;
	}
	else if (map == 'W')
	{
		scene->dir.x = 0;
		scene->dir.y = -1;
	}
	else if (map == 'E')
	{
		scene->dir.x = 0;
		scene->dir.y = 1;
	}
	scene->start_dir = scene->dir;
}

void	ft_start_pos_init(t_scene *scene, char **map, int line, int col)
{
	scene->map[line][col] = '9';
	scene->pos.x = line + 0.5;
	scene->pos.y = col + 0.5;
	scene->start_pos = scene->pos;
	ft_set_dir(scene, map[line][col]);
	scene->plane.x = scene->dir.x * FOV;
	scene->plane.y = scene->dir.y * FOV;
	scene->start_plane = scene->plane;
	ft_offset(&scene->plane, 1.570796);
}

void	ft_set_sprite(t_scene *scene, char **map, int line, int col)
{
	scene->map[line][col] = map[line][col];
	scene->nbr_sprite++;
}
