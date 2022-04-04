/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:19 by apaege            #+#    #+#             */
/*   Updated: 2022/03/24 20:50:29 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_scene(t_scene	*scene)
{
	scene->tex = ft_calloc(sizeof(char *), NB_TEXTURES);
	scene->tex[NORTH] = NULL;
	scene->tex[SOUTH] = NULL;
	scene->tex[WEST] = NULL;
	scene->tex[EAST] = NULL;
	scene->floor = NULL;
	scene->ceil = NULL;
	scene->map = NULL;
	scene->size.w = -1;
	scene->pos.x = -1;
	scene->pos.y = -1;
	scene->dir.x = -1;
	scene->dir.y = -1;
	scene->move.up = 0;
	scene->move.down = 0;
	scene->move.left = 0;
	scene->move.right = 0;
	scene->move.turn_left = 0;
	scene->move.turn_right = 0;
}

static void	ft_set_dir(t_double *dir, char **map, int line, int col)
{
	if (map[line][col] == 'S')
	{
		dir->x = 1;
		dir->y = 0;
	}
	else if (map[line][col] == 'N')
	{
		dir->x = -1;
		dir->y = 0;
	}
	else if (map[line][col] == 'W')
	{
		dir->x = 0;
		dir->y = -1;
	}
	else if (map[line][col] == 'E')
	{
		dir->x = 0;
		dir->y = 1;
	}
}

void	ft_start_pos_init(t_scene *scene, char **map, int line, int col)
{
	scene->map[line][col] = '9';
	scene->pos.x = line + 0.5;
	scene->pos.y = col + 0.5;
	ft_set_dir(&scene->dir, map, line, col);
	scene->plane.x = scene->dir.x * FOV;
	scene->plane.y = scene->dir.y * FOV;
	ft_offset(&scene->plane, 1.570796);
}
